#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

enum{
    _NULL = -1,
    _VISITED = 1,
    _BEGIN = 2,
};

#define VERBOSE 2

#define S0 "\x1B[37m\u25A0 " 
#define S1 "\x1B[32m\u25A0 "
#define S3 "\x1B[35m\u25A0 "

#define iterate_M for(int i = 0 ; i < SZ ; i++) \
                  for(int j = 0 ; j < SZ ; j++)\

#define set_M(A) iterate_M *M_ptr(point(i,j)) = A;

#define SZ 8

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

bool operator == (point A , point B ){
    return (A.x==B.x) && (A.y==B.y);
}

int M[SZ][SZ] = {0};

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
        printf("    ");
        for(int number = 0 ; number < 2 ; number++){
            for(int j = 0 ; j < SZ ; j++){     
                    if(p.x == i && p.y == j){
                        if(number)
                            printf("\x1B[35m%4d",(M[i][j]));
                        else
                            printf("%2s",S3);
                    }else{
                        if(number)
                            printf("\x1B[37m%4d",(M[i][j]));
                        else
                            printf("%2s",(M[i][j]>0)?S1:S0);
                    }            
            }
            printf("  |  ");
        }
        printf("\n");
    }
    fflush(stdout);
}

void setM(point p,int v){
    M[p.x][p.y] = v;
}

point movePoint(point p,int n){
    return (p+directions[n]);
}

bool isVisited(point p){
    return (M[p.x][p.y]>=_VISITED);
}

bool isOK(point p){
    return (p.x>=0) && (p.y>=0) && (p.x<SZ) && (p.y<SZ); 
}   

void printPoint(point p, char * txt = (char *)""){
    printf("[%2d,%2d]%s",p.x,p.y,txt);
}


bool isNextMoves(point p1, point p2){
    for(int i = 0 ; i < 8 ; i++){
        if(p2 == movePoint(p1,i) ){
            return true;
        }
    }
    return false;
}

void findPath(point p, stack<point> &_path, int count = 1){
    
    point p_;
    static int solves = 0;
    static point p0;

    if(count == (SZ*SZ)){       
        if(isNextMoves(p,p0)){
            printf("Solution found!!! : %d\n",++solves); 
            _path.push(p);
        }        
    }    

    if(solves) return;
       
    if(count == 1) p0 = p;

    *M_ptr(p) = _VISITED;   

    for(int i = 0 ; i < 8 ; i++){
        p_ = movePoint(p,i);
        
        if(isOK(p_)&&!isVisited(p_)){ 
            
            findPath(p_,_path,count+1);

            if(solves){
                _path.push(p);
                break;
            }
            
        }

    }

    *M_ptr(p) = _NULL;
    
}



typedef struct vertex
{   
    point pos;
    int depth;
}vertex;


int h(point p){
    static int count;
    static point p_;
    count = 0;
   for(int i = 0 ; i < 8 ; i++){
        p_ = movePoint(p,i);
        if(isOK(p_) && !isVisited(p_)){
            count ++;
        }
   }

    return count;
}

void findPathA(point p,stack<point> &_path, int count = 1){
    point p_, p_next, p0 , p_max;
    int i;
    
    p0 = p;
    p_next = p;

    for(i = 0 ; i < SZ*SZ ; i++){

        *M_ptr(p_next) = _VISITED;
        _path.push(p_next);

        int min_h = SZ+1, aux_h;
        int s = rand()%SZ;

        for(int j = 0 ; j < SZ ; j++){
            p_ = movePoint(p_next,(j+s)%SZ);

            if(isOK(p_) && !isVisited(p_)){
                aux_h=h(p_);
                if(aux_h<=min_h){
                    min_h = aux_h;
                    p_next = p_;
                    p_max = p_;
                }
            }
        }

        if(min_h == ( SZ+1)) {
            break;
        }     

    }

    if(i == SZ*SZ-1 && isNextMoves(p_next,p0)){
        printf("Solution found!!!");
    }else{
        _path = stack<point>();
    }
    
}

void animate(stack<point>  _path, bool sec = true, bool clear = false){
    static point p;
    static int count = 0;
    set_M(_NULL);
    count = 0;
    
    while (!_path.empty())
    {           
        p = _path.top();
        *M_ptr(p) = ++count;        
        
        if(sec){
            system("sleep .1");
            if(clear)system("clear");
            printM(p);    
        }        

        _path.pop();
    }          
    if(!sec)printM(p);
}

int main(){
    
    srand(time(NULL));

    stack<point> _path0;
    stack<point> _path1;

    system("clear");
    point p0(1,1);
    
    int xr,yr;

    while(true){
        xr = rand(),yr = rand();
        p0 = point((xr)%SZ,(yr)%SZ);
        
        system("clear");
        printf("Finding solution for :");
        printPoint(p0,(char *)"\n");       

        _path1 = stack<point>();
        set_M(_NULL);
        findPathA(p0,_path1); 
        if(_path1.size()!=0){
            break;
        }
    }
    
    // p0 = point(1,1);
    
    set_M(_NULL);
    findPath(p0,_path0); 
        
    #if VERBOSE >= 2

        animate(_path0,false,false);

        animate(_path1,false,false); 
         
    #endif

    
    return 0;
}