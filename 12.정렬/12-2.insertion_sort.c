#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

int list [MAX_SIZE] ;
int n;

void insertion_sort (int list[], int n) {
    int i, j, key, t ;
    for (i = 1; i < n ; i++) {
        printf("%d회 : ", i) ;
        key = list[i] ;
        for (j = i - 1 ; j >=0 && list[j] > key ; j-- )
            list[j+1] = list[j] ; //key값보다 크면 한 칸씩 뒤로 옮긴다.
        list[ j+1 ] = key ; //key 값보다 작은 값 뒤에 key 값을 넣는다.
        for (t = 0 ; t < n ; t++) 
            printf("%d ", list[t]);
        printf("\n") ;
    }
}

int main (void) {
    int i ;
    n = MAX_SIZE ;
    srand(time(NULL)) ;
    printf("랜덤한 배열 : ") ;
    for (i = 0 ; i < n ; i ++)  {    //난수 생성 및 출력
        list[i] = rand() % 100 ;    //난수 발생 범위 0~99
        printf("%d ", list[i]);
    }
    printf("\n") ;
    printf("삽입 정렬 : \n") ;
    insertion_sort(list, n) ;

    printf("최종 정렬 : ") ;
    for (i = 0 ; i < n ; i++) 
        printf("%d ", list[i]);
    printf("\n") ;
    return 0 ;
}