// 최댓값 구하기//

#include<stdio.h>
#define MAX 100 // max 값이 100이다.
int scores [MAX] ; // scorese 리스트에 MAX_ELEMENT 넣기

int get_max_scores (int n) { //get_max_scores 정수 함수 정의
    int i, largest ;
    largest = scores [0] ; //scores 리스트에 있는 첫번째 수를 가장 큰 수로 저장
    for (i = 1 ; i < n ; i++) { 
        if (scores[i] > largest ) { //scores리스트의 i번째 있는 숫자와 largest 변수에 있는 수와 비교
            largest = scores [i] ;
        }
    }
    return largest ;
}