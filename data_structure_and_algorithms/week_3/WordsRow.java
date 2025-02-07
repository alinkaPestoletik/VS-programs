/*
 * author Alina Pestova DSAI-5
 * I used the improved code implementation of HashMap from the third lab 
 */

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class WordsRow {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        scanner.nextLine();
        String[] firstRow = scanner.nextLine().split(" ");
        int m = scanner.nextInt();
        scanner.nextLine();
        String[] secondRow = scanner.nextLine().split(" ");

        AlinaHashMap<String, Integer> secondMap = new AlinaHashMap<>(691);
        for (String word : secondRow) {
            secondMap.put(word, secondMap.getNum(word, 0) + 1);
        }

        ArrayList<String> uniqueDistinctWords = new ArrayList<>();
        for (String word : firstRow) {
            if (word != null && secondMap.getNum(word, 0) == 0) {
                uniqueDistinctWords.add(word);
                secondMap.put(word, 2);
            }
        }

        System.out.println(uniqueDistinctWords.size());
        for (String word : uniqueDistinctWords) {
            System.out.println(word);
        }

        scanner.close();
    }
}

interface AlinaMap<K, V> {
    V get(K key);

    void put(K key, V value);

    void remove(K key);

    int size();

    boolean isEmpty();

    V getNum(K key, V value);
}

class KeyValue<K, V> {
    K key;
    V value;

    public KeyValue(K key, V value) {
        this.key = key;
        this.value = value;
    }
}

class AlinaHashMap<K, V> implements AlinaMap<K, V> {
    private final List<KeyValue<K, V>>[] hashTable;
    private final int capacity;

    public AlinaHashMap(int capacity) {
        this.capacity = capacity;
        this.hashTable = new List[capacity];
        for (int i = 0; i < capacity; i++) {
            this.hashTable[i] = new ArrayList<>();
        }
    }

    @Override
    public void put(K key, V value) {
        int index = Math.abs(key.hashCode()) % this.capacity;
        List<KeyValue<K, V>> pair = this.hashTable[index];

        for (KeyValue<K, V> entry : pair) {
            if (entry.key.equals(key)) {
                entry.value = value;
                return;
            }
        }

        pair.add(new KeyValue<>(key, value));
    }

    @Override
    public V get(K key) {
        int index = Math.abs(key.hashCode()) % this.capacity;
        List<KeyValue<K, V>> pair = this.hashTable[index];

        for (KeyValue<K, V> entry : pair) {
            if (entry.key.equals(key)) {
                return entry.value;
            }
        }

        return null;
    }

    @Override
    public V getNum(K key, V defaultValue) {
        int i = Math.abs(key.hashCode() % this.capacity);
        for (KeyValue<K, V> kv : this.hashTable[i]) {
            if (kv.key.equals(key)) {
                return kv.value;
            }
        }
        return defaultValue;
    }

    @Override
    public void remove(K key) {
        int index = Math.abs(key.hashCode()) % this.capacity;
        List<KeyValue<K, V>> pair = this.hashTable[index];

        for (KeyValue<K, V> entry : pair) {
            if (entry.key.equals(key)) {
                pair.remove(entry);
                break;
            }
        }
    }

    @Override
    public int size() {
        int count = 0;
        for (List<KeyValue<K, V>> pair : this.hashTable) {
            count += pair.size();
        }
        return count;
    }

    @Override
    public boolean isEmpty() {
        return size() == 0;
    }
}
