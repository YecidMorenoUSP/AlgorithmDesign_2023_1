#include<iostream>


int main(){

    int N,S,X,s;
    scanf("%d ",&N);


    for (int n = 0; n < N; n++){
        scanf("%d ",&S);
        X = 0;        
        for (int si = 0; si < S; si++){
            scanf("%d ",&s);
            X ^= s;
        }
        printf("%d\n",X==0);
    }
    

    return 0;
}