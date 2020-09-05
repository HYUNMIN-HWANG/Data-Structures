//거듭제곱 반복적인 방법

# include <stdio.h>

double slow_power (double x, int n) ;

int main () {
    double x = 2.0 ;
    int n = 5 ;
    int final ;
    final = slow_power(x, n);
    printf("%d",final);
    return 0;
}

double slow_power (double x, int n) {
    int i ;
    double result = 1.0 ; 
    for ( i = 0 ; i < n ; i++)
        result = result * x ;
    return (result) ;
}