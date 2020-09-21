//링크 표현법으로 생성된 이진트리
//노드가 구조체로 표현, 데이터를 저장하는 필드1 + 왼쪽 자식 노르와 오른쪽 자식노들르 가리키는 2개 포인터 
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {                       //구조체를 이용하여 노드의 구조를 정의
    int data ;
    struct TreeNode *left, *right ;
} TreeNode ;

/*
    n1
   / |
n2  n3
*/

int main (void) {
    TreeNode *n1, *n2, *n3 ;                    //노드 n1, n2, n3

    n1 = (TreeNode *)malloc(sizeof(TreeNode)) ; //노드를 동적 메모리 할당을 이용하여 생성
    n2 = (TreeNode *)malloc(sizeof(TreeNode)) ;
    n3 = (TreeNode *)malloc(sizeof(TreeNode)) ;

    n1->data = 10 ;                             //노드 n1 생성
    n1->left = n2 ;
    n1->right = n3 ;

    n2->data = 20 ;                             //노드 n2 생성
    n2->left = NULL ;
    n2->right = NULL ;

    n3->data = 30 ;                             //노드 n3 생성
    n3->left = NULL ;
    n3->right = NULL ;

    free(n1) ; free(n2) ; free(n3) ;
    return 0;
}
