//배열을 함수의 매개변수로 사용하는 프로그램
//배열의 이름은 배열의 시자부분을 가리키는 포인터.

#include <stdio.h>
#define SIZE 6

//입력한 값을 list[i] 주소에 해당하는 값에 넣는다.
void get_integers (int list[]) {
    printf("6개의 정수를 입력하시오 : ") ;
    for (int i = 0; i < SIZE; ++i ) {
        scanf("%d", &list[i]) ;
        printf("%d", &list[i]) ;
    }
}

//배열에 있는 정수의 합계
int cal_sum (int list[]) {
    int sum = 0 ;
    for (int i = 0 ; i < SIZE ; ++i ) {
        sum += *(list + i) ;
    }
    return sum ;
}

int main (void) {
    int list [SIZE] ;
    get_integers (list) ;
    printf("합 = %d \n", cal_sum (list)) ;
    return 0 ;
}