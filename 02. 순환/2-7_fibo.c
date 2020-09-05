//피보나치 수열, 반복적 구조
//피보타치 수열 : (n-2) + (n-1) = n

#include <stdio.h>

int fib_iter(int n) ;

int main () {
    int n = 6 ;
    int result = 0 ;
    result = fib_iter(n) ;
    printf("%d",result) ;
    return 0;
}

int fib_iter(int n) {
    if ( n == 0) return 0;
    if ( n == 1) return 1;
    
    int pp = 0 ;
    int p = 1 ;
    int result = 0 ;

    for (int i = 2 ; i <= n ; i++ ) {
        result = pp + p ;
        pp = p ;
        p = result ;
    }
    return result ;
}