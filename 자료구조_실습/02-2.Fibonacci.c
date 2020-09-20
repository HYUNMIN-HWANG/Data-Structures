//음이 아닌 정수값 𝑛에 대해, 피보나치수 𝐹n을 구하는 재귀 프로그램을 작성

#include <stdio.h>
#include <time.h>

int fibo (int n) {
    int result ;
    if (n<=1) return n ;
    return (fibo(n-1)+fibo(n-2)) ;
}

int main (void) {
    int n  ;
    printf("음이 아닌 정수값 n을 입력하세요. \n") ;
    scanf("%d",&n) ;

    clock_t start = clock() ;
    int fib_result = fibo(n) ;
    printf("The %d-th Fibonacci number = %d \n", n, fib_result) ;
    clock_t finish = clock() ;
    printf("The execution time = %f", (double)(finish-start)/CLOCKS_PER_SEC) ;
    return 0 ;
}