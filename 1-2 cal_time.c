//수행시간 측정하기//
#include <stdio.h>
#include <stdlib.h> //문자열 변환, 의사 난수 생성, 동적 메모리 관리 등의 함수들을 포함
#include <time.h>

int main (void) {
    clock_t start, stop ; // clock() 함수는 프로그램의 실행 시작으로부터 경과된 시간을 clock ticks 수로 반환
    double duration ;
    start = clock() ; //시간 측정 시작

    for ( int i = 0 ; i < 100000 ; i ++) 
            ;
    stop = clock() ; //시간 측정 종료
    duration = (double)(stop-start) / CLOCKS_PER_SEC ; //CLOCKS_PER_SEC : 초당 clock ticks의 수를 나타낸 매크로
    
    printf("수행시간은 %f초 입니다.\n", duration);
    return 0;
}