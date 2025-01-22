#include <stdio.h>
#include <string.h>

void reverse(char* arr, int arrSize) {
    char buffer[5];
    int bufferIdx = 0;
    for (int i = arrSize - 1; i > -1; i--) {
        buffer[bufferIdx] = *(arr + i);
        bufferIdx++;
    }
    arr = buffer;
    printf("%s", arr);
}


struct string{
    char string[5];
    int x;
} s;

int main() {
    char array[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
    reverse(array, strlen(array));
}




