//순환구조//

# include <stdio.h>

int factorial (int n) ;

int main () {
    int n = 5;
    n = factorial(n) ;
    printf("%d",n);
    return 0;
}

int factorial (int n) {
    if (n <= 1 ) return (1) ; //순환을 멈추는 부분 
    else return ( n * factorial(n-1)); // factorial 자기 자신을 다시 호출 (순환구조)
}
