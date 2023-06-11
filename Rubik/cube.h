#pragma once

#include<iostream>
#include <bits/stdc++.h>

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

#define array_6_3_3 array<array<array<char,3>,3>,6>
#define array_3_3 array<array<char,3>,3>


char colors[7] = "YWGBOR";
char moves   [13] = "RUFurLlBbdfD";
char moves_i [13] = "rufURlLbBDFd";

char mov_inv(char m){
    if(m == 'U')      return 'u';
    else if(m == 'u') return 'U';
    else if(m == 'D') return 'd';
    else if(m == 'd') return 'D';
    else if(m == 'F') return 'f';
    else if(m == 'f') return 'F';
    else if(m == 'B') return 'b';
    else if(m == 'b') return 'B';
    else if(m == 'R') return 'r';
    else if(m == 'r') return 'R';
    else if(m == 'L') return 'l';
    else if(m == 'l') return 'L';

    return ' ';
}

class Cube{

    public:
        
    array_6_3_3 DATA;

    Cube();

    void reset();
    void draw();
    void move(char m);

};

int operator/(Cube& a , Cube& b);
bool operator==(Cube& a , Cube& b);

void readSTD(Cube& cube);
