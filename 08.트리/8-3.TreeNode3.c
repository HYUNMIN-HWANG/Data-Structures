//링크법으로 생성된 이진트리
//이진트리의 3가지 순회방법 테스트 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
   int data ;
   struct TreeNode *left, *right ;
} TreeNode;

//     15
//   4    20
// 1    16   25

TreeNode n1 = { 1, NULL, NULL} ;
TreeNode n2 = { 4, &n1, NULL} ;
TreeNode n3 = { 16, NULL, NULL} ;
TreeNode n4 = { 25, NULL, NULL} ;
TreeNode n5 = { 20, &n3, &n4} ;
TreeNode n6 = { 15, &n2, &n5} ;
TreeNode *root = &n6 ;

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

int main (void) {
    printf("중위순회 = ") ;
    inorder(root) ;
    printf("\n") ;

    printf("전위순회 = ") ;
    preorder(root) ;
    printf("\n") ;   

    printf("후위순회 = ") ;
    postorder(root) ;
    printf("\n") ;   

    return 0 ;
}

// 중위순회 = [1][4][15][16][20][25]
// 전위순회 = [15][4][1][20][16][25]
// 후위순회 = [1][4][16][25][20][15]
