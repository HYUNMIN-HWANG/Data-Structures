#include <stdio.h>
#include <time.h>
#include <limits.h>

int fib (int n) {
    if (n == 0) return 0 ;
    else if (n == 1) return 1 ;
    return (fib(n-1) + fib(n-2)) ;
}

int main (void) {
    int n = 0 ;
    unsigned long result ;
    clock_t start, end ;
    double total_time ;

    start = clock() ;

    for ( n = 0 ; n < INT_MAX - 1 ; n++) {
        result = fib(n) ;
        end = clock() ;
        total_time = (double)(end - start) / CLOCKS_PER_SEC ;
        if (total_time >= 180 || result > UINT_MAX)
            break ;
    }

    printf("최대 n 값 : %d\n", n ) ;
    printf("최대 Fn 값 : %lu\n", result ) ;
    printf("실행시간 : %.3lf sec", total_time ) ;

    return 0;
}