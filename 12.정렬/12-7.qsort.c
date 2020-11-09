#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compare (const void *arg1, const void *arg2) {
    if (*(double *)arg1 > *(double *)arg2) return 1 ;
    else if (*(double *)arg1 == *(double *)arg2) return 0 ;
    else return -1 ;
}

int main (void) {
    int i ;
    double list[5] = {2.1, 0.9, 1.6, 3.8, 1.2} ;
    qsort((void *)list, (size_t)5, sizeof(double), compare) ;   //배열의 시작 주소, 배열 요소의 개수, 배열 요소 하나의 크기
    for ( i = 0 ; i < 5 ; i++)
        printf("%f ", list[i]) ;
    return 0 ;
}

//0.900000 1.200000 1.600000 2.100000 3.800000 