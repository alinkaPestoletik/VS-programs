#include <stdio.h>
int main() {
  char s[102];
  scanf("%s", s);
  int len = 0;
  for( ; s[len] != '\0'; len++); 
  for(int i = len - 1; i >= 0; i--)
  printf("%c", s[i]);
  return 0;
}