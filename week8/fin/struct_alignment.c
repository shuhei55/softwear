#include <stdio.h>

struct student {
    int id;
    char name[100];
    int age;
    double height;
    double weight;
};

struct tagged_student1 {
    int id;
    char name[100];
    int age;
    double height;
    double weight;
    char tag;
};

struct tagged_student2 {
    char tag;
    int id;
    char name[100];
    int age;
    double height;
    double weight;
};

int main(int argc, char** argv)
{
    struct student s;
    struct tagged_student1 s1;
    struct tagged_student2 s2;
    /* 各構造体の中身のポインタを表示するプログラムを書く */
    printf("%d\n", sizeof(struct student));  //128byte
    printf("student:\n");
    printf("%p\n", &s.id);                           //4byte
    printf("%p\n", &s.name);                         //100byte
    printf("%p\n", &s.age);                          //8byte  ここがどういうアラインメントが起きているか分からない環境依存？？
    printf("%p\n", &s.height);                       //8byte
    printf("%p\n", &s.weight);                       //8byte
    printf("%d\n", sizeof(struct tagged_student1));  //136byte
    printf("tagged_student1:\n");
    printf("%p\n", &s1.id);                          //4byte
    printf("%p\n", &s1.name);                        //100byte
    printf("%p\n", &s1.age);                         //8byte
    printf("%p\n", &s1.height);                      //8byte
    printf("%p\n", &s1.weight);                      //8byte
    printf("%p\n", &s1.tag);                         //8byte
    printf("%d\n", sizeof(struct tagged_student2));  //128byte
    printf("tagged_student2:\n");
    printf("%p\n", &s2.tag);     //4byte
    printf("%p\n", &s2.id);      //4byte
    printf("%p\n", &s2.name);    //104byte  ここが増えているが4byte毎のアライメントではないので分からないやはり環境依存？？
    printf("%p\n", &s2.height);  //8byte
    printf("%p\n", &s2.weight);  //8byte


    /* printf で %p フォーマットを指定する*/
    return 0;
}
