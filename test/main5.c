#include <stdio.h>

// func1: 自然数Nを2進法に変換して表示する関数
void func1(int N)
{
    while (1) {
        printf("%d", (N % 2));
        N /= 2;
        if (N == 0) {
            break;
        }
    }
    printf("\n");
}

/* ここから下を編集しないこと */
#define INPUT_NUM 5
int inputs[INPUT_NUM] = {15, 128, 9105, 516219, 368274};

int main(void)
{
    int i;
    for (i = 0; i < INPUT_NUM; i++) {
        /* func1の中で答えの表示を行うこと */
        func1(inputs[i]);
    }
    return 0;
}
