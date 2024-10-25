#include <stdio.h>
#include <string.h>
void bruteForce(char s[]);

int main() {
  int s[4];
  scanf("%[^\n]", s);
  bruteForce(s);
  return 0;
}

void bruteForce(char s[]) {
int len = 0;
char password[4];
for (; s[len] != '\0'; len++);
for (int i = 32; i <= 126; ++i) {
    for (int j = 32; j <= 126; ++j) {
      for (int k = 32; k <= 126; ++k) {
        password[0] = i;
        if(len == 1)
          password[1] = '\0';
        else{
          password[1] = j;
          if(len == 2)
          password[2] = '\0';
          else{
          password[2] = k;
          password[3] = '\0';
          }
        }
        if(strcmp(password, s)==0) {
        printf("%d",((i-31)*(j-31)*(k-31)));
        return;
        }    
      }
    }
  }
}