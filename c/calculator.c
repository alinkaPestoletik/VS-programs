#include <stdio.h>
int main () {
    int a, b;
    char operation;
    printf("Write 1 number: \n");
    scanf("%d", &a);
    printf("Write 2 number: \n");
    scanf("%d", &b);
    printf("Write operation: \n");
    scanf(" %c", &operation);

    if (operation == '+') {
        int sum = a+b; 
        printf("Summa: %d", sum);
    }
    else if (operation == '/') {
        int div = a/b; 
        printf("Division: %d", div);
    }
    else if (operation == '-') {
        int sub = a-b; 
        printf("Sub: %d", sub);
    }
    else if (operation == '*') {
        int mult = a*b; 
        printf("Multiplication: %d", mult);
    }
    return 0;
}

