//n개의 디스크가 말뚝 A에 있을 때 말뚝 A에 있는 모든 디스크를 빈 말뚝들을 사용하여 말뚝 C로 옮기는 재귀 프로그램

#include <stdio.h>

int count = 0 ;                                                     //하노이 디스크 이동 횟수 : 전역변수로 정의

int hanoi (int n, char from, char temp, char to) {
    if (n==1) {
        printf("Move disc 1 from peg %c to peg %c.\n",from, to) ;   //마지막에 남은 디스크는 A->C
        count++ ;
    }
    else {
        hanoi(n-1, from, to, temp) ;                                //재귀 함수로 정의
        printf("Move disc %d from peg %c to peg %c.\n",n,from,to) ; //n-1개 디스크는 A->B로 이동
        count++ ;
        hanoi(n-1, temp, from, to) ;                                //n-1개 디스크를 B->C로 이동
    }    
    return count;
}

int main (void) {
    int n ;
    printf("n값을 입력하세요 : ") ;
    scanf("%d", &n) ;

    hanoi(n,'A','B','C') ;
    printf("The number of disc moves = %d\n", count) ;
    return 0 ;
}