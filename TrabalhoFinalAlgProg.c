#include <stdio.h>
#include <string.h>

int main () {

    /*Definindo os vetores de "ponteiros de ponteiros" para cada pilha de cartas do jogo */
    carta_t monteDescarte[tamanho];
    carta_t monteCompra[tamanho];   /*haverao mais montes*/


    /*Definindo o vetor baralho, com todas as cartas e o inicializando com uma funcao*/
    carta_t baralhoCompleto[tamanho] = {0};
    inicializa_baralho(baralhoCompleto);



}

/*Definicao do tipo de estrutura Carta */
typedef struct carta{
    int valor;
    char naipe[7];
} carta_t;

/*Definicao da funcao que inicializa um vetor com todas as cartas de um baralho normal */
void inicializa_baralho (carta_t deckvazio[]){
    int i;
    for (i=0; i<tamanho; i++){
        deckvazio[i].valor = (i%13)+1;       /*Dessa forma, cada parcela de memoria do vetor recebe um valor entre 1 e 13 (de As ate o Rei)*/
                                                    /*repetindo de 13 em 13 parcelas do vetor*/
        if(i <= 12){
            strcpy (deckvazio[i].naipe, "Copas");
        }
        else if(12 < i && i <= 25 ){
            strcpy (deckvazio[i].naipe, "Espadas");             /*As parcelas do vetor de 0 a 12 sao do naipe de Copas, e assim por diante*/
        }                                                     /*ate que todas as parcelas recebam um naipe, de 13 em 13 parcelas*/
        else if(25 < i && i <= 38){
            strcpy (deckvazio[i].naipe, "Ouros");
        }
        else {
            strcpy (deckvazio[i].naipe, "Paus");
        }
    }
}
