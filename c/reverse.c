
#include <stdio.h>
#include <string.h>

int main() {
    char str[50];
    int l,i;
    printf("Enter your string: ");
    scanf("%s", str);
    l = strlen(str);
    int size=0;
    for (i=l-1; i>=0;  i--) 
        printf("%c", str[i]);
        
    printf("\n");
    for (i=0; i<50; i++) 
    {
        if (str[i]!='\0')
        size++;
        else break;
    }
    for (int i=0; i<l/2; i++) 
    {
        char t=str[i];
        str[i]= str[l-1-i];
        str[l-1-i] = t;
    }
    printf("Reversed string: %s\n", str);
    return 0;
}



