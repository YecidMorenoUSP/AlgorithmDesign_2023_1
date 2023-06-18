#include <iostream>

using namespace std;

int main() {

    int T;
    int N,B;
    int i;int a_i;

    int to_cat;
    int to_friends;
    int cat_count;
    
    for(cin>>T ; T > 0 ; T--){
        to_cat = 0;
        for(cin>>N>>B ; B > 0 ; B--){
            cat_count = 1;
            to_friends = 1;
            for(cin>>i; i > 0 ; i--){
                cin>>a_i;
                to_friends *= a_i;
                cat_count  = to_friends%N;
                to_friends = cat_count%N;
            }
            to_cat = (to_cat+cat_count)%N;
        }      
        cout<<to_cat<<endl;  
    }   
    return 0;
}