#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_S 1000000

using namespace std;

char _text[MAX_S+10];
char _patt[MAX_S+10];
size_t N;
size_t M;

size_t KMPSearch(char* pat, char* txt, size_t* lps)
{
	size_t C = 0; 
    size_t n = 0;
    size_t m = 0;
    
    while ((N - n) >= (M - m)) {
        // Avanço de 1 para o texto e o padrão
        if (pat[m] == txt[n])m++,n++;

        // Se a comparação do padrão chaga no final, acresenta mais uma ocorrencia 
        if (m == M) C++ , m = lps[m - 1];
        
        // No caso de ser diferente, tenta pular o máximo de copaçãoes
        else if (n < N && pat[m] != txt[n]) {
            if (m != 0)
                m = lps[m - 1];
            else
                n = n + 1;
        }
    }
    
    return C;
}

void computeLPS(char* pat, size_t* lps)
{
    size_t len = 0;
    lps[0] = 0;

    size_t m = 1;
    while (m < M) {
        if (pat[m] == pat[len]) {
            len++;
            lps[m] = len;
            m++;
        }else{
            if (len != 0) {
                len = lps[len - 1];
            }else{
                lps[m] = 0;
                m++;
            }
        }
    }
}
 

int main(){

	scanf("%s",_text);
	scanf("%s",_patt);

	N = strlen(_text);
	M = strlen(_patt);

    size_t lps[M];
    computeLPS(_patt, lps);

	size_t ocurrences = KMPSearch(_patt, _text, lps);

    printf("%ld\n",ocurrences);

	return 0;
}