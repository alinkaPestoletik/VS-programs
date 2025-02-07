/*
 * author Alina Pestova DSAI-5
 * I used the code of ArrayStack implementation from the second lab
 */


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

class ArrayStack<T> implements Alina_Stack<T> {
    Alina_ArrayList<T> items;
    final int stackCapacity = 256; // maximum number of elements
    int stackSize; // number of elements in this stack

    public ArrayStack() {
        this.items = new Alina_ArrayList<>();
        // this.items.ensureCapacity(stackCapacity);
        this.stackSize = 0;
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
        if(this.stackSize == 0) {
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

public class StackArray {
    public static void main(String[] args) {
        Alina_Stack<Integer> myStack = new ArrayStack<>();

        myStack.push(1);
        myStack.push(2);

        System.out.println("Size of the stack : " + myStack.size());
        System.out.println("Pop from the stack : " + myStack.pop());
        System.out.println("Size of the stack : " + myStack.size());
        System.out.println("Peek from the stack : " + myStack.peek());
        System.out.println("Size of the stack : " + myStack.size());
        System.out.println("Is the stack empty? " + myStack.isEmpty());

        myStack.push(3);
        myStack.push(4);
        myStack.push(5);

        while (!myStack.isEmpty()) {
            System.out.println("Pop from the stack : " + myStack.pop());
        }

        try {
            System.out.println("Pop from the stack : " + myStack.pop());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}