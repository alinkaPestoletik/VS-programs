#include <iostream>
#include <cstring>

template <typename T>
class Wrapper {
public:
    Wrapper(T value) : value(value) {}

    T getValue() const {
        return value;
    }

private:
    T value;
};

template <>
class Wrapper<char*> {
public:
    Wrapper(char* value) : value(value) {}

    size_t getValue() const {
        return std::strlen(value);
    }

private:
    char* value;
};

int main() {
    Wrapper<int> intWrapper(42);
    std::cout << "Wrapped int value: " << intWrapper.getValue() << std::endl;

    char str[] = "Hello, world!";
    Wrapper<char*> charWrapper(str);
    std::cout << "Length of wrapped char* value: " << charWrapper.getValue() << std::endl;

    return 0;
}