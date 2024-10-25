#include <stdio.h>
int factorial(int n);
int strong(int n);
int main() {
  int start, end;
  printf("Enter the start of the range: ");
  scanf("%d", &start);
  printf("Enter the end of the range: ");
  scanf("%d", &end);
  printf("Strong numbers between %d and %d are:\n", start, end);
  for (int i = start; i <= end; ++i) {
    if (strong(i) == 1) {
      printf("%d\n", i);  
    }
  }
  return 0;
}

int factorial(int n) {
  int result = 1;
  for (int i = n; i > 1; --i) {
    result *= i;
  }
  return result;
}

int strong(int n) {
  int sum = 0;
  int remainingDigits = n;
  while (remainingDigits > 0) {
    sum += factorial(remainingDigits % 10);
    remainingDigits /= 10;
  }
  return (sum == n) ? 1 : 0;
}