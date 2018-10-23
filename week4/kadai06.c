#include <stdio.h>

int strlen1(char* s);

int main(int argc, char** argv)
{
    if (argc == 1) {
        printf("Usage : ./a.out [string] ...\n");
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        printf("%d\n", strlen1(argv[i]));
    }
    return 0;
}

int strlen1(char* s)
{
    int num = 0;
    while (1) {
        if (*(s + num) == '\0') {
            break;
        }
        num++;
    }
    return num;
}
