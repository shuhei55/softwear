#include <stdio.h>

const int MAX_NUM = 1000;

int main()
{
    int Pnum[MAX_NUM];
    int i = 0;
    int cnt = 0;
    int check = 1;
    for (; i < MAX_NUM; i++) {
        check = 1;
        if (i == 0) {
            continue;
        }
        if (i == 1) {
            Pnum[cnt] = i + 1;
            cnt++;
            printf("%d\n", i + 1);
            continue;
        }
        for (int j = 0; j < cnt; j++) {
            if ((i + 1) % Pnum[j] == 0) {
                check *= -1;
                break;
            }
        }
        if (check == -1) {
            continue;
        } else {
            Pnum[cnt] = i + 1;
            printf("%d\n", i + 1);
            cnt++;
        }
    }
}
