#include <stdio.h>
#include <string.h>


typedef struct line {
    int a;
    int b;
} line;

int ctoi(char c)
{
    return (int)c - (int)'a';
}

char itoc(int c)
{
    return (char)((int)'a' + c);
}

int check_afin(char* before, char* after, line l)
{
    for (int k = 0; k < strlen(before); k++) {
        if ((ctoi(before[k]) * l.a + l.b) % 26 != ctoi(after[k])) {
            return 0;
        }
    }
    return 1;
}

line seachkey(char* before, char* after)
{
    for (int i = 1; i < 26; i += 2) {
        for (int j = 0; j < 26; j++) {
            line l = {i, j};
            if (check_afin(before, after, l)) {
                return l;
            }
        }
    }
    line l = {-1, -1};
    return l;
}

char* afinto(line l, char* c)
{
    if (l.a == -1) {
        return c;
    }
    for (int i = 0; i < strlen(c); i++) {
        for (int n = 0; n < 25; n++) {
            if ((ctoi(c[i]) + 26 * n - l.b) % l.a == 0 && (ctoi(c[i]) + 26 * n - l.b) / l.a >= 0 && (ctoi(c[i]) + 26 * n - l.b) % l.a <= 25) {
                c[i] = itoc((ctoi(c[i]) + 26 * n - l.b) / l.a);
                break;
            }
        }
    }
    return c;
}


int main()
{
    char himitu1[] = "dybxsyz";
    char himitu2[] = "duuz";
    char himitu3_0[] = "okfbgpbx";
    char himitu3_1[] = "hflxv";

    /*afinto(seachkey("google", "txxtcf"), himitu1);
    printf("%s\n", himitu1);
    afinto(seachkey("learning", "juehrkrc"), himitu2);
    printf("%s\n", himitu2);
    afinto(seachkey("perfect", "oxkixbg"), himitu3_0);
    printf("%s\n", himitu3_0);
    afinto(seachkey("perfect", "oxkixbg"), himitu3_1);
    printf("%s\n", himitu3_1);*/

    char hoge[] = "hsodahio";
    while (1) {
        scanf("%s", hoge);
        afinto(seachkey("quirky", "wiyzeu"), hoge);
        printf("%s\n", hoge);
    }
}
