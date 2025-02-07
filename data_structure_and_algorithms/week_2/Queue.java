/*
 * author Alina Pestova DSAI-5
 * I used this code from the second lab
 */

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
        if(this.head == null) {
            this.head = new Node<>(value, null);
            this.tail = this.head;
        }
        else {
            this.tail.next = new Node<>(value, null);
            this.tail = this.tail.next;
        }
        this.queueSize++;
    }

    @Override
    public T pool() {
        T item = this.head.data;
        this.head = this.head.next;

        if(this.head == null)   {
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

public class Queue {
    public static void main(String[] args) {
        Alina_Queue<Integer> myQueue = new LinkedQueue<>();

        myQueue.offer(1);
        myQueue.offer(2);

        System.out.println("Size of the queue : " + myQueue.size());
        System.out.println("Pool from the queue : " + myQueue.pool());
        System.out.println("Size of the queue : " + myQueue.size());
        System.out.println("Peek from the queue : " + myQueue.peek());
        System.out.println("Size of the queue : " + myQueue.size());
        System.out.println("Is the queue empty? " + myQueue.isEmpty());

        myQueue.offer(3);
        myQueue.offer(4);
        myQueue.offer(5);

        while (!myQueue.isEmpty()) {
            System.out.println("Pool from the Queue : " + myQueue.pool());
        }

        try {
            System.out.println("Pool from the Queue : " + myQueue.pool());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}