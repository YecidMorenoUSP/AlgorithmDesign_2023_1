#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>

#define MAX_N 100

using namespace std;

int find_idx(vector<char> M, char N){
    int idx = -1;
    for(int i = 0 ; i < (int)M.size() ; i++){
        if(M[i] == N) idx = i;
    }
    return idx;
}

void calculeHigher(vector<char> M ,vector<char> MM, int K, int N){
    /*
        M: Vector de datos
        MM: Vector de dator ordenado
        K: Numero de permutaciones hechas
        N: Numero maximo de permutaciones
    */

    if(K == N){
        printf("%s\n",&M[0]);
        return;
    }

    char N_M = *(MM.begin()+K);
    int idx_M = find_idx(M,N_M);
   
    M[idx_M] = M[K];
    M[K] = N_M;
    
    calculeHigher(M,MM,K+1,N);
}

int main(){

    vector<char> M(MAX_N),MM(MAX_N);
    int N;

    while (scanf("%s",&M[0])>0)
    {   
        scanf("%d",&N);
        
        M.resize(strlen(&M[0]));
        MM=M;
        
        sort(MM.begin(),MM.end(),greater<int>());     
        
        calculeHigher(M,MM,0,N);
        
        M.resize(MAX_N);
    }
    

    return 0;
}