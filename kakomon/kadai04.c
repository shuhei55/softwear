#include <stdio.h>

void setvalue(int);

int y;
int z;

int main()
{
    int x;
    x = 10;
    y = 10;
    z = 10;
    printf("(x,y,z) = (%d, %d, %d)\n", x, y, z);
    setvalue(5);
    printf("(x,y,z) = (%d, %d, %d)\n", x, y, z);
    return 0;
}

void setvalue(int val)
{
    int x;
    extern int y;
    int z;
    x = val;
    y = val;
    z = val;
}


//setvalue関数内でのxとyは上で宣言されているxやzとは異なる別の変数でありこの値を変更した所でもとのxやzなどは変化しない
//一方setvalue内でyはexternされているのでグローバルで宣言されているyと同じものを指しているのでこれを変更すれば当然yの値も変わる
//この関数を動かすためにはx,y,zをグローバル変数にして関数内でyのようにexternで宣言してあげる方法でも良いが基本的にグローバル変数など使うことは無く汎用性が低い
//なのでx,y,zを関数の引数として受けとる方法がよい
//しかしただ引数として受け取っても受け渡しのところで新たに関数内に別変数を宣言してしまいそれを書き換えたところで上のプログラムと同じ結果になってしまうので
//x,y,zを参照渡しにして引数にx,y,zのポインタを渡すことで解決できる
//
//以下解決プログラム
/*
void setvalue(int val, int* x, int* y, int* z);


int main()
{
    int x;
    int y;
    int z;
    x = 10;
    y = 10;
    z = 10;
    printf("(x,y,z) = (%d, %d, %d)\n", x, y, z);
    setvalue(5, &x, &y, &z);
    printf("(x,y,z) = (%d, %d, %d)\n", x, y, z);
    return 0;
}

void setvalue(int val, int* x, int* y, int* z)
{
    *x = val;
    *y = val;
    *z = val;
}
*/
