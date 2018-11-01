#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp;
    if ((fp = fopen("hoge.data", "r")) == NULL) {
        perror("ファイルが開けません");
        return EXIT_FAILURE;
    }

    int c;

    c = fgetc(fp);
    printf("%c\n", c);
    c = fgetc(fp);
    c = fgetc(fp);
    printf("%c\n", c);
    c = fgetc(fp);
    c = fgetc(fp);
    printf("%c\n", c);
    c = fgetc(fp);
    c = fgetc(fp);
    printf("%c\n", c);

    fclose(fp);
    return EXIT_SUCCESS;
}
