//피보나치 수열, 순환적 구조
//피보타치 수열 : (n-2) + (n-1) = n

#include <stdio.h>

int fib(int n) ;

int main () {
    int n = 6 ;
    int result = 0 ;
    result = fib(n) ;
    printf("%d",result) ;
    return 0;
}

int fib(int n) {
    if ( n == 0) return 0;
    if ( n == 1) return 1;
    return (fib(n-2) + fib(n-1)) ;
}