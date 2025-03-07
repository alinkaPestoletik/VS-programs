#include <iostream>
#include <vector>
#include <functional>

// Implementing the customMap function
std::vector<int> customMap(const std::vector<int> &vec, std::function<int(int)> func) {
    std::vector<int> result;
    for (int value : vec) {
        result.push_back(func(value));
    }
    return result;
}

// Implementing the customFilter function
std::vector<int> customFilter(const std::vector<int> &vec, std::function<bool(int)> predicate) {
    std::vector<int> result;
    for (int value : vec) {
        if (predicate(value)) {
            result.push_back(value);
        }
    }
    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    auto squared = customMap(nums,  -> int { return x * x; });
    std::cout << "Squared values: ";
    for (int value : squared) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    auto odds = customFilter(nums,  -> bool { return x % 2 != 0; });
    std::cout << "Odd values: ";
    for (int value : odds) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    auto doubled = customMap(nums,  -> int { return x * 2; });
    std::cout << "Doubled values: ";
    for (int value : doubled) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    auto evens = customFilter(nums,  -> bool { return x % 2 == 0; });
    std::cout << "Even values: ";
    for (int value : evens) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}