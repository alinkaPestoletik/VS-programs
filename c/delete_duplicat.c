#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char newStr[100];
    int shift;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the shift amount: ");
    scanf("%d", &shift);

    for (int i = 0; i < shift; i++) {
        *(newStr + i) = ' ';
    }

    for (int i = shift; i < strlen(str) + shift; i++) {
        *(newStr + i) = *(str + i-shift);
    }
    *(newStr + strlen(str) + shift) = '\0';
    printf("%s", newStr);
}




