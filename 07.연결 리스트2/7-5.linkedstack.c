//연결 리스트로 구현한 스택

#include <stdio.h>
#include <malloc.h>

typedef int element ;
typedef struct StackNode {              //노드 구조체 정의
    element data ;
    struct StackNode *link ;
} StackNode ;

typedef struct {                        //연결된 스택 정의
    StackNode *top ;
} LinkedStackType ;

//스택 초기화 함수
void init(LinkedStackType *s) {
    s->top = NULL ;
}

//공백 상태 검출 함수
int is_empty(LinkedStackType *s){
    return (s->top == NULL) ;
}

//포화 상태 검출 함수
int is_fully(LinkedStackType *s) {
    return 0;
}

//삽입 함수
void push(LinkedStackType *s, element item) {
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode)) ;
    temp->data = item ;

    temp->link = s->top;
    s->top = temp;
}

//스택출력
void print_stack (LinkedStackType *s) {
    for (StackNode *p = s->top ; p != NULL ; p=p->link) 
        printf("%d ->",p->data) ;
    printf("NULL\n");
}

//삭제 함수
element pop (LinkedStackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1) ;
    }
    else {
        StackNode *temp = s->top ;      //top 값을 temp에 복사
        int data = temp->data ;
        s->top = s->top->link ;
        free(temp) ;
        return data ;                   //temp에 있는 data를 pop
    }
}

//피크 함수
element peek (LinkedStackType *s) {
    if(is_empty(s)) {
        fprintf(stderr,"스택이 비어있음\n") ;
        exit(1) ;
    }
    else {
        return s->top->data ;
    }
}

//주 함수
int main (void) {
    LinkedStackType s;
    init(&s) ;
    push(&s, 1) ; print_stack(&s) ;
    push(&s, 2) ; print_stack(&s) ;
    push(&s, 3) ; print_stack(&s) ;
    pop(&s) ; print_stack(&s) ;
    pop(&s) ; print_stack(&s) ;
    pop(&s) ; print_stack(&s) ;
    return 0;
}

/*
출력 결과
1 ->NULL
2 ->1 ->NULL
3 ->2 ->1 ->NULL
2 ->1 ->NULL
1 ->NULL
NULL
*/