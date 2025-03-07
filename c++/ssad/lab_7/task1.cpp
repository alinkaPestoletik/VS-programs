#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class CircularBuffer {
public:
    CircularBuffer(size_t capacity) : capacity(capacity), buffer(capacity), head(0), tail(0), count(0) {}

    void push(const T& value) {
        buffer[tail] = value;
        tail = (tail + 1) % capacity;
        if (count == capacity) {
            head = (head + 1) % capacity; 
        } else {
            ++count;
        }
    }

    T pop() {
        if (empty()) {
            throw std::out_of_range("Buffer is empty");
        }
        T value = buffer[head];
        head = (head + 1) % capacity;
        --count;
        return value;
    }

    bool empty() const {
        return count == 0;
    }

    size_t size() const {
        return count;
    }

    class Iterator {
    public:
        Iterator(CircularBuffer& buffer, size_t index) : buffer(buffer), index(index), startIndex(index), iterated(0) {}

        T& operator*() {
            return buffer.buffer[index];
        }

        Iterator& operator++() {
            index = (index + 1) % buffer.capacity;
            ++iterated;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return iterated != buffer.count;
        }

    private:
        CircularBuffer& buffer;
        size_t index;
        size_t startIndex;
        size_t iterated;
    };

    Iterator begin() {
        return Iterator(*this, head);
    }

    Iterator end() {
        return Iterator(*this, tail);
    }

private:
    size_t capacity;
    std::vector<T> buffer;
    size_t head;
    size_t tail;
    size_t count;
};

int main() {
    CircularBuffer<int> cb(5);

    cb.push(1);
    cb.push(2);
    cb.push(3);
    cb.push(4);
    cb.push(5);

    std::cout << "Buffer contents: ";
    for (auto it = cb.begin(); it != cb.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    cb.push(6); 

    std::cout << "Buffer contents after pushing 6: ";
    for (auto it = cb.begin(); it != cb.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Popped value: " << cb.pop() << std::endl;

    std::cout << "Buffer contents after popping: ";
    for (auto it = cb.begin(); it != cb.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}