//이진 탐색 트리에서의 삭제 함수

//이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 새로운 루트 노드를 반환한다.

TreeNode * delete_nodde ( TreeNode * root, int key) {
    if ( root == NULL) return root ;

    //만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
    if (key < root->key) 
        root->left = delete_nodde(root->left, key) ;

    //키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
    else if (key > root->key)
        root->right = delete_nodde(root->right. key) ;

    //키가 루트와 같으면 이 노드를 삭제한다.
    else {
        // 삭제하려는 노드가 단말 노드일 경우 or 삭제하려는 노두가 하나의 서브트리만 가지고 있는 경우
        if (root->left == NULL) {
            TreeNode * temp = root->right ;
            free(root) ;
            return temp ;               //오른쪽 서브트리에 있는 값을 return 시킨다.
        }
        else if (root->right == NULL) {
            TreeNode * temp = root->left ;
            free (root) ;
            return temp ;               //왼쪽 서브트리에 있는 값을 return 시킨다.
        }
        
        //삭제하려는 노드가 두 개의 서브트리를 가지고 있는 경우
        TreeNode * temp = min_value_node (root->right) ;
        
        //중외 순회시 후계 노드를 복사한다.
        root->key = temp-> key ;

        //중외 순회시 후계 노드를 삭제한다.
        root->right = delete_nodde(root->right, temp->key) ;
    }
    return root ;
}

TreeNode * min_value_node(TreeNode * node) {
    TreeNode * current = node ;

    //맨 왼쪽 단말 노드를 찾으러 내려감
    while ( current->left != NULL)
        current = current->left ;

    return current ;
}