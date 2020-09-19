//이중연결 노드 타입을 활용한 MP3 PLAYER 만들기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element[100] ;
typedef struct DListNode {
    element data ;
    struct DListNode *llink ;
    struct DListNode *rlink ;
} DListNode ;

DListNode* current ;

//이중연결 노드 초기화
void init(DListNode *phead) {
    phead->rlink = phead ;
    phead->llink = phead ;
}

//이중연결 리스트의 노드를 출력
void print_dlist (DListNode *phead) {

    DListNode *p;
    for(p = phead->rlink ; p != phead ; p = p->rlink ) {
        if (p == current)                                   //현재 재생 중인 곡
            printf(" <-| #%s# |-> ", p->data) ;
        else
            printf(" <-| %s |-> ", p->data) ;
    }
    printf("\n") ;
}

//노드 newnode를 노드 before의 오른쪽에 삽입한다.
void dinsert (DListNode *before, element data) {
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode)) ;
    strcpy(newnode->data, data) ;
    newnode->llink = before ;
    newnode->rlink = before->rlink ;
    before->rlink->llink = newnode ;
    before->rlink = newnode ;
}

//노드 removed를 삭제한다.
void ddelte (DListNode *head, DListNode *removed) {
    if (removed = head) return ;
    removed->llink->rlink = removed->rlink ;
    removed->rlink->llink = removed->llink ;
    free(removed) ;
} 

//테스트 프로그램
int main (void) {
    char ch ;
    DListNode *head = (DListNode *)malloc(sizeof(DListNode)) ;
    init(head) ;

    dinsert(head, "우산-윤하") ;
    dinsert(head, "커다란-민수") ;
    dinsert(head, "있지-자우림") ;

    current = head->rlink ;
    print_dlist(head) ;

    do {
        printf("\n 명령어를 입력하시오 (<, >, q) : ") ;
        ch = getchar() ;

        if (ch == '<') {                    //이전 곡으로 이동
            current = current->llink ;
            if(current == head)             //헤더 노드에 있다면 한 번 더 왼쪽으로 이동한다. 
                current = current->llink ;
        }
        else if (ch == '>') {
            current = current->rlink ;
            if(current == head)             //헤더 노드에 있다면 한 번 더 오른쪽으로 이동한다. 
                current = current->rlink ;
        }
        print_dlist(head) ;
        getchar() ;
    } while(ch != 'q') ;                      // q : 멈춤
    free(head);
    return 0;
}