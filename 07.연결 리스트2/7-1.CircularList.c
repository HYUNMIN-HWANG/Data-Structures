#include <stdio.h>
#include <stdlib.h>

typedef int element ;
typedef struct ListNode {               //노드 타입
    element data ;
    struct ListNode *link ;
} ListNode ;


//헤드 포인터 head가 마지막 노드를 가리킨다.
//리스트의 항목 출력
void print_list (ListNode* head) {
    ListNode *p ;

    if (head == NULL) return ;
    p = head->link ;
    do {
        printf("%d -> ", p->data) ;
        p = p->link ;
    } while (p != head) ;               //원형 연결 리스트이기 때문에 다시 head로 돌아올 때 리스트 끝에 도달한 것
    printf("%d -> ", p->data) ;         //마지막 노드 출력
}   

//원형 리스트 처음에 새로운 노드 삽입
ListNode* insert_first(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode)) ;
    node->data = data ;
    if(head == NULL) {
        head = node ;
        node->link = head ;
    }
    else {
        node->link = head->link ;       // (1) 새로운 노드는 head가 가리키고 있었던 첫번째 노드를 가리킴 
        head->link = node ;             // (2) head가 새로운 노드를 가리킴
    }
    return head ;
}

//원형 리스트 끝에 새로운 노드 삽입
ListNode* insert_last(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode)) ;
    node->data = data ;
    if(head == NULL) {
        head = node ;
        node->link = head ;
    }  
    else {
        node->link = head->link ;       // (1) 새로운 노드는 head가 가리키고 있었던 첫번째 노드를 가리킴 
        head->link = node ;             // (2) head가 새로운 노드를 가리킴    
        head = node ;                   // (3) head의 위치를 node로 변경함 > 새로운 노드가 마지막 노드가 된다.
    }
    return head ;
}

//원형 연결 리스트 테스트 프로그램
int main (void) {
    ListNode *head = NULL ;

    head = insert_last(head, 20) ;
    head = insert_last(head, 30) ;    
    head = insert_last(head, 40) ;
    head = insert_first(head, 10) ;
    print_list(head) ;
    return 0 ;    
}

//결과 : 10 -> 20 -> 30 -> 40 -> 