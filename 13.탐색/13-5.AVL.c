#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))

//AVL 트리 노드 정의
typedef struct AVLNode {
    int key ; 
    struct AVLNode *left ;
    struct AVLNode *right ;
} AVLNode ;

//오늘쪽으로 회전시키는 함수
AVLNode *rotate_right (AVLNode *parent) {
    AVLNode* child = parent->left ;
    parent->left = child->right ;
    child->right = parent ;
    return child ; //새로운 루트 반환
}

//왼쪽으로 회전시키는 함수
AVLNode *rotate_left (AVLNode *parent) {
    AVLNode *child = parent->right ;
    parent->right = child->left ;
    child->left = parent ;
    return child ; //새로운 루트 반환
}

//트리의 높이를 반환
int get_height (AVLNode *node) {
    int height = 0 ;
    if (node != NULL) {
        height = 1 + max(get_height(node->left) , 
        get_height(node->right)) ;
    }
    return height ;
}

//노드의 균형인수를 반환
int get_balance(AVLNode* node) {
    if (node == NULL) return 0 ;
    return get_height(node->left) - get_height(node->right) ;
}

//노드를 동적으로 생성하는 함수
AVLNode* create_node (int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode)) ;
    node->key = key ;
    node->left = NULL ;
    node->right = NULL ;
    return (node) ;
}

//AVL 트리에 새로운 노드 추가 함수
AVLNode* insert(AVLNode* node, int key) {
    if(node==NULL)
        return (create_node(key)) ;
    
    if(key < node->key)
        node->left = insert(node->left, key) ;
    else if (key > node->key) 
        node->right = insert(node->right, key) ;
    else
        return node ;

    //노드들의 균형인수 재계산
    int balance = get_balance(node) ;
    
    //LL 타입 처리 (왼쪽 자식의 왼쪽에 새로운 노드가 추가된 경우)
    if (balance > 1 && key < node->left->key) 
        return rotate_right(node) ;
    //RR 타입 처리 (오른쪽 자식의 오른쪽에 새로운 노드가 추가된 경우)
    if (balance < -1 && key > node->right->key)
        return rotate_left(node) ;
    //LR 타입 처리 (왼쪽 자식의 오른쪽에 새로운 노드가 추가된 경우)
    if (balance > 1 && key > node->left->key) {
        node->left = rotate_left(node->left) ;
        return rotate_right(node) ;
    }
    //RL 타입 처리 (오른쪽 자식의 왼쪽에 새로운 노드가 추가된 경우)
    if (balance < -1 && key < node->right->key) {
        node->right = rotate_right(node->right) ;
        return rotate_left(node) ;
    }
    return node;        
}

//전위 순회 함수
void preorder (AVLNode *root) {
    if (root != NULL) {
        printf("[%d] ", root->key) ;
        preorder(root->left) ;
        preorder(root->right) ;
    }
}

int main (void) {
    AVLNode *root = NULL ;

    root = insert(root, 10) ;
    printf("1 : ") ; preorder(root) ;
    root = insert(root, 20) ;
    printf("2 : ") ; preorder(root) ;
    root = insert(root, 30) ;
    printf("3 : ") ; preorder(root) ;
    root = insert(root, 40) ;
    printf("4 : ") ; preorder(root) ;
    root = insert(root, 50) ;
    printf("5 : ") ; preorder(root) ;
    root = insert(root, 29) ;

    printf("전위 순회 결과 \n") ;
    preorder(root) ;
    return 0 ;
}

//[30] [20] [10] [29] [40] [50] 