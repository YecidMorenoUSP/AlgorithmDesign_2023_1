#include<iostream>
#include<string.h>

using namespace std;

int main(){

    int N;
    int p_idx;   
    scanf("%d ",&N);

    string str_in;
    char P_l[2];
    char P_l_1[2];

    for (int n = 0; n < N; n++){
       cin>>str_in;

       P_l_1[0] = 'a'-1;
       P_l_1[1] = 'z'+1;

       p_idx = 0;
       for(auto& l : str_in){
    
        if(l != P_l_1[p_idx]){         

           if(p_idx==0){
                P_l[p_idx] = (l=='a')?'b':'a';    
           }
           else {
                P_l[p_idx] = (l=='z')?'y':'z';    
           }

           P_l_1[p_idx] = l;
            
        }
                   
        printf("%c",P_l[p_idx]) ;
        p_idx =(p_idx+1)%2;
       }
       
       printf("\n");
    }
    

    return 0;
}