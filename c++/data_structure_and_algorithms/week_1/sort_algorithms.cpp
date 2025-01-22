#include <iostream>
using namespace std;


void bubbleSort(int N, int numbers[]) {
	bool swapped = true;
	while (swapped) {
		swapped = false;
		for (int i = 1; i < N; i++) {
			if (numbers[i-1] > numbers[i]) {
				swap(numbers[i-1], numbers[i]);
				swapped = true;
			}
		}
	}
}

void selectionSort(int N, int numbers[]) {
    for (int i = 0; i < N - 1; i++){
        int min_idx = i;
        for (int j = i + 1; j < N; j++){
            if (numbers[j] < numbers[min_idx]){
                min_idx = j;
            }
        }
        swap(numbers[i], numbers[min_idx]);
    }
}

// void selectionSort(int N, int numbers[]) {
// 	int i = 0;
// 	while (i < N - 1) {
// 		int min_idx = i;
// 		for (int j = i + 1; j < N; j++) {
// 			if (numbers[j] < numbers[min_idx]) {
// 				min_idx = j;
// 			}
// 		}
// 		swap(numbers[i], numbers[min_idx]);
// 		i++;
// 	}
// }

void insertionSort(int N, int numbers[]) {
    for (int i = 1; i < N; i++){
        int key = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > key){
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = key;
    }
}

int main()
{
	int N;
    cin >> N;

    int numbers[N];
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    bubbleSort(N, numbers);
	
    for (int i = 0; i < N; i++) {
        if (i != N - 1)
            cout << numbers[i] << " ";
        else
            cout << numbers[i] << endl;
    }

    return 0;
}
