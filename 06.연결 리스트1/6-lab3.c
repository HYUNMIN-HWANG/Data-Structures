// 두 개의 리스트를 하나로 합치는 함수

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
ListNode * insert_first (ListNode *head, element value) {
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

// 첫 번째 리스트의 마지막 노드 링크가 두번째 리스트 첫 번째 노드를 가리키도록 변경
ListNode * contact_list (ListNode *head1, ListNode *head2) {
    if (head1 == NULL) return head2 ;
    else if (head2 == NULL) return head1;
    else {
        ListNode *p ;
        p = head1 ;
        while (p->link != NULL) 
            p = p->link ;           //첫 번째 리스트의 맨 끝으로 이동
        p->link = head2 ;           //첫 번째 리스트의 마지막 노드를 두번째 리스트 헤드에 연결
        return head1 ;
    }
}

//테스트 프로그램
int main(void) {
    ListNode *head1 = NULL ;
    ListNode *head2 = NULL ;
    
    head1 = insert_first (head1, 10) ;
    head1 = insert_first (head1, 20) ;
    head1 = insert_first (head1, 30) ;
    printf("첫번째 리스트 : ") ;
    print_list(head1) ;

    head2 = insert_first (head2, 50) ;   
    head2 = insert_first (head2, 60) ;   
    printf("두번째 리스트 : ") ;
    print_list(head2) ;

    ListNode *total = contact_list(head1, head2) ;
    printf("리스트 연결 : ") ;
    print_list(total) ;

    return 0 ;
}

/*
출력 결과
첫번째 리스트 : 30 -> 20 -> 10 -> NULL 
두번째 리스트 : 60 -> 50 -> NULL 
리스트 연결 : 30 -> 20 -> 10 -> 60 -> 50 -> NULL 
*/