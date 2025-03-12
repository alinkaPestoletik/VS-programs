// the author is Alina Pestova DSAI-5
// I used the idea of the heap implementation from the lecture 8

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class AlinaMaxHeap {
public:
    int d;
    vector<T> AlinaHeap;

    AlinaMaxHeap(int d) : d(d) {}

    void insert(T key) {
        AlinaHeap.push_back(key);
        heapify(AlinaHeap.size() - 1);
    }

    vector<T> getHeap() {
        return AlinaHeap;
    }

    int getParentIndex(int childIndex) {
        return (childIndex - 1) / d;
    }

    void heapify(int index) {
        while (index > 0 && AlinaHeap[getParentIndex(index)] < AlinaHeap[index]) {
            swap(AlinaHeap[getParentIndex(index)], AlinaHeap[index]);
            index = getParentIndex(index);
        }
    }
};

int main() {
    int N, d;
    cin >> N >> d;
    vector<int> array(N);
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    AlinaMaxHeap<int> AlinaHeap(d);

    for (int key : array) {
        AlinaHeap.insert(key);
    }
    vector<int> heap = AlinaHeap.getHeap();
    for (int x : heap) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}