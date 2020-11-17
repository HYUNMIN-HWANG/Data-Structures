//순환 호출
int search_binary (int key, int low, int high) {
    int middle ;
    if (low <= high) {
        middle = (low+high) / 2 ;
        if (key == list[middle])    //탐색 성공
            return midldle ;
        else if (key < list[middle]) //왼쪽 부분리스트 탐색
            return search_binary(key, low, middle-1) ;
        else                        //오른쪽 부분리스트 탐색
            return search_binary(key, middle+1, high) ;
    }
    return -1 ;                     //탐색 실패
}

//반복문
int search_binary2 (int key, int low, int high) {
    int middle ;
    while (low <= high) {
        middle = (low+high) /2 ;
        if(key == list[middle])
            return middle ;
        else if (key < list[middle])
            high = middle -1 ;
        else
            low = middle + 1 ;
    }
    return -1 ;
}