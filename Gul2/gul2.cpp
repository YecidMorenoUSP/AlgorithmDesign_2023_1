#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N_b , N_s , N_case=0, min_b, aux;
    vector<int> B;
    // vector<int> S;

    while (true){
        
        min_b = 10000+1;

        scanf("%d %d",&N_b,&N_s);    
        if(N_b == 0 && N_s == 0) break;

        printf("Case %d: ",++N_case);      

        B.resize(N_b,0);
        // S.resize(N_s,0);

        for(int i = 0 ; i < (N_b) ; i++){
            scanf("%d",&B[i]);   
            if(B[i] < min_b) min_b = B[i];
        }

        for(int i = 0 ; i < (N_s) ; i++){
            // scanf("%d",&S[i]);
            scanf("%d",&aux);
        }

        if(N_b<=N_s) printf("0 \n");
        else printf("%d %d \n",N_b-N_s , min_b);

    }
    
    

    return 0;
}