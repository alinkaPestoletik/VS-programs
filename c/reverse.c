#include <stdio.h>
int main() {
  char s[102];
  gets(s);
  int len = 0;
  char *pointer = s;
  while (*(pointer++) != '\0') {
    len++;
  }
  printf("%d", len);
  return 0;
}
