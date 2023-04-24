#include<iostream>
#include<stdio.h>
#include<vector>
#include<list>

#define OFF 'X'
#define ON  ' '
#define VISITED '*'
#define NO_VISITED ON

#define VERBOSE 2
 
using namespace std;

int R,C;
typedef struct point {

    int x,y;

    point(int _x,int _y):x(_x),y(_y){}

    point operator+(point * b){
        return point(this->x + b->x,this->y + b->y);         
    }  

    point operator+(point b){
        return point(this->x + b.x,this->y + b.y);         
    }   

}point;

point dir[3] = {point(0,-1),point(1,0),point(-1,0),};


long count = 0;

void print_M(int ** M){
        system("sleep 0.1");
        system("clear");    
        printf("-------%ld------\n",count++);
        for(int r = 0 ; r < R ; r++){
            for(int c = 0 ; c < C ; c++){
                printf("%c",M[r][c]);
            }
            printf("\n");
        }   
        printf("\n\n");
}
bool isValid(int ** M,point p){
    return ! (p.x<0||p.y<0 || p.x>=R || p.y>=C);
}
bool isBoom(int ** M,point p){
    return M[p.x][p.y] == OFF;
}
void setOFF(int ** M,point p){
    if(!isValid(M,p)) return;
    M[p.x][p.y] = OFF;
}

unsigned long min_iter = 0;
unsigned long solves = 0;






list<point> points_min;
void findPath(int ** M,int RR,int CC,unsigned long iter, bool first = false){
    
    static list<point> points;

    // Recorrer cada una de las filas de la matriz
    for(int i = (RR) ; i >= 0 && first ; i--)
        findPath(M,i,CC,1);
    
    // Si ha llegado al objetivo
    if(CC == 0){
        return;
    }   
    
    // Si le iteracion actual es mayor que la minima ya encontrada
    if(iter >= min_iter && min_iter>0){
        return;
    }
        

    point pos(0,0);

    // Ejecutar los 3 posibles movimientos por cada celda
    for(int p = 0 ; p < 3 ; p++){
        // Dislocarse 

        pos = point(RR,CC)+dir[p];

        // Verificar que el movimiento es valido y que no explotará
        if(isValid(M,pos) && !isBoom(M,pos)){
            // Si ya ha sido visitado, evitelo
            if(M[pos.x][pos.y] == VISITED) continue;
            points.push_back(pos);
            // Marcar celda visitada
            M[pos.x][pos.y] = VISITED;
            #if VERBOSE >= 2
                print_M(M);
            #endif
            findPath(M,pos.x,pos.y,iter+1);
            // Si el final es la columna 0, es porque ha llegado al destino
            if(pos.y == 0){
                if(solves++ == 0 || iter<min_iter){
                    min_iter = iter;
                    
                    points_min = points;

                    #if VERBOSE
                        print_M(M);
                    #endif
                    for(auto &p : points){
                        printf("[%d,%d] ",p.x,p.y);
                    }
                    printf("\n");
                }
            }   
            // Liberar la celda visitada
            M[pos.x][pos.y] = NO_VISITED;
            points.pop_back();
        }
    }  
}


int main(){


    #if VERBOSE
        system("clear");
        struct timespec *t0, *t1;
        t0 = (struct timespec *)malloc(sizeof(t0));
        t1 = (struct timespec *)malloc(sizeof(t1)); 

        clock_gettime(CLOCK_MONOTONIC, t0);
    #endif

    int aux;
    
    scanf("%d %d",&R,&C);

    int ** M;
    M = new int * [R];
    for(int r = 0 ; r < R ; r++){
        M[r] = new int [C];
    }

    

    for(int r = 0 ; r < R ; r++){
        for(int c = 0 ; c < C ; c++){
            scanf("%d",&aux);
            point p(r,c);
            if(aux==0){
                setOFF(M,p);
                setOFF(M,point( 0,-1)+p);
                setOFF(M,point( 0, 1)+p);
                setOFF(M,point(-1, 0)+p);
                setOFF(M,p + point( 1, 0));
            }

            if(M[r][c]!=OFF){
                M[r][c] = ON;
            }else{
                M[r][c] = OFF;
            }
        }
    }

    findPath(M,R-1,C-1,1,true);

    #if VERBOSE
        printf("Solves: %ld\n",solves);
    #endif

    if(min_iter == 0)
        printf("Nao ha caminho valido\n");
    else
        printf("Comprimento da rota = %lu\n",min_iter);

    #if VERBOSE
        
        clock_gettime(CLOCK_MONOTONIC, t1);

        printf("Time %fs \n",(t1->tv_nsec-t0->tv_nsec)/1e9f);
    #endif

    return 0;
}