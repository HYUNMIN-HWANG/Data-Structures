#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element ;
typedef struct {                                //큐타입 구조체
    int front ; 
    int rear ;
    element data [MAX_QUEUE_SIZE] ;
} QueueType ;

//오류 함수
void error (char *message) {
    fprintf(stderr,"%s\n",message) ;
    exit(1) ;
}

void init_queue (QueueType *q) {                //큐 초기화, 초기값은 -1
    q -> front = -1 ;
    q -> rear = -1 ;

} 

void queue_print (QueueType *q) {
    for (int i = 0 ; i <MAX_QUEUE_SIZE ; i++) {
        if ( i <= q->front || i > q->rear)      //데이터가 없는 부분
            printf("   | ") ;
        else                                    //데이터가 있는 부분
            printf("%d | ", q->data[i]) ;
    }
    printf("\n") ;
}

int is_full (QueueType *q) {                    //큐가 꽉 차 있을 때
    if (q->rear == MAX_QUEUE_SIZE -1)
        return 1 ;
    else
        return 0 ;   
}

int is_empty (QueueType *q) {                   //큐가 비어있을 때
    if (q->front == q->rear) 
        return 1;
    else
        return 0 ;    
}

void enqueue(QueueType *q, int item) {          //큐에 요소를 추가하는 연산, rear += 1
    if (is_full(q)) {
        error("큐가 포화상태입니다.") ;
        return;
    }
    q->data[++(q->rear)] = item ;
}

int dequeue(QueueType *q) {                     //큐에 요소를 삭제하는 연산, front += 1
    if (is_empty(q)) {
        error("큐가 공백상태입니다.") ;
        return ;
    }
    int item = q->data[++(q->front)] ;
    return item ;
}

int main (void) {
    int item = 0 ;
    QueueType q ;

    init_queue(&q) ;

    enqueue(&q, 10) ; queue_print(&q) ;
    enqueue(&q, 20) ; queue_print(&q) ;
    enqueue(&q, 30) ; queue_print(&q) ;
    
    item = dequeue(&q) ; queue_print(&q) ;
    item = dequeue(&q) ; queue_print(&q) ;
    item = dequeue(&q) ; queue_print(&q) ;

    return 0 ;    
}


// 출력
// 10 |    |    |    |    | 
// 10 | 20 |    |    |    | 
// 10 | 20 | 30 |    |    | 
//    | 20 | 30 |    |    | 
//    |    | 30 |    |    | 
//    |    |    |    |    | 
