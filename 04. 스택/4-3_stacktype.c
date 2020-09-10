//여러 개의 스택을 동시에 사용하기 위해 
//top과 stack을 하나의 구조체로 결합시키고 이 구조체의 포인터를 함수로 전달한다.

#include <stdio.h>
#include <stdlib.h>

//차후에 스택이 필요하면 여기만 복사하여 붙인다.
// =========스택 코드의 시작 ==========

#define MAX_STACK_SIZE 100

typedef int element ;                   //스택을 구조체로 정의
typedef struct {
    element data [MAX_STACK_SIZE] ;
    int top ;
} StackTpe ;

void init_stack (StackTpe *s) {         //스택 초기화 함수
    s -> top = -1 ;
}

int is_empty (StackTpe *s) {            //공백 상태 검출 함수
    return (s -> top == -1) ;
}

int is_fully (StackTpe *s) {            //포화 상태 검출 함수
    return (s -> top == (MAX_STACK_SIZE -1)) ;
}

void push (StackTpe *s, element item) { //삽입 함수
    if (is_fully(s)) {
        fprintf(stderr, "스택 포화 에러\n") ;
        return ;
    }
    else s->data[++(s->top)] = item ;
}

element pop (StackTpe *s) {             //삭제 함수
    if(is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n") ;
        exit(1) ;
    }
    else return s->data[(s->top)--] ;
}

element peek (StackTpe *s) {            //피크 함수
    if(is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n") ;
        exit(1) ;
    }
    else return s->data[(s->top)] ;
}

// =========스택 코드의 끝 ==========

int main (void) {
    StackTpe s;

    init_stack(&s) ;                //초기화
    push(&s, 1) ;                   //스택에 값 저장
    push(&s, 2) ;
    push(&s, 3) ;
    printf("%d\n", pop(&s)) ;       //스택에서 값 호출
    printf("%d\n", pop(&s)) ;
    printf("%d\n", pop(&s)) ;
}

// 결과 :  3 2 1