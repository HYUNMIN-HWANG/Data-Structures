//원형 큐 알고리즘

#include <stdio.h>
#include <stdlib.h>

// ===== 원형 코드 시작 ===== 
#define MAX_QUEUE_SIZE 5
typedef int element ;
typedef struct {                            //큐타입 구조
    element data [MAX_QUEUE_SIZE] ;
    int front, rear ;
} Queuetype ;

//오류 함수
void error (char *message) {
    fprintf(stderr, "%s\n", message) ;
    exit(1) ;
}

//초기화 함수
void init_queue(Queuetype *q) {
    q -> front = q -> rear = 0 ;
}

//공백 상태 검출 함수
int is_empty (Queuetype *q) {
    return (q->front == q->rear) ;
}

//포화 상태 검출 함수
int is_full (Queuetype *q) {
    return ((q->rear+1) % MAX_QUEUE_SIZE == q->front) ;
}

//원형큐 출력 함수
void queue_print(Queuetype *q) {
    printf("QUEUE (front = %d rear = %d) = ", q->front, q->rear) ;
    if (!is_empty(q)) {
        int i = q->front ;
        do {
            i = ( i+1 ) % MAX_QUEUE_SIZE ;
            printf("%d | ", q->data[i]) ;
            if ( i == q->rear )
                break ;
        } while (i != q->front) ;
    }
    printf("\n") ;
}

//삽입 함수
void enqueue(Queuetype *q, element item) {
    if (is_full(q))
        error("큐가 포화상태입니다.") ;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE ;
    q->data[q->rear] = item ;
}

//삭제함수
element dequeue(Queuetype *q) {
    if(is_empty(q))
        error("큐가 공백상태입니다.") ;
    q->front = (q->front + 1) % MAX_QUEUE_SIZE ;
    return q->data[q->front] ;
}

//피크 함수
element peek (Queuetype *q) {
    if(is_empty(q))
        error("큐가 공백상태입니다.") ;
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE] ;
}

// ===== 원형 코드 끝 ===== 

int main (void) {
    Queuetype queue ;
    int element ;

    init_queue(&queue) ;
    printf("== 데이터 추가 단계 == \n") ;
    while (!is_full(&queue)) {
        printf("정수를 입력하시오 : \n") ;
        scanf("%d",&element) ;
        enqueue(&queue, element) ;
        queue_print(&queue) ;
    }
    printf("큐는 포화상태입니다.\n\n") ;

    printf("== 데이터 삭제 단계 == \n") ;
    while (!is_empty(&queue)) {
        element = dequeue(&queue) ;
        printf("꺼내진 정수 : %d \n", element) ;
        queue_print(&queue) ;
    }
    printf("큐는 공백상타입니다. \n") ;
    return 0 ;
}

/*
== 데이터 추가 단계 == 
정수를 입력하시오 : 
QUEUE (front = 0 rear = 1 = 10 | 
정수를 입력하시오 : 
QUEUE (front = 0 rear = 2 = 10 | 20 | 
정수를 입력하시오 : 
QUEUE (front = 0 rear = 3 = 10 | 20 | 30 | 
정수를 입력하시오 : 
QUEUE (front = 0 rear = 4 = 10 | 20 | 30 | 40 | 
큐는 포화상태입니다.

== 데이터 삭제 단계 == 
꺼내진 정수 : 10 
QUEUE (front = 1 rear = 4 = 20 | 30 | 40 | 
꺼내진 정수 : 20 
QUEUE (front = 2 rear = 4 = 30 | 40 | 
꺼내진 정수 : 30 
QUEUE (front = 3 rear = 4 = 40 | 
꺼내진 정수 : 40 
QUEUE (front = 4 rear = 4 = 
큐는 공백상타입니다. 
*/