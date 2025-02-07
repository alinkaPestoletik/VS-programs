/*
 * author Alina Pestova DSAI-5
 * I used the improved code implementation of HashMap from the third lab 
 * I used the idea of the implementation of Merge sort from SLRS
 */

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class MapSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int k = scanner.nextInt();
        String[] words = new String[n];
        for (int i = 0; i < n; i++) {
            words[i] = scanner.next();
        }

        System.out.println(findWord(n, k, words));

        scanner.close();
    }

    private static String findWord(int n, int k, String[] words) {
        AlinaMap<String, Integer> numberWord = new AlinaHashMap<>(n);
        AlinaMap<String, Integer> firstIndex = new AlinaHashMap<>(n);

        // solve the number of current word and the index of its first appearance
        for (int i = 0; i < n; i++) {
            String word = words[i];
            numberWord.put(word, numberWord.get(word) == null ? 1 : numberWord.get(word) + 1);
            if (firstIndex.get(word) == null) {
                firstIndex.put(word, i);
            }
        }

        ArrayList<String> sortWords = new ArrayList<>(numberWord.keys()); 
        mergeSortAlinka(sortWords, numberWord, firstIndex);

        // find the necessary word
        if (k <= sortWords.size() && k > 0) {
            return sortWords.get(k - 1);
        } else {
            return ""; 
        }
    }

    private static void mergeSortAlinka(ArrayList<String> words, AlinaMap<String, Integer> numberWord, AlinaMap<String, Integer> firstIndex) {
        if (words.size() <= 1) {
            return;
        }
        int middle = words.size() / 2;
        ArrayList<String> left = new ArrayList<>(words.subList(0, middle));
        ArrayList<String> right = new ArrayList<>(words.subList(middle, words.size()));

        mergeSortAlinka(left, numberWord, firstIndex);
        mergeSortAlinka(right, numberWord, firstIndex);

        mergeAlinka(words, left, right, numberWord, firstIndex);
    }

    private static void mergeAlinka(ArrayList<String> words, ArrayList<String> left, ArrayList<String> right, AlinaMap<String, Integer> numberWord, AlinaMap<String, Integer> firstIndex) {
        int i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size()) {
            String leftWord = left.get(i);
            String rightWord = right.get(j);

            int temp = Integer.compare(numberWord.get(rightWord), numberWord.get(leftWord)); 

            if (temp < 0) {
                words.set(k++, leftWord);
                i++;

            } else if (temp > 0) {
                words.set(k++, rightWord);
                j++;

            } else {
                if (firstIndex.get(leftWord) <= firstIndex.get(rightWord)) {
                    words.set(k++, leftWord);
                    i++;
                } else {
                    words.set(k++, rightWord);
                    j++;
                }
            }
        }

        while (i < left.size()) {
            words.set(k++, left.get(i++));
        }

        while (j < right.size()) {
            words.set(k++, right.get(j++));
        }
    }
}

interface AlinaMap<K, V> {
    V get(K key);

    void put(K key, V value);

    void remove(K key);

    int size();

    boolean isEmpty();

    ArrayList<K> keys();
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
    List<KeyValue<K, V>>[] hashTable;
    int capacity;
    int numberOfElements;

    public AlinaHashMap(int capacity) {
        this.capacity = capacity;
        this.numberOfElements = 0;
        this.hashTable = new List[capacity];
        for (int i = 0; i < capacity; i++) {
            this.hashTable[i] = new LinkedList<>();
        }
    }

    @Override
    public void put(K key, V value) {
        int i = Math.abs(key.hashCode() % this.capacity);
        for (KeyValue<K, V> kv : this.hashTable[i]) {
            if (kv.key.equals(key)) {
                kv.value = value;
                return;
            }
        }
        this.hashTable[i].add(new KeyValue<>(key, value));
        ++this.numberOfElements;

    }

    @Override
    public void remove(K key) {
        int i = Math.abs(key.hashCode() % this.capacity);
        this.hashTable[i].removeIf(kv -> kv.key.equals(key));
    }

    @Override
    public V get(K key) {
        int i = Math.abs(key.hashCode() % this.capacity);
        for (KeyValue<K, V> kv : this.hashTable[i]) {
            if (kv.key.equals(key)) {
                return kv.value;
            }
        }
        return null;
    }

    @Override
    public int size() {
        return this.numberOfElements;
    }

    @Override
    public boolean isEmpty() {
        return (this.numberOfElements == 0);
    }

    @Override
    public ArrayList<K> keys() {
        ArrayList<K> keys = new ArrayList<>();
        for (List<KeyValue<K, V>> pair : hashTable) {
            for (KeyValue<K, V> kv : pair) {
                keys.add(kv.key);
            }
        }
        return keys;
    }
}

