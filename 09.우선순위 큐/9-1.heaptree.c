//히프트리 테스트 프로그램

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
    int key ;
} element ;

typedef struct {
    element heap[MAX_ELEMENT] ;
    int heap_size ;
} HeapType ;

//생성 함수
HeapType * create() {
    return  (HeapType *)malloc(sizeof(HeapType)) ;
}

//초기화 함수
void init (HeapType* h) {
    h->heap_size = 0 ;
}

//현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
//삽입 함수
void insert_max_heap (HeapType *h, element item) {
    int i ;
    i = ++(h->heap_size) ;                              // 맨 마지막 노드에 새로운 itme 추가
    //트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i!=1) && (item.key > h->heap[i/2].key)) {   //item이 부모노드 값보다 크다면
        h->heap[i] = h->heap[i/2] ;                     //item을 부모노드 자리와 교환
        i /= 2 ;
    }
    h->heap[i] = item ;                                 //부모노드 자리에 item 넣기
}

//삭제 함수
element delete_max_heap (HeapType *h) {
    int parent, child  ;
    element item, temp ;

    item = h->heap[1] ;                                 //item = 삭제하고자 하는 루트 노드 값
    temp = h->heap[(h->heap_size)--] ;                  //temp = 맨 마지막에 있는 노드 값
    parent = 1;
    child = 2 ;

    while (child <= h->heap_size) {
        //현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
        if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child+1].key)  //오른쪽 자식노드 값이 더 크다면,
            child++ ;                                                               //기준이 되는 자식노드를 오른쪽으로 설정
        if (temp.key >= h->heap[child].key) break ;                                 //temp가 자식노드보다 크다면 알맞게 들어간 것이기 때문에 중단
        //자식노드보다 크지 않으면, 한 단계 아래로 이동
        h->heap[parent] = h->heap[child] ;
        parent = child ;
        child *= 2 ;
    }
    h->heap[parent] = temp ;
    return item ;
}

int main (void) {
    element e1 = {10}, e2 = {5}, e3 = {30} ;
    element e4, e5, e6 ;
    HeapType *heap ;

    heap = create() ;       //히프 생성
    init(heap) ;            //초기화

    //삽입
    insert_max_heap(heap, e1) ; 
    insert_max_heap(heap, e2) ;
    insert_max_heap(heap, e3) ;

    //삭제
    e4 = delete_max_heap(heap) ;
    printf("< %d > ", e4.key) ;
    e5 = delete_max_heap(heap) ;
    printf("< %d > ", e5.key) ;   
    e6 = delete_max_heap(heap) ;
    printf("< %d > \n", e6.key) ;

    free(heap) ;
    return 0 ;
}

//출력 결과 : < 30 > < 10 > < 5 > 