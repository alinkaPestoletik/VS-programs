#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char s1[100] = "Hello";
    cout << strlen(s1) << endl;

    char s2[] = ", world!";
    strcat(s1, s2);

    char s3[6] = {72, 101, 108, 108, 111};
    if (strcmp(s1, s3) == 0) {
        cout << "s1 == s3" << endl;
    }
}
