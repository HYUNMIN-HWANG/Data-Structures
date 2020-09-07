//다항식 덧셈 프로그램
//하나의 배열로 하나의 다항식 표현
// C = A + B (A와 B는 다항식)

#include <stdio.h>
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MAX_DEGREE 101

                                // 다항식 구조체 타입 선언
typedef struct {
    int degree ;                //다항식의 차수
    float coef[MAX_DEGREE] ;    //다항식의 계수
} polynominal ;

polynominal poly_add1 (polynominal A, polynominal B) {
    polynominal C ;                                     //결과 다항식
    int Apos = 0 , Bpos = 0 , Cpos = 0 ;                //배열 인덱스 변수
    int degree_a = A.degree ;                           // A의 차수
    int degree_b = B.degree ;                           // B의 차수
    C.degree = MAX(A.degree, B.degree) ;                //결과 다항식의 차수는 A와 B 중 더 큰 차수가 C의 차수가 된다.

    while (Apos <= A.degree & Bpos <= B.degree) {  
      
        if (degree_a > degree_b) {                      // A 차수 > B 차수일 때, C의 계수는 A의 계수와 같다.
            C.coef[Cpos++] = A.coef[Apos++] ; 
            degree_a--;
        }
        else if (degree_a == degree_b) {                // A 차수 = B 차수일 때, C의 계수는 A+B의 계수와 같다.
        C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
        degree_a--; degree_b--;
        }
        else {                                          // A 차수 < B 차수일 때, C의 계수는 B의 계수와 같다.
            C.coef[Cpos++] = B.coef[Bpos++] ;
            degree_b--;
        }
    }
    return C ;
}

void print_poly (polynominal p) {
    for (int i = p.degree ; i > 0 ; i--)
        printf("%3.1fx^%d + " , p.coef[p.degree - i], i) ;  //계수와 차수 출력
    printf("%3.1f \n", p.coef[p.degree]) ;                  //상수 출력
}

int main (void) {
    polynominal a = {3, {1,0,2,3}} ;
    polynominal b = {3, {-1,0,4,-1}} ;
    polynominal c ;

    print_poly (a) ;
    print_poly (b) ;
    c = poly_add1 (a , b) ;
    printf("-----------------------------------------------------\n") ;
    print_poly(c) ;
    return 0 ;
}