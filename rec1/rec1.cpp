#include<iostream>
#include<stdio.h>
#include<math.h>

int N = 5;

void spaces(int n){
    if(n <= 0) return;
        printf(" ");
    spaces(n-1);
}

void printFractal(int n){
    if(n < 0) return;

    printFractal(n-1);
    
    static int s,i;

    s = pow(2,N-n)-1;
    spaces(s);   

    for(i = 0 ; i < pow(2,n) ; i++){
        printf("%d",n);
        spaces(s*2+1);
    }
    printf("\n");

    if(n == N) return;

    for(int j = 0 ; j < pow(2,N-n-1) ; j++){
        spaces(s-j-1);

        for(int k = 0 ; k < pow(2,n) ; k++){
            printf("/");
            spaces(2*j+1);
            printf("\\");
            spaces(2*s-2*j-1);            
        }   

        printf("\n");
    }
    
    
    

    
}

int main(){

    system("clear");

    printFractal(N);

    return 0;
}