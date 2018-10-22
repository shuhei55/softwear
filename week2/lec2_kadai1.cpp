#include <stdio.h>

int get_max(int numbers[], int N);

int main()
{
    int hoge[7] = {0, 3, 252, 54340, 23, 243, 430};
    printf("%i\n", get_max(hoge, 7));
}

int get_max(int numbers[], int N)
{
    int max = numbers[0];
    for (int i = 0; i < N; i++) {
        max = max < numbers[i] ? numbers[i] : max;
    }
    return max;
}
