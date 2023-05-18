#include <iostream>
#include <vector>

#define int_ unsigned long long int
#define for_(A,N) for(int A = 0 ; A < N ; A++)
#define for_i for_(i,N)
#define for_j for_(j,N)

#define OK '.'

using namespace std;

typedef struct Point{   
    int x,y;
    Point():x(0),y(0){}
    Point(int _x,int _y):x(_x),y(_y){}
    bool isPositive(){
        return this->x >= 0  && this->y >= 0;
    }
}Point;

Point operator+(Point& A, Point& B){
    return *new Point(A.x+B.x,A.y+B.y);
}
Point operator-(Point& A, Point& B){
    return *new Point(A.x-B.x,A.y-B.y);
}


Point DIR[2] = {Point(0,1),Point(1,0)};

template<typename Tchar>
class Table{
    public:
        int N;
        vector<vector<Tchar>> M;
        vector<vector<int_>> S;
        Table(){}
        void fill_stdin(){
            scanf("%d ",&N);
            M.resize(N);
            S.resize(N);

            for_i{
                M[i].resize(N);
                S[i].resize(N);
                fill(S[i].begin(),S[i].end(),-1);
            }
            for_i for_j scanf("%c ",&M[i][j]);  
        }
        void print_M(){
            for_i{
                for_j printf("%c",M[i][j]);
                printf("\n");
            }
        }
        void print_S(){
            for_i{
                for_j printf("%6lld ",S[i][j]);
                printf("\n");
            }
        }
        Tchar& operator[](Point p){
            return M[p.x][p.y];
        }
        
        bool isValid(Point p){
            return p.isPositive() && 
                    p.x < N && p.y < N;
        }

        bool isOk(Point p){
            return isValid(p) && (*this)[p] == OK ;
        }

        int_& solve_of(Point p){
            return S[p.x][p.y];
        }
};

Table<char>& T = *new Table<char>();

int_ solve(Point p){
    
    if(!T.isValid(p)) return 0;
    
    int_& S = T.solve_of(p);

    if(S != -1ULL) return S;

    if(p.x == 0 && p.y == 0) S=1;
    else if (!T.isOk(p)) S = 0;
    else{
        Point p0, p1;
        p0 = p - DIR[0];
        p1 = p - DIR[1];

        S = solve(p0) + solve(p1);
    }
    
    S = S%(1000000007ULL);

    return S;
}

int main(){    


    T = *new Table<char>();
    T.fill_stdin();    

    int_ res = solve(Point(T.N-1,T.N-1));

    printf("%lld\n",res);    

    return 0;
}