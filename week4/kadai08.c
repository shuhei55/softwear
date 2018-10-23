#include <stdio.h>

int strcmp1(char *s, char*t);

int main()
{
    char* s = "hogehoge";
    char* t = "fugafuga";
    printf("%d\n",strcmp1(s,t));
}

int strcmp1(char *s, char*t)
{
    if (*s > *t) {
        return 1;
    } else if (*s < *t) {
        return -1;
    } else {
        return 0;
    }
}
