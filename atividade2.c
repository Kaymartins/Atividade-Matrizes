/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
2 ∗ UNIFAL − U ni v e r si d a d e F e d e r al de Al f e n a s .
3 ∗ BACHARELADO EM CIENCIA DA COMPUTACAO.
4 ∗ Trabalho . . : A ti vi d a d e 2
5 ∗ D i s c i p l i n a : Programacao
6 ∗ P r o f e s s o r . : Luiz Eduardo da S i l v a
7 ∗ Aluno . . . . . : Kayan Martins de Freitas
8 ∗ Data . . . . . . : 28/07/2020
9 ∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

#include <stdio.h>
int piso [20][20]; 
int direcao; // 0=direita, 1=para baixo, 2=esquerda, 3=para cima;//
int caneta; // 0=abaixada, 1=levantada; //
int linha, coluna; // posicao da tartaruga // 
char comando;
int operando;
int destino; // para onde a tartaruga vai a cada operando;

int main(void){
    int i,j;
    for (i=0; i<20; i++){
        for (j=0; j<20; j++){
            piso[i][j] = 0;
        }
    direcao = 0;
    caneta = 1;
    linha = 0;
    coluna = 0;
    }
    do{
        scanf("%c", &comando);
        if(comando == 'w'){
            scanf("%d",&operando);
                if(caneta == 1){//se a caneta estiver levantada, matriz recebe 0;
                        if(direcao == 0){ // para direita
                            destino = coluna+operando;
                                while(coluna < destino){
                                    if(piso[linha][coluna]!=1){
                                    piso[linha][coluna] = 0;}
                                    coluna += 1;                    
                                } if (coluna == destino){coluna -= 1;}
                        }else if (direcao == 1){//para baixo
                            destino = linha + operando;
                                while(linha < destino){
                                    if(piso[linha][coluna]!=1){
                                    piso[linha][coluna] = 0;}
                                    linha += 1;
                                } if (linha == destino){linha -= 1;}
                        }else if (direcao == 2)//para esquerda
                        {   
                            destino = coluna-operando;
                                while(coluna > destino){
                                    if(piso[linha][coluna]!=1){
                                    piso[linha][coluna] = 0;}
                                    coluna -= 1;
                                }if (coluna == destino){coluna += 1;}
                                
                        }else{//para cima
                            destino = linha-operando;
                                while (linha > destino)
                                {
                                    if(piso[linha][coluna]!=1){
                                    piso[linha][coluna] = 0;}
                                    linha -= 1;
                                }if (linha == destino){linha += 1;}
                                
                        }
                        
                        
                }else{// caneta abaixada, matriz recebe 1;
                        if(direcao == 0){
                            destino = coluna+operando;
                                while(coluna < destino){
                                    piso[linha][coluna] = 1;
                                    coluna += 1;
                                }if (coluna == destino){coluna -= 1;}

                        }else if (direcao == 1){
                           destino = linha+operando;
                                while(linha < destino){
                                    piso[linha][coluna] = 1;
                                    linha += 1;
                                } if (linha == destino){linha -= 1;}

                        }else if (direcao == 2)
                        {
                            destino = coluna-operando;
                                    while (coluna > destino){
                                        piso[linha][coluna] = 1;
                                        coluna -= 1;
                                    }if(coluna == destino){coluna += 1;}                              
                        }else{
                                destino = linha-operando;
                                    while(linha > destino){
                                        piso[linha][coluna] = 1;
                                        linha -= 1;
                                    }if (linha == destino){linha += 1;}
                        }    
                        

                }

        }else if (comando == 'u')
        {
            caneta = 1;
        }else if (comando == 'd')
        {
            caneta = 0;
        }else if (comando == 'r')
        {
            if(direcao == 3){
                direcao = 0;
            }else{
                direcao += 1;
            }
        }else if (comando == 'l')
        {
            if(direcao == 0){
                direcao = 3;
            }else{
                direcao -= 1;
            }
        }else if (comando == 'p'){

            for (i=0; i<20; i++){
                for (j=0; j<20; j++){
                    if(piso[i][j]==0){
                        printf(".");
                    }else{
                        printf("*");
                    }
                    if (j==19){
                        printf("\n");
                    }
                }
            }
        }   
    }while(comando != 'e');


    return 0;
}
