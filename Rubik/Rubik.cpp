#include <cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

#define for_ifj for (i = 0; i < 3; i++){\
                for (f = 0; f < 6; f++){\
                for (j = 0; j < 3; j++)\

#define for_fij for (f = 0; f < 6; f++){\
                for (i = 0; i < 3; i++){\
                for (j = 0; j < 3; j++)\

#define for_ij  for (i = 0; i < 3; i++){\
                for (j = 0; j < 3; j++)\

#define for_i  for (i = 0; i < 3; i++)

char colors[7] = "YWGBOR";
char moves [13] = "UuDdFfBbRrLl";

class Cube{
    public:
    
    char DATA[6][3][3];

    Cube(){
        memset(DATA,'O',sizeof DATA);
        reset();
    }

    void reset(){
        int f,i,j;
        
        for_fij{
            DATA[f][i][j] = colors[f];
        }
        }
        }
    }

    void draw(){
        int f,i,j;

        for_ifj{
            printf("%c",DATA[f][i][j]);   
        }
            printf("  ");  
        }   
            printf("\n");         
        }

        printf("\n");
               
    }

    char aux[3];
    void move(char m){
        int i = 0, j = 0;
        char a = ' ';
        char aux3[3][3];

        if(m == 'U'){
            for(i = 0 ; i < 3 ; i++){
                a = DATA[2][0  ][i  ];
                DATA[2][0  ][i  ] = DATA[4][0  ][i  ];
                DATA[4][0  ][i  ] = DATA[3][2  ][2-i];
                DATA[3][2  ][2-i] = DATA[5][0  ][i  ];
                DATA[5][0  ][i  ] = a;
            }
        }else 
        if(m == 'u'){
            for(i = 0 ; i < 3 ; i++){
                a = DATA[2][0  ][i  ];
                DATA[2][0  ][i  ] = DATA[5][0  ][i  ];
                DATA[5][0  ][i  ] = DATA[3][2  ][2-i];
                DATA[3][2  ][2-i] = DATA[4][0  ][i  ];
                DATA[4][0  ][i  ] = a;
            }

        }else                
        if(m == 'D'){
            for(i = 0 ; i < 3 ; i++){
                a = DATA[2][2  ][i  ];
                DATA[2][2  ][i  ] = DATA[5][2  ][i  ];
                DATA[5][2  ][i  ] = DATA[3][0  ][2-i];
                DATA[3][0  ][2-i] = DATA[4][2  ][i  ];
                DATA[4][2  ][i  ] = a;
            }
        }else                
        if(m == 'd'){
            for(i = 0 ; i < 3 ; i++){
                a = DATA[2][2  ][i  ];
                DATA[2][2  ][i  ] = DATA[4][2  ][i  ];
                DATA[4][2  ][i  ] = DATA[3][0  ][2-i];
                DATA[3][0  ][2-i] = DATA[5][2  ][i  ];
                DATA[5][2  ][i  ] = a;
            }
        }else                
        if(m == 'F'){
            for(i = 0 ; i < 3 ; i++){
                a = DATA[0][2  ][i  ];
                DATA[0][2  ][i  ] = DATA[5][2-i][2  ];
                DATA[5][2-i][2  ] = DATA[1][0  ][2-i];
                DATA[1][0  ][2-i] = DATA[4][i  ][0  ];
                DATA[4][i  ][0  ] = a;
            }
        }else                
        if(m == 'f'){
            for(i = 0 ; i < 3 ; i++){
                a = DATA[0][2  ][i  ];
                DATA[0][2  ][i  ] = DATA[4][i  ][0  ];
                DATA[4][i  ][0  ] = DATA[1][0  ][2-i];
                DATA[1][0  ][2-i] = DATA[5][2-i][2  ];
                DATA[5][2-i][2  ] = a;
            }
        }else                
        if(m == 'B'){
            for(i = 0 ; i < 3 ; i++){
                a = DATA[0][0  ][i  ];
                DATA[0][0  ][i  ] = DATA[4][i  ][2  ];
                DATA[4][i  ][2  ] = DATA[1][2  ][2-i];
                DATA[1][2  ][2-i] = DATA[5][2-i][0  ];
                DATA[5][2-i][0  ] = a;
            }
        }else                
        if(m == 'b'){
            for(i = 0 ; i < 3 ; i++){
                a = DATA[0][0  ][i  ];
                DATA[0][0  ][i  ] = DATA[5][2-i][0  ];
                DATA[5][2-i][0  ] = DATA[1][2  ][2-i];
                DATA[1][2  ][2-i] = DATA[4][i  ][2  ];
                DATA[4][i  ][2  ] = a;
            }
        }else                
        if(m == 'R'){
            for(i = 0 ; i < 3 ; i++){
                a = DATA[0][i  ][2  ];
                DATA[0][i  ][2  ] = DATA[2][i  ][2  ];
                DATA[2][i  ][2  ] = DATA[1][i  ][2  ];
                DATA[1][i  ][2  ] = DATA[3][i  ][2  ];
                DATA[3][i  ][2  ] = a;
            }
        }else                
        if(m == 'r'){
            for(i = 0 ; i < 3 ; i++){
                a = DATA[0][i  ][2  ];
                DATA[0][i  ][2  ] = DATA[3][i  ][2  ];
                DATA[3][i  ][2  ] = DATA[1][i  ][2  ];
                DATA[1][i  ][2  ] = DATA[2][i  ][2  ];
                DATA[2][i  ][2  ] = a;
            }
        }else
        if(m == 'L'){
            for(i = 0 ; i < 3 ; i++){
                a = DATA[0][i  ][0  ];
                DATA[0][i  ][0  ] = DATA[3][i  ][0  ];
                DATA[3][i  ][0  ] = DATA[1][i  ][0  ];
                DATA[1][i  ][0  ] = DATA[2][i  ][0  ];
                DATA[2][i  ][0  ] = a;
            }
        }else                
        if(m == 'l'){
            for(i = 0 ; i < 3 ; i++){
                a = DATA[0][i  ][0  ];
                DATA[0][i  ][0  ] = DATA[2][i  ][0  ];
                DATA[2][i  ][0  ] = DATA[1][i  ][0  ];
                DATA[1][i  ][0  ] = DATA[3][i  ][0  ];
                DATA[3][i  ][0  ] = a;
            }
        }else{
            return;
        }
                



        int face = 0 , rotate = 0;
        
             if(m == 'U') face = 0, rotate= 1;
        else if(m == 'u') face = 0, rotate=-1;
        else if(m == 'D') face = 1, rotate= 1;
        else if(m == 'd') face = 1, rotate=-1;
        else if(m == 'F') face = 2, rotate= 1;
        else if(m == 'f') face = 2, rotate=-1;
        else if(m == 'B') face = 3, rotate= 1;
        else if(m == 'b') face = 3, rotate=-1;
        else if(m == 'R') face = 4, rotate= 1;
        else if(m == 'r') face = 4, rotate=-1;
        else if(m == 'L') face = 5, rotate= 1;
        else if(m == 'l') face = 5, rotate=-1;

 
        memcpy(aux3,DATA[face],sizeof aux3);
        for(i = 0 ; i < 3 ; i++){
            for(j = 0 ; j < 3 ; j++){
                if(rotate ==  1) DATA[face][i][j] = aux3[2-j][i];
                else DATA[face][2-j][i] = aux3[i][j];
            }                    
        }

    }

};

int main(){

    Cube cube;
    cube.reset();
    cube.draw();
    
    char sec[]  = {"bruRUB"};
    char sec2[] = {"burURB"};


    for(auto& a : sec){
        cube.move(a);
    }
    cube.draw();

    for(auto& a : sec2){
        cube.move(a);
    }
    cube.draw();

    return 0;
}