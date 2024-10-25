#include <stdio.h>

int main(void) {
  int sum, sub, mult, div, x, y;
  scanf("%d %d", &x, &y);
  sum = x+y;
  sub = x-y;
  mult = x*y;
  div = x/y;
  printf("%d %d %d %d",sum, sub, mult, div);
  return 0;
}