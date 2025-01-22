#include <iostream>
using namespace std;

int main() {
    int time, hours, minutes, seconds;
	cin >> time;
	hours = time / 3600;
	minutes = (time % 3600) / 60;
	seconds = (time % 3600) % 60;
	cout << hours << ":" << minutes << ":" << seconds;
	return 0;
}
