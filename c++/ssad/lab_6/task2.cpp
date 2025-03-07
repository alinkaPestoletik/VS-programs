#include <iostream>
#include <unordered_map>
#include <cmath>

template <typename K, typename V>
class Dictionary {
public:
    void put(K key, V value) {
        data[key] = value;
    }

    V get(K key) const {
        return data.at(key);
    }

    void remove(K key) {
        data.erase(key);
    }

    size_t size() const {
        return data.size();
    }

private:
    std::unordered_map<K, V> data;
};

template <typename K>
class Dictionary<K, int> {
public:
    void put(K key, int value) {
        data[key] = value;
    }

    int get(K key) const {
        return std::abs(data.at(key));
    }

    void remove(K key) {
        data.erase(key);
    }

    int size() const {
        int sum = 0;
        for (const auto& pair : data) {
            sum += pair.second;
        }
        return sum;
    }

private:
    std::unordered_map<K, int> data;
};

int main() {
    Dictionary<std::string, std::string> dict;
    dict.put("apple", "fruit");
    dict.put("carrot", "vegetable");
    std::cout << "Value for 'apple': " << dict.get("apple") << std::endl;
    std::cout << "Size of dictionary: " << dict.size() << std::endl;
    dict.remove("apple");
    std::cout << "Size of dictionary after removal: " << dict.size() << std::endl;

    Dictionary<std::string, int> intDict;
    intDict.put("one", -1);
    intDict.put("two", 2);
    std::cout << "Absolute value for 'one': " << intDict.get("one") << std::endl;
    std::cout << "Sum of all values in intDict: " << intDict.size() << std::endl;

    return 0;
}