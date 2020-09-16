//단어들을 저장하는 연결 리스트

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100] ;
} element ;
 
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
        printf("%s -> ", p->data.name) ;
    printf("NULL \n") ;
}

//테스트 프로그램
int main(void) {
    ListNode *head = NULL ;
    element data ;

    strcpy (data.name, "APPLLE") ;
    head = insert_first (head, data) ;
    print_list(head) ;

    strcpy (data.name, "KIWI") ;
    head = insert_first (head, data) ;
    print_list(head) ;  

    strcpy (data.name, "BANANA") ;
    head = insert_first (head, data) ;
    print_list(head) ; 

    return 0;
}

/*
결과
APLLE -> NULL 
KIWI -> APLLE -> NULL 
BANANA -> KIWI -> APLLE -> NULL
*/