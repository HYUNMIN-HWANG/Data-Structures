//1. 순환적인 탐색 함수

TreeNode * search (TreeNode *node, int key) {
    if (node == NULL) return NULL ;             //NULL 이면 NULL로 끝낸다.
    if (key == node->key) return node ;         //(1) 비교한 결과가가 같으면 탐색을 성공적으로 끝낸다.
    else if (key < node->key)                   //(2) 주어진 키 값이 루트 노드의 값보다 작으면, 루트 노드의 왼쪽 자식을 기준으로 다시 시작한다.
        return search (node->left, key) ;
    else                                        //(3) 주어진 키 값이 루트 노드의 값보다 크면, 루트 녿의 오른쪽 자식을 기준으로 다시 시작한다.
        return search (node->right, key) ;
}

//2. 반복적인 탐색 함수

TreeNode *search (TreeNode *node, int key) {
    while (node != NULL) {
        if (key == node->key) return node ;         //(1) 비교한 겨로가가 같으면 탐색을 성공적으로 끝낸다.
        else if (key < node->key)                   //(2) 주어진 키 값이 루트 노드의 값보다 작으면, 루트 노드의 왼쪽 자식을 기준으로 다시 시작한다.
            node = node->left ;
        else                                        //(3) 주어진 키 값이 루트 노드의 값보다 크면, 루트 녿의 오른쪽 자식을 기준으로 다시 시작한다.
            node = node->right ;
    }
    return NULL ;                                   // 탐색에 실패했을 경우 NULL로 반환
}