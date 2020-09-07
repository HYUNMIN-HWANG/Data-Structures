#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

//element : 행렬을 (row, col, value)로 표현한 구조체
typedef struct {
    int row ; 
    int col ;
    int value ;
} element ;

//SparseMatrix : 희소행렬을 나타내는데 필요한 것들을 모아놓은 구조체
typedef struct SparseMatrix {
    element data [MAX_TERMS] ;
    int rows ;                           //행의 개수
    int cols ;                           //열의 개수
    int terms ;                          //항의 개수
 } SparseMatrix ;       

SparseMatrix martix_transpose2(SparseMatrix a) {
    SparseMatrix b ;

    int bindex ;                         //행렬 b에서 현재 저장 위치
    b.rows = a.rows ;                    //행렬 a와 행, 열, 값 개수가 동일하다.
    b.cols = a.cols ;
    b.terms = a.terms ;

    if (a.terms > 0) {                   //0이 아닌 것만 B에 저장할 것이다.
        bindex = 0 ;                     //행렬 b 시작점
        for ( int c = 0 ; c < a.cols ; c++) {               //행렬 a의 cols 값이 0인 것 부터 탐색
            for ( int i = 0 ; i < a.terms ; i++) {          //i : 행렬 a의 위치
                if (a.data[i].col == c ) {
                    b.data[bindex].row = a.data[i].col ;
                    b.data[bindex].col = a.data[i].row ;
                    b.data[bindex].value = a.data[i].value ;
                    bindex++;
                }
            }
        }

    }
    return b ;
}

void matrix_print(SparseMatrix a) {
    printf("==================================\n") ;
    for (int i = 0 ; i < a.terms ; i++) {
        printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value) ;
    }
    printf("==================================\n") ;
}

int main (void) {
    SparseMatrix m = {
        { {0,3,7}, {1,0,9}, {1,5,8}, {3,0,6}, {3,1,5},{4,5,1},{5,2,2}},
        6,          //행의 개수
        6,          //열의 개수
        7           //항의 개수
    } ;
    SparseMatrix result ;

    result = martix_transpose2(m) ;
    matrix_print(result) ;
    return 0 ;
}