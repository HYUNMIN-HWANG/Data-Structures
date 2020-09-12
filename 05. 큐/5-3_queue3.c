//큐의 응용 : 버퍼

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
    srand(time(NULL)) ;

    for (int i=0 ; i <100 ; i++) {
        if(rand() % 5 == 0) {              // 5로 나누어 떨어지면
            enqueue ( &queue, rand() % 100 ) ;
        }
        queue_print(&queue) ;
        if (rand() % 100 == 0) {            // 10로 나누어 떨어지면
            int data = dequeue(&queue) ;
        }
        queue_print(&queue);
    }
    return 0 ;
}