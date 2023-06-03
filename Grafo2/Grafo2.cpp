#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

#define DEBUG 0

#define ll long long

using namespace std;

typedef struct{   
    int a,b;
    ll w;
}arc;


int N,M;
int a,b;
ll sum = 0;
ll w;

vector<arc> arcs;
vector<int> opt;

int find(int u){
    if(opt[u] < 0)   return u; 
    opt[u] = find(opt[u]);
    return opt[u];
}

bool merge(int u, int v){
    
    u = find(u); v = find(v);
    
    #if DEBUG
        printf("u: %3d v: %3d\n",u,v);
    #endif
    if(u == v)  return false;

    opt[v] = opt[u];
    opt[u] = v;

    return true;
}

int main(){
               
    scanf("%d %d",&N,&M);
    arcs.resize(M);
    opt.resize(M+1);
    fill(opt.begin(),opt.end(),-1);

    for (int i = 0; i < M; i++){
        scanf("%d %d %lld",&arcs[i].a,
                           &arcs[i].b,
                           &arcs[i].w);
    }

    sort(arcs.begin(),arcs.end(),[](arc A, arc B){
        return A.w < B.w;
    });

    #if DEBUG
    sum = 0;
    for(auto& o : arcs){
        printf("%4d %4d %4lld %4lld\n",o.a,o.b,o.w,sum);
        sum+=o.w;
    }
    printf("--------\n");
    #endif

    sum = 0;
    for(int i = 0; i < M; i++){
        arc cur = arcs[i];
        if(merge(cur.a, cur.b)){
            sum += cur.w;
            N--;
        }
    }

    if(N == 1)  printf("%lld\n", sum);
    else        printf("IMPOSSIBLE\n");
        
    return 0;
}