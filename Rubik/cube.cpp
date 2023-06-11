#include "cube.h"

Cube::Cube(){
    reset();
}


int operator/(Cube& a , Cube& b){
    int res = 0;
    int f,i,j;    
    for (f = 0; f < 6; f++){ 
        for (i = 0; i < 3; i++){ 
            for (j = 0; j < 3; j++){
                if(a.DATA[f][i][j] == b.DATA[f][i][j]) res++;
            }
        }
    }
    return res;
}

bool operator==(Cube& a , Cube& b){
    return (a/b) == 54;
}

void Cube::reset(){
    int f,i,j;
    
    for (f = 0; f < 6; f++){ 
        for (i = 0; i < 3; i++){ 
            for (j = 0; j < 3; j++){
                DATA[f][i][j] = colors[f];
            }
        }
    }
}

void Cube::draw(){
    int f,i,j;

    for (i = 0; i < 3; i++){ 
        for (f = 0; f < 6; f++){ 
            for (j = 0; j < 3; j++){
                printf("%c",DATA[f][i][j]);   
            }
            printf("  ");  
        }   
        printf("\n");         
    }

    printf("\n");
            
}

void Cube::move(char m){
    int i = 0, j = 0;
    char a = ' ';
    

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

    // char aux3[3][3];
    // memcpy(aux3,DATA[face],sizeof aux3);

    array<array<char,3>,3> aux3;
    aux3 = DATA[face];

    for(i = 0 ; i < 3 ; i++){
        for(j = 0 ; j < 3 ; j++){
            if(rotate ==  1) DATA[face][i][j] = aux3[2-j][i];
            else DATA[face][2-j][i] = aux3[i][j];
        }                    
    }

}


void readSTD(Cube& cube){
    int type;
    char mov;

    scanf("%d",&type);

    if(type == 1){

        while ( scanf("%c",&mov)>=0 ){
            if(mov == ' ' || mov == '\0' || mov == '\n' || mov == '\t') continue;
            cube.move(mov);
        }
               
    }else if(type == 2){
        cube.reset();
        int count = 0;
        int f=0,r=0,c=0;
        while ( scanf("%c",&mov)>=0 ){
            if(mov == ' ' || mov == '\0' || mov == '\n' || mov == '\t') continue;
            
            cube.DATA[f][r][c] = mov;
            
            count++;

            if(count%1 == 0){
                c++;
                c = c%3;
            } 

            if(count%3 == 0){
                f++;
                f = f%6;
            } 

            if(count%(3*6) == 0){
                r++;
                r = r%3;
            }
            
        }
    }else if(type == 3){
        for(int i = 0 ; i < 500 ; i++ ){
            cube.move( moves[ (i+(rand()%123)) %12] );
        }
    }else{
        return;
    }
}


