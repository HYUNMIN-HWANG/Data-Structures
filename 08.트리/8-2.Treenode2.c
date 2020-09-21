//이진트리의 3가지 순회방법

//1. 중위순회 : 왼쪽서브트리 -> 루트노드 -> 오른쪽서브트리

void inorder (TreeNode *root) {
    if ( root != NULL) {
        inorder(root->left) ;
        printf("[%d]", root->data) ;
        inorder(root->right) ;
    }
}

//2. 전위순회 : 루트노드 -> 왼쪽서브트리 -> 오른쪽서브트리

void preorder (TreeNode *root) {
    if(root != NULL) {
        printf("[%d]", root->data) ;
        preorder(root->left) ;
        preorder(root->right) ;
    }
}

//3. 후위순회 : 왼쪽서브트리 -> 오른쪽서브트리 -> 루트노드
void postorder(TreeNode *root) {
    if ( root != NULL ) {
        postorder(root->left) ;
        postorder(root->right) ;
        printf("[%d]", root->data) ;

    }
}
