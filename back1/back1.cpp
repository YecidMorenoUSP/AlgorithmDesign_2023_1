#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<math.h>

#define MAX_N 100

using namespace std;
int b[MAX_N] = {0};

void bin(int n,int * b,long idx)
{
    if (n > 1) bin(n >> 1,b,idx+1);
    b[idx] = n & 1;
}

void addSpace(char * C, int N, long O){
    
    if(O == pow(2,N-1)){
        printf("\n");
        memset(b,0,sizeof(b));
        return;
    }
    
    bin(O,b,0);
    
    if((O+1) == pow(2,N-1) || true){
        for(int i = 0 ; i < N ; i++)
        printf(b[N-i-2]==1?"%c ":"%c",C[i]);
        printf("\n");
    }
    
    addSpace(C,N,O+1);
}

int main(){

    char C[MAX_N];
    while(scanf("%s",C)>0){
        addSpace(C,strlen(C),0);        
    }

    return 0;
}