# Projeto de Algoritmos - Proj. Algoritmos - 2023

## Arquivos
    1. *.pdf: Inclui a declaração do programa e as instruções de conformidade.
    2. *.in: São os parâmetros de entrada do programa, em formato *stdin*.
    3. *.out: É a saida desejada do programa.
    4. *.cpp: É o algoritmo compete num arquivo só.
   
## Cómo executar (Linux)

### Manualmente
```bash
    g++ [filename].cpp -o [filename].out

    [filename].out < [number].in > [number].out1
    
    diff [number].out [number].out1
    
```

### Script 
```bash
    ./evaluate [folderName]
```

```shell
yecid@yecid-ubuntu:/media/yecid/Estudios/Pós-Graduação/Projeto de Algoritmos/Alg
orithmDesign_2023_1$ ./evaluate.sh PDin6/
Compiling PDin6.cpp file...

----------1.in-------------[OK]
aa
aa

----------2.in-------------[OK]



----------3.in-------------[OK]



----------4.in-------------[OK]
aaadara
aaadara

----------5.in-------------[OK]
bcdf
bcdf

```