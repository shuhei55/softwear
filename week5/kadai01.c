#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAT_X 40
#define MAT_Y 40

void matprint();

char matrix[MAT_Y][MAT_X] = {' '};

int main()
{
    for (int i = 0; i < MAT_Y; i++) {
        matprint();
        matrix[i][i] = '*';
        sleep(1);
        system("clear");
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
