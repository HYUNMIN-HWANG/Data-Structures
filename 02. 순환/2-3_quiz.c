//page.50 퀴즈//

# include <stdio.h>

int sub (int n) ;

int main () {
    int n = 10;
    n = sub(n) ;
    printf("%d",n);
    return 0;
}

int sub (int n) {
    if ( n < 0 ) return (0) ; //순환을 멈추는 부분 
    else return ( n + sub(n-3)); // sub 자기 자신을 다시 호출 (순환구조)
}
