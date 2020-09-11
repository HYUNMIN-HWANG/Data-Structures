//후위 표기식 계산

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element ;                   //스택을 구조체로 정의
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

int eval (char exp[]) {                 //후위 표기 수식 계산 함수
    int op1, op2, value, i = 0 ;
    int len = strlen(exp) ;
    char ch ;
    StackTpe s ;

    init_stack(&s) ;
    for (i=0 ; i <len ; i++) {
        ch = exp[i] ;
        if ( ch != '+' && ch != '-' && ch != '*' && ch != '/') {    //입력이 피연산자라면
            value = ch - '0' ;
            push(&s,value) ;
        }
        else {                           //입력이 연산자라면 피연산자를 스택에서 제거해야 함
            op2 = pop(&s) ;
            op1 = pop(&s) ;
            switch (ch) {               //연산을 수행하고 연산 값을 스택에 저장
            case '+': push(&s, op1 + op2) ; break;
            case '-': push(&s, op1 - op2) ; break;
            case '*': push(&s, op1 * op2) ; break;
            case '/': push(&s, op1 / op2) ; break;
            }
        }
    }
    return pop(&s) ;
}

int main (void) {
    int result ; 
    printf("후위 표기식은 82/3-32*+\n") ;
    result = eval("82/3-32*+") ;
    printf("결과값은 %d\n",result) ;
    return 0;
}