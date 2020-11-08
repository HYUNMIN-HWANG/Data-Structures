//gap만큼 떨어진 요소들을 삽입 정렬
//정렬의 범위는 first에서 last

//일정한 간격으로 떨어져 있는 요소들을 삽입 정렬하는 함수
inc_insertion_sort(int list[], int first, int last, int gap) {
    int i, j, key ;
    for (i = first + gap ; i <= last ; i = i+gap) {
        key = list[i] ;
        for (j = i-gap ; j >= first && key<list[j] ; j = j - gap) 
            list[j+gap] = list[j] ;
        list[j+gap] = key ;
    }
}

//쉘 정렬
void shell_sort (int list[], int n) {   // n = size
    int i, gap ;
    for (gap = n/2 ; gap > 0 ; gap = gap / 2) {
        if ((gap % 2) == 0) gap++;      //간격이 짝수라면 1을 더한다.
        for (i = 0 ; i < gap ; i++)
            inc_insertion_sort(list, i, n-1, gap) ;
    }
}