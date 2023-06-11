#include<iostream>
#include <bits/stdc++.h>

#include "cube.h"

#include "cube.cpp"

using namespace std;

Cube cube;
Cube cubeSolve;
Cube cubeSolve_1;

map< array_6_3_3 ,bool> visited;
queue<char> seq;
// array<array_6_3_3,2> V;

void findSolve(Cube cube,queue<char> seq){

    vector<char> S;
    S.push_back(0);
    
    Cube cur = cube;
    
    int count_v  = 0;
    int count_nv = 0;

    while (true){ 
        
        cur = cube;
        for(auto& s : S){
            cur.move(moves[(int)s]);
        }

        if(cur == cubeSolve){
            printf("Found\n");
            for(auto& s : S){
                printf("%4c",moves[(int)s]);
            }
            printf("\n");
            printf("count_v  %d\n",count_v  );
            printf("count_nv %d\n",count_nv );
            break;
        }

        if(visited[cur.DATA]) count_v++;
        else{
            visited[cur.DATA] = true;
            count_nv++;
        }

        
        // printf("\n");        
        

        int sz = S.size();

        int c = sz-1;
        while (true){    
            if((S[c]+1)%12==0){
                S[c] = 0;
                if(c == 0){
                    S.push_back(0);
                    break;
                }
                c--;
                continue;
            }else{
                S[c]++;
                break;
            }
            
        }
          
                   
        if(S.size()>=10) break;

    }

    
    
}


void findSolve2(Cube cube,queue<char> seq){
    
    visited.clear();
    list<vector<char>> S;

    int r = 0;rand()%100;
    for(int i = 0 ; i < 12 ; i++){
        S.push_back({moves[ (i+r)%12  ]});
    }
    
    
    
    vector<char> cur_s;
    Cube cur = cube;
    
    int H = 0;
    int h = 0;

    cur = cube;
    visited[cur.DATA]=true;

    int loops = 0;
    while(!S.empty()){
        // if(loops++ >= 4) break;

        
        cur_s = S.front();
        if(cur_s.size()>8) break;

        h = 0;
        int count_h = 1;

        cur = cube;
        for(auto& val : cur_s){
            cur.move(val);
            h += (cur/cubeSolve)*count_h;
            count_h++;
        }
        
        // if(h>H){
        //     H = h;
        //     printf("H:  %5d  ",h);
        //     for(auto& val : cur_s){
        //         printf("%4c",val);
        //     }
        //     printf("\n");

        // }else{
        //     // visited[cur.DATA] = true;            
        // }

        if(visited[cur.DATA]==false){
            visited[cur.DATA] = true;
            
            if(cur == cubeSolve){
                printf("Found: \n");
                for(auto& val : cur_s){
                    printf("%4c",val);
                }
                printf("\n");
                return;
            }

            int r = 0;rand()%100;
            for(int i = 0 ; i < 12 ; i++){

                cur_s = S.front();
                cur_s.push_back(moves[ (i+r)%12 ]);
                            
                S.push_back(cur_s);           

            }       

        }else{
               
        }

        
        S.pop_front();
        
    }
    




}


int heuristic(Cube a,Cube b){
    int res = 0;
    int f,i,j;    
    for (f = 0; f < 6; f++){ 
        for (i = 0; i < 3; i++){ 
            for (j = 0; j < 3; j++){
                if(b.DATA[f][i][j] == 'X' ||
                   a.DATA[f][i][j] == 'X'  ) continue;

                if(a.DATA[f][i][j] != b.DATA[f][i][j])res++;
            }
        }
    }
    return res;
}

list<vector<char>> S;
int step = 0;

