//스택을 활용한 괄호 검사 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//차후에 스택이 필요하면 여기만 복사하여 붙인다.
// =========스택 코드의 시작 ==========

#define MAX_STACK_SIZE 100

typedef char element ;                   //스택을 구조체로 정의
typedef struct {
    element data [MAX_STACK_SIZE] ;
    int top ;
} StackType ;

void init_stack (StackType *s) {         //스택 초기화 함수
    s -> top = -1 ;
}

int is_empty (StackType *s) {            //공백 상태 검출 함수
    return (s -> top == -1) ;
}

int is_fully (StackType *s) {            //포화 상태 검출 함수
    return (s -> top == (MAX_STACK_SIZE -1)) ;
}

void push (StackType *s, element item) { //삽입 함수
    if (is_fully(s)) {
        fprintf(stderr, "스택 포화 에러\n") ;
        return ;
    }
    else s->data[++(s->top)] = item ;
}

element pop (StackType *s) {             //삭제 함수
    if(is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n") ;
        exit(1) ;
    }
    else return s->data[(s->top)--] ;
}

element peek (StackType *s) {            //피크 함수
    if(is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n") ;
        exit(1) ;
    }
    else return s->data[(s->top)] ;
}

// =========스택 코드의 끝 ==========

int check_matching (const char *in) {
    StackType s ;
    char ch, open_ch ;               //open_ch :  여는 괄호
    int i , n=strlen(in) ;           //n = 문자열의 길이
    init_stack(&s) ;                 //스택의 초기화

    for ( i = 0 ; i < n ; i++) {
        ch = in[i];                 //ch변수에 다음 문자를 하나씩 저장
        //printf("%c\n",in[i]) ;

        switch (ch) {
        case '(': case '{' : case '[' : //괄호가 나타나면 스택에 하나씩 저장
            push(&s, ch) ;
            break ;
        case ')': case '}' : case ']' :
            if (is_empty(&s)) return 1 ; //스택이 비어있으면 오류
            else {
                open_ch = pop(&s) ;
                if((open_ch == '(' && ch != ')') || //스택에서 나온 데이터와 ch 데이터가 같은지 비교, 다르면 오류 
                (open_ch == '{' && ch != '}') ||
                (open_ch == '[' && ch != ']')) {
                    return 1 ;
                }
                break ;
            }
        }
    }
    if(!is_empty(&s)) return 1;     //스택에 데이터가 남아있으면 오류
    return 0 ;
}

int main (void) {
    char *p = "{A[(i+1)]=0;}" ;
    if (check_matching(p) == 0) 
        printf("%s 괄호검사성공\n", p) ;
    else
        printf("%s 괄호검사실패\n", p) ;
    return 0;   
}

