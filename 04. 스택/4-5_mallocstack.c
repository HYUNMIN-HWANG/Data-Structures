//동적 메모리 할당을 이용하는 스택

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 


typedef int element ;                   //스택을 구조체로 정의
typedef struct {
    element *data ;                     //data은 포인터로 정의된다.
    int capacity ;
    int top ;
} StackTpe ;

void init_stack (StackTpe *s) {         //스택 생성 함수
    s -> top = -1 ;
    s -> capacity = 1 ;
    s -> data(element *)malloc(s->capacity * sizeof(element)); 
}

int is_empty (StackTpe *s) {            //공백 상태 검출 함수
    return (s -> top == -1) ;
}

int is_fully (StackTpe *s) {            //포화 상태 검출 함수
    return (s -> top == (MAX_STACK_SIZE -1)) ;
}

void push (StackTpe *s, element item) { //삽입 함수
    if (is_fully(s)) {
        s-> capacity *= 2 ;
        s -> data = (element *)realloc(s->data, s->capacity * sizeof(element)) ;
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

int main (void) {
    StackTpe s;

    init_stack(&s) ;                //초기화
    push(&s, 1) ;                   //스택에 값 저장
    push(&s, 2) ;
    push(&s, 3) ;
    printf("%d\n", pop(&s)) ;       //스택에서 값 호출
    printf("%d\n", pop(&s)) ;
    printf("%d\n", pop(&s)) ;
    free(s.data) ;
    return 0 ;
}

// 결과 :  3 2 1