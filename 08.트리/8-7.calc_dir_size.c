//트리 응용 : 디렉토리 용량 계산 프로그램
//후위 순회 방식 이용

#include <stdio.h>
#include <stdlib.h>

//트리 구조체 정의
typedef struct TreeNode {                       
    int data ;
    struct TreeNode *left, *right ;
} TreeNode ;

int calc_dir_size (TreeNode *root) {
    int left_size, right_size ;
    if (root == NULL) return 0 ;
    
    left_size = calc_dir_size(root->left) ;
    right_size = calc_dir_size(root->right) ;
    return (root->data + left_size + right_size) ;
}

int main (void) {
    TreeNode n4 = {500, NULL, NULL} ;
    TreeNode n5 = {200, NULL, NULL} ;
    TreeNode n3 = {100, &n5, &n4} ;
    TreeNode n2 = {50, NULL, NULL} ;
    TreeNode n1 = {0, &n2, &n3} ;
    
    printf("디렉토리의 크기 = %d\n", calc_dir_size(&n1)) ;

}

//결과 > 디렉토리의 크기 = 850