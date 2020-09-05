//거듭제곱 순환적인 방법

# include <stdio.h>

double power (double x, int n) ;

int main () {
    double x = 2.0 ;
    int n = 6 ;
    int final ;
    final = power(x, n);
    printf("%d",final);
    return 0;
}

double power (double x, int n) {
    if (n == 0) return 1 ;
    else if ((n%2) == 0)
        return power (x * x, n/2) ;
    else return x * power (x * x , (n-1)/2) ;
}