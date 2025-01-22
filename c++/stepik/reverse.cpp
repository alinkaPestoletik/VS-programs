#include <iostream>
using namespace std;

int foo() {
   int num;
    cin >> num;
    if (num == 0) {
       return 0;
    } else {
    foo();
    cout << num << " ";
    return 0;
    }
}

int main()
{
    foo();
	return 0;
}