#include <stdio.h>

// func3: S(N, m)を最大にするようなmを返す関数
// func3は返り値がintであることに注意せよ。
int func3(int N)
{
    int max = 0;
    int ans = 2;
    int M = N;
    for (int i = 2; i <= 10; i++) {
        int sum = 0;
        N = M;
        while (1) {
            sum += (N % i);
            N = (N - (N % i)) / i;
            if (N == 0) {
                break;
            }
        }
        if (max < sum) {
            max = sum;
            ans = i;
        }
    }
    return ans;
}

/* ここから下を編集しないこと */
#define INPUT_NUM 3
int inputs[INPUT_NUM] = {35, 732043, 991326};

int main(void)
{
    int i;
    for (i = 0; i < INPUT_NUM; i++) {
        /* func3はS(N, m)を最大にするようなmを返すこと。 */
        printf("%d\n", func3(inputs[i]));
    }
    return 0;
}
