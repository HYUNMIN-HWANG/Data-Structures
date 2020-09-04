#음의 정수를 포함하여 입력한 값 중에서 가장 큰 값 구하기

#include <stdio.h>
 
int main(void)

{
    int big, x ;
    scanf("%d",&x);
    big = x; #Tip. 맨 처음에 입력한 값을 최댓값으로 설정한다.

    while(!eof(stdin))
    {
        scanf("%d",&x);
        if( x > big) big = x;
    }
    printf("the big is : %d\n", big);
}
