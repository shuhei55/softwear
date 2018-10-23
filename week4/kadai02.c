#include <stdio.h>

#include <stdlib.h>

int main()

{

  int *p;

  p = (int *) malloc(sizeof(int) * 1);

  *p = 100;

  printf("*p = %d\n", *p); //pのポインタの中身(保存されている値)

  printf("p = %p\n", p); //pのポインタ(住所名)

  printf("&p = %p\n", &p); //ポインタのポインタ

  free(p);

  return 0;

}
