#include <stdio.h>
#include <string.h>

#define tamanho 52
#define tamanhoTableau 20 /* 20 porque o tableau de maior tamanho de inicializacao eh 7 e a partir dele agruparia-se no maximo mais 13 cartas*/
#define tamanhoFund 13 /* 13 porque a fundacao recebera no maximo 13 cartas, do 1 (As) ao 13 (Rei) */
#define tamanhoNaipe 7
int main () {
                                            /*Definindo os vetores de "ponteiros de ponteiros" para cada pilha de cartas do jogo */
    carta_t monteDescarte[tamanho] = {0};    /* e inicializando eles com 0 */
    carta_t monteEstoque[tamanho] = {0};

    carta_t monteTableau0 [tamanhoTableau][2] = {{0},{0}};
    carta_t monteTableau1 [tamanhoTableau][2] = {{0},{0}};
    carta_t monteTableau2 [tamanhoTableau][2] = {{0},{0}};
    carta_t monteTableau3 [tamanhoTableau][2] = {{0},{0}};    /*definicao de todos os montes do tableau*/
    carta_t monteTableau4 [tamanhoTableau][2] = {{0},{0}};     /* e inicializacao deles com 0 */
    carta_t monteTableau5 [tamanhoTableau][2] = {{0},{0}};
    carta_t monteTableau6 [tamanhoTableau][2] = {{0},{0}};

    carta_t monteFund0 [tamanhoFund][2] = {{0},{0}};
    carta_t monteFund1 [tamanhoFund][2] = {{0},{0}}; /* Definicao de Todos os montes de fundacao */
    carta_t monteFund2 [tamanhoFund][2] = {{0},{0}};  /* e inicializacao deles com 0 */
    carta_t monteFund3 [tamanhoFund][2] = {{0},{0}};   /*esses montes sao matrizes pois um elemento de cada linha apontara para o valor e o outro para o naipe da carta*/

    /*Definindo o vetor baralho, com todas as cartas e o inicializando com uma funcao*/
    carta_t baralhoCompleto[tamanho] = {0};
    inicializa_baralho(baralhoCompleto);

    /* Definicao de outras variaveis importantes */
    int score = 0;
    char nome[15];


}

/*Definicao do tipo de estrutura Carta */
typedef struct carta{
    int valor;
    char naipe[tamanhoNaipe];
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

void inicializacao () {   /* Uma funcao que eh chamada no inicio de cada jogo para resetar e iniciar as variaveis */


}


int imediatamente_inferior (carta_t origem[], int tamanhoOrigem, carta_t destino[], int tamanhoDestino){  /* Uma funcao que recebe dois montes e seus tamanhos e retorna um valor int que se refere a */
                                                                                                           /* possibilidade da carta do topo do monte de origem ser imeditamente inferior a */
                                                                                                            /* carta no topo do monte de destino */
    if (origem[tamanhoOrigem].valor == destino[tamanhoDestino].valor - 1){
        return 1; /* Se o valor eh imediatamente inferior a jogada eh possivel, entao retorna 1 */
    }

    else
        return 0; /* Se o valor n eh imediatamente inferior a jogada eh ilegal, entao retorna 0 */
}

int cor_contraria (carta_t origem[], int tamanhoOrigem, carta_t destino[], int tamanhoDestino) { /* Uma funcao que recebe dois montes e seus tamanhos e retorna um valor */
    char naipeOrigem[tamanhoNaipe];                                                                          /* referente a legalidade ou nao do movimento pretendido */
    char naipeDestino[tamanhoNaipe];

    strcpy (naipeOrigem, origem[tamanhoOrigem].naipe);
    strcpy (naipeDestino, destino[tamanhoDestino].naipe);  /* Copiando os naipes recebidos para variaveis locais */

    if (strcmp(naipeOrigem, "Copas") || strcmp(naipeOrigem, "Ouros")){
        if (strcmp(naipeDestino, "Paus") || strcmp(naipeDestino, "Espadas")){
            return 1; /* Se o naipe de origem for vermelho e o de destino for preto, o movimento eh legal e retorna 1 */
        }
    }

    if (strcmp(naipeOrigem, "Paus") || strcmp(naipeOrigem, "Espadas")){
        if (naipeDestino, "Copas") || strcmp(strcmp(naipeDestino, "Ouros")){
            return 1; /* Se o naipe de origem for preto e o de destino for vermelho, o movimento eh legal e retorna 1 */
        }
    }

    else return 0; /* Se os dois casos acima forem falsos, entao o movimento eh ilegal e retorna 0 */
}

/* Essa funcao esta comentada pois esta bem incompleta, mas ainda sera feita
void embaralha (carta_t baralhoOrdenado[]){ /* Uma funcao que recebe o baralhoCompleto para embaralha-lo

    int embaralhado[tamanho];
    int i;

    for (i=0; i<tamanho; i++){ /* aqui vamos atribuimos um valor aleatorio de 0 a 52 a cada parcela do vetor embaralhado

    }

} */




