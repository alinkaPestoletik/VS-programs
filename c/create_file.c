#include <stdio.h>
#include <stdlib.h>
int main() {
  char s[10001]; 
  scanf("%[^\n]", s);
  FILE *f = fopen("file.txt", "w");
  if (f == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  fprintf(f, "%s\n", s);
  fclose(f);
}
