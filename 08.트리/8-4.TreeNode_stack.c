//반복적인 중위 순회
//스택을 활용해 반복적 트리 순회를 만든다.

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_SIZE 100 ;                      //스택 정의

typedef struct TreeNode {               //노드 구조체 정의
    int data ;
    struct TreeNode *left, *right ;    
} TreeNode ;

int top = -1 ;
TreeNode *stack[MAX_SIZE] ;

void push (TreeNode *p) {               //스택 push
    if (top < MAX_SIZEE -1)
        stack[++top] = p ;
}

TreeNode *pop() {                       //스택 pop
    TreeNode *p = NULL ;
    if (top >= 0)
        p = stack[top--] ;
    return p ;
}

void inorder_iter (TreeNode *root) {
    while(1) {
        for (; root ; root = root->left)    //왼쪽서브트리 순회 
            push (root) ;
        root = pop() ;
        if (!root) break ;
        printf("[%d] ", root->data) ;        //노드 방문
        root = root->right ;                //오늘쪽서브트리 순회
    }
}

//     15
//   4    20
// 1    16   25

TreeNode n1 = {1, NULL, NULL} ;
TreeNode n2 = {4, &n1, NULL} ;
TreeNode n3 = {16, NULL, NULL} ;
TreeNode n4 = {25, NULL, NULL} ;
TreeNode n5 = {20, &n3, &n4} ;
TreeNode n6 = {15, &n2, &n5} ;
TreeNode *root = &n6 ;

int main(void) {
    printf("중위순회 = ") ;
    inorder_iter(root) ;
    printf("\n") ;
    return 0 ;
}

