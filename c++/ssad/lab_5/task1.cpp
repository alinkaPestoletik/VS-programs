#include <iostream>
using namespace std;

template<typename T>
class GenericStack {
private:
    const int DEFAULT_CAPACITY = 16;
    const int MULT = 2;
    int capacity;
    int size = 0;
    T *buffer;

public:
    GenericStack() : buffer(new T[DEFAULT_CAPACITY]), capacity(DEFAULT_CAPACITY) {
    }

    GenericStack(int capacity) : buffer(new T[capacity]), capacity(capacity) {
    }

    virtual void push(T el) {
        if (size == capacity) {
            capacity *= MULT;
            T *newBuffer = new T[capacity];
            for (int i = 0; i < size; i++) {
                newBuffer[i] = buffer[i];
            }
            T *toDelete = buffer;
            delete[] toDelete;
            buffer = newBuffer;
        }
        buffer[size++] = el;
    }

    virtual T pop() {
        if (size == 0) {
            throw out_of_range("Stack is empty");
        }
        return buffer[--size];
    }

    T peek() {
        return buffer[size - 1];
    }

    bool empty() {
        return size == 0;
    }

    int amountOfElements() {
        return size;
    }

    ~GenericStack() { delete[] buffer; }
};


class StringStack : public GenericStack<string> {
public:
    StringStack() : GenericStack<string>() {
    }

    StringStack(int capacity) : GenericStack<string>(capacity) {
    }

    void push(string el) override {
        if (el.size() != 0) {
            GenericStack<string>::push(el);
        } else {
            cout << "String is empty";
        }
    }

    string pop() override {
        if (GenericStack<string>::empty()) {
            throw out_of_range("Stack is empty");
        }
        return GenericStack<string>::pop();
    }

    string peek() {
        if (GenericStack<string>::empty()) {
            throw out_of_range("Stack is empty");
        }
        return GenericStack<string>::peek();
    }

    void concatTopTwo() {
        if (GenericStack<string>::amountOfElements() < 2) {
            throw out_of_range("Not enough elements on stack!");
        }
        string first = GenericStack<string>::pop();
        string second = GenericStack<string>::pop();
        GenericStack<string>::push(first + second);
    }
};


int main() {
    StringStack stringStack;
    stringStack.push("hello");
    stringStack.push("hello");
    stringStack.concatTopTwo();
    cout << stringStack.peek();
}
