#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

#define min3(A,B,C) min(min(A,B),C);
#define str0 str[0]
#define str1 str[1]

using namespace std;

vector<string> str(2);

int LCS(int m, int n){

    /*
           0   1   2   3   4   5   6   7   8   9   10  11 
           a   v   a   d   a   k   e   d   a   v   r   a    
       0   0   0   0   0   0   0   0   0   0   0   0   0
   a   0   1   1   1   1   1   1   1   1   1   1   1   1
   b   0   1   1   1   1   1   1   1   1   1   1   1   1
   r   0   1   1   1   1   1   1   1   1   1   1   2   2
   a   0   1   1   2   2   2   2   2   2   2   2   2   3
   c   0   1   1   2   2   2   2   2   2   2   2   2   3
   a   0   1   1   2   2   3   3   3   3   3   3   3   3
   d   0   1   1   2   3   3   3   3   4   4   4   4   4
   a   0   1   1   2   3   4   4   4   4   5   5   5   5
   b   0   1   1   2   3   4   4   4   4   5   5   5   5
   r   0   1   1   2   3   4   4   4   4   5   5   6   6
   a   0   1   1   2   3   4   4   4   4   5   5   6   7
    */

   int L[m + 1][n + 1];
   memset(L,0,sizeof L);

   for (int i = 0; i <= m; i++) {
        for (int j = i; j <= n; j++) {
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (str0[i - 1] == str1[j - 1]) L[i][j] = 1;                      
            else L[i][j] = 0;
        }
    }
    
    int cl = 0;
    for (int j = 0; j <= n; j++) {
        for (int i = 0; i <= m; i++){
            if(L[i][j] == 1 && cl <= i){
                printf("%c",str0[i-1]);
                cl = i;
                j++;
            }
        }
    }

    if(!true){
        printf("\n%4c%4c",' ',' ');
        for(int j = 0 ; j <= n ; j++)
            printf("%4c",str1[j]==0?' ':str1[j]);
        printf("\n ");
        for(int i = 0 ; i <= m ; i++){
            printf("%4c",str0[i]==0?' ':str0[i-1]);
            for(int j = 0 ; j <= n ; j++){
                printf("%4d",L[i][j]);
            }
            printf("\n");
        }
    }


    return 0;
} 

int main(){
    

    cin >> str[0];
    cin >> str[1];
    
    if(str0.length()>=str1.length()){
        string aux = str0;
        str0 = str1;
        str1 = aux;
    }

    LCS(str[0].length(),str[1].length());

    printf("\n");
    
    return 0;
}