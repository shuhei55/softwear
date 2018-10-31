#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAT_X 40
#define MAT_Y 40

void matprint();

char matrix[MAT_Y][MAT_X];

int main()
{
    for (int j = 0; j < MAT_X; j++) {
        for (int k = 0; k < MAT_Y; k++) {
            matrix[j][k] = '-';
        }
    }
    matprint();
    while (1) {
        int input_x, input_y;
        char hoge;
        scanf("%d %d %c", &input_x, &input_y, &hoge);
        matrix[input_y][input_x] = hoge;
        system("clear");
        matprint();
    }

    return 0;
}

void matprint()
{
    for (int j = 0; j < MAT_X; j++) {
        for (int k = 0; k < MAT_Y; k++) {
            printf("%c ", matrix[j][k]);
        }
        printf("\n");
    }
}
