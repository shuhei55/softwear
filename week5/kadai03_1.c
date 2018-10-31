#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAT_X 10
#define MAT_Y 10

void matprint();
void fmatprint();

char matrix[MAT_Y][MAT_X];

int main()
{
    FILE* fp;
    /* File Open */

    if ((fp = fopen("data.txt", "a+")) == NULL) {
        perror("ファイルが開けません");
        return EXIT_FAILURE;
    }

    time_t t = time(NULL);
    fprintf(fp, "%s log \n", ctime(&t));
    fprintf(fp, "---------------------------------------------------------");
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
        if (input_x == -1) {
            break;
        }
        matrix[input_y][input_x] = hoge;
        system("clear");
        matprint();
        fmatprint(fp);
    }

    /* File Close */
    fclose(fp);
    return EXIT_SUCCESS;
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

void fmatprint(FILE* fp)
{
    for (int j = 0; j < MAT_X; j++) {
        for (int k = 0; k < MAT_Y; k++) {
            fprintf(fp, "%c ", matrix[j][k]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "------------------------------------------------\n");
}
