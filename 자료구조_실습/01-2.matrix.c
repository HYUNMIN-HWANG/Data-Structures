//두개의 행렬 A 와 B를 곱하여 그 결과 행렬 C를 구하는 함수를 작성

#include <stdio.h>

int main (void) {

    int A[2][3] = {{3, 1, 0}, {2, 1, 1}} ;
    int B[3][2] = {{1 ,-1} ,{-2, 3} ,{0, 1}} ;
    int C[2][2] = {0} ;

    int i, j, p ;
    for ( i = 0 ; i<2 ; i++) {
        for(j=0 ; j<2 ; j++) {
            for(p=0 ; p<3 ; p++) {
                C[i][j] += A[i][p] * B[p][j] ;
            }
        }
    }

    for( i = 0 ; i < 2 ; i++) {
        for (j = 0 ; j < 2 ; j++) 
            printf("C[%d][%d] = %d  ", i, j, C[i][j]) ;
        printf("\n") ;
    }
    
    return 0;    
}