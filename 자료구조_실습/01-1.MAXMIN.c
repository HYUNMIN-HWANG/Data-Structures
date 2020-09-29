//키보드 또는 파일에서 n개의 정수를 1차원 배열로 모두 읽어 들인 후, 최대값과 최소값을 동시에 찾는 함수

#include <stdio.h>

void findMaxMin (int list[], int *max, int *min, int n) {

    int large = *max ;
    int small = *min ;
    //printf("초기값 %d, %d\n", large, small) ; 10, 10

    for (int i=0 ; i<n ; i++) {
        if (large <= list[i]) {
            large = list[i] ;
            //printf("large %d \n", large) ;
            *max = large ;
            continue ;
        }
        else if (small >= list[i]) {
            small = list[i] ;
            //printf("small %d \n",small) ;
            *min = small ;
            continue ;
        }
    }
}

int main (void) {

    int n = 7 ;                                     //배열의 개수
    int data[7] = {10, 20, 34, -4, -10, 3, 12} ;    //배열 정의
    int max = data[0] ;                             //min 초기화
    int min = data[0] ;                             //max 초기화

    findMaxMin(data, &max, &min, n) ;
    int Maximum = max ;
    int Minimum = min ;

    printf("Maximum : %d\n", Maximum) ;
    printf("Minimum : %d\n", Minimum) ;


    return 0 ;
}

/*
Maximum : 34
Minimum : -10
*/


//실패한 것
// int findMaxMin (int list[], int n) {
//     int max = list[0] ;
//     int min = list[0] ;

//     for (int i=0 ; i<n ; i++) {
//         if (max <= list[i]) 
//             max = list[i] ;
//         else if (min >= list[i])
//             min = list[i] ;
//     }
//     return max, min ;
// }

// int main (void) {
    
//     int data[7] ;
//     printf("7개 정수를 입력하시오 : ") ;
//     for (int i = 0 ; i < 7 ; i++)
//         scanf("%d\n", &data[i]) ;

//     int Maximum, Minimum = findMaxMin(data, sizeof(data)/sizeof(int)) ;

//     printf("Maximum : %d\n", Maximum) ;
//     printf("Minimum : %d\n", Minimum) ;
//     return 0 ;
// }

/*
출력 결과 : 
Maximum : 0
Minimum : -6
*/