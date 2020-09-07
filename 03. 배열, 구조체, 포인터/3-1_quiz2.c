#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  
#include <math.h>

// 구조체 Point 정의
typedef struct Point {
    int x ;
    int y ;
} point ;

float get_distance(int x1, int y1, int x2, int y2) ;

int main (void) {
   
   //구조체 p1, p2 정의
   point p1 ;
   point p2 ;

   //p1 정의
   p1.x = 1 ;
   p1.y = 2 ;

   //p2 정의
   p2.x = 9 ;
   p2.y = 8 ;
   
   float length ;
   length = get_distance (p1.x, p1.y, p2.x, p2.y) ;

   printf("p1(%d, %d)\n", p1.x, p1.y) ;
   printf("p2(%d, %d)\n", p2.x, p2.y) ;
   printf("p1과 p2 사이의 거리는 %.2f\n", length) ;
   return 0 ;
}

//get_distance 함수 정의
float get_distance(int x1, int y1, int x2, int y2) {
    int dis_x = x1 - x2 ;
    int dis_y = y1 - y2 ;
    float distance = sqrt(pow(dis_x , 2) + pow(dis_y, 2)) ;
    return distance ;
}