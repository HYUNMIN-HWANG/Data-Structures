//구조체 배열 스택 프로그램
//스택을 구조체에 넣는다.

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100          //스택의 최대 크기 100
#define MAX_STRING 100              //문자의 최대 길이 100

typedef struct {                    //스택에 저장되는 데이터를 구조체로 정의
    int student_no ;
    char name[MAX_STRING] ;
    char address[MAX_STRING] ;
} element ;

element stack [MAX_STACK_SIZE] ;    //1차원 배열
int top = -1 ;                      //스택이 비워있을 때, top = -1

int is_empty() {                    //공백 상태 검출 함수
    return (top == -1) ;
}

int is_full() {                     //포화 상태 검출 함수
    return (top == (MAX_STACK_SIZE - 1)) ;   
}

void push (element item) {           //삽입 함수
    if (is_full()) {
        fprintf(stderr, "스택 포화 에러\n") ;
        return ;
    }
    else stack[++top] = item ;
}

element pop() {            //삭제 함수
    if (is_empty()) {
        fprintf(stderr, "스택 공백 에러\n") ;
        exit(1) ;
    }
    else return stack[top--] ;
}

element peek() {                    //피크 함수 : 스택에서 삭제하지 않고 보기만 하는 연산
    if (is_empty()) {
        fprintf(stderr, "스택 공백 에러\n") ;
        exit(1) ;
    }
    else return stack[top] ;
}

int main (void) {
    element ie = { 20190101, "홍길동", "Soeul"} ; // 스택에 저장할 데이터
    element oe ;                                  //스택에서 나온 정보를 저장할 구조체

    push(ie) ;
    oe = pop() ;

    printf("학번 : %d\n", oe.student_no) ;
    printf("이름 : %s\n", oe.name) ;
    printf("주소 : %s\n", oe.address) ;

    return 0 ;
}

//결과 -> 학번 : 20190101 이름 : 홍길동 주소 : Soeul