void findSolve3(){
 
    vector<char> cur_s;
    static int H = 99999999;
    Cube cur = cube;
    int h = 0;

    

    static bool __init = true;
    if(__init){
        S.clear();
        for(int i = 0 ; i < 12 ; i++){
            vector<char> s;s.push_back(moves[i]);
            S.push_back(s);
        }

        __init = false;
    }

    bool omit = false;
    h = heuristic(cur,cubeSolve_1);
    if(h==0 && step != -1){
        printf("Eureka");
        omit = true;
    }
    
    while (true){
        
    if(step==-1) break;

    if(S.size() == 0 && h!=0){
        printf("END\n");
        break;      
    }


    if(!omit){
        cur_s = S.front();    
        cur = cube;   
        for(auto& v : cur_s){
            cur.move(v);
        }
    }
    
    
    if(visited[cur.DATA] == false || omit == true){
        visited[cur.DATA] = true;

        if(omit){
            cur = cube;
        }
        
        if((h = heuristic(cur,cubeSolve_1)) == 0){

            printf("H(%4d): ",h);
            for(auto& v : cur_s){
                printf("%c ",v);
            }
            printf("\n");

            step++;
            // CRUZ
            if(step == 1){
                // strcpy(moves  ,"RUFurLlBbdfD");
                // strcpy(moves_i,"rufURlLbBDFd");
                cubeSolve_1.DATA[1][0][1] = 'W'; //W
                cubeSolve_1.DATA[2][2][1] = 'G'; //G
            }
            else if(step == 2){
                cubeSolve_1.DATA[1][2][1] = 'W'; //W
                cubeSolve_1.DATA[3][0][1] = 'B'; //B
            }
            else if(step == 3){
                cubeSolve_1.DATA[1][1][2] = 'W'; //W
                cubeSolve_1.DATA[4][2][1] = 'O'; //O
            }
            else if(step == 4){
                cubeSolve_1.DATA[1][1][0] = 'W'; //W
                cubeSolve_1.DATA[5][2][1] = 'R'; //R
            }else if(step == 5) step = -1;
            // EZQUINAS
            else if(step == 5){
                cubeSolve_1.DATA[1][0][2] = 'W';
                cubeSolve_1.DATA[2][2][2] = 'G';
                cubeSolve_1.DATA[4][2][0] = 'O';
                cubeSolve_1.DATA[2][1][2] = 'G';
                cubeSolve_1.DATA[4][1][0] = 'O';
            }
            else if(step == 6){
                cubeSolve_1.DATA[1][0][0] = 'W';
                cubeSolve_1.DATA[2][2][0] = 'G';
                cubeSolve_1.DATA[5][2][2] = 'R';
                cubeSolve_1.DATA[2][1][0] = 'G';
                cubeSolve_1.DATA[5][1][2] = 'R';
            }
            else if(step == 7){
                cubeSolve_1.DATA[1][2][2] = 'W';
                cubeSolve_1.DATA[3][0][2] = 'B';
                cubeSolve_1.DATA[4][2][2] = 'O';
            }
            else if(step == 8){
                cubeSolve_1.DATA[1][2][2] = 'W';
                cubeSolve_1.DATA[3][0][0] = 'B';
                cubeSolve_1.DATA[5][2][0] = 'R';
            }
            // ARISTAS
            // FIN
            else{
                step = -1;
            }
                        
             
            cube = cur;
            // cube.draw();
            __init = true;
            // visited.clear();

            findSolve3();
            break;
        }

        for(int i = 0 ; i < 12 ; i++){
            char c = moves[ i ];           
            
            if((cur_s.size()+1) > 10) break;;
            
            vector<char> cur_s2 = cur_s;
            cur_s2.push_back(c);

            S.push_back(cur_s2);

        }

    }
    
    

    S.pop_front();

    }

}

void initSolves(){
    cubeSolve.reset();
    cubeSolve_1.reset();
    
    int f,i,j; 
    for (f = 0; f < 6; f++){ 
        for (i = 0; i < 3; i++){ 
            for (j = 0; j < 3; j++){
                
                if(f!=1){
                    cubeSolve_1.DATA[f][i][j] = 'X';
                }

            }
        }
    }

    cubeSolve_1.DATA[1][0][0] = 'X';
    cubeSolve_1.DATA[1][0][2] = 'X';
    cubeSolve_1.DATA[1][2][0] = 'X';
    cubeSolve_1.DATA[1][2][2] = 'X';
    
    cubeSolve_1.DATA[1][0][1] = 'X'; //W
    cubeSolve_1.DATA[1][2][1] = 'X'; //W
    cubeSolve_1.DATA[1][1][2] = 'X'; //W
    cubeSolve_1.DATA[1][1][0] = 'X'; //W    
    

    cubeSolve_1.DATA[2][2][1] = 'X'; //G
    cubeSolve_1.DATA[3][0][1] = 'X'; //B
    cubeSolve_1.DATA[4][2][1] = 'X'; //O
    cubeSolve_1.DATA[5][2][1] = 'X'; //R

    

}

int main(){
    srand(time(NULL));
    initSolves();
    
    cube.reset();  
    readSTD(cube);
    cube.draw(); 
    
    findSolve2(cube,seq);
    
    visited.clear();
    visited[cube.DATA] = true;
    // findSolve3();

    cube.draw();

    return 0;
}