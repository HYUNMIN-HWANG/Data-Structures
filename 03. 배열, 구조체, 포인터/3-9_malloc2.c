#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct studentTag {
    char name[10] ;             //문자배열로 된 이름
    int age ;                   //나이를 나타내는 정수값
    double gpa ;                //평균평점을 나타내는 실수값
} student ;

int main (void) {
    student *s ;                //구조체에 포인터 선언

    s = (student *)malloc(sizeof(student)) ;
    if (s == NULL) {            //공간할당에 실패한 경우
        fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다. \n ") ;
        exit(1) ;
    }

    strcpy (s->name, "PARK") ;  //(*s).name = "PARK" //strcpy : 문자열 복사
    s -> age = 20 ;             //(*s).age = 20
    s -> gpa = 4.2 ;            //(*s).gpa = 4.2

    printf("%s, %d, %.3f", (*s).name, (*s).age, (*s).gpa) ;

    free(s) ;
    return 0 ;
}
