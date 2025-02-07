/*
 * author Alina Pestova DSAI-5
 * I used the code of ArrayStack and LinkedQueue implementation from the second lab
 * I used the structure of the Shunting Yard algorithm from https://www.geeksforgeeks.org/evaluation-of-postfix-expression/
 * I also discussed the approach taken in this solution with Denis Nurmuhametov
 */

import java.util.Scanner;
import java.lang.Math;

public class ShuntingYardAlgorithm {

    private static LinkedQueue<String> queue = new LinkedQueue<>();
    private static AlinaStack<String> stack = new AlinaStack<>();
    private static AlinaStack<String> stackOperations = new AlinaStack<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String expression = scanner.nextLine();
        ShuntingYardAlg(expression.split(" "));
        String[] array = queue.fromQueueToStringArray();
        int result = evaluatePostfixExpression(array);
        System.out.println(result);

    }

    public static void ShuntingYardAlg(String[] expression) {
        for (String token : expression) {
            if (token.equals("0") || token.equals("1") || token.equals("2") || token.equals("3") || token.equals("4") ||
                    token.equals("5") || token.equals("6") || token.equals("7") || token.equals("8")
                    || token.equals("9")) {
                queue.offer(token);

            } else if (token.equals("max") || token.equals("min")) {
                stack.push(token);

            } else if (isOperator(token)) {
                while (!stack.isEmpty() && isOperator(stack.peek()) && precedence(token) <= precedence(stack.peek())) {
                    queue.offer(stack.pop());
                }
                stack.push(token);

            } else if (token.equals(",")) {
                while (!stack.isEmpty() && isOperator(stack.peek())) {
                    queue.offer(stack.pop());
                }

            } else if (token.equals("(")) {
                stack.push(token);

            } else if (token.equals(")")) {
                while (!stack.isEmpty() && isOperator(stack.peek())) {
                    queue.offer(stack.pop());
                }
                stack.pop();
                if (!stack.isEmpty()) {
                    if (stack.peek().equals("max") || (stack.peek().equals("min"))) {
                        queue.offer(stack.pop());
                    }
                }
            }
        }

        while (!stack.isEmpty()) {
            queue.offer(stack.pop());
        }
    }

    public static boolean isOperator(String token) {
        if (token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/")) {
            return true;
        }
        return false;
    }

    public static int precedence(String token) {
        if (token.equals("+") || token.equals("-")) {
            return 1;
        } else if (token.equals("*") || token.equals("/")) {
            return 2;
        }
        return -1;
    }

    public static int evaluatePostfixExpression(String[] expr) {

        for (int i = 0; i < expr.length; i++) {
            if (expr[i].equals("0") || expr[i].equals("1") || expr[i].equals("2") || expr[i].equals("3") ||
                    expr[i].equals("4") || expr[i].equals("5") || expr[i].equals("6") || expr[i].equals("7") ||
                    expr[i].equals("8") || expr[i].equals("9")) {
                stackOperations.push(expr[i]);
            } else if (isOperator(expr[i]) || expr[i].equals("max") || expr[i].equals("min")) {
                int firstOperand = Integer.parseInt(stackOperations.pop());
                int secondOperand = Integer.parseInt(stackOperations.pop());
                switch (expr[i]) {
                    case "+":
                        stackOperations.push(String.valueOf(firstOperand + secondOperand));
                        break;
                    case "-":
                        stackOperations.push(String.valueOf(secondOperand - firstOperand));
                        break;
                    case "*":
                        stackOperations.push(String.valueOf(firstOperand * secondOperand));
                        break;
                    case "/":
                        stackOperations.push(String.valueOf(secondOperand / firstOperand));
                        break;
                    case "max":
                        stackOperations.push(String.valueOf(Math.max(firstOperand, secondOperand)));
                        break;
                    case "min":
                        stackOperations.push(String.valueOf(Math.min(firstOperand, secondOperand)));
                        break;
                }
            }
        }
        return Integer.parseInt(stackOperations.pop());
    }

}

