#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

int list [MAX_SIZE] ;
int n;

void selection_sort (int list[], int n) {
    int i, j, least, temp, t ;
    for ( i = 0 ; i < n-1 ; i++) {
        printf("%d회 : ", i+1) ;
        least = i ;
        for ( j = i+1 ; j < n ; j++)              //최솟값 탐색
            if (list[j] < list[least]) least = j ;
        SWAP(list[i], list[least], temp) ;     //최솟값과 맨 처음 값 교환
        for ( t=0 ; t < n ; t++)
            printf("%d ", list[t]);
            printf("\n") ;
    }
}

int main (void) {
    int i ;
    n = MAX_SIZE ;
    srand(time(NULL)) ;
    printf("랜덤한 배열 :");
    for (i = 0 ; i < n ; i ++)  {    //난수 생성 및 출력
        list[i] = rand() % 100 ;    //난수 발생 범위 0~99
        printf("%d ", list[i]);
    }
    printf("\n") ;
    printf("선택 정렬 : \n") ;
    selection_sort(list, n) ;
    printf("최종 정렬 결과 : ") ;
    for (i = 0 ; i < n ; i++) 
        printf("%d ", list[i]);
    printf("\n") ;
    return 0 ;
}