#include <stdio.h>
#include <stdlib.h>

//===== 리스트 정의 시작 =====

#define MAX_LIST_SIZE 100

typedef int element ;                       // 항목의 정의
typedef struct {                            
    element array [MAX_LIST_SIZE] ;         // 배열의 정의
    int size;                               // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

void error (char *message) {                // 오류 처리 함수
    fprintf(stderr, "%s\n", message) ;
    exit(1) ;
}

void init (ArrayListType *L) {              // 리스트 초기화 함수
    L -> size = 0 ;
}

int is_empty (ArrayListType *L) {           // 리스트가 비어 있으면 1을 반환, 그렇지 않으면 0을 반환
    return L -> size == 0 ;
}

int is_full (ArrayListType *L) {            // 리스트가 가득 차 있으면 1 반환, 그렇지 않으면 0을 반환
    return L -> size == MAX_LIST_SIZE ;
}

element get_entry (ArrayListType *L, int pos) {      //pos 위치의 요소를 반환한다.
    if (pos < 0 || pos >= L -> size ) 
        error("위치 모름") ;
    return L->array[pos] ;
} 

void print_list (ArrayListType *L) {                //리스트 요소를 출력한다.
    int i ;
    for ( i=0 ; i< L->size ; i++) 
        printf("%d -> ", L->array[i]) ;
    printf("\n") ;
}

void insert_last (ArrayListType *L, element item) {  //리스트 맨 끝에 항목을 추가한다.
    if(L->size > MAX_LIST_SIZE) 
        error("리스트 오버플로우") ;
    L->array[L->size++] = item ;
}

void insert (ArrayListType *L, int pos, element item) { //pos 위치에 항목을 추가한다.
    if (!is_full(L) && (pos >= 0) && pos <= L->size) {
        for (int i = (L->size-1) ; (i >=pos) ; i--) 
            L->array[i+1] = L->array[i] ;               //pos 이후 항목들을 모두 오른쪽으로 한 칸씩 이동
        L->array[pos] = item ;
        L->size++;
    }
}

element delete(ArrayListType *L, int pos) {                //pos 위치에 있는 항목을 삭제한다.
    element item ;

    if (pos<0 || pos>= L->size) 
        error("위치 오류") ;

    item = L->array[pos] ;
    for ( int i = pos ; i <= (L->size-1) ; i++) 
        L->array[i] = L->array[i+1] ;                       //pos 위치로 왼쪽으로 한 칸씩 이동
    L->size--;
    return item ; 
}

//===== 리스트 정의 끝 =====

int main (void) {
// ArrayListType 를 정적으로 생성하고 
//ArrayListType를 가리키는 포인트럴 함수의 매개변수로 전달한다.

    ArrayListType list ;

    init(&list) ;
    insert(&list, 0, 10) ; print_list(&list) ; //0번째 위치에 10 추가
    insert(&list, 0, 20) ; print_list(&list) ; //0번째 위치에 20 추가
    insert(&list, 0, 30) ; print_list(&list) ; //0번째 위치에 30 추가

    insert_last(&list, 40) ; print_list(&list) ; //마지막 위치에 40 추가

    delete(&list,0) ; print_list(&list) ;       //0번째 위치 항목 삭제
    return 0 ;
}