#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

//이진 트리 구조체
typedef struct TreeNode {
    int weigh ;
    char ch ;
    struct TreeNode *left ;
    struct TreeNode *right ;
} TreeNode ;

typedef struct {
    TreeNode* ptree ;
    char ch ;
    int key ;
} element ;

//히프 구조체
typedef struct {
    element heap[MAX_ELEMENT] ;
    int heap_size ;
} Heaptype ;

//생성 함수
Heaptype* create() {
    return (Heaptype *)malloc(sizeof(Heaptype)) ;
}

//초기화 함수
void init(Heaptype *h) {
    h->heap_size = 0 ;
}

//현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
//삽입함수 (최소 히프)
void insert_min_heap (Heaptype *h, element item) {
    int i ;
    i = ++(h->heap_size) ;

    // 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1 ) && (item.key < h->heap[i/2].key)) {
        h->heap[i] = h->heap[i/2] ;
        i /= 2;
    }
    h->heap[i] = item ;     // 새로운 노드를 삽입    
}

//삭제 함수 (최소 히프)
element delete_min_heap (Heaptype *h) {
    int parent, child ;
    element item, temp ;

    item = h->heap[1] ;
    temp = h->heap[(h->heap_size)--] ;
    parent = 1 ;
    child = 2 ;
    while (child <= h->heap_size) {
        // 현재 노드의 자식 중 더 작은 자식노드를 찾는다.
        if ((child < h->heap_size) && h->heap[child].key > h->heap[child+1].key)  
            child ++ ;
        if (temp.key < h->heap[child].key) break ;
        // temp 값이 더 작을 때, 한 단계 아래로 이동
        h->heap[parent] = h->heap[child] ;
        parent = child ;
        child *= 2 ;
    }
    h->heap[parent] = temp ;
    return item ;    
}

//이진 트리 생성 함수
TreeNode *make_tree(TreeNode* left, TreeNode *right) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode)) ;
    node->left = left ;
    node->right = right ;
    return node ;
}

//이진 트리 제거 함수
void destroy_tree (TreeNode *root) {
    if(root == NULL) return ;
    destroy_tree(root->left) ;
    destroy_tree(root->right) ;
    free(root) ;
}

//단말노드인지 아닌지 확인하는 함수
int is_leaf (TreeNode *root) {
    return !(root->left) && !(root->right) ;
}

//배열 출력 함수
void print_array(int codes[], int n) {
    for (int i = 0 ; i < n ; i++) 
        printf("%d", codes[i]) ;
    printf("\n") ;
}

//코드 출력 함수
void print_codes (TreeNode *root, int codes[], int top) {
    // 왼쪽 : 1을 저장하고 순환호출한다.
    if (root->left) {
        codes[top] = 1 ;
        print_codes(root->left, codes, top+1) ;
    }
    // 오른쪽 : 0을 저장하고 순환호출한다.
    if (root->right) {
        codes[top] = 0 ;
        print_codes(root->right, codes, top+1) ;
    }
    //단말노드면 코드를 출력한다.
    if(is_leaf(root)) {
        printf("%c : ", root->ch) ;
        print_array(codes, top) ;
    }
}

//허프만 코드 생성 함수
void huffman_tree (int freq[], char ch_list[], int n) {
    int i ;
    TreeNode *node, *x ;
    Heaptype *heap ;
    element e, e1, e2 ;
    int codes[100] ;
    int top = 0 ;

    heap = create() ;
    init(heap) ;
    for (i=0 ; i<n ; i++) {
        node = make_tree(NULL, NULL) ;
        e.ch = node->ch = ch_list[i] ;  //문자 리스트
        e.key = node->weigh = freq[i] ; //문자 출연 횟수
        e.ptree = node ;
        insert_min_heap(heap, e) ;
    }
    
    for (i=1 ; i<n ; i++) {
        //최소값을 가지는 두 개의 노드를 삭제
        e1 = delete_min_heap(heap) ;
        e2 = delete_min_heap(heap) ;
        //최소값을 가진 두 노드를 합친다.
        x = make_tree(e1.ptree, e2.ptree) ;
        e.key = x->weigh = e1.key + e2.key ;
        e.ptree = x ;
        printf("%d + %d = %d \n", e1.key, e2.key, e.key) ;
        insert_min_heap(heap, e) ;
    }

    e = delete_min_heap(heap) ; //최종 트리
    print_codes(e.ptree, codes, top) ;
    destroy_tree(e.ptree) ;
    free(heap) ;
}

int main(void) {
    char ch_list[] = { 's', 'i', 'n', 't', 'e'} ;
    int freq[] = { 4, 6, 8, 12, 15} ;
    huffman_tree(freq, ch_list, 5) ;
    return 0 ;
}

/*
4 + 6 = 10 
8 + 10 = 18 
12 + 15 = 27 
18 + 27 = 45 
n : 11
s : 101
i : 100
t : 01
e : 00
*/