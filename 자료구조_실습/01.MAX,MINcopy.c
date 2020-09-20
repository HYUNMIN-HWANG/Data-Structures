//키보드 또는 파일에서 n개의 정수를 1차원 배열로 모두 읽어 들인 후, 최대값과 최소값을 동시에 찾는 함수

#include <stdio.h>

int* findMaxMin (int list) {
    int n = sizeof(list)/sizeof(int) ;
    int i ;
    int max = list[0] ;
    int min = list[0] ;

    for (i=0 ; i<n ; i++) {
        if (max <= list[i]) 
            max = list[i] ;
            printf("max -> %d\n",max) ;
        if (min >= list[i])
            min = list[i] ;
            printf("min -> %d\n",min) ;
    }
    return max, min ;
}

int main (void) {
    
    int data[7] ;
    int i ;
    printf("7개 정수를 입력하시오 : ") ;
    for (i = 0 ; i < 7 ; i++)
        scanf("%d\n", &data[i]) ;

    int max, min = findMaxMin(data) ;

    printf("Maximum : %d\n", max) ;
    printf("Minimum : %d\n", min) ;
    return 0 ;
}