class Node<T> {
    T data;
    Node<T> next;

    public Node(T data, Node<T> next) {
        this.data = data;
        this.next = next;
    }
}

interface Alina_Queue<T> {
    void offer(T value);

    T pool();

    T peek();

    int size();

    boolean isEmpty();
}

class LinkedQueue<T> implements Alina_Queue<T> {
    Node<T> head;
    Node<T> tail;
    int queueSize;

    public LinkedQueue() {
        this.head = null;
        this.tail = null;
        this.queueSize = 0;
    }

    public void listQueue() {
        Node<T> object = this.head;
        for (int i = 0; i < this.queueSize; i++) {
            if (i == queueSize - 1) {
                System.out.println(object.data);
            } else {
                System.out.print(object.data + " ");
            }
            object = object.next;
        }

    }

    public String[] fromQueueToStringArray() {
        Node<T> object = this.head;
        String[] array = new String[this.queueSize];
        for (int i = 0; i < this.queueSize; i++) {
            array[i] = (String) object.data;
            object = object.next;
        }
        return array;
    }

    @Override
    public int size() {
        return this.queueSize;
    }

    @Override
    public boolean isEmpty() {
        return (this.queueSize == 0);
    }

    @Override
    public void offer(T value) {
        if (this.head == null) {
            this.head = new Node<>(value, null);
            this.tail = this.head;
        } else {
            this.tail.next = new Node<>(value, null);
            this.tail = this.tail.next;
        }
        this.queueSize++;
    }

    @Override
    public T pool() {
        T item = this.head.data;
        this.head = this.head.next;

        if (this.head == null) {
            this.tail = null;
        }

        this.queueSize--;
        return item;
    }

    @Override
    public T peek() {
        return this.head.data;
    }
}

class Alina_ArrayList<T> {
    private T[] data;
    private int size;
    private int capacity;

    public Alina_ArrayList() {
        this(10);
    }

    public Alina_ArrayList(int capacity) {
        this.capacity = capacity;
        this.data = (T[]) new Object[capacity];
        this.size = 0;
    }

    public void add(T element) {
        if (size == capacity) {
            resize();
        }
        data[size++] = element;
    }

    public T get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }
        return data[index];
    }

    public void remove(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        data[--size] = null;
    }

    public int size() {
        return size;
    }

    private void resize() {
        if (capacity > Integer.MAX_VALUE / 2) {
            throw new IllegalStateException("Array capacity overflow");
        }
        capacity *= 2;
        T[] newData = (T[]) new Object[capacity];
        System.arraycopy(data, 0, newData, 0, size);
        data = newData;
    }
}

interface Alina_Stack<T> {
    void push(T value);

    T pop();

    T peek();

    int size();

    boolean isEmpty();
}

class AlinaStack<T> implements Alina_Stack<T> {
    Alina_ArrayList<T> items;
    final int stackCapacity = 256; // maximum number of elements
    int stackSize; // number of elements in this stack

    public AlinaStack() {
        this.items = new Alina_ArrayList<>();
        this.stackSize = 0;
    }

    public void listStack() {
        for (int i = 0; i < stackSize; i++) {
            System.out.print(items.get(i) + " ");
        }
    }

    @Override
    public int size() {
        return this.stackSize;
    }

    @Override
    public boolean isEmpty() {
        return (this.stackSize == 0);
    }

    @Override
    public void push(T value) {
        this.items.add(value);
        this.stackSize++;
    }

    @Override
    public T pop() {
        if (this.stackSize == 0) {
            throw new RuntimeException("Pop from an empty stack");
        }
        this.stackSize--;
        T item = this.items.get(this.stackSize);
        this.items.remove(this.stackSize);
        return item;
    }

    @Override
    public T peek() {
        return this.items.get(this.stackSize - 1);
    }
}
