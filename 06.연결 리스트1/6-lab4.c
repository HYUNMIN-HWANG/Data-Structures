//리스트를 역순으로 만드는 연산

#include <stdio.h>
#include <stdlib.h>

typedef int element ;
typedef struct ListNode {                   //노드 타입
    element data ;
    struct ListNode *link ;
} ListNode;

//오류 처리 함수
void error (char *message) {
    fprintf(stderr, "%s\n", message) ;
    exit(1) ;
}

// 리스트 첫 부분에 새로운 노드 추가
ListNode * insert_first (ListNode *head, int value) {
    ListNode *p = (ListNode *) malloc (sizeof(ListNode)) ;
    p->data = value ; 
    p->link = head ;        //헤드 포인터의 값을 복사
    head = p ;              //헤드 포인터를 새로운 노드 포인터로 변경
    return head ;           //변경된 헤드 포인터 변환
} 

// 리스트 방문 알고리즘 (노드의 데이터를 화면에 출력)
void print_list (ListNode *head) {
    for (ListNode *p = head ; p != NULL ; p=p->link)
        printf("%d -> ", p->data) ;
    printf("NULL \n") ;
}

//역순 알고리즘
ListNode * reverse (ListNode *head) {
    ListNode *p, *q, *r ;

    p = head ;
    q = NULL ;
    while ( p != NULL) {
        r = q ;
        q = p ;
        p = p->link ;           //q : 현재 역순으로 만들 노드
        q->link = r ; 
    }
    return q ;
}

//테스트 프로그램
int main(void) {
    ListNode *head1 = NULL ;
    ListNode *head2 = NULL ;

    head1 = insert_first (head1, 10) ;
    head1 = insert_first (head1, 20) ;
    head1 = insert_first (head1, 30) ;
    print_list(head1) ;

    head2 = reverse(head1) ;
    print_list(head2) ;
    
    return 0 ;
}

/*
출력 결과

*/