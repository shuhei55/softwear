#include <stdio.h>

int main()
{
    char a[3][10] = {"alpha", "beta", "gamma"};
    printf("%c\n", *(a[1]));
    return 0;
}

//"beta"の'b'が出力される
//a[3][10]はchar型の一文字がまず10個の配列となりそれが三個の配列となっている
//a[1]は三個の配列のうちの２つめ先頭の文字のポインタをさしており、*(a[1])はa[1][0]と同義である
//よって'b'が出力される
