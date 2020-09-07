#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  
#include <math.h>

typedef struct Point {
    int x ;
    int y ;
} point ;

float get_distance(int x1, int y1, int x2, int y2) ;

int main (void) {
   
   point p1 ;
   point p2 ;

   p1.x = 1 ;
   p1.y = 2 ;

   p2.x = 9 ;
   p2.y = 8 ;

    int dis_x = p1.x - p2.x ;
    int dis_y = p1.y - p2.y ;
    double distance = sqrt(pow(dis_x , 2) + pow(dis_y, 2)) ;

  // float length = get_distance (p1.x, p1.y, p2.x, p2.y) ;

   printf("p1(%d, %d)\n", p1.x, p1.y) ;
   printf("p2(%d, %d)\n", p2.x, p2.y) ;
   printf("p1과 p2 사이의 거리는 %.2f\n", distance) ;
   return 0 ;
}

// float get_distance(int x1, int y1, int x2, int y2) {
//     int dis_x = x1 - x2 ;
//     int dis_y = y1 - y2 ;
//     double distance = sqrt(pow(dis_x , 2) + pow(dis_y, 2)) ;
// }


