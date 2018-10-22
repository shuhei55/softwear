#include <stdio.h>

double get_average(int numbers[], int N);
double get_variance(int numbers[], int N);

int main()
{
    int hoge[7] = {0, 1, 2, 3, 4, 5, 6};
    printf("%f\n", get_variance(hoge, 7));
}

double get_average(int numbers[], int N)
{
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += numbers[i];
    }
    return sum / N;
}

double get_variance(int numbers[], int N)
{
    double dispersion = 0;
    double average = get_average(numbers, N);
    for (int i = 0; i < N; i++) {
        dispersion += (numbers[i] - average) * (numbers[i] - average);
    }
    return dispersion / N;
}
