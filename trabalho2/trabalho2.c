#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

typedef struct{
    int *inicio;
    int capacidade;
    int qtd;
} Bloco;

Bloco *vetorPrincipal[TAM];

int estahVazio(int posicao) {
    if (posicao < 1 || posicao > 10) return POSICAO_INVALIDA;
    
    if (vetorPrincipal[posicao - 1] == NULL) return SEM_ESTRUTURA_AUXILIAR;
    
    if (vetorPrincipal[posicao - 1]->qtd == 0) return ESTRUTURA_AUXILIAR_VAZIA;
    
    return SUCESSO;
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    // se posição é um valor válido {entre 1 e 10}
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }
    // o tamanho nao pode ser menor que 1
    if(tamanho < 1){
        return TAMANHO_INVALIDO;
    }
    // a posicao pode já existir estrutura auxiliar
    if(vetorPrincipal[posicao - 1] != NULL){
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }
    vetorPrincipal[posicao - 1] = malloc(sizeof(Bloco));
    // o tamanho ser muito grande
    if(vetorPrincipal[posicao - 1] == NULL){
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[posicao - 1]->inicio = malloc(tamanho * sizeof(int));

    if(vetorPrincipal[posicao - 1]->inicio == NULL){
        free(vetorPrincipal[posicao - 1]);
        vetorPrincipal[posicao - 1] = NULL; 
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[posicao - 1]->capacidade = tamanho;
    vetorPrincipal[posicao - 1]->qtd = 0;
    // deu tudo certo, crie
    return SUCESSO;

}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{

    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao - 1] != NULL)
        {
            if (vetorPrincipal[posicao - 1]->qtd < vetorPrincipal[posicao - 1]->capacidade)
            {
                vetorPrincipal[posicao - 1]->inicio[vetorPrincipal[posicao - 1]->qtd] = valor;
                vetorPrincipal[posicao - 1]->qtd++;
                return SUCESSO;
            }
            else
            {
                return SEM_ESPACO;
            }
        }
        else
        {
            return SEM_ESTRUTURA_AUXILIAR;
        }
    }

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = estahVazio(posicao);

    if(retorno == SUCESSO){
        vetorPrincipal[posicao - 1]->qtd--;
        return SUCESSO;
    }
    
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = estahVazio(posicao);

    int num_valido = 0;

    if(retorno == SUCESSO){
        for(int i = 0; i < vetorPrincipal[posicao - 1]->qtd; i++){
            if(vetorPrincipal[posicao - 1]->inicio[i] == valor){
                num_valido = 1;
                
                for(int j = i; j < vetorPrincipal[posicao - 1]->qtd - 1; j++){
                    vetorPrincipal[posicao - 1]->inicio[j] = vetorPrincipal[posicao - 1]->inicio[j + 1];
                }
                
                vetorPrincipal[posicao - 1]->qtd--;
                
                break; 
            }
        }
        if(num_valido != 1) return NUMERO_INEXISTENTE;
    }

    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = estahVazio(posicao);

    if(retorno == SUCESSO){
        for(int i = 0; i < vetorPrincipal[posicao - 1]->qtd; i++){
            vetorAux[i] = vetorPrincipal[posicao - 1]->inicio[i];
        }
    }
    
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);

    if(retorno == SUCESSO){
        for(int i = 0; i < vetorPrincipal[posicao - 1]->qtd; i++){
            for(int j = i + 1; j < vetorPrincipal[posicao - 1]->qtd; j++){
                if(vetorAux[i] > vetorAux[j]){
                    int aux;
                    aux = vetorAux[i];
                    vetorAux[i] = vetorAux[j];
                    vetorAux[j] = aux;
                }
            }
        }
    }    
    
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int qtdGeral = 0;

    for(int i = 0; i < 10; i++){
        if(vetorPrincipal[i] != NULL){
            for(int j = 0; j < vetorPrincipal[i]->qtd; j++){
                vetorAux[qtdGeral] = vetorPrincipal[i]->inicio[j];
                qtdGeral++;
            }
        }
    }

    if(qtdGeral == 0) return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int qtdGeral = 0;

    for(int i = 0; i < 10; i++){
        if(vetorPrincipal[i] != NULL){
            for(int j = 0; j < vetorPrincipal[i]->qtd; j++){
                vetorAux[qtdGeral] = vetorPrincipal[i]->inicio[j];
                qtdGeral++;
            }
        }
    }

    if(qtdGeral == 0){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }else{
        for(int k = 0; k < qtdGeral; k++){
            for(int l = k + 1; l < qtdGeral; l++){
                if(vetorAux[k] > vetorAux[l]){
                    int aux;
                    aux = vetorAux[k];
                    vetorAux[k] = vetorAux[l];
                    vetorAux[l] = aux;
                }
            }
        }
    }

    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    if(posicao < 1 || posicao > 10) return POSICAO_INVALIDA;

    if(vetorPrincipal[posicao - 1] == NULL) return SEM_ESTRUTURA_AUXILIAR;

    int tamanhoAtual = vetorPrincipal[posicao - 1]->capacidade;
    int tamanhoFinal = tamanhoAtual + novoTamanho;

    if(tamanhoFinal < 1) return NOVO_TAMANHO_INVALIDO;

    int *temp = realloc(vetorPrincipal[posicao - 1]->inicio, tamanhoFinal * sizeof(int));

    if(temp == NULL) return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[posicao - 1]->inicio = temp;
    vetorPrincipal[posicao - 1]->capacidade = tamanhoFinal;

    if(vetorPrincipal[posicao - 1]->qtd > tamanhoFinal){
        vetorPrincipal[posicao - 1]->qtd = tamanhoFinal;
    }

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int qtd = 0;
    int retorno = estahVazio(posicao);

    if(retorno == SUCESSO){
        for(int i = 0; i < vetorPrincipal[posicao - 1]->qtd; i++){
            qtd++;
        }
    }

    return qtd;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    int qtdTotal = 0;
    
    for (int i = 0; i < 10; i++) {
        if (vetorPrincipal[i] != NULL) {
            qtdTotal += vetorPrincipal[i]->qtd;
        }
    }
    
    if (qtdTotal == 0) return NULL;

    No *cabecote = (No*)malloc(sizeof(No));
    cabecote->prox = NULL;
    
    No *atual = cabecote;

    for (int i = 0; i < 10; i++) {
        if (vetorPrincipal[i] != NULL) {
            for (int j = 0; j < vetorPrincipal[i]->qtd; j++) {
                No *novoNo = (No*)malloc(sizeof(No));
                novoNo->conteudo = vetorPrincipal[i]->inicio[j];
                novoNo->prox = NULL;
                
                atual->prox = novoNo;
                atual = novoNo;
            }
        }
    }

    return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{

    if (inicio == NULL) return;

    No *atual = inicio->prox;
    int i = 0;

    while (atual != NULL) {
        vetorAux[i] = atual->conteudo;
        i++;
        atual = atual->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    if (inicio == NULL || *inicio == NULL) return;

    No *atual = *inicio;
    No *proximo = NULL;


    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar() {
    for (int i = 0; i < 10; i++) vetorPrincipal[i] = NULL;
}

void finalizar() {
    for (int i = 0; i < 10; i++) {
        if (vetorPrincipal[i] != NULL) {
            free(vetorPrincipal[i]->inicio);
            free(vetorPrincipal[i]);
            vetorPrincipal[i] = NULL;
        }
    }
}