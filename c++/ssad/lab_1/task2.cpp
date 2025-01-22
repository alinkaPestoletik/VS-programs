#include <iostream>
using namespace std;


void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a;
    int b;
    cin >> a >> b;
    //cout << a << " " << b << endl;
    //swap(&a, &b);
    swap(a, b);
    cout << a << " " << b;
}
