#include <stdio.h>

int get_average(int numbers[2][3], int N);

int main()
{
    int hoge[2][3] = {{0, 1, 2}, {3, 4, 5}};
    printf("%i\n", get_average(hoge, 2));
}

int get_average(int numbers[2][3], int N)
{
    int sum = 0;
    int w = sizeof(numbers) / (sizeof(int) * N);
    for (int i = 0; i < w; i++) {
        sum += numbers[0][i];
    }
    return sum;
}
