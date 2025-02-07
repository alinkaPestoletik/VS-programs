/*
 * author Alina Pestova DSAI-5
 * I used the improved code implementation of HashMap from the third lab and Internet resorces for implementation of build-in sort (compareTo) of words 
 */

 import java.util.ArrayList;
 import java.util.LinkedList;
 import java.util.List;
 import java.util.Scanner;
 
 public class Map {
     public static void main(String[] args) {
         Scanner scanner = new Scanner(System.in);
 
         int n = scanner.nextInt();
         int k = scanner.nextInt();
         String[] words = new String[n];
         for (int i = 0; i < n; i++) {
             words[i] = scanner.next();
         }
 
         System.out.println(SearchWord(n, k, words));
 
         scanner.close();
     }
 
     private static String SearchWord(int n, int k, String[] words) {
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
 
         List<String> sortWords = new ArrayList<>();
         for (KeyValue<String, Integer> kv : numberWord.entrySet()) {
             // if the word exists and has not null value, we will add to the list
             if (kv != null && kv.value != null) {
                 sortWords.add(kv.key);
             }
         }
 
 
         sortWords.sort((word1, word2) -> {
             int temp = numberWord.get(word2).compareTo(numberWord.get(word1)); // sorting words in descending order
             if (temp != 0) {
                 return temp;
             } else {
                 return firstIndex.get(word1).compareTo(firstIndex.get(word2)); // sorting words by ascending index of the first appearance
             }
         });
 
         // find the necessary word
         if (k <= sortWords.size() && k > 0) {
             return sortWords.get(k - 1);
         } else {
             return "";
         }
     }
 }   
 
 interface AlinaMap<K, V> {
     V get(K key);
 
     void put(K key, V value);
 
     void remove(K key);
 
     int size();
 
     boolean isEmpty();
     
     // an additional method to provide a view of the data stored in AlinaHashMap
     List<KeyValue<K, V>> entrySet();
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
     public List<KeyValue<K, V>> entrySet() {
         List<KeyValue<K, V>> entries = new ArrayList<>();
         for (List<KeyValue<K, V>> bucket : hashTable) {
             entries.addAll(bucket);
         }
         return entries;
     }
 }
 
 
 
 