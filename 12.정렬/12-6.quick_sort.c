#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE] ;
int n;
int j ;

int partition (int list[], int left, int right) {
    int pivot, temp ;
    int low, high ;

    low = left ;
    high = right + 1 ;
    pivot = list[left] ;
    do {
        do
            low++ ;
        while (list[low] < pivot) ;                              //list[low]가 pivot보다 작으면 계속 low 증가시킨다.
        do
            high-- ;
        while (list[high] > pivot) ;                            //list[high]가 pivot보다 크면 계속 high를 증가시킨다.
        if (low < high) SWAP(list[low], list[high], temp) ;     //low와 high를 아직 교차하기 전이라면 교차한다.
    } while (low < high) ;

    SWAP(list[left], list[high], temp) ;                        //list[left]에 있는 피봇을 [high]자리인 중앙으로 위치시킨다.
    printf("%d회 : ", j++) ;
    for (int i = 0 ; i < n ;i++ )
        printf("%d ", list[i]) ;
    printf("\n") ;
    return high ;                                               //피봇의 위치를 반환한다.
    
}

void quick_sort (int list[], int left, int right) {
    if (left < right) {
        int q = partition (list, left, right) ; //피벗을 기준으로 2개의 리스틀 분할한다. 
        quick_sort (list, left, q-1) ;          //피벗 앞까지를 대상으로 순환호출
        quick_sort (list, q+ 1, right) ;        //피벗 다음부터 끝까지를 대상으로 순환호출
    }   
}

int main(void) {
    int i ;
    n = MAX_SIZE ;
    srand(time(NULL)) ;
    printf("랜덤 배열 : \n");
    for (i = 0 ; i < n ; i++)
        list[i] = rand() % 100 ;
    for (i = 0 ; i < n ;i++ )
        printf("%d ", list[i]) ;
    printf("\n") ;

    printf("퀵 정렬 : \n") ;
    quick_sort(list, 0, n-1) ; 

    printf("최종 정렬 : \n") ;
    for (i = 0 ; i < n ;i++ )
        printf("%d ", list[i]) ;
    printf("\n") ;
    return 0 ;
}

/*
랜덤 배열 : 
49 31 57 80 63 83 68 99 22 73 
퀵 정렬 : 
0회 : 22 31 49 80 63 83 68 99 57 73 
1회 : 22 31 49 80 63 83 68 99 57 73 
2회 : 22 31 49 57 63 73 68 80 99 83 
3회 : 22 31 49 57 63 73 68 80 99 83 
4회 : 22 31 49 57 63 73 68 80 99 83 
5회 : 22 31 49 57 63 68 73 80 99 83 
6회 : 22 31 49 57 63 68 73 80 83 99 
최종 정렬 : 
22 31 49 57 63 68 73 80 83 99 
*/