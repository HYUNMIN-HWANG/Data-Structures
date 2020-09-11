//중위 표기 수식을 후위 표기 수식으로 변환하는 알고리즘

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

// =========스택 코드의 시작 ==========

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

int prec(char op) {                 //연산자의 우선순위를 반환한다.
    switch (op)
    {
    case '(' : case ')' : return 0 ;
    case '+' : case '-' : return 1 ;
    case '*' : case '/' : return 2 ;
    }
    return -1 ;
}

void infix_to_postfix (char exp[]) {  //중위 표기 수식을 후위 표기 수식으로 바꾼다.
    int i = 0 ;
    char ch, top_op ;
    int len = strlen(exp) ;
    StackTpe s;

    init_stack(&s) ;                  //스택 초기화

    for ( i=0 ; i < len ; i++ ) {
        ch = exp[i] ;
        switch (ch) {
        case '+': case '-' : case '*' : case '/' : //연산자인 경우
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))   
                printf("%c",pop(&s)) ; //스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
            push(&s,ch) ;
            break ;
        case '(' :                     //왼쪽 괄호는 무조건 스택에 저장
            push(&s, ch) ;
            break ;
        case ')' :
            top_op = pop(&s) ; 
            while (top_op != '(') {
                printf("%c", top_op) ;
                top_op = pop(&s) ;
            }
            break ;
        default :                    //피연산자 무조건 출력
            printf("%c",ch) ;
            break ;
        }
    }
    while (!is_empty(&s))           //스택에 저장된 연산자들 출력
        printf("%c", pop(&s)) ;
}      

int main (void) {
    char *s = "(2+3)*4+9" ;
    printf("중위표시수식 %s \n", s) ;
    printf("후위표시수식 ") ;
    infix_to_postfix(s);
    printf("\n") ;
    return 0 ;
}