#include <iostream>
#include <cstring>

#define N_MAX 500
#define no_exist(A) (A == -1)

using namespace std;

long long len[N_MAX+1][N_MAX+1];

void solve_all(int N){

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){         
            for(int j = 1; j <= N; j++){

                if(len[i][j] == 0) continue;
                if( no_exist(len[i][k]) || no_exist(len[k][j]) ) continue;

                if(no_exist(len[i][j])){
                    len[i][j] = len[i][k] + len[k][j];
                }else{
                    len[i][j] = min(len[i][j], len[i][k] + len[k][j]);
                }  
            }
        }
    }      
}

int main(){
    
    int n, m, Q;
    int a, b;
    long long c;
    
    scanf("%d %d %d", &n, &m, &Q);

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++)
            len[i][j] = -1;
        len[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        scanf("%d %d %lld", &a, &b, &c);

        if(no_exist(len[a][b])){
            len[a][b] = c;    
        }else{
            len[a][b] = min(len[a][b], c);    
        }
        len[b][a] = len[a][b];
    }
    
    solve_all(n);

    for(int q = 0; q < Q; q++){
        scanf("%d %d", &a, &b);
        printf("%lld\n", len[a][b]);
    }
}