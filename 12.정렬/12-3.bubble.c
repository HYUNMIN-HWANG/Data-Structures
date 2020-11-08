#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t) )
void bubble_sort (int list[], int n) {
    int i, j, temp ;
    for (i = n-1 ; i >0; i--) {                 //스캔 한 번할 때마다 오른쪽 끝에 가장 큰 값이 온다.
        for (j=0; j<i ; j++)
            if (list[j] > list[j+1])            //앞뒤의 레코드를 비교한 후 큰 값이 오른쪽으로 가도록 교체
                SWAP (list[j], list[j+1], temp) ;
    }
}
