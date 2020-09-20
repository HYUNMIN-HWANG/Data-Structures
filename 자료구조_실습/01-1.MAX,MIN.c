//키보드 또는 파일에서 n개의 정수를 1차원 배열로 모두 읽어 들인 후, 최대값과 최소값을 동시에 찾는 함수

#include <stdio.h>

int findMaxMin (int list[], int n) {
    int max = list[0] ;
    int min = list[0] ;

    for (int i=0 ; i<n ; i++) {
        if (max <= list[i]) 
            max = list[i] ;
            //printf("max - %d\n",max) ;
        if (min >= list[i])
            min = list[i] ;
            //printf("min - %d\n",min) ;
    }
    return max, min ;
}

int main (void) {
    
    int data[7] ;
    printf("7개 정수를 입력하시오 : ") ;
    for (int i = 0 ; i < 7 ; i++)
        scanf("%d\n", &data[i]) ;

    int Maximum, Minimum = findMaxMin(data, sizeof(data)/sizeof(int)) ;

    printf("Maximum : %d\n", Maximum) ;
    printf("Minimum : %d\n", Minimum) ;
    return 0 ;
}

/*
출력 결과 : 
Maximum : 0
Minimum : -6
*/