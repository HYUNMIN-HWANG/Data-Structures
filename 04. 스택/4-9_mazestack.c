// 스택을 활용한 미로탐색 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 6

// =========스택 코드의 시작 ==========

typedef struct {
    short r ;
    short c ;
} element ;                   //스택을 구조체로 정의

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

element here = {1, 0}, entry = {1, 0} ; 
char maze[MAX_STACK_SIZE][MAX_STACK_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'}
} ;

//위치를 스택에 삽입
void push_loc(StackType *s, int r, int c) {
    if ( r<0 || c<0 ) return ;
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp ;
        tmp.r = r ;
        tmp.c = c;
        push(s , tmp) ;
    }
}

//미로를 화면에 출력한다.
void maze_print(char maze[MAX_STACK_SIZE][MAX_STACK_SIZE]) {
    printf("\n") ;
    for (int r = 0 ; r < MAX_STACK_SIZE ; r++) {
        for (int c = 0 ; c < MAX_STACK_SIZE ; c++) {
            printf("%c",maze[r][c]) ;
        }
        printf("\n") ;
    }
}

int main (void) {
    int r, c ;
    StackType s ;

    init_stack (&s) ;
    here = entry ;
    while (maze[here.r][here.c] != 'x') {
        r = here.r ;
        c = here.c ;
        maze[r][c] = '.';
        maze_print(maze) ;

        push_loc (&s, r - 1, c) ;
        push_loc (&s, r + 1, c) ;
        push_loc (&s, r , c-1 ) ;
        push_loc (&s, r , c+1 ) ;
        
        if (is_empty(&s)) {
            printf("실패\n") ;
            return ;
        }
        else  
            here = pop(&s) ;
    }
    printf("성공\n") ;
    return 0 ;      
}