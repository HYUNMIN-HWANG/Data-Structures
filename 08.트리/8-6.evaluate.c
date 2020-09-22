//트리 응용 : 수식 트리 처리
//후위 순회 방식 이용

#include <stdio.h>
#include <stdlib.h>

//트리 구조체 정의
typedef struct TreeNode {                       
    int data ;
    struct TreeNode *left, *right ;
} TreeNode ;

//       +
//   *      +
// 1  4   16  25

TreeNode n1 = {1, NULL, NULL} ;
TreeNode n2 = {4, NULL, NULL} ;
TreeNode n3 = {'*', &n1, &n2} ;
TreeNode n4 = {16, NULL, NULL} ;
TreeNode n5 = {25, NULL, NULL} ;
TreeNode n6 = {'+', &n4, &n5} ;
TreeNode n7 = {'+', &n3, &n6} ;
TreeNode *exp = &n7 ;

//수식 계한 함수
int evaluate (TreeNode *root) {
    if (root == NULL) 
        return 0 ;
    if (root->left == NULL && root->right == NULL) 
        return root->data ;
    else {
        int op1 = evaluate(root->left) ;
        int op2 = evaluate(root->right) ;
        printf("%d %c %d을 계산합니다. \n", op1, root->data, op2) ;

        switch (root->data) {
        case '+':
            return op1 + op2 ;
        case '*' :
            return op1 * op2 ;
        case '-' :
            return op1 - op2 ;
        case '/' :
            return op1 / op2 ;
        }
    }
    return 0 ;
}

int main (void) {
    printf("수식의 값은 %d입니다. \n", evaluate(exp)) ;
    return 0 ;
}

// 출력 결과
// 1 * 4을 계산합니다. 
// 16 + 25을 계산합니다. 
// 4 + 41을 계산합니다. 
// 수식의 값은 45입니다.