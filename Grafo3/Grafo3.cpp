#include<iostream>
#include<algorithm>
#include<vector>

#define DEBUG 0
#define pii pair<int,int>

using namespace std;

vector< pii > V;
vector<int> team;
vector<int> near;

int N,M;
int a,b;

int main(){

    scanf("%d %d",&N,&M);
    V.resize(M);
    team.resize(N+1);
    near.resize(N+1);

    fill(team.begin(),team.end(),0);
    fill(near.begin(),near.end(),0);

    for(int i = 0 ; i < M ; i++){
        scanf("%d %d",&a,&b);
  
        V[i].first  = min(a,b);
        V[i].second = max(a,b);
       
    }

    sort(V.begin(),V.end(),[](pair<int,int>& a, pair<int,int>& b){
        return a.first < b.first;
    });

    for(int i = 0 ; i < M ; i++){
        near[ V[i].first  ]++;
        near[ V[i].second ]++;
    }

    for(int i = 1 ; i <= N ; i++){
        if(near[ i ] == 0){
            team[i] = 1;
        }
    }
    

    team[0] = 1;
    team[1] = 1;
    int updated = 1;
    int i=0,k=0,j=1;


    bool END = false;
    int good = 0;
    int firstbad = 0;

    for( ; i < M ; i++){

        if(END) break;
        

        updated = 0;
        good = 0;
        firstbad = 0;

       
        for( k=firstbad ; k < M ; k++){
            if(END) break;

            a = V[k].first;
            b = V[k].second;       
            

            if(team[a] == team[b] && team[b]!=0){
                printf("IMPOSSIBLE\n");
                END = true;
            }else
            if(team[a] != 0 && team[b] != 0){
                good++;
                continue;
            }

            if(firstbad!=0) firstbad = k;
            
            if(team[a] != 0 && team[b] == 0){
                team[b] = team[a]*-1; 
                // printf("Team[ %4d ]: %4d\n",b,team[b]);
                updated++;
                // near[a]--;
                // near[b]--;
            }
            else if(team[b] != 0 && team[a] == 0){
                team[a] = team[b]*-1;
                // printf("Team[ %4d ]: %4d\n",a,team[a]);
                updated++;
                // near[a]--;
                // near[b]--;
            }           

        }

        // printf("UPDATED %4d  j: %4d \n",updated,j);

        if(good == M){
                break;
        }else
        if(updated==0){         
     
            // for( int k=firstbad ; k < M ; k++){
            //     a = V[k].first;
            //     b = V[k].second;

            //     if(near[ a ] == 2 && near[ b ] == 2 && team[a]==0 && team[b]==0){                    
            //     //    printf("a: %5d , b:%5d\n",a,b); 
            //     //    team[a] = 1;
            //     //    team[b] = -1;
            //     }

            // }
          

            for( ; j <= N ; j++){
                if(team[j]==0){
                    team[j] = 1;

                    if(near[j] == 1){
                        
                    }else{
                        
                    }
                    
                    // printf("Neast[ %4d ] : %d\n",j,near[j]);

                    break;
                    
                }
            }

            // if(j==N) END = true;
        }else{
            // printf("UPDATED %4d  j: %4d \n",updated,j);
        }

        
    }

    #if DEBUG == 1
        for(auto& v : V){
            printf("%d %d\n",v.first,v.second);
        }

        for(int i = 1 ; i <= N ; i++){
            printf("%d ",i);
        }
        printf("\n");
    #endif

    if(END) return 0;
    for(int i = 1 ; i <= N ; i++){
        printf("%d",((team[i]>=0)? team[i] : 2));
        if(i!=N)printf(" ");
        else    printf("\n");
    }
    
    

    return 0;
}