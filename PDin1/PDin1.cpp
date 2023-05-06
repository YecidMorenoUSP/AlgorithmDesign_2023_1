#include<iostream>
#include<vector>
#include<math.h>

#define base long long
#define base_f "%lld"
#define base_f10 "%10lld"
#define base_f4 "%4lld"
#define base_read(A) scanf(base_f,& A);
#define base_print(v) printf(base_f,v);
#define base_println(v) printf(base_f "\n",v);
#define base_v vector<base>

using namespace std;

base_v V;
base_v RES;

base s = 0;

base cal(base n, base i){
    
    // printf("return abs( " base_f4 " - " base_f4 " ) = " base_f4 "\n" 
    //        ,V[n]
    //        ,V[n-i]
    //        ,abs( V[n] - V[n-i] ) );

    return abs( V[n] - V[n-i] );
}

base solve(base n){

    static base r = 0;
    base sa,sb,a,b;

    if(RES[n] != -1) return RES[n];

         if(n == 0) r = 0;
    else if(n == 1) r = cal(1,1);
    else{

        a = cal(n,1);
        b = cal(n,2);    

        sa = solve(n-1)+a;
        sb = solve(n-2)+b;

        if(sb < sa) r = sb;
        else r = sa;

        if(sb < sa) s+=b;
        else s+=a;
    
        // printf("\n  a: " base_f10 "  b: " base_f10 "\n",a,b);
        // printf(  " sa: " base_f10 " sb: " base_f10 "\n",sa,sb);

    }
    // printf(base_f10 " -> " base_f10 "\n", n , r); 
    RES[n] = r;
    return r;
    
}

int main(){

    base N;
    base_read(N);
    
    RES.resize(N);
    fill(RES.begin(),RES.end(),-1);

    V.resize(N);
    for(auto & v : V)
        base_read(v);

    base_println(solve(N-1));

    return 0;
}