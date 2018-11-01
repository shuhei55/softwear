#include <ctype.h>   // 文字一文字を受け取り大文字にするtoupper()関数を利用する
#include <stdio.h>   // printf
#include <string.h>  // strlen

#define STR_LEN 20

char* str_toupper(char* src)
{
    char dst[STR_LEN];
    for (int i = 0; i <= (int)strlen(src); ++i) {
        dst[i] = toupper(src[i]);
    }

    return dst;
}

int main(void)
{
    char src[STR_LEN] = "Hello World";
    char* dst = str_toupper(src);
    printf("original: %s, to_upper: %s\n", src, dst);
    return 0;
}


/*
上のソースコードではstr_toupper()関数はスコープが関数内のローカール変数のポインタを返してしまっている。
そのためmain関数内でこの関数を呼び出しポインタを受け取ったところですでに解放されてしまっている変数の中身が保存されていない場所のポインタを受け取ってしまっているから。
またこの行為はプログラムと関係のないポインタにアクセスしてしまうため非常に危険である。
*/
