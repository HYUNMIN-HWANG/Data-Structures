//하노이탑 알고리즘

#include <stdio.h>

void hanoi_tower (int n, char from, char tmp, char to);

int main () {
    hanoi_tower (4,'A','B','C') ;
    return 0 ;
}

void hanoi_tower (int n, char from, char tmp, char to) { //void : 반환하지 않는다.
    if ( n == 1 ) printf("원판 1을 %c에서 %c으로 옮긴다.\n", from, to); //가장 큰 원판을 from 에서 to로 옮긴다.
    else {
        hanoi_tower (n-1, from, to, tmp) ; //가장 큰 원반을 제외한 n-1개의 원판을 from 에서 tmp로 옮긴다.
        printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to) ;
        hanoi_tower (n-1, tmp, from, to) ; //tmp에 있는 n-1개의 원판을 to로 옮긴다.
    }
}
