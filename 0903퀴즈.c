#음의 정수를 포함하여 입력한 값 중에서 가장 큰 값 구하기

#include <stdio.h>
#include <limits.h>
 
int main(void)

{
    int x ;
    int big = INT_MIN -1;

    while(stdin != EOF)
    {
        scanf("%d",&x);
        if( x > big) big = x;
    }
    printf("the big is : %d\n", big);
}
