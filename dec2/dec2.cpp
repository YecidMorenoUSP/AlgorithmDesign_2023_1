#include <iostream>
#include <vector>

using namespace std;


typedef struct lims{
    long a,b;
    lims(long _a = 0, long _b = 0):a(_a),b(_b){}
    void str(){
        printf("[%ld %ld] \n",a,b);
    }
}lims;

long findSong(vector<long> & V, long v, lims l){

    if(l.a == l.b){
        return l.a;
    }

    long m = (l.a+l.b)/2l;

    if(v <= V[m]){
        return findSong(V,v,lims(l.a,m));
    }
    else {
        return findSong(V,v,lims(m+1l,l.b));
    }

    
}

int main()
{

    long N,M,c,t,v;

    scanf("%ld %ld",&N,&M);

    vector<long> V(N+1);
    V[0] = 0;

    for(long n = 1 ; n <= N ; n++){
        scanf("%ld%ld", &c, &t);
        V[n] = V[n-1] + c*t;
    }

    
    long song;
    for(long i = 0 ; i < M ; i++)
    {
        scanf("%ld",&v);
        
        song = findSong(V,v,lims(0,N));
               
        printf("%ld\n",song);
        // printf("%10ld | %10ld -> %10ld %10ld %10ld\n",v,song, V[song-1],V[song],V[song+1] );
        
    }

    return 0;
}