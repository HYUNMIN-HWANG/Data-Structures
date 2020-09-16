//특정한 값을 탐색하는 함수

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

// 노드값 탐색 알고리즘
ListNode * search_list (ListNode *head, element x) {
    ListNode *p = head ;

    while ( p != NULL) {
        if (p->data == x ) return p ;
        p = p->link ;
    }
    return NULL ;
}

//테스트 프로그램
int main(void) {
    ListNode *head = NULL ;

    head = insert_first(head, 10) ;
    print_list(head) ;
    head = insert_first(head, 20) ;
    print_list(head) ;  
    head = insert_first(head, 30) ;
    print_list(head) ;

    if (search_list(head, 30) != NULL)
        printf("리스트에서 30을 찾았습니다. \n") ;
    else
        printf("리스트에서 30을 찾지 못했습니다. \n");
    return 0 ;
}

/*
결과
10 -> NULL 
20 -> 10 -> NULL 
30 -> 20 -> 10 -> NULL 
리스트에서 30을 찾았습니다. 
*/