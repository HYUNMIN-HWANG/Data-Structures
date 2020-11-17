//순차 탐색

int seq_search (int key, int low, int high) {
    int i ;
    for (i = low ; i <= high ; i++) {
        if (list[i] == key)
            return i ;
    }
    return -1 ;
}

//갠선된 순차탐색
int seq_search2 (int key, int low, int high) {
    int i ;
    list[high+1] = key ;
    for (i=low ; list[i] != key ; i++)  ;   //키 값을 찾으면 종료
    if (i == (high+1)) return -1 ;          //탐색 실패
    else return i ;                         //탐색 성공, 인덱스 값 리턴
}