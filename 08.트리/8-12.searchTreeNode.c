//이진 탐색 트리

#include <stdio.h>
#include <stdlib.h>

typedef int element ;
typedef struct TreeNode {
    element key ;
    struct TreeNode *left, *right ;    
} TreeNode ;

//순환적인 탐색 함수
TreeNode * search (TreeNode *node, int key) {
    if (node == NULL) return NULL ;             //NULL 이면 NULL로 끝낸다.
    if (key == node->key) return node ;         //(1) 비교한 결과가가 같으면 탐색을 성공적으로 끝낸다.
    else if (key < node->key)                   //(2) 주어진 키 값이 루트 노드의 값보다 작으면, 루트 노드의 왼쪽 자식을 기준으로 다시 시작한다.
        return search (node->left, key) ;
    else                                        //(3) 주어진 키 값이 루트 노드의 값보다 크면, 루트 녿의 오른쪽 자식을 기준으로 다시 시작한다.
        return search (node->right, key) ;
}

// 새로운 노드 생성
TreeNode *new_node (int item) {
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode)) ;
    temp->key = item ;
    // printf("%d  ", temp->key) ;
    temp->left = temp->right = NULL ;
    return temp ;
}

//이진트리 삽입 연산
TreeNode *insert_node (TreeNode * node, int key) {
    //트리가 공백이면 새로운 노드를 반환한다.
    if (node == NULL) return new_node(key) ;

    //그렇지 않으면 순환적으로 트리를 내려간다.
    if (key < node->key) 
        node->left = insert_node(node->left, key) ;
    else if (key > node->key)
        node->right = insert_node(node->right, key) ;
    
    //변경된 루트 포인터를 반환한다.
    // printf("%d  ", node->key) ;
    return node ;
}

//서브트리 중 가장 작은 값을 찾는다.
TreeNode * min_value_node (TreeNode * node) {
    TreeNode * current = node ;

    //맨 왼쪽 단말 노드를 찾으러 내려감
    while (current->left != NULL) 
        current = current->left ;

    return current ;
}

//이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 새로운 루트 노드를 반환한다.
TreeNode * delete_node ( TreeNode * root, int key) {
    if ( root == NULL ) return root ;

    //만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
    if (key < root->key) 
        root->left = delete_node(root->left, key) ;

    //키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
    else if (key > root->key)
        root->right = delete_node(root->right, key) ;

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
        root->right = delete_node(root->right, temp->key) ;
    }
    return root ;
}

//중위 순회
void inorder(TreeNode *root) {
    if (root) {
        inorder (root -> left) ;        //왼쪽 서브트리 순회
        printf("[%d] ", root->key) ;    //노드 방문
        inorder (root-> right) ;         //오른쪽 서브트리 순회
    }
}

int main (void) {
    TreeNode * root = NULL ;
    TreeNode * tmp = NULL ;

    root = insert_node(root, 30) ;
    root = insert_node(root, 20) ;
    root = insert_node(root, 10) ;
    root = insert_node(root, 40) ;
    root = insert_node(root, 50) ;
    root = insert_node(root, 60) ;

    printf("이진 탐색 트리 중위 순회 결과 \n") ;
    inorder (root) ;
    printf("\n\n") ;
    if(search(root, 30) != NULL) 
        printf("이진 탐색 트리에서 30을 발견함 \n") ;
    else    
        printf("이진 탐색 트리에서 30을 발견 못함 \n") ;
    return 0 ;
}  

/*
출력결과
이진 탐색 트리 중위 순회 결과 
[10] [20] [30] [40] [50] [60] 

이진 탐색 트리에서 30을 발견함 
*/
