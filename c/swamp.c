#include <stdio.h>

void swamp(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", a, b);
    swamp(&a, &b);
    printf("%d %d", a, b);
    return 0;
  }