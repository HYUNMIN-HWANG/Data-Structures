//트리 레벨 순회 프로그램
//큐를 사용한 순회법

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data ;
    struct TreeNode *left, *right ;
} TreeNode ;

//============원형큐 코드 시작==========
#define MAX_QUEUE_SIZE 100
typedef TreeNode * element ;
typedef struct {                            //큐 구조체 정의
    element data [MAX_QUEUE_SIZE] ;
    int front, rear ;
} QueueType;

//오류 함수 
void error (char *message) {
    fprintf (stderr, "%s\n", message) ;
    exit(1) ;
}

// 큐 초기화
void init_queue (QueueType *q) {
    q->front = q->rear = 0 ;
}

//공백 상태 검출 함수
int is_empty (QueueType *q) {
    return (q->front == q->rear) ;
}

//포화 상태 검출 함수
int is_full (QueueType *q) {
    return ((q->rear+1)  % MAX_QUEUE_SIZE == q->front) ;
}

//삽입 함수
void enqueue (QueueType *q, element item) {
    if (is_full(q)) 
        error("큐가 포화상태입니다.") ;
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE ;     
    q->data[q->rear] = item ;
}

//삭제 함수
element dequeue (QueueType *q) {
    if (is_empty(q)) 
        error ("큐가 공백상태입니다.") ;
    q->front = (q->front+1) % MAX_QUEUE_SIZE ;
    return q->data[q->front] ;
}

//============원형큐 코드 끝==========

void level_order (TreeNode *ptr) {          //root 값이 들어감
    QueueType q ;

    init_queue(&q) ;                        //초기화
    if (ptr == NULL) return ;
    enqueue(&q, ptr) ;
    while (!is_empty(&q)) {                 //큐가 비어있을 때까지
        ptr = dequeue(&q) ;                 //root 값 변경
        printf("[%d] ", ptr->data) ;        //root 값 출력
        if (ptr->left)                      //왼쪽 노드 먼저
            enqueue(&q,ptr->left) ;
        if (ptr->right)                     //오른쪽 노드 나중에 
            enqueue(&q, ptr->right) ;
    } 
}

//     15
//   4    20
// 1    16   25

TreeNode n1 = {1, NULL, NULL} ;
TreeNode n2 = {4, &n1, NULL} ;
TreeNode n3 = {16, NULL, NULL} ;
TreeNode n4 = {25, NULL, NULL} ;
TreeNode n5 = {20, &n3, &n4} ;
TreeNode n6 = {15, &n2, &n5} ;
TreeNode *root = &n6 ;

int main (void) {
    printf("레벨 순회 = ") ;
    level_order(root) ;
    printf("\n") ;
    return 0 ;
}

//결과 : 레벨 순회 = [15] [4] [20] [1] [16] [25] 