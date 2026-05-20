// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Angelo Gabriel Almeida dos Santos Santana
//  email: ag5257720@gmail.com
//  Matrícula: 20252160005
//  Semestre: 2026.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]) {
    DataQuebrada dq = quebraData(data); 

    if (dq.valido == 0) return 0; 

    if(dq.iAno < 26){
        dq.iAno = dq.iAno + 2000;
    }else if(dq.iAno < 100){
        dq.iAno = dq.iAno + 1900;
    }

    if(dq.iAno > 2026 || dq.iAno < 1900) return 0;
    if(dq.iMes > 12 || dq.iMes < 1) return 0;

    int ehbissexto = 0;
    if(dq.iAno % 400 == 0){
        ehbissexto = 1;
    }else if(dq.iAno % 100 == 0){
        ehbissexto = 0;
    }else if(dq.iAno % 4 == 0){
        ehbissexto = 1;
    }

    if(dq.iMes == 1 || dq.iMes == 3 || dq.iMes == 5 || dq.iMes == 7 || dq.iMes == 8 || dq.iMes == 10 || dq.iMes == 12){
        if(dq.iDia > 31 || dq.iDia < 1) return 0;
    }
    
    if(dq.iMes == 4 || dq.iMes == 6 || dq.iMes == 9 || dq.iMes == 11){
        if(dq.iDia > 30 || dq.iDia < 1) return 0;
    }

    if(dq.iMes == 2){
        if(ehbissexto == 1){
            if(dq.iDia > 29 || dq.iDia < 1) return 0;
        }else{
            if(dq.iDia > 28 || dq.iDia < 1) return 0;
        }
    }

    return 1;
}

// função auxiliar para saber quantos dias tem um mês específico.
int diasNoMes(int mes, int ano) {
    int ehbissexto = 0;
    if (ano % 400 == 0) ehbissexto = 1;
    else if (ano % 100 == 0) ehbissexto = 0;
    else if (ano % 4 == 0) ehbissexto = 1;

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) return 30;
    if (mes == 2) {
        if (ehbissexto) return 29;
        else return 28;
    }
    return 31;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]) {
    DiasMesesAnos dma;

    if (q1(datainicial) == 0) {
        dma.retorno = 2;
        return dma;
    }
    if (q1(datafinal) == 0) {
        dma.retorno = 3;
        return dma;
    }

    DataQuebrada dataIni = quebraData(datainicial);
    DataQuebrada dataFim = quebraData(datafinal);

    if (dataIni.iAno < 26) dataIni.iAno += 2000;
    else if (dataIni.iAno < 100) dataIni.iAno += 1900;

    if (dataFim.iAno < 26) dataFim.iAno += 2000;
    else if (dataFim.iAno < 100) dataFim.iAno += 1900;

    int dataInvertida = 0;

    if (dataIni.iAno > dataFim.iAno) {
        dataInvertida = 1;
    } 
    else if (dataIni.iAno == dataFim.iAno) {
        if (dataIni.iMes > dataFim.iMes) {
            dataInvertida = 1;
        } 
        else if (dataIni.iMes == dataFim.iMes) {
            if (dataIni.iDia > dataFim.iDia) {
                dataInvertida = 1;
            }
        }
    }

    if (dataInvertida == 1) {
        dma.retorno = 4;
        return dma;
    }

    int diasIni = dataIni.iDia;
    int mesIni = dataIni.iMes;
    int anoIni = dataIni.iAno;

    int diasFim = dataFim.iDia;
    int mesFim = dataFim.iMes;
    int anoFim = dataFim.iAno;

    if (diasFim < diasIni) {
        mesFim--;
        int mesAnterior = mesFim;
        int anoAnterior = anoFim;
        if (mesAnterior == 0) {
            mesAnterior = 12;
            anoAnterior--;
        }
        diasFim += diasNoMes(mesAnterior, anoAnterior);
    }
    dma.qtdDias = diasFim - diasIni;

    if (mesFim < mesIni) {
        anoFim--;
        mesFim += 12;
    }
    dma.qtdMeses = mesFim - mesIni;

    dma.qtdAnos = anoFim - anoIni;
    dma.retorno = 1;

    return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) {
    int qtdOcorrencias = 0;
    
    for (int i = 0; texto[i] != '\0'; i++) {
        char letraAtual = texto[i];
        char letraBusca = c;
        
        if (isCaseSensitive != 1) {
            if (letraAtual >= 'A' && letraAtual <= 'Z') {
                letraAtual = letraAtual + 32;
            }
            if (letraBusca >= 'A' && letraBusca <= 'Z') {
                letraBusca = letraBusca + 32;
            }
        }
        
        if (letraAtual == letraBusca) {
            qtdOcorrencias++;
        }
    }
    
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]) {
    int qtdOcorrencias = 0;
    int posIndex = 0;

    for (int i = 0; strTexto[i] != '\0'; i++) {
        
        int j = 0;
        int k = i;
        
        while (strTexto[k] == strBusca[j] && strBusca[j] != '\0' && strTexto[k] != '\0') {
            k++;
            j++;
        }
        
        if (strBusca[j] == '\0') {
            
            posicoes[posIndex] = i + 1;
            
            posicoes[posIndex + 1] = k;
            
            posIndex += 2; 
            
            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num) {
    int invertido = 0;

    while (num > 0) {
        int ultimoDigito = num % 10;
        
        invertido = (invertido * 10) + ultimoDigito;
        
        num = num / 10;
    }

    return invertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca) {
    int qtdOcorrencias = 0;
    int divisor = 1;
    int temp = numerobusca;

    while (temp > 0) {
        divisor = divisor * 10;
        temp = temp / 10;
    }

    while (numerobase > 0) {
        
        if (numerobase % divisor == numerobusca) {
            qtdOcorrencias++;
            
            numerobase = numerobase / divisor; 
        } 
        else {
            numerobase = numerobase / 10;
        }
    }

    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

int q7(char matriz[8][10], char palavra[5]) {
    int linhas = 8;
    int colunas = 10;


    int dLinha[] = {-1, 1,  0, 0, -1, -1,  1, 1};
    int dColuna[] = { 0, 0, -1, 1, -1,  1, -1, 1};

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            
            if (matriz[i][j] == palavra[0]) {
                
                for (int direcao = 0; direcao < 8; direcao++) {
                    int k = 1; 
                    int linhaAtual = i + dLinha[direcao];
                    int colAtual = j + dColuna[direcao];

                    while (palavra[k] != '\0') {
                        if (linhaAtual < 0 || linhaAtual >= linhas || colAtual < 0 || colAtual >= colunas) {
                            break; 
                        }

                        if (matriz[linhaAtual][colAtual] != palavra[k]) {
                            break; 
                        }

                        linhaAtual += dLinha[direcao];
                        colAtual += dColuna[direcao];
                        k++;
                    }

                    if (palavra[k] == '\0') {
                        return 1; 
                    }
                }
            }
        }
    }

    return 0;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
