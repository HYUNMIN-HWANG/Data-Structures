//동적 메모리 할당의 예
//MALLOC.C : malloc을 이용하여 정수 10을 저장할 수 있는 동적 메모리를 할당하고 free를 이용하여 메모리를 반납한다.

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10

int main (void) {
int *p ;                                                            //포인트 변수 p
    p = (int *) malloc (SIZE * sizeof(int)) ;                       //힙 영역으로 정수 10개를 저장할 수 있는 동적 메모리 할당
    if ( p == NULL) {                                               //메모리 공간 할당에 실패할 경우
        fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다. \n") ; 
        exit(1) ;
    }

    for ( int i = 0 ; i <SIZE ; i++)                                //동적 메모리 p[i] 에 값 저장
        p[i] = i ;

    for (int i = 0 ; i<SIZE ; i++) 
        printf("%d",p[i]) ;

    free(p) ;                                                       //동적 메모리 반납
    return 0 ;    
}
