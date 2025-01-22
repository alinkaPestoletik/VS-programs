#include <iostream>

void swap (int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int k = 10, m = 20;
    swap(&k, &m);
    std::cout << k << ' ' << m << std::endl;
    return 0;
}