#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strcpy1(char* s, char* t);
int strlen1(char* s);

int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("Usage : ./a.out [string]\n");
        return 1;
    }

    char buf[] = "abcd";

    //buf = (char*)malloc(strlen1(argv[1])+1);

    printf("%s\n", argv[1]);

    strcpy1(buf, argv[1]);
    //
    printf("%c\n",*buf);
    //memcpy(buf,argv[1],strlen1(argv[1]));

    //printf("%s\n", buf);
    return 0;
}

void strcpy1(char* s, char* t)
{
    printf("%c\n",*s);
    s = (char*)malloc((size_t)(strlen1(t)+1));
    printf("%c\n",*s);
    memcpy(s,t,strlen1(t));
    printf("%s\n",s);
}

int strlen1(char* s)
{
    int num = 0;
    while (1) {
        if (*(s + num) == '\0') {
            break;
        }
        num++;
    }
    return num;
}
