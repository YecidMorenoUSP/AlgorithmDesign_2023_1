#include <iostream>
#include <stdio.h>
#include <chrono>
#include <stack>
#include <queue>

bool P0_RAND = false;

using namespace std;

enum{
    _NULL = -1,
    _VISITED = 1,
    _BEGIN = 2,
};

#define VERBOSE 1

#define S0 "\x1B[37m\u25A0 " 
#define S1 "\x1B[32m\u25A0 "
#define S3 "\x1B[35m\u25A0 "

#define iterate_M for(int i = 0 ; i < SZ ; i++) \
                  for(int j = 0 ; j < SZ ; j++)\

#define set_M(A) iterate_M *M_ptr(point(i,j)) = A;

#define SZ 8


chrono::steady_clock::time_point __time[2];
#define __tic __time[0] = std::chrono::steady_clock::now()
#define __toc __time[1] = std::chrono::steady_clock::now()
#define __getTime_us chrono::duration_cast<std::chrono::microseconds>(__time[1] - __time[0]).count()
#define __getTime_ns chrono::duration_cast<std::chrono::nanoseconds>(__time[1] - __time[0]).count()
#define __getTime_ms chrono::duration_cast<std::chrono::milliseconds>(__time[1] - __time[0]).count()


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

void findPath_BT(point p, stack<point> &_path, int count = 1){
    
    point p_;
    static int solves = 0;
    static point p0;

    if(count==1){
        solves = 0;
    }

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
            
            findPath_BT(p_,_path,count+1);

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

void findPath_WD(point p,queue<point> &_path, int count = 1){
    point p0, p_, p_next;
    int i;
    
    p0 = p;
    p_next = p0;

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
                }
            }
        }

        if(min_h == ( SZ+1)) {
            break;
        }     

    }

    if(i == SZ*SZ-1 && isNextMoves(p_next,p0)){
        printf("Solution found!!!\n");
    }else{
        _path = queue<point>();
    }
    
}

void HandorfHeuristic(point &p0, queue<point> & _path_wd){
    int xr,yr;

    point p0_c = p0;

    while(true){
        if(P0_RAND){
            p0 = point((rand())%SZ,(rand())%SZ);
        }        
        
        
        // system("clear");
        // printf("Finding solution for :");
        // printPoint(p0,(char *)"\n");       

        _path_wd = queue<point>();
        set_M(_NULL);
        findPath_WD(p0,_path_wd); 
        if(_path_wd.size()!=0){
            break;
        }
    }
}

void animate(stack<point>  _path, bool sec = true, bool clear = false,char * txt = (char *)"M:"){
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
            printf("%s\n",txt);
            printM(p);    
        }        

        _path.pop();
    }          
    if(!sec){
        printf("%s\n",txt);
        printM(p);
    }
}

void animate(queue<point>  _path, bool sec = true, bool clear = false, char * txt = (char *)"M:"){
    static point p;
    static int count = 0;
    set_M(_NULL);
    count = 0;
    
    while (!_path.empty())
    {           
        p = _path.front();
        *M_ptr(p) = ++count;        
        
        if(sec){
            system("sleep .1");
            if(clear)system("clear");
            printf("%s\n",txt);
            printM(p);    
        }        

        _path.pop();
    }          
    if(!sec){
        printf("%s\n",txt);
        printM(p);
    }
}

int main(){
    
    srand(time(NULL)); 
    
    int Nreps = 10;
    char txt[200];
    P0_RAND = false;
    long int time_wd[Nreps],time_bt[Nreps];

    stack<point> _path_bt;
    queue<point> _path_wd;

    point p0(1,1);
    system("clear");

    for(int reps = 0 ; reps < Nreps ; reps++){       

        _path_bt = stack<point>();
        _path_wd = queue<point>();
        
        __tic;
            set_M(_NULL);
            HandorfHeuristic(p0,_path_wd);   
        __toc;
        time_wd[reps] = __getTime_ms;

        __tic;
            set_M(_NULL);
            findPath_BT(p0,_path_bt); 
        __toc;
        time_bt[reps] = __getTime_ms;
            
        #if VERBOSE >= 2
            sprintf(txt,"\n>> Solution for the knight's beginning at point [%d,%d] using BackTrack",p0.x,p0.y);
            animate(_path_bt,true,true,txt);

            sprintf(txt,"\n>> Solution for the knight's beginning at point [%d,%d] using Handorf's heuristic",p0.x,p0.y);
            animate(_path_wd,true,true,txt); 
            
            system("clear") ;
        #endif

            sprintf(txt,"\n>> Solution for the knight's beginning at point [%d,%d] using BackTrack",p0.x,p0.y);
            animate(_path_bt,false,false,txt);

            sprintf(txt,"\n>> Solution for the knight's beginning at point [%d,%d] using Handorf's heuristic",p0.x,p0.y);
            animate(_path_wd,false,false,txt);
    }

        printf("\n\n>> Time results\n");
        printf("     Point  | %15s | %15s\n","Time BT [ms]","Time WD [ms]");
        for(int reps = 0 ; reps < Nreps ; reps++){
            printf("    [%2d,%2d] |   %13ld |   %13ld\n",p0.x,p0.y,time_bt[reps],time_wd[reps]);
        }
        
        printf("\n\n## Analysis of the algorithms\n\n"
              "----------------Tempo------------------------\n"
              "  >> BT :  O tempo de excecução tem poca variação, mas isso é devido que o numero de operações são sempre as mesmas, este é um algoritmo que vai ser executado sempre da mesma maneira e no mesmo ordem.\n" 
              "  >> WD :  No caso deste algoritmo, cada uma das execuções é diferente, pois ela está ligada com a aleatoridade, e tenta encontrar uma soluçáo de maneira aleatoria, ingeniosamente isso decrementa o tempo notavelmente, no peor dos casos o maior tempo vai ser o mesmo do BT\n"
              "\n"        
              "----------------Soluções---------------------\n"
              "  >> BT : Sempre é encontrada a mesma solução.\n"
              "  >> WD : Soluções diferentes são quase sempre encontradas.\n"
              "\n"      
              );
        
        printf("\n");
    
    return 0;
}