// the author is Alina Pestova DSAI-5

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct AlinaFrequencyItem {
    int frequency;
    T value;

    AlinaFrequencyItem(int freq, T val) : frequency(freq), value(val) {}
};

template <typename T>
class AlinaMinHeap {
public:
    int d;
    vector<AlinaFrequencyItem<T>> AlinaHeap;

    AlinaMinHeap(int d) : d(d) {}

    void insert(int freq, T val) {
        AlinaHeap.push_back(AlinaFrequencyItem<T>(freq, val));
        heapify(AlinaHeap.size() - 1);
    }

    AlinaFrequencyItem<T> extractMin() {
        AlinaFrequencyItem<T> min_ = AlinaHeap[0];
        AlinaHeap[0] = AlinaHeap.back();
        AlinaHeap.pop_back();
        heapify(0);
        return min_;
    }

    bool isEmpty() {
        return AlinaHeap.empty();
    }

    int getParentIndex(int childIndex) {
        return (childIndex - 1) / d;
    }

    void heapify(int index) {
        int parentIndex = getParentIndex(index);
        if (index > 0 && AlinaHeap[parentIndex].frequency > AlinaHeap[index].frequency) {
            swap(AlinaHeap[parentIndex], AlinaHeap[index]);
            heapify(parentIndex);
        } else {
            int small = index;
            int n = AlinaHeap.size();
            for (int i = 1; i <= d; ++i) {
                int child = d * index + i;
                if (child < n && AlinaHeap[child].frequency < AlinaHeap[small].frequency) {
                    small = child;
                }
            }
            if (small != index) {
                swap(AlinaHeap[index], AlinaHeap[small]);
                heapify(small);
            }
        }
    }
};

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low;
        int j = high - 1;

        while (i <= j) {
            while (i <= j && arr[i] < pivot) {
                i++;
            }
            while (i <= j && arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        swap(arr[i], arr[high]);

        quickSort(arr, low, i - 1);
        quickSort(arr, i + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr, 0, arr.size() - 1);

    vector<AlinaFrequencyItem<int>> vector;
    int num = arr[0];
    int freq = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] == num) {
            freq++;
        } else {
            vector.push_back(AlinaFrequencyItem<int>(freq, num));
            num = arr[i];
            freq = 1;
        }
    }
    vector.push_back(AlinaFrequencyItem<int>(freq, num));

    AlinaMinHeap<int> minHeap(2);

    for (auto const& item : vector) {
        minHeap.insert(item.frequency, item.value);
    }

    while (!minHeap.isEmpty()) {
        cout << minHeap.extractMin().value << endl;
    }

    return 0;
}