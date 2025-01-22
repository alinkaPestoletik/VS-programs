#include <iostream>
#include <vector>
using namespace std;



int findDuplicate(vector<int>& array, int start) {
    for (int i = start + 1; i < array.size(); i++){
        if (array[i] == array[start]) {
            return i;
        }
    }
    return -1;
}

void removeDuplicates(vector<int>& array) {
    for (int i = 0; i <array.size(); i++) {
        int duplicate = findDuplicate(array, i);
        while (duplicate != -1) {
            array.erase(array.begin() + duplicate);
            duplicate = findDuplicate(array, i);
        }
    }
}

void printArray(vector<int> array) {
    for (int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> array;
    for (int i = 0; i < N; i++) {
        int insertedNum;
        cin >> insertedNum;
        array.push_back(insertedNum);
    }

    removeDuplicates(array);
    printArray(array);

}
