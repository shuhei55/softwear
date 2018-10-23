#include <stdio.h>
#include <string.h>

int ctoi(const char c);

const int L = 3;

int main()
{
    char DATA[] = "123456789";

    int max = 1;
    for (int i = 0; i < strlen(DATA) - L + 1; i++) {
        int pro = 1;
        for (int j = 0; j < L; j++) {
            pro *= ctoi(DATA[i + j]);
        }
        if (max < pro) {
            max = pro;
        }
    }
    printf("%d\n", max);
}

int ctoi(const char c)
{
    switch (c) {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    default:
        return -1;
    }
}
