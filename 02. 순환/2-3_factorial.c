//2-2 순환구조를 반복구조로 바꾸기

# include <stdio.h>

int factorial (int n) ;

int main () {
    int n = 5;
    n = factorial(n) ;
    printf("%d",n);
    return 0;
}

int factorial(int n) {
    int i, result = 1 ;
    for ( i = 1 ; i <= n ; i++)
        result = result * i ;
    return (result);
}