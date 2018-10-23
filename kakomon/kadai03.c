#include <stdio.h>
#include <string.h>

void reverse(char* s)
{
    int c;
    char* t;

    for (t = s + strlen(s) - 1; s < t; s++, t--) {
        c = *t;
        *t = *s;
        *s = c;
    }
}

int main()
{
    char str[] = "ashusoh";  //char *str = "hoge";はだめ変更不可能でせぐふぉる
    reverse(str);
    printf("%s\n", str);
}
