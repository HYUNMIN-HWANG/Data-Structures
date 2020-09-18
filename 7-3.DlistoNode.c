#include <stdio.h>
#include <stdlib.h>

typedef int element ;
typedef struct DListNode {              //이중연결 노드 타입
    element data;
    struct DListNode *llink ;
    struct DListNode *rlink ;
} DListNode ; 

//이중 연결 리스트를 초기화
void init (DListNode *phead) {
    phead -> llink = phead ;
    phead -> rlink = phead ; 
}

//이중 연결 리스트의 노드를 출력
void print_list (DListNode *phead) {
    DListNode *p ;
    for (p = phead->rlink ; p != phead ; p=p->rlink) { //rlink가 가리키는 값 즉, head에서부터 출력이 시작된다.
        printf("<-||%d||->", p->data) ;
    }
    printf("\n") ;
} 

//새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert (DListNode* before, element data) {
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode)) ;

    newnode->data = data ;
    newnode->llink = before ;
    newnode->rlink = before->rlink ;
    before->rlink->llink = newnode ;
    before->rlink = newnode;
}

//노드 removed를 샂게한다.
void ddelte (DListNode *head, DListNode *removed) {
    if (removed == NULL) return ;
    removed->llink->rlink = removed->rlink ;
    removed->rlink->llink = removed->llink ;
    free (removed) ;
}

//이중 연결 리스트 테스트 프로그램
int main (void) {
    DListNode *head = (DListNode *)malloc(sizeof(DListNode)) ;
    init(head) ;

    printf("추가 단계 \n") ;
    for (int i = 0 ; i < 5 ; i++) {
        dinsert(head,i) ;                   //헤더 노드의 오른쪽에 삽입
        print_list(head) ;
    }

    printf("\n삭제 단계 \n") ;
    for (int i = 0 ; i < 5 ; i++) {
        print_list(head) ;
        ddelte(head, head->rlink) ;
    }

    free(head) ;
    return 0;
}

/*
추가 단계 
<-||0||->
<-||1||-><-||0||->
<-||2||-><-||1||-><-||0||->
<-||3||-><-||2||-><-||1||-><-||0||->
<-||4||-><-||3||-><-||2||-><-||1||-><-||0||->

삭제 단계 
<-||4||-><-||3||-><-||2||-><-||1||-><-||0||->
<-||3||-><-||2||-><-||1||-><-||0||->
<-||2||-><-||1||-><-||0||->
<-||1||-><-||0||->
<-||0||->
*/