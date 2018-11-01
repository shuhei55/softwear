#include <stdio.h>

double pie(double x0, int N);

int main(int argc, char* argv[])
{
    for (int i = 1; i <= 10; i++) {
        printf("N = %d : %f\n", i, pie(0.1, i));
    }
    printf("N = %d : %f\n", 100, pie(0.1, 100));
    printf("N = %d : %f\n", 1000, pie(0.1, 1000));
}


double pie(double x0, int N)
{
    double x = x0;
    for (int i = 0; i < N; i++) {
        x = x * 2;
        if (x > 1.0) {
            x = 2 - x;
        }
    }
    return x;
}

//結果
/*
N = 1 : 0.200000
N = 2 : 0.400000
N = 3 : 0.800000
N = 4 : 0.400000
N = 5 : 0.800000
N = 6 : 0.400000
N = 7 : 0.800000
N = 8 : 0.400000
N = 9 : 0.800000
N = 10 : 0.400000
N = 100 : 0.000000
N = 1000 : 0.000000
*/
