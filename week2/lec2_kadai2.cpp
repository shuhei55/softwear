#include <stdio.h>

int get_average(int numbers[], int N);

int main()
{
    int hoge[7] = {0, 1, 2, 3, 4, 5, 6};
    printf("%i\n", get_average(hoge, 7));
}

int get_average(int numbers[], int N)
{
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += numbers[i];
    }
    return sum / N;
}
