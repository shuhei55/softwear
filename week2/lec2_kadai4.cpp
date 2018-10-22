#include <stdio.h>
#include <string.h>
int check_kaibun(char str[]);
int main()
{
    char str[] = "hogeeoh";
    if (check_kaibun(str)) {
        printf("%s is palindrome.\n", str);
    } else {
        printf("%s is NOT palindrome.\n", str);
    }
    return 0;
}
int check_kaibun(char str[])
{
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != str[strlen(str) - i - 1]) {
            return 0;
        }
    }
    return 1;
}
