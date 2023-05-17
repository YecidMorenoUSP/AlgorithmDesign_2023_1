#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef struct ticket{
    int days;
    int price;
    ticket(int _d , int _p):days(_d),price(_p){}
    ticket(){}

}ticket;

vector<ticket> T = {ticket(1,0),ticket(7,0),ticket(30,0)};
vector<int> D;
vector<int> dp;

/*
4
5 10 6
1 32 34 35
*/

int solve(int N){
    
    int i,s = INT_MAX;
    
    if(N >= (int)D.size()) return 0;
    if(dp[N] != -1) return dp[N];
    
    for(auto &t : T){
      for(i = N ; i < (int)D.size() && D[i]<D[N]+t.days ; i++)
        s = min(s,t.price + solve(i+1));  
    }
    
    // printf("N: %3d   S: %3d\n",N,s);
    
    return dp[N] = s;
}

int main() {
    int N;
    scanf("%d",&N);    
    
    for(int i = 0 ; i < 3 ; i++)
        scanf("%d",&T[i].price);
    
    dp.resize(N);
    fill(dp.begin(),dp.end(),-1);

    D.resize(N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&D[i]);
    
    printf("%d\n",solve(0));
}