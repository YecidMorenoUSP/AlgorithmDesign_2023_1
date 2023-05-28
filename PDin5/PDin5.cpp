#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

#define min3(A,B,C) min(min(A,B),C);
#define str0 str[0]
#define str1 str[1]

#define _INSERT  val[i  ][j-1]
#define _REMOVE  val[i-1][j  ]
#define _REPLACE val[i-1][j-1]

#define _i0 ( (i - 0) % 2 )
#define _i1 ( (i - 1) % 2 )

using namespace std;

vector<string> str(2);

int editDistance(int m, int n){

    // Falta memoria

    // int val[m+1][n+1];

    // for(int i = 0 ; i <= m ; i++){
    //     for(int j = 0 ; j <= n ; j++){
    //              if(i==0) val[i][j] = j;
    //         else if(j==0) val[i][j] = i;
    //         else if(str0[i-1] == str1[j-1]) val[i][j] = val[i-1][j-1];
    //         else val[i][j] = 1 + min3(_INSERT,_REMOVE,_REPLACE);
    //     }
    // }   

    // return val[m][n];  


    /*
        Tentei procurar uma solução que não consuma tanta memoria,
        mas não tive sucesso, por isso me basei na publicação web de:
        https://www.geeksforgeeks.org/edit-distance-dp-5/

       Achei esta solução muito interessante, porque só precisa dos
       valores anteriores e guarda os actuais para o próximo loop,
       usamdo o conceito de circular array 

       _i0 é o valor atual
       _i1 é o valor anterior

       Este algoritmo é exatamente igual do que o anterior, so tem uma 
       otimização de memoria

    */

    int val[2][m+1];
    memset(val, 0, sizeof val);
 
    for (int i = 0; i <= m; i++) val[0][i] = i;
        
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){

            if( j == 0 ) val[_i0][j] = i;

            else if(str0[j-1] == str1[i-1]){
                val[_i0][j] = val[_i1][j - 1];
            }else {
                val[_i0][j] = 1 + min3(val[_i1][j    ],
                                       val[_i0][j - 1],
                                       val[_i1][j - 1]);
            }
            // printf("%d ",val[_i0][j]);
        }
    }


    return val[n % 2][m];
    
}

int main(){
    

    cin >> str[0];
    cin >> str[1];

    
    if(str0.length()>=str1.length()){
        string aux = str0;
        str0 = str1;
        str1 = aux;
    }

    // printf("%s\n",str0.c_str());
    // printf("%s\n",str1.c_str());

    printf("%d\n",editDistance(str[0].length(),str[1].length()));
    
    return 0;
}