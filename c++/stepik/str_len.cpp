#include <iostream>

int strlen(char *str)
{
    unsigned int i = 0;
    unsigned int res = 0;
    while (str[i] != '\0') {
        res++;
        i++;
    }

    return res;
}

void strcat(char* to, char* from)
{
    int len1 = strlen(to);
    int len2 = strlen(from);
    for (int i = 0; i < len2+1; i++)
    {
        to[len1] = from[i];
        len1++;
    }
}