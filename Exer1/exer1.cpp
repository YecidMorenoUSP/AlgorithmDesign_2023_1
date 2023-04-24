#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>


using namespace std;

enum{
    _SINGLE = -2,
    _MARRIED = -3
};

int main(){

    int N_test,N_sub,i_in,i_idx;
    scanf("%d",&N_test);

    for(int idx = 0 ; idx < N_test ; idx++){
        scanf("%d",&N_sub);

        int WxM[N_sub];
        int MxW[N_sub];
        queue<int> m_single;       
        
        vector<queue<int>> M(N_sub);
        vector<list<int>> W(N_sub);

        
        for(int i = 0 ; i < (N_sub*2) ; i++){
            
            if(i < N_sub) {
                WxM[i] = _SINGLE;
                MxW[i] = _SINGLE;
                m_single.push(i);
            }

            scanf("%d",&i_idx);
            for(int j = 0 ; j < (N_sub) ; j++){
                scanf("%d",&i_in);
                if(i<N_sub) W[i_idx-1].push_back(i_in-1);
                else M[i_idx-1].push(i_in-1);
            } 

        }

        int w,m,m_;
        while (!m_single.empty())
        {


            m = m_single.front();
            w = M[m].front();
            M[m].pop();
            m_ = WxM[w];
            
            #ifdef VERBOSE
                printf("\n");
                printf("\n");
                printf("prop:%3d   cur:%3d  w:%3d\n",m+1,m_+1,w+1);
            #endif

            if(m_ == _SINGLE){
                WxM[w] = m_single.front();
                MxW[m] = w;
                m_single.pop();
            }else{
                
                int prop ;//= (*find(W[w].begin(),W[w].end(),m));
                int cur  ;//= (*find(W[w].begin(),W[w].end(),m_));
                
                int count = 0;
                for(auto & k : W[w]){
                    if(k==m) prop = count;
                    if(k==m_) cur = count;
                    count++;
                }
                               
                #ifdef VERBOSE
                    printf("m:%2d:%3d        m_:%2d:%3d\n",m,prop,m_,cur);
            
                    for(auto & k : W[w]){
                        printf("%d  ",(k+1));
                    }
                    printf("   \n");
                #endif

                if(cur>prop){
                    
                    m_single.push(m_);
                    MxW[m_]=_SINGLE;

                    WxM[w] = m;
                    MxW[m] = w;
                    m_single.pop();

                }else{
                    // m_single.push(m_single.front());
                    // m_single.pop();
                }
            }
            
            #ifdef VERBOSE
                for (int i = 0 ; i < N_sub ; i++)
                printf("%d %d\n",i+1,MxW[i]+1);
            #endif

        }

        for (int i = 0 ; i < N_sub ; i++)
            printf("%d %d\n",i+1,MxW[i]+1);

        
        
        //  1 | 3 4 2 1 6 7 5       1 | 4 5 3 7 2 6 1
        //  2 | 6 4 2 3 5 1 7       2 | 5 6 4 7 3 2 1
        //  3 | 6 3 5 7 2 4 1       3 | 1 6 5 4 3 7 2
        //  4 | 1 6 3 2 4 7 5       4 | 3 5 6 7 2 4 1
        //  5 | 1 6 5 3 4 7 2       5 | 1 7 6 4 3 5 2
        //  6 | 1 7 3 4 5 6 2       6 | 6 3 7 5 2 4 1
        //  7 | 5 6 2 4 3 7 1       7 | 1 7 4 2 6 5 3
        
        
        
        
        
        
        
     

    }

    return 0;
}