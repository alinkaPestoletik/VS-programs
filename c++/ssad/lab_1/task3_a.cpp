#include <iostream>
using namespace std;



void removeElement(int* array, int& size, int index) {
    for(int i = index; i < size-1; i++) {
        *(array+i) = *(array + i + 1);
    }
    size--;
}

int findDuplicate(int* array , int& size, int start) {
    for (int i = start + 1; i < size; i++){
        if (*(array + i) == *(array + start)) {
            return i;
        }
    }
    return -1;
}

void removeDuplicates(int* array, int& size) {
    for (int i = 0; i < size; i++) {
        int duplicate = findDuplicate(array, size, i);
        while (duplicate != -1) {
            removeElement(array, size, duplicate);
            duplicate = findDuplicate(array, size, i);
        }
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++){
        cout << *(array +i) << " ";
    }
}

int main() {
    int N;
    cin >> N;
    int array[N];
    for (int i = 0; i < N; i++) {
        int insertedNum;
        cin >> insertedNum;
        array[i] = insertedNum;
    }
    removeDuplicates(array, N);
    printArray(array, N);
}
