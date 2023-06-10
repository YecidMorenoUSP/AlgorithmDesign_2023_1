#include <iostream>
#include <bits/stdc++.h>

#define INF 1000+1
#define MAX_A 100+1

using namespace std;

vector<vector<int>> jp;
vector<vector<int>> arcs;

void findPaths(double& clicks_avr){

    int sum   = 0;
    int count = 0;

    int depth = 1;
    bitset<MAX_A> visited;
    queue<int> q;

    for(int i = 1 ; i < MAX_A ; i++){

        depth = 1;
        visited = bitset<MAX_A>();
        q = queue<int>();

        q.push(i);
        visited.set(i);

        while (!q.empty()){
            int u = q.front();
            q.pop();

            for(auto& v : arcs[u]){
                if( !visited.test(v)){
                    visited.set(v);
                    q.push(v);
                    
                    jp[i][v] = jp[i][u]==INF? 1 : jp[i][u]+1;

                    sum += jp[i][v];
                    count ++;

                }
            }

            depth++;
        }
        
    }
    clicks_avr = (double)sum/count;
}

void findPaths2(){
    for (int k = 1; k < MAX_A; ++k)
            for (int i = 1; i < MAX_A; ++i)
                for (int j = 1; j < MAX_A; ++j)
                    jp[i][j] = min(jp[i][j], jp[i][k] + jp[k][j]);            
}

double getClicksAvr(){
    int sum   = 0;
    int count = 0;
    for(int i = 1 ; i < MAX_A ; i++){
        for(int j = 1 ; j < MAX_A ; j++){

            if(i!=j && jp[i][j]!=INF){
                sum+=jp[i][j];
                count++;
            }
        }
    }

    return (double)sum/count;
}

int fillStd(){
    int n_arcs = 0;
    int n0,n1;

    jp.assign(MAX_A, vector<int>(MAX_A,INF));
    arcs.assign(MAX_A, vector<int>());

    fill(jp.begin(),jp.end(),vector<int>(MAX_A,INF));

    while (scanf("%d %d",&n0,&n1)>0 && n0!=0 && n1!=0){
        arcs[n0].push_back(n1);
        jp[n0][n1] = 1;
        n_arcs++;    
    } 
    return n_arcs;
}

int main(){

    static int n_case = 1;  
    double clicks_avr = 0;

    // if(n_case == 2) return 0;
       
    if(fillStd()==0) return 0;

    findPaths(clicks_avr); 
    
    // findPaths2(); 
    // clicks_avr = getClicksAvr();


    printf("Case %d: average length between pages = %.3f clicks\n",n_case++,clicks_avr);   
    // printf("Case 1: average length between pages = 1.917 clicks\n\n");

    main();

    return 0;
}