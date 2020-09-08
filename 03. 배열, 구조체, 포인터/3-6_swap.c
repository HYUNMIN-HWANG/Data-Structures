//포인터를 함수의 매개변수로 사용하는 프로그램
//외부 변수 2개의 값을 서로 바꾼다.

#include <stdio.h>

void swap(int *px, int *py) {
    int tmp ; 
    tmp = *px ;                             //px, py 포인터가 가리키는 장소에 저장된 값을 서로 바꾼다.
    *px = *py ; 
    *py = tmp ;
}

int main (void) {
    int a = 1 , b = 2 ;
    printf("swap를 호출하기 전 : a = %d, b = %d\n" , a, b) ;
    swap(&a, &b) ;                         //a와 b의 주소를 함수의 매개변수로 전달
    printf("swap를 호출한 다음 : a = %d, b = %d\n", a, b) ;
    return 0 ;
}