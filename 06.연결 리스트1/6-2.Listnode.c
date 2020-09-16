//단순 연결 리스트 연산 구현

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

//노드 pre 뒤에 새로운 노드 삽입
ListNode * insert (ListNode *head, ListNode *pre, element value) {
    ListNode *p = (ListNode *) malloc (sizeof(ListNode)) ;
    p->data = value ;
    p->link = pre->link ;   //pre 포인터의 값을 복사
    pre->link = p ;         //pre 포인터를 새로운 노드 포인터로 변경
    return head ;           //헤드 포인터 변환
}

// 리스트 첫 노드를 삭제
ListNode * delete_first (ListNode *head) {
    ListNode *removed ;
    if ( head == NULL ) return NULL ;
    removed = head ;        //헤드 포인터의 값을 복사
    head = removed->link ;  //헤드 포인터를 제거된 노드 다음 노드 포인터로 변경
    free (removed) ;        //노드 삭제
    return head ;           //변경된 헤드 포인터 변환
}

//pre가 가리키는 노드의 다음 노드를 삭제한다.
ListNode * delete (ListNode *head, ListNode *pre) {
    ListNode *removed ;
    removed = pre->link ;       //pre 포인터의 값을 복사
    pre->link = removed->link ; //pre 포인터를 제거된 노드 다음 노드 포인터로 변경
    free(removed) ;             //노드 삭제
    return head ;               //헤드 포인터 변환
}

// 리스트 방문 알고리즘 (노드의 데이터를 화면에 출력)
void print_list (ListNode *head) {
    for (ListNode *p = head ; p != NULL ; p=p->link)
        printf("%d -> ", p->data) ;
    printf("NULL \n") ;
}

//테스트 프로그램
int main(void) {
    ListNode *head = NULL ;

    for (int i=0 ; i <5 ; i++) {
        head = insert_first(head, i) ;
        print_list(head) ;
    }

    for (int i=0 ; i < 5 ; i++) {
        head = delete_first(head) ;
        print_list(head) ;
    }
    return 0 ;
}

/*
출력 결과
0 -> NULL 
1 -> 0 -> NULL 
2 -> 1 -> 0 -> NULL 
3 -> 2 -> 1 -> 0 -> NULL 
4 -> 3 -> 2 -> 1 -> 0 -> NULL 
3 -> 2 -> 1 -> 0 -> NULL 
2 -> 1 -> 0 -> NULL 
1 -> 0 -> NULL 
0 -> NULL 
NULL 
*/