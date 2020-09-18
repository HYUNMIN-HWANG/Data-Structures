//원형 리스트를 활용한 멀티 플레이어 게임

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100] ;
typedef struct ListNode {
    element data ;
    struct ListNode *link ;
} ListNode ;

ListNode *insert_first (ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode)) ;
    strcpy(node->data , data) ;

    if (head == NULL) {
        head = node ;
        node->link = head ;
    }
    else {
        node->link = head->link ;
        head->link = node ;
    }
    return head ;
}

int main (void) {
    ListNode *head = NULL ;

    head = insert_first(head, "Kim") ;
    head = insert_first(head, "Park") ;
    head = insert_first(head, "Choi") ;

    ListNode *p = head ;
    for (int i = 0 ; i < 10 ; i++) {
        printf("현재 차례 = %s \n", p->data) ;
        p = p->link ;
    }
    return 0;
}

/*
결과
현재 차례 = Kim 
현재 차례 = Choi 
현재 차례 = Park 
현재 차례 = Kim 
현재 차례 = Choi 
현재 차례 = Park 
현재 차례 = Kim 
현재 차례 = Choi 
현재 차례 = Park 
현재 차례 = Kim 
*/