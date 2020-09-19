//연결 리스트로 구현한 큐

#include <stdio.h>
#include <stdlib.h>

typedef int element ;           //요소의 타입
typedef struct QueueNode {      //큐의 노드의 타입
    element data ;
    struct QueueNode *link ;
} QueueNode ;

typedef struct {                //큐의 rear , front 포인터 정의
    QueueNode * rear ;
    QueueNode * front ;
} LinkQueueType ;

//큐 초기화 함수
void init(LinkQueueType *q) {
    q->front = q->rear = 0 ;
}

//공백 상태 검출 함수
int is_empty(LinkQueueType *q) {
    return (q->front == NULL) ;
}

//포화 상태 검출 함수
int is_fully(LinkQueueType *q) {    //연결 리스트의 경우 메모리 할당과정에서 오류가 있지 않는 한 포화 상태는 없다.
    return 0 ;
}

//삽입 함수
void enqueue (LinkQueueType *q, element data) {
    QueueNode *temp  = (QueueNode *)malloc(sizeof(QueueNode)) ;
    temp->data = data ;
    temp->link = NULL ;
    if (is_empty(q)) {                //큐가 공백이라면
        q->front = temp ;
        q->rear = temp ;
    }
    else {                          //큐가 공백이 아니면
        q->rear->link = temp ;
        q->rear = temp ;
    }
}

//삭제 함수
element dequeue (LinkQueueType *q) {
    QueueNode *temp = q->front ;
    element data ;
    if (is_empty(q)) {
        fprintf(stderr, "스택이 비어있음\n") ;
        exit(1) ;
    }
    else {
        data = temp->data ;
        q->front = q->front->link ; //front를 다음노드를 가리키도록 한다.
        if (q->front == NULL)       //공백상태
            q->rear = NULL ;
        free(temp) ;
        return temp->data ;
    }
}

//큐 출력 함수
void print_queue (LinkQueueType *q) {
    QueueNode *p ;
    for ( p = q->front ; p != NULL ; p = p->link)
        printf("%d -> ",p->data) ;
    printf("NULL\n") ;
}

//연결된 큐 테스트 함수
int main (void) {
    LinkQueueType queue ;

    init(&queue) ;

    enqueue(&queue, 10) ; print_queue(&queue) ;
    enqueue(&queue, 20) ; print_queue(&queue) ;
    enqueue(&queue, 30) ; print_queue(&queue) ;
    dequeue(&queue) ; print_queue(&queue) ;
    dequeue(&queue) ; print_queue(&queue) ;
    dequeue(&queue) ; print_queue(&queue) ;
    return 0 ;
}

/*
결과 출력
10 -> NULL
10 -> 20 -> NULL
10 -> 20 -> 30 -> NULL
20 -> 30 -> NULL
30 -> NULL
NULL
*/