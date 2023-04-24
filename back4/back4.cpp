#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

enum{
    _NULL = 0,
    _VISITED = 1,
    _BEGIN = 2,
};

#define VERBOSE 2

#define S0 "\x1B[37m\u25A0 " 
#define S1 "\x1B[32m\u25A0 "
#define S3 "\x1B[35m\u25A0 "

#define SZ 5

typedef struct point
{
    int x,y;
    point(int _x, int _y):x(_x),y(_y){}
    point(){}
}point;

point operator + (point & A , point & B ){
    A.x += B.x;
    A.y += B.y;
    return A;
}

int M[SZ][SZ] = {0};
list<point> q;

void M_set(point p,int v){
    M[p.x][p.y] = v;
}

int * M_ptr(point p){
    return &M[p.x][p.y];
}

point directions[8] = {point( 1, 2),
                       point( 1,-2),
                       point(-1, 2),
                       point(-1,-2),
                       point( 2, 1),
                       point( 2,-1),
                       point(-2, 1),
                       point(-2,-1)};

void printM(point p = point(-1,-1)){
    printf("\n");
    for(int i = 0 ; i < SZ ; i++){
        for(int j = 0 ; j < SZ ; j++){
            // printf("%2s",(M[i][j])?S1:S0);

            
                if(p.x == i && p.y == j){
                    printf("%2s",S3);
                }else{
                    printf("%2s",(M[i][j])?S1:S0);
                    // printf("\x1B[37m%2d",(M[i][j]));
                }            
        }
        printf("\n");
    }
}

void setM(point p,int v){
    M[p.x][p.y] = v;
}

point movePoint(point p,int n){
    return (p+directions[n]);
}

bool isOK(point p){
    return (p.x>=0) && (p.y>=0) && (p.x<SZ) && (p.y<SZ) && (M[p.x][p.y]==_NULL); 
}   

void printPoint(point p){
    printf("[%2d,%2d]",p.x,p.y);
}

void findPath(point p, int count = 0){

    static int solves = 0;

    if(count == (SZ*SZ-1)){
        printf("count: %d\n",++solves); 
        printM(p);
        return;   
    }
    if(solves) return;
       
    point p_;

    for(int i = 0 ; i < 8 ; i++){
        
        *M_ptr(p) = count+1;

        p_ = movePoint(p,i);
        
        if(isOK(p_)){ 
            
            
            *M_ptr(p) = _VISITED;

            findPath(p_,count+1);

            #if VERBOSE >= 2
                if(solves == 1){
                    system("sleep 0.1");
                    system("clear");
                    printM(p);
                }
            #endif
        }

        *M_ptr(p) = _NULL;
                  
    }


}


typedef struct vertex
{   
    point pos;
    int depth;
}vertex;


int h(){
    static int count;

    count = 0;
    for(int i = 0 ; i < SZ ; i++)
    for(int j = 0 ; j < SZ ; j++)
        if(M[i][j]!=0) count++;

    return (SZ*SZ)-count;
}

void findPathA(point p, int count = 0){

    *M_ptr(p) = _VISITED;
    
}

int main(){

    system("clear");
  

    for(int i = 0 ; i < SZ ; i++)
    for(int j = 0 ; j < SZ ; j++)
    *M_ptr(point(i,j)) = _NULL;

    point p0(2,2);

    findPath(p0);  


    

    return 0;
}