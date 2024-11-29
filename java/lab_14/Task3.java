import java.util.concurrent.locks.ReentrantLock;

class Counter {
    private int counter = 0;
    private final ReentrantLock lock = new ReentrantLock();

    public void increment() throws InterruptedException {
        lock.lock();
        try {
            counter++;
            System.out.println(getValue());
            Thread.sleep(500);
        } finally {
            lock.unlock();
        }
    }

    public int getValue() {
        lock.lock();
        try {
            return this.counter;
        } finally {
            lock.unlock();
        }

    }
}

public class Task3 {
    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter();

        Thread thread1 = new Thread(() -> {
            for (int i = 0; i < 10; i++) {
                try {
                    counter.increment();
                } catch (InterruptedException e) {
                }
            }
        });

        Thread thread2 = new Thread(() -> {
            for (int i = 0; i < 10; i++) {
                try {
                    counter.increment();
                } catch (InterruptedException e) {
                }
            }
        });

        thread1.start();
        thread2.start();
    }
}
