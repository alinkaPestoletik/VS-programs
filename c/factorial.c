#include <stdio.h>

int factorial (int n) {
  if (n == 0) {
    return 1;
  }
  return factorial(n - 1) * n;
}

int main() {
  printf("%d\n", factorial(4));
  return 0;
}

