#include <iostream>
#include <vector> 


using namespace std;
int N,X;

vector<int>  price;
vector<int>  pages;
vector<vector<int>>  RES;

int solve(int x, int n){
    
    if(x < 0 || n < 0) return 0;

    int& S = RES[x][n];
    if(S != -1) return S;
    
    return S = (x >= price[n])?
                     max(solve(x-price[n],n-1)+pages[n],solve(x,n-1))
                    :solve(x,n-1);

    // if(x >= price[n]){
    //     S =  max(solve(x-price[n],n-1)+pages[n],solve(x,n-1));
    // }else{
    //     S =  solve(x,n-1);
    // }

    // static int c = 0;
    // printf("%4d   x:%d n:%d -> %d\n",++c,x,n,aux);

    // return S;
    
}

int main(){
    
    scanf("%d",&N);
    scanf("%d",&X);

    price.resize(N);
    pages.resize(N);

    RES.resize(X+1);
    fill(RES.begin(),RES.end(),vector<int>(N,-1));
    
    for(auto & p : price)
        scanf("%d",&p);
    for(auto & p : pages)
        scanf("%d",&p);

    int S = solve(X,N-1);

    printf("%d\n",S);

    return 0;
}