#include <stdio.h>

char check(int x)
{
    switch (x) {
    case 10:
        return 'a';
    case 11:
        return 'b';
    case 12:
        return 'c';
    case 13:
        return 'd';
    case 14:
        return 'e';
    case 15:
        return 'f';
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    default:
        return 0;
    }
}

// func2: 自然数Nをn進法に変換して表示する関数
void func2(int N, int n)
{
    while (1) {
        printf("%c", check((N % n)));
        N = (N - (N % n)) / n;
        if (N == 0) {
            break;
        }
    }
    printf("\n");
}

/* ここから下を編集しないこと */
#define INPUT_NUM 7
int inputs[INPUT_NUM] = {91328, 35516, 619820, 317138, 981536, 568102, 1048575};
int bases[INPUT_NUM] = {3, 7, 9, 11, 12, 15, 16};

int main(void)
{
    int i;
    for (i = 0; i < INPUT_NUM; i++) {
        /* func2の中で答えの表示を行うこと */
        func2(inputs[i], bases[i]);
    }
    return 0;
}
