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
