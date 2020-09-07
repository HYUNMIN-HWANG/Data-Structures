//구조체 만들고 사용하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // strcpy 함수가 선언된 헤더 파일

struct studentTag //struct 이름 만들기
{
    char name[10] ;
    int age;
    double gpa;
} ;

int main ()
{
    struct studentTag p1; // struct 변수 선언

    strcpy(p1.name, "홍길동") ;
    p1.age = 23 ;
    p1.gpa = 4.3 ;

    printf("이름 : %s\n", p1.name) ;
    printf("나이 : %d\n",p1.age) ;
    printf("학점 : %f\n",p1.gpa) ;

    return 0 ;
}
