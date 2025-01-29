// author Alina Pestova
// I used selection sort algorithm from the first lab

#include <iostream>
using namespace std;

void selectionSort(int N, int K, string players[], int scores[]) {
    for (int i = 0; i < K; i++) {
        int score = scores[i];
        int idx = i;
        int j = i + 1;
        while (j < N) {
            if (score < scores[j]) {
                score = scores[j];
                idx = j;
            }
            j++;
        }

        if (idx != i) {
            swap(scores[idx], scores[i]);
            swap(players[idx], players[i]);
        }

        cout << players[i] << " " << scores[i] << endl;
    }
}

int main()
{
    int N, K;
    cin >> N;
    cin >> K;

    string players[N];
    int scores[N];
    for (int i = 0; i < N; i++) {
        cin >> players[i] >> scores[i];
    }

    if (K > N) {
        K = N;
    }

    selectionSort(N, K, players, scores);
    return 0;
}