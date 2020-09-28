//인접 리스트를 이용한 그래프 추상 데이터 타입의 구현

#include <stdlib.h>
#include <stdio.h>

#define MAX_VERTICES 50
typedef struct GraphNode {
    int vertex ;
    struct GraphNode *link ;
} GraphNode ;

typedef struct GraphType {
    int n ;                                 //정점의 개수
    GraphNode *adj_list[MAX_VERTICES] ;     //각 정점마다 필요한 연결 리스트
} GraphType ;

//그래프 초기화
void init (GraphType *g) {
    int v ;
    g->n = 0 ;
    for (v=0 ; v<MAX_VERTICES ; v++)
        g->adj_list[v] = NULL ;
}

//정점 삽입 연산
void insert_vertex (GraphType *g, int v) {
    if (((g->n)+1) > MAX_VERTICES) {
        fprintf(stderr, "그래프 : 정점의 개수 초과") ;
        return ;
    }
    g->n++ ;
}

// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다. (정점 u에서 정점 v로 가는 간선 삽입)
void insert_edge (GraphType *g, int u, int v) {
    GraphNode *node ;
    if (u > g->n || v > g->n ) {
        fprintf(stderr, "그래프 : 정점 번호 오류") ;
        return ;
    }
    node = (GraphNode *)malloc(sizeof(GraphNode)) ;
    node->vertex = v;
    node->link = g->adj_list[u] ;
    g->adj_list[u] = node ;
}

//연결 리스트 그래프 출력
void print_adj_list (GraphType *g) {
    for (int i=0 ; i<g->n ; i++) {
        GraphNode *p = g->adj_list[i] ;
        printf("정점 %d의 인접 리스트", i) ;
        while (p != NULL) {
            printf("-> %d", p->vertex) ;
            p = p->link ;
        }
        printf("\n") ;
    }
}

int main() {
    GraphType *g ;
    g = (GraphType *)malloc(sizeof(GraphType)) ;
    init(g) ;
    for(int i = 0 ; i<4 ; i++) 
        insert_vertex(g, i) ;
    insert_edge(g, 0, 1) ;
    insert_edge(g, 1, 0) ;
    insert_edge(g, 0, 2) ;
    insert_edge(g, 2, 0) ;
    insert_edge(g, 0, 3) ;
    insert_edge(g, 3, 0) ;
    insert_edge(g, 1, 2) ;
    insert_edge(g, 2, 1) ;
    insert_edge(g, 2, 3) ;
    insert_edge(g, 3, 2) ;
    print_adj_list(g) ;
    free(g) ;
    return 0;
}

/*
정점 0의 인접 리스트-> 3-> 2-> 1
정점 1의 인접 리스트-> 2-> 0
정점 2의 인접 리스트-> 3-> 1-> 0
정점 3의 인접 리스트-> 2-> 0
*/