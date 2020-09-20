//음이 아닌 정수값 𝑛에 대해, 계승값 𝑛!을 구하는 재귀 프로그램을 작성

#include <stdio.h>
#include <time.h>
// #define CLOCKS_PER_SEC 1000

int factorial(int n) {
    int result ;                                     //factorial 결과값이 저장될 변수

    if(n==0) 
        return (1) ;
    else {
        result = n * factorial(n-1) ;               //재귀함수를 이용한 계승
    }
    return result ;
}

int main (void) {
    int n ;
    printf("음이 아닌 n값을 입력하세요. : \n") ;
    scanf("%d", &n) ;

    clock_t start = clock() ;                       //시작하는 시간
    long long ans = factorial(n);
    printf("The Factorial %d = %lld\n", n, ans) ;   // n의 factorial 결과값 출력
    clock_t end = clock() ;                          //끝나는 시간
    
    printf("The execution = %lf msec\n", (double)(end-start)/CLOCKS_PER_SEC) ;  //걸리는 시간 출력
    return 0 ;
}