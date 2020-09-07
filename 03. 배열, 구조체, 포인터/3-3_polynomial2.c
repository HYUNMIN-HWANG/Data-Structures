//다항식 덧셈 프로그램
//하나의 배열로 여러 개의 다항식 표현

#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101 

typedef struct {
    float coef ;        //계수
    int expon ;         //차수
} polynominal ;
polynominal terms [MAX_TERMS] = { {8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0}} ;
int avail = 6 ;

//두 개의 정수 비교하는 함수
char compare (int a, int b) {
    if ( a>b ) return '>' ;
    else if ( a==b ) return '=' ;
    else return '<' ;
}

//새로운 항을 다항식 terms 에 추가
void attach (float coef, int expon) {
    if (avail > MAX_TERMS) {
        fprintf(stderr, "항의 개수가 너무 많음 \n") ;
        exit(1) ;
    }
    terms[avail].coef = coef ;
    terms[avail].expon = expon ;
    avail++ ;
}

// C = A + B
void poly_add2 (int As, int Ae, int Bs, int Be, int *Cs, int *Ce) { 
    //A의 처음과 끝(As,Ae), B의 처음과 끝(Bs,Be), 새로 생성된 다항식의 처음과 끝(Cs,Ce)
    float tempcoef ;
    *Cs = avail ;                                            //Cs의 처음 주소 : avail
    while ( As <= Ae && Bs <= Be)
        switch (compare(terms[As].expon, terms[Bs].expon)) {
        
        case '>' :                                           // A의 차수 > B의 차수
            attach(terms[As].coef, terms[As].expon) ;
            As++ ;
            break;

        case '<' :                                           // A의 차수 < B의 차수
            attach(terms[Bs].coef, terms[Bs].expon) ;
            Bs++ ;
            break;

        case '=' :                                           // A의 차수 = B의 차수
            tempcoef = terms[As].coef + terms[Bs].coef;
            if(tempcoef)
                attach(tempcoef, terms[As].expon) ;
            As++ ; Bs++ ;
            break;
        }
    
    //A의 나머지 항들을 이동함
    for ( ; As <= Ae ; As++)
        attach(terms[As].coef, terms[As].expon) ;
    //B의 나머지 항들을 이동함
    for ( ; Bs <= Be ; Bs++)
        attach(terms[Bs].coef, terms[Bs].expon) ;
    *Ce = avail - 1 ;                                          //Cs의 주소 : 마지막 원소가 들어있는 곳
}

void print_poly (int s, int e) {
    for (int i = s ; i < e ; i++) 
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon) ;
    printf("%3.1fx^%d\n",terms[e].coef, terms[e].expon) ;
}

//주함수
int main (void) {
    int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce ;
    poly_add2(As, Ae, Bs, Be, &Cs, &Ce) ;
    print_poly(As, Ae) ;
    print_poly(Bs, Be) ;
    printf("-------------------------------------------------\n") ;
    print_poly(Cs, Ce) ;
    return 0 ;    
}