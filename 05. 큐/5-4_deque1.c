//덱 (Duble-ended queue) : 큐의 전단과 후단에서 모두 삽입과 삭제가 가느한 큐를 의미

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef element ;
typedef struct {                    //큐 타입
    element data [MAX_QUEUE_SIZE] ;
    int front, rear ;
} Dequetype  ;

//오류 함수
void error (char *message) {
    fprintf(stderr, "%s\n", message) ;
    exit(1) ;
}

//초기화
void init_deque(Dequetype *q) {
    q->front = q-> rear = 0 ;
}

//공백 상태 검출 함수
int is_empty(Dequetype *q) {
    return (q->front == q->rear) ;
}

//포화 상태 검출 함수
int is_fully(Dequetype *q) {
    return ((q->rear+1) % MAX_QUEUE_SIZE == q->front) ;
}

//원형큐 출력 함수
void deque_print(Dequetype *q) {
    printf("DEQUE(front = %d rear = %d) = ", q->front, q->rear) ;
    if (!is_empty(q)) {
        int i = q->front ;
        do {
            i = ( i + 1 ) % MAX_QUEUE_SIZE ;
            printf("%d | ",q->data[i]) ;
            if ( i == q->rear ) 
                break ;
        } while (i != q->front) ;
    }
    printf("\n") ;
}

//rear_삽입함수
void add_rear (Dequetype *q, element item) {
    if(is_fully(q)) 
        error("큐가 포화상태입니다.") ;
    q->rear = (q->rear +1) % MAX_QUEUE_SIZE ;
    q->data[q->rear] = item ;
}

//front_삭제 함수
element delete_front (Dequetype *q) {
    if(is_empty(q)) 
        error("큐가 공백상태입니다.") ;
    q->front = (q->front + 1) % MAX_QUEUE_SIZE ;
    return q->data[q->front] ;
}

//front_반환 함수
element get_front (Dequetype *q) {
    if(is_empty(q)) 
        error("큐가 공백상태입니다.") ;
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE] ;
}

//front_삽입 함수
void add_front (Dequetype *q, element val) {
    if(is_fully(q)) 
        error("큐가 포화상태입니다.") ;
    q->data[q->front] = val ;                       //front 가 있었던 자리에 값을 넣는다.
    q->front = (q->front - 1 + MAX_QUEUE_SIZE ) % MAX_QUEUE_SIZE ;  //front의 위치를 -1 칸 옮긴다. 대신, 값이 위치가 -1먄 안되기 때문에 MAX 값을 더해준다.
}

//rear_삭제 함수
element delete_rear (Dequetype *q) {
    int prev = q->rear ;                            //rear 위치에 있는 값을 prev에 넣는다.
    if(is_empty(q)) 
        error("큐가 공백상태입니다.") ;
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE ;     //rear의 위치를 -1 칸 옮긴다. 값이 위치가 -1먄 안되기 때문에 MAX 값을 더해준다.
    return q->data[prev] ;                          //prev 값 반환
}   

//rear_반환 함수
element get_rear (Dequetype *q) {
    if(is_empty(q)) 
        error("큐가 공백상태입니다.") ;
    return q->data[(q->rear)] ;
}

int main (void) {
    Dequetype queue ;
    
    init_deque(&queue) ;
    for ( int i = 0 ; i < 3 ; i++ ) {
        add_front(&queue, i) ;
        deque_print(&queue) ;
    }
    for ( int i = 0 ; i < 3 ; i++ ) {
        delete_rear(&queue) ;
        deque_print(&queue) ;
    }
    return 0 ;
}