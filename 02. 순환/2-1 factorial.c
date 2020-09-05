#include <stdio.h>
int n = 3 ;
int factorial (int n) {
    if ( n <= 1 ) return (1) ;
    else return (n * factorial(n-1))  ;
}