#include<iostream>
#include<vector>

using namespace std;

typedef struct lims{
    int a,b;
    lims(int _a = 0, int _b = 0):a(_a),b(_b){}
    void str(){
        printf("[%d %d]",a,b);
    }
}lims;


void dec(vector<int> & V, lims l, int & min){
       
    if(l.a == l.b){
        if(V[l.a] <= min || min == -1)
            min = V[l.a];
        return;
    }

    int m = (l.a+l.b)/2;

    dec(V,lims(l.a,m),min);
    dec(V,lims(m+1,l.b),min);
        
}


int main(){

    int N,min;
    lims l;

    scanf("%d",&N);
    vector<int> V(N);

    for(auto & v : V){
        scanf("%d",&v);
    }

    
    

    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d %d",&l.a,&l.b);
        
        min = -1;
        dec(V,l,min);
        printf("%d\n",min);
    }

    


    return 0;
}