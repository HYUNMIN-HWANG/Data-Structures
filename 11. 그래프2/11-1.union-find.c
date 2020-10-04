//union-find 프로그램 : 추가하고자 하는 간선의 양끝 정점이 같은 집합에 속해 있는지 검사

int parent [MAX_VERTICES] ; // 부모 노드

// 초기화
void set_init(int n) {
    for (int i = 0 ; i<n ; i++)
        parent[i] = -1 ;    // 배열의 값이 -1이면 부모 노드가 없는 것
}

// curr가 속하는 집합을 반환한다.
int set_find (int curr) {
    if (parent[curr] == -1) // 루트
        return curr ;
    while (parent[curr] != -1) curr = parent[curr] ;    // 부모 노드 값이 변함
    return curr ;
}

// 두 개의 원소가 속한 집합을 합친다.
void set_union(int a, int b) {
    int root1 = set_find(a) ;
    int root2 = set_find(b) ;
    if (root1 != root2)     //root1과 roo2가 같지 않을 때 합친다. (같다면 사이클이 형성된다.)
        parent[root1] = root2 ;
}
