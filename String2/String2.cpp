#include <bits/stdc++.h>
#include <iostream>


using namespace std;

map<string,bool> L;

int main(){   

    int N,type,res,C;
    scanf("%d",&N);    
    
    for(int n = 0 ; n < N ; n++){
        string txt;

        scanf("%d",&type);
        cin>>txt;

        if(type == 1){
            L.insert({txt,true});
            continue;
        }else if(type == 2){
            L.erase(txt);
            continue;
        }
        
        C=0;
        for(auto& l : L){
            // res = memcmp(l.first.c_str(),
            //         txt.c_str(),
            //         txt.length());
            res = l.first.compare(0,txt.length(),txt);
            if(res == 0) C++;
        }
        printf("%d\n",C);

    }

    

    return 0;
}