#include <stdio.h>
#include <string.h>
#include <ctype.h>

//tamanhos
#define TAMALUNOS 3
#define TAM_NOME 256
#define TAM_DATA 6
#define TAM_CPF 12
#define TAMPROFESSOR 3
#define TAM_CODIGO 9
#define TAMDISCIPLINA 3

//retornos
#define LISTA_CHEIA -1
#define MATRICULA_INVALIDA -2
#define SEXO_INVALIDO -3
#define CAD_SUCESSO -4
#define ATL_SUCESSO -5
#define INEXISTENTE -6
#define LISTA_VAZIA -7
#define EXC_SUCESSO -8
#define DATA_INVALIDA -9
#define CPF_INVALIDO -10
#define SEMESTRE_INVALIDO -11
#define ALUNO_DUPLICADO -12

//estruturas
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int matricula;
    char nome[TAM_NOME];
    char sexo; 
    Data data_nascimento; 
    char cpf[TAM_CPF];
    int ativo;
} Aluno;

typedef struct {
    int matricula;
    char nome[TAM_NOME];
    char sexo;
    Data data_nascimento;
    char cpf[TAM_CPF];
    int ativo;
} Professor;

typedef struct {
    char codigo[TAM_CODIGO];
    char nome[TAM_NOME];
    int semestre;
    int matricula_professor; 
    int matriculas_alunos[TAMALUNOS]; 
    int contAlunosMatriculados;
    int ativo;
} Disciplina;

//funções
int menuPrincipal();

int menuAluno();
int cadastrarAluno(Aluno lista_Alunos[], int contAlunos);
void listarAlunos(Aluno lista_Alunos[], int contAlunos);
int atualizarAluno(Aluno lista_Alunos[], int contAlunos);
int excluirAluno(Aluno lista_Alunos[], int contAlunos);
void listarAlunosPorSexo(Aluno lista_Alunos[], int contAlunos);
void listarAlunosPorNome(Aluno lista_Alunos[], int contAlunos);
void listarAlunosPorData(Aluno lista_Alunos[], int contAlunos);

int menuProfessor();
int cadastrarProfessor(Professor lista_Professor[], int contProfessores);
void listarProfessores(Professor lista_Professor[], int contProfessores);
int atualizarProfessor(Professor lista_Professor[], int contProfessores);
int excluirProfessor(Professor lista_Professor[], int contProfessores);
void listarProfessoresPorSexo(Professor lista_Professor[], int contProfessores);
void listarProfessoresPorNome(Professor lista_Professor[], int contProfessores);
void listarProfessoresPorData(Professor lista_Professor[], int contProfessores);

int menuDisciplina();
int cadastrarDisciplina(Disciplina lista_Disciplina[], int contDisciplina, Professor lista_Professor[], int contProfessores);
void listarDisciplina(Disciplina lista_Disciplina[], int contDisciplina, Professor lista_Professor[], int contProfessores);
int atualizarDisciplina(Disciplina lista_Disciplina[], int contDisciplina, Professor lista_Professor[], int contProfessores);
int excluirDisciplina(Disciplina lista_Disciplina[], int contDisciplina);
int inserirAlunoDisciplina(Disciplina lista_Disciplina[], int contDisciplina, Aluno lista_Alunos[], int contAlunos);
int excluirAlunoDisciplina(Disciplina lista_Disciplina[], int contDisciplina);
void listarAlunosDaDisciplina(Disciplina lista_Disciplina[], int contDisciplina, Aluno lista_Alunos[], int contAlunos);

void listarAniversariantes(Aluno lista_Alunos[], int contAlunos, Professor lista_Professor[], int contProfessores);
void buscarPessoasPorString(Aluno lista_Alunos[], int contAlunos, Professor lista_Professor[], int contProfessores);
void listarAlunosMenosDe3Disciplinas(Aluno lista_Alunos[], int contAlunos, Disciplina lista_Disciplina[], int contDisciplina);
void listarDisciplinasMaisDe40Vagas(Disciplina lista_Disciplina[], int contDisciplina, Professor lista_Professor[], int contProfessores);

//INICIO
int main (){
    int sair = 0;
    int contAlunos = 0;
    int contProfessores = 0;
    int contDisciplina = 0;
    Aluno lista_Alunos[TAMALUNOS];
    Professor lista_Professor[TAMPROFESSOR];
    Disciplina lista_Disciplina[TAMDISCIPLINA];
    Data lista_Datas[TAM_DATA];

    while(!sair){
        int retorno;
        int opcao = menuPrincipal();
        
        switch(opcao){
            case 0:{
                sair = 1;
                break;
            }

            case 1:{
                int sairAluno = 0;

                while(!sairAluno){
                    int opcaoAluno = menuAluno();

                    switch(opcaoAluno){
                        case 0:{
                            sairAluno = 1;
                            break;
                        }
                        
                        case 1:{
                            retorno = cadastrarAluno(lista_Alunos, contAlunos);

                            switch(retorno){
                                case LISTA_CHEIA:{
                                    printf("\nLISTA CHEIA!!!\n");
                                    break;
                                }

                                case MATRICULA_INVALIDA:{
                                    printf("\nMATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case SEXO_INVALIDO:{
                                    printf("\nSEXO INVÁLIDO!!!\n");
                                    break;
                                }

                                case DATA_INVALIDA:{
                                    printf("\nDATA INVÁLIDA!!!\n");
                                    break;
                                }

                                case CPF_INVALIDO:{
                                    printf("\nCPF INVÁLIDO!!!\n");
                                    break;
                                }

                                case CAD_SUCESSO:{
                                    printf("\nMatrícula concluída com sucesso!\n");
                                    contAlunos++;
                                    break;
                                }    
                            }
                            
                            break;                            
                        }

                        case 2:{
                            listarAlunos(lista_Alunos, contAlunos);
                            break;
                        }

                        case 3:{
                            listarAlunosPorSexo(lista_Alunos, contAlunos);
                            break;
                        }

                        case 4:{
                            listarAlunosPorNome(lista_Alunos, contAlunos);
                            break;
                        }

                        case 5:{
                            listarAlunosPorData(lista_Alunos, contAlunos);
                            break;
                        }

                        case 6:{
                            retorno = atualizarAluno(lista_Alunos, contAlunos);

                            switch(retorno){

                                case LISTA_VAZIA:{
                                    printf("\nNão existe nenhum aluno ainda(Clique em 1 - Atualizar Aluno)\n");
                                    break;
                                }

                                case MATRICULA_INVALIDA:{
                                    printf("\nMATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case SEXO_INVALIDO:{
                                    printf("\nSEXO INVÁLIDO!!!\n");
                                    break;
                                }

                                case DATA_INVALIDA:{
                                    printf("\nDATA INVÁLIDA!!!\n");
                                    break;
                                }

                                case CPF_INVALIDO:{
                                    printf("\nCPF INVÁLIDO!!!\n");
                                    break;
                                }

                                case ATL_SUCESSO:{
                                    printf("\nAtualização concluída com sucesso!\n");
                                    break;
                                }
                                
                                case INEXISTENTE:{
                                    printf("\nALUNO INEXISTENTE!\n");
                                    break;
                                }
                            }
                            break;
                        }

                        case 7:{
                            retorno = excluirAluno(lista_Alunos, contAlunos);
                            switch(retorno){

                                case LISTA_VAZIA:{
                                    printf("\nNão existe nenhum aluno ainda(Clique em 1 - Cadastrar Aluno)\n");
                                    break;
                                }

                                case EXC_SUCESSO:{
                                    printf("\nExclusão concluída com sucesso!\n");
                                    contAlunos--;
                                    break;
                                }
                                
                                case INEXISTENTE:{
                                    printf("\nALUNO INEXISTENTE!\n");
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
                break;    
            }
            
            case 2:{
                int sairProfessor = 0;

                while(!sairProfessor){
                    int opcaoProfessor = menuProfessor();

                    switch(opcaoProfessor){
                        case 0:{
                            sairProfessor = 1;
                            break;
                        }
                        
                        case 1:{
                            retorno = cadastrarProfessor(lista_Professor, contProfessores);

                            switch(retorno){
                                case LISTA_CHEIA:{
                                    printf("\nLISTA CHEIA!!!\n");
                                    break;
                                }

                                case MATRICULA_INVALIDA:{
                                    printf("\nMATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case SEXO_INVALIDO:{
                                    printf("\nSEXO INVÁLIDO!!!\n");
                                    break;
                                }

                                case DATA_INVALIDA:{
                                    printf("\nDATA INVÁLIDA!!!\n");
                                    break;
                                }

                                case CPF_INVALIDO:{
                                    printf("\nCPF INVÁLIDO!!!\n");
                                    break;
                                }

                                case CAD_SUCESSO:{
                                    printf("\nMatrícula concluída com sucesso!\n");
                                    contProfessores++;
                                    break;
                                }    
                            }
                            break;                            
                        }

                        case 2:{
                            listarProfessores(lista_Professor, contProfessores);
                            break;
                        }

                        case 3:{
                            listarProfessoresPorSexo(lista_Professor, contProfessores);
                            break;
                        }

                        case 4:{
                            listarProfessoresPorNome(lista_Professor, contProfessores);
                            break;
                        }

                        case 5:{
                            listarProfessoresPorData(lista_Professor, contProfessores);
                            break;
                        }

                        case 6:{
                            retorno = atualizarProfessor(lista_Professor, contProfessores);

                            switch(retorno){

                                case LISTA_VAZIA:{
                                    printf("\nNão existe nenhum professor ainda(Clique em 1 - Cadastrar Professor)\n");
                                    break;
                                }

                                case MATRICULA_INVALIDA:{
                                    printf("\nMATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case SEXO_INVALIDO:{
                                    printf("\nSEXO INVÁLIDO!!!\n");
                                    break;
                                }

                                case DATA_INVALIDA:{
                                    printf("\nDATA INVÁLIDA!!!\n");
                                    break;
                                }

                                case CPF_INVALIDO:{
                                    printf("\nCPF INVÁLIDO!!!\n");
                                    break;
                                }

                                case ATL_SUCESSO:{
                                    printf("\nAtualização concluída com sucesso!\n");
                                    break;
                                }
                                
                                case INEXISTENTE:{
                                    printf("\nALUNO INEXISTENTE!\n");
                                    break;
                                }
                            }
                            break;
                        }

                        case 7:{
                            retorno = excluirProfessor(lista_Professor, contProfessores);
                            switch(retorno){
                                
                                case LISTA_VAZIA:{
                                    printf("\nNão existe nenhum professor ainda(Clique em 1 - Cadastrar Professor)\n");
                                    break;
                                }

                                case MATRICULA_INVALIDA:{
                                    printf("\nMATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case EXC_SUCESSO:{
                                    printf("\nExclusão concluída com sucesso!\n");
                                    contProfessores--;
                                    break;
                                }
                                
                                case INEXISTENTE:{
                                    printf("\nALUNO INEXISTENTE!\n");
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
                break;    
            }

            case 3:{
                int sairDisciplina = 0;

                while(!sairDisciplina){
                    int opcaoDisciplina = menuDisciplina();

                    switch(opcaoDisciplina){
                        case 0:{
                            sairDisciplina = 1;
                            break;
                        }
                        
                        case 1:{
                            retorno = cadastrarDisciplina(lista_Disciplina, contDisciplina, lista_Professor, contProfessores);

                            switch(retorno){

                                case LISTA_VAZIA:{
                                    printf("\nNão existe nenhum professor ainda(Clique em 1 - Cadastrar Professor)\n");
                                    break;
                                }

                                case LISTA_CHEIA:{
                                    printf("\nLISTA CHEIA!!!\n");
                                    break;
                                }

                                case SEMESTRE_INVALIDO:{
                                    printf("\nSEMESTRE INVÁLIDO!!!\n");
                                    break;
                                }

                                case MATRICULA_INVALIDA:{
                                    printf("\nMATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case CAD_SUCESSO:{
                                    printf("\nDisciplina adicionada com sucesso!\n");
                                    contDisciplina++;
                                    break;
                                }    
                            }
                            
                            break;                            
                        }

                        case 2:{
                            listarDisciplina(lista_Disciplina, contDisciplina, lista_Professor, contProfessores);
                            break;
                        }

                        case 3:{
                            listarAlunosDaDisciplina(lista_Disciplina, contDisciplina, lista_Alunos, contAlunos);


                            break;
                        }

                        case 4:{
                            retorno = atualizarDisciplina(lista_Disciplina, contDisciplina, lista_Professor, contProfessores);

                            switch(retorno){

                                case LISTA_VAZIA:{
                                    printf("\nNão existe nenhuma disciplina ainda(Clique em 1 - Cadastrar Disciplina)\n");
                                    break;
                                }

                                case MATRICULA_INVALIDA:{
                                    printf("\nMATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case SEMESTRE_INVALIDO:{
                                    printf("\nSEMESTRE INVÁLIDO!!!\n");
                                    break;
                                }

                                case ATL_SUCESSO:{
                                    printf("\nAtualização concluída com sucesso!\n");
                                    break;
                                }
                                
                                case INEXISTENTE:{
                                    printf("\nDISCIPLINA INEXISTENTE!\n");
                                    break;
                                }
                            }
                            break;
                        }

                        case 5:{
                            retorno = excluirDisciplina(lista_Disciplina, contDisciplina);
                            switch(retorno){
                                case LISTA_VAZIA:{
                                    printf("\nNão existe nenhuma disciplina ainda(Clique em 1 - Cadastrar Disciplina)\n");
                                    break;
                                }

                                case EXC_SUCESSO:{
                                    printf("\nExclusão concluída com sucesso!\n");
                                    contDisciplina--;
                                    break;
                                }
                                
                                case INEXISTENTE:{
                                    printf("\nDISCIPLINA INEXISTENTE!\n");
                                    break;
                                }
                            }
                            break;
                        }

                        case 6:{
                            retorno = inserirAlunoDisciplina(lista_Disciplina, contDisciplina, lista_Alunos, contAlunos);

                            switch(retorno){
                                case LISTA_VAZIA:{
                                    printf("\nNão existe nenhuma disciplina ou nenhum aluno ainda(Clique em 1 - Cadastrar Aluno no Menu Pricipal ou Criar Disciplina neste menu)\n");
                                    break;
                                }

                                case LISTA_CHEIA:{
                                    printf("\nLISTA CHEIA!!!\n");
                                    break;
                                }

                                case MATRICULA_INVALIDA:{
                                    printf("\nMATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case CAD_SUCESSO:{
                                    printf("\nAluno adicionado(a) com sucesso!\n");
                                    break;
                                }

                                case INEXISTENTE:{
                                    printf("\nDISCIPLINA INEXISTENTE!\n");
                                    break;
                                }
                            }
                            break;
                        }

                        case 7:{
                            retorno = excluirAlunoDisciplina(lista_Disciplina, contDisciplina);

                            switch(retorno){
                                case LISTA_VAZIA:{
                                    printf("\nNão existe nenhuma disciplina ou nenhum aluno ainda(Clique em 1 - Cadastrar Aluno no Menu Pricipal)\n");
                                    break;
                                }

                                case MATRICULA_INVALIDA:{
                                    printf("\nMATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case EXC_SUCESSO:{
                                    printf("\nAluno excluído(a) com sucesso!\n");
                                    break;
                                }
                            }

                        }
                    }
                }
                break; 
            }
            
            case 4:{
                listarAniversariantes(lista_Alunos, contAlunos, lista_Professor, contProfessores);
                break;
            }

            case 5:{
                buscarPessoasPorString(lista_Alunos, contAlunos, lista_Professor, contProfessores);
                break;
            }

            case 6:{
                listarAlunosMenosDe3Disciplinas(lista_Alunos, contAlunos, lista_Disciplina, contDisciplina);
                break;
            }

            case 7:{
                listarDisciplinasMaisDe40Vagas(lista_Disciplina, contDisciplina, lista_Professor, contProfessores);
                break;
            }

            default:{
                printf("<<<<< Sessão inválida! >>>>>\n");
                break;
            }
        }

    }
    
}

//INSERÇÕES E VALIDAÇÕES
int menuPrincipal(){
    int opcao;
    printf("\n");
    printf("<===== Menu Principal =====>\n");
    printf("0 - Sair\n");
    printf("1 - Alunos\n");
    printf("2 - Professores\n");
    printf("3 - Disciplinas\n");
    printf("4 - Aniversariante do mês\n");
    printf("5 - Buscar Alunos/Professores a partir de 3 letras\n");
    printf("6 - Listar Alunos matriculados em menos de 3 disciplinas\n");
    printf("7 - Lista de Disciplinas que extrapolam 40 vagas\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar();
    return opcao;
}

int validarMatricula(int matricula) {
    if (matricula <= 0) {
        return 0; 
    }

    return 1; 
}

int validarSexo(char sexo) {
    if (sexo == 'M' || sexo == 'm' || sexo == 'F' || sexo == 'f') {
        return 1; 
    }
    return 0;
}

int validarData(int dia, int mes, int ano) {
    if (dia < 1 || dia > 31) return 0;
    if (mes < 1 || mes > 12) return 0;
    if (ano < 1900 || ano > 2026) return 0;
    return 1;
}

int validarCPF(char cpf[]) {
    if (strlen(cpf) != 11) {
        return 0;
    }

    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return 0;
        }
    }

    return 1;
}

int validarSemestre(int semestre) {

    int ano = semestre / 10; 
    
    int periodo = semestre % 10; 

    if (ano < 1900 || ano > 2026) {
        return 0; 
    }
    
    if (periodo != 1 && periodo != 2) {
        return 0; 
    }

    return 1;
}

void listarAniversariantes(Aluno lista_Alunos[], int contAlunos, Professor lista_Professor[], int contProfessores) {
    
    if (contAlunos == 0 && contProfessores == 0) {
        printf("\nNão há pessoas cadastradas no sistema!\n");
        return;
    }

    int mesBusca;
    printf("\nDigite o mês (1 a 12) para buscar os aniversariantes: ");
    scanf("%d", &mesBusca);
    getchar();

    if (mesBusca < 1 || mesBusca > 12) {
        printf("Mês inválido! Digite um número de 1 a 12.\n");
        return;
    }

    int encontrou = 0;

    printf("\n~~~~~~ ANIVERSARIANTES DO MÊS %02d ~~~~~~\n", mesBusca);

    for (int i = 0; i < contAlunos; i++) {
        if (lista_Alunos[i].data_nascimento.mes == mesBusca) {
            printf("[ALUNO] Nome: %s | Data: %02d/%02d/%04d\n", 
                   lista_Alunos[i].nome,
                   lista_Alunos[i].data_nascimento.dia, 
                   lista_Alunos[i].data_nascimento.mes, 
                   lista_Alunos[i].data_nascimento.ano);
            encontrou = 1;
        }
    }

    for (int i = 0; i < contProfessores; i++) {
        if (lista_Professor[i].data_nascimento.mes == mesBusca) {
            printf("[PROFESSOR] Nome: %s | Data: %02d/%02d/%04d\n", 
                   lista_Professor[i].nome,
                   lista_Professor[i].data_nascimento.dia, 
                   lista_Professor[i].data_nascimento.mes, 
                   lista_Professor[i].data_nascimento.ano);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Ninguém faz aniversário neste mês.\n");
    }
    printf("----------------------------------------\n");
}

void buscarPessoasPorString(Aluno lista_Alunos[], int contAlunos, Professor lista_Professor[], int contProfessores) {
    
    if (contAlunos == 0 && contProfessores == 0) {
        printf("\nNão há pessoas cadastradas no sistema!\n");
        return;
    }

    char termo[TAM_NOME];
    
    printf("\nDigite o termo para busca (mínimo de 3 letras): ");
    fgets(termo, sizeof(termo), stdin);
    termo[strcspn(termo, "\n")] = '\0';

    if (strlen(termo) > 3) {
        printf("Busca inválida! Você precisa digitar pelo menos 3 caracteres.\n");
        return;
    }

    int encontrou = 0;
    
    printf("\n~~~~~~ RESULTADOS DA BUSCA POR \"%s\" ~~~~~~\n", termo);

    for (int i = 0; i < contAlunos; i++) {
        if (strstr(lista_Alunos[i].nome, termo) != NULL) {
            printf("[ALUNO] Nome: %s | Matrícula: %d\n", lista_Alunos[i].nome, lista_Alunos[i].matricula);
            encontrou = 1;
        }
    }

    for (int i = 0; i < contProfessores; i++) {
        if (strstr(lista_Professor[i].nome, termo) != NULL) {
            printf("[PROFESSOR] Nome: %s | Matrícula: %d\n", lista_Professor[i].nome, lista_Professor[i].matricula);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma pessoa encontrada contendo \"%s\" no nome.\n", termo);
    }
    printf("----------------------------------------\n");
}

void listarAlunosMenosDe3Disciplinas(Aluno lista_Alunos[], int contAlunos, Disciplina lista_Disciplina[], int contDisciplina) {
    
    if (contAlunos == 0) {
        printf("\nNão há alunos cadastrados no sistema!\n");
        return;
    }

    printf("\n~~~~~~ ALUNOS EM MENOS DE 3 DISCIPLINAS ~~~~~~\n");
    int encontrou = 0;

    for (int i = 0; i < contAlunos; i++) {
        
        int matriculaAluno = lista_Alunos[i].matricula;
        int contDisciplinasDoAluno = 0;

        for (int j = 0; j < contDisciplina; j++) {
            
            for (int k = 0; k < lista_Disciplina[j].contAlunosMatriculados; k++) {
                
                if (lista_Disciplina[j].matriculas_alunos[k] == matriculaAluno) {
                    contDisciplinasDoAluno++;
                    break;
                }
            }
        }

        if (contDisciplinasDoAluno < 3) {
            printf("----------------------------------------\n");
            printf("Matrícula: %d | Nome: %s\n", lista_Alunos[i].matricula, lista_Alunos[i].nome);
            printf("Matriculado em: %d disciplina(s)\n", contDisciplinasDoAluno);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Todos os alunos estão matriculados em 3 ou mais disciplinas.\n");
    }
    printf("----------------------------------------\n");
}

void listarDisciplinasMaisDe40Vagas(Disciplina lista_Disciplina[], int contDisciplina, Professor lista_Professor[], int contProfessores) {
    
    if (contDisciplina == 0) {
        printf("\nNão há disciplinas cadastradas no sistema!\n");
        return;
    }

    int encontrou = 0;
    
    printf("\n~~~~~~ DISCIPLINAS COM MAIS DE 40 ALUNOS ~~~~~~\n");

    for (int i = 0; i < contDisciplina; i++) {
        
        if (lista_Disciplina[i].contAlunosMatriculados > 40) {
            
            char nomeProf[TAM_NOME] = "Desconhecido";
            
            for (int j = 0; j < contProfessores; j++) {
                if (lista_Professor[j].matricula == lista_Disciplina[i].matricula_professor) {
                    strcpy(nomeProf, lista_Professor[j].nome);
                    break;
                }
            }

            printf("----------------------------------------\n");
            printf("Disciplina: %s (%s)\n", lista_Disciplina[i].nome, lista_Disciplina[i].codigo);
            printf("Professor Responsável: %s\n", nomeProf);
            printf("Total de Vagas Ocupadas: %d\n", lista_Disciplina[i].contAlunosMatriculados);
            
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma disciplina extrapolou o limite de 40 vagas no momento.\n");
    }
    printf("----------------------------------------\n");
}

//ALUNO
int menuAluno(){
    int opcao;
    printf("\n");
    printf("<===== Menu Alunos =====>\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Listar por sexo\n");
    printf("4 - Listar por nome\n");
    printf("5 - Listar por data\n");
    printf("6 - Atualizar\n");
    printf("7 - Excluir\n");
    printf("Escolha uma opção: ");

    scanf("%d", &opcao);
    return opcao;
}

int cadastrarAluno(Aluno lista_Alunos[], int contAlunos) {
    
    if (contAlunos == TAMALUNOS) {
        return LISTA_CHEIA;
    }

    printf("Insira a matrícula: ");
    scanf("%d", &lista_Alunos[contAlunos].matricula);
    getchar();
    
    if (!validarMatricula(lista_Alunos[contAlunos].matricula)) {
        return MATRICULA_INVALIDA;
    }

    printf("Insira o nome: ");
    fgets(lista_Alunos[contAlunos].nome, TAM_NOME, stdin);
    lista_Alunos[contAlunos].nome[strcspn(lista_Alunos[contAlunos].nome, "\n")] = '\0';

    printf("Insira o sexo (M/F): ");
    scanf("%c", &lista_Alunos[contAlunos].sexo);
    getchar(); 

    if (!validarSexo(lista_Alunos[contAlunos].sexo)) {
        return SEXO_INVALIDO;
    }

    printf("Insira a data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &lista_Alunos[contAlunos].data_nascimento.dia, 
                      &lista_Alunos[contAlunos].data_nascimento.mes, 
                      &lista_Alunos[contAlunos].data_nascimento.ano);
    getchar(); 

    if (!validarData(lista_Alunos[contAlunos].data_nascimento.dia, 
                     lista_Alunos[contAlunos].data_nascimento.mes, 
                     lista_Alunos[contAlunos].data_nascimento.ano)) {
        return DATA_INVALIDA;
    }

    printf("Insira o CPF do aluno (apenas os 11 numeros, sem pontos/tracos): ");
    fgets(lista_Alunos[contAlunos].cpf, TAM_CPF, stdin);

    if (lista_Alunos[contAlunos].cpf[strlen(lista_Alunos[contAlunos].cpf) - 1] == '\n') {
        lista_Alunos[contAlunos].cpf[strlen(lista_Alunos[contAlunos].cpf) - 1] = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    if (!validarCPF(lista_Alunos[contAlunos].cpf)) {
        return CPF_INVALIDO;
    }

    lista_Alunos[contAlunos].ativo = 1;
    
    return CAD_SUCESSO;
}

void listarAlunos(Aluno lista_Alunos[], int contAlunos) {
    if (contAlunos == 0) {
        printf("\nNão há alunos cadastrados no momento!\n");
        return; 
    }

    printf("\n~~~~~~~~ ALUNOS ~~~~~~~~\n");
    
    for (int i = 0; i < contAlunos; i++) {
        printf("-----------------------------------\n");
        printf("Matrícula: %d\n", lista_Alunos[i].matricula);
        printf("Nome: %s\n", lista_Alunos[i].nome);
        
        printf("Sexo: %s\n", (lista_Alunos[i].sexo == 'M' || lista_Alunos[i].sexo == 'm') ? "Masculino" : "Feminino");
        
        printf("Data de Nascimento: %02d/%02d/%04d\n", 
               lista_Alunos[i].data_nascimento.dia, 
               lista_Alunos[i].data_nascimento.mes, 
               lista_Alunos[i].data_nascimento.ano);
               
        printf("CPF: %s\n", lista_Alunos[i].cpf);
    }
    printf("-----------------------------------\n");
}

void listarAlunosPorSexo(Aluno lista_Alunos[], int contAlunos) {
    
    if (contAlunos == 0) {
        printf("\nNão há alunos cadastrados no momento!\n");
        return;
    }

    char sexoBusca;
    printf("\nQual sexo deseja filtrar? (M)asculino ou (F)eminino: ");
    scanf(" %c", &sexoBusca);
    getchar(); 

    int buscaMasculino = (sexoBusca == 'M' || sexoBusca == 'm');
    int buscaFeminino = (sexoBusca == 'F' || sexoBusca == 'f');

    if (!buscaMasculino && !buscaFeminino) {
        printf("Opção inválida! Digite M ou F.\n");
        return;
    }

    int encontrou = 0;
    
    printf("\n~~~~~~ ALUNOS FILTRADOS POR SEXO ~~~~~~\n");

    for (int i = 0; i < contAlunos; i++) {
        
        int alunoMasculino = (lista_Alunos[i].sexo == 'M' || lista_Alunos[i].sexo == 'm');
        int alunoFeminino = (lista_Alunos[i].sexo == 'F' || lista_Alunos[i].sexo == 'f');

        if ((buscaMasculino && alunoMasculino) || (buscaFeminino && alunoFeminino)) {
            
            printf("----------------------------------------\n");
            printf("Matrícula: %d | Nome: %s\n", lista_Alunos[i].matricula, lista_Alunos[i].nome);
            printf("Data de Nascimento: %02d/%02d/%04d\n", 
                   lista_Alunos[i].data_nascimento.dia, 
                   lista_Alunos[i].data_nascimento.mes, 
                   lista_Alunos[i].data_nascimento.ano);
            
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum aluno encontrado com este filtro.\n");
    }
    printf("----------------------------------------\n");
}

void listarAlunosPorNome(Aluno lista_Alunos[], int contAlunos) {
    
    if (contAlunos == 0) {
        printf("\nNão há alunos cadastrados no momento!\n");
        return;
    }

    Aluno lista_Ordenada[TAMALUNOS];
    for (int i = 0; i < contAlunos; i++) {
        lista_Ordenada[i] = lista_Alunos[i]; 
    }

    for (int i = 0; i < contAlunos - 1; i++) {
        for (int j = i + 1; j < contAlunos; j++) {
            
            if (strcmp(lista_Ordenada[i].nome, lista_Ordenada[j].nome) > 0) {
                
                Aluno alunoTemp = lista_Ordenada[i];
                lista_Ordenada[i] = lista_Ordenada[j];
                lista_Ordenada[j] = alunoTemp;
            }
        }
    }

    printf("\n~~~~~~ ALUNOS ORDENADOS POR NOME ~~~~~~\n");

    for (int i = 0; i < contAlunos; i++) {
        printf("----------------------------------------\n");
        printf("Nome: %s\n", lista_Ordenada[i].nome);
        printf("Matrícula: %d | Sexo: %s\n", 
               lista_Ordenada[i].matricula, 
               (lista_Ordenada[i].sexo == 'M' || lista_Ordenada[i].sexo == 'm') ? "Masculino" : "Feminino");
        printf("Data de Nascimento: %02d/%02d/%04d\n", 
               lista_Ordenada[i].data_nascimento.dia, 
               lista_Ordenada[i].data_nascimento.mes, 
               lista_Ordenada[i].data_nascimento.ano);
    }
    printf("----------------------------------------\n");
}

void listarAlunosPorData(Aluno lista_Alunos[], int contAlunos) {
    
    if (contAlunos == 0) {
        printf("\nNão há alunos cadastrados no momento!\n");
        return;
    }

    Aluno lista_Ordenada[TAMALUNOS];
    for (int i = 0; i < contAlunos; i++) {
        lista_Ordenada[i] = lista_Alunos[i];
    }

    for (int i = 0; i < contAlunos - 1; i++) {
        for (int j = i + 1; j < contAlunos; j++) {

            long data_i = (lista_Ordenada[i].data_nascimento.ano * 10000) + 
                          (lista_Ordenada[i].data_nascimento.mes * 100) + 
                           lista_Ordenada[i].data_nascimento.dia;

            long data_j = (lista_Ordenada[j].data_nascimento.ano * 10000) + 
                          (lista_Ordenada[j].data_nascimento.mes * 100) + 
                           lista_Ordenada[j].data_nascimento.dia;

            if (data_i > data_j) {
                Aluno alunoTemp = lista_Ordenada[i];
                lista_Ordenada[i] = lista_Ordenada[j];
                lista_Ordenada[j] = alunoTemp;
            }
        }
    }

    printf("\n~~~~~~ ALUNOS ORDENADOS POR DATA DE NASCIMENTO ~~~~~~\n");

    for (int i = 0; i < contAlunos; i++) {
        printf("----------------------------------------\n");
        printf("Data de Nascimento: %02d/%02d/%04d\n", 
               lista_Ordenada[i].data_nascimento.dia, 
               lista_Ordenada[i].data_nascimento.mes, 
               lista_Ordenada[i].data_nascimento.ano);
        printf("Nome: %s | Matrícula: %d\n", lista_Ordenada[i].nome, lista_Ordenada[i].matricula);
    }
    printf("----------------------------------------\n");
}

int atualizarAluno(Aluno lista_Alunos[], int contAlunos) {
    int matriculaBusca;
    
    if (contAlunos == 0) return LISTA_VAZIA;

    printf("\nDigite a matrícula do aluno que deseja atualizar: ");
    scanf("%d", &matriculaBusca);
    getchar(); 

    for (int i = 0; i < contAlunos; i++) {
        if (lista_Alunos[i].matricula == matriculaBusca) {
            
            printf("~~~~ Aluno Encontrado (%s) ~~~~\n", lista_Alunos[i].nome);
            
            int novaMatricula;
            printf("Insira a nova matrícula: ");
            scanf("%d", &novaMatricula);
            getchar();
            if (!validarMatricula(novaMatricula)) return MATRICULA_INVALIDA;
            
            printf("Insira o novo nome: ");
            fgets(lista_Alunos[i].nome, TAM_NOME, stdin);
            lista_Alunos[i].nome[strcspn(lista_Alunos[i].nome, "\n")] = '\0';

            char novoSexo;
            printf("Insira o novo sexo (M/F): ");
            scanf("%c", &novoSexo);
            getchar();
            if (!validarSexo(novoSexo)) return SEXO_INVALIDO;

            int d, m, a;
            printf("Insira a nova data de nascimento (DD MM AAAA): ");
            scanf("%d %d %d", &d, &m, &a);
            getchar();
            if (!validarData(d, m, a)) return DATA_INVALIDA;

            char novoCPF[TAM_CPF + 2];
            printf("Insira o novo CPF (11 dígitos): ");
            fgets(novoCPF, sizeof(novoCPF), stdin);
            if (novoCPF[strlen(novoCPF) - 1] == '\n') {
                novoCPF[strlen(novoCPF) - 1] = '\0';
            } else {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
            
            if (!validarCPF(novoCPF)) return CPF_INVALIDO;

            lista_Alunos[i].matricula = novaMatricula;
            lista_Alunos[i].sexo = novoSexo;
            lista_Alunos[i].data_nascimento.dia = d;
            lista_Alunos[i].data_nascimento.mes = m;
            lista_Alunos[i].data_nascimento.ano = a;
            strcpy(lista_Alunos[i].cpf, novoCPF);

            return ATL_SUCESSO;
        }
    }

    return INEXISTENTE;
}

int excluirAluno(Aluno lista_Alunos[], int contAlunos) {
    int matriculaBusca;
    
    if (contAlunos == 0) return LISTA_VAZIA;

    printf("\nQual Aluno deseja excluir? (digite a matrícula): ");
    scanf("%d", &matriculaBusca);
    getchar();

    if (!validarMatricula(matriculaBusca)) {
        return MATRICULA_INVALIDA;
    }

    for (int i = 0; i < contAlunos; i++) {
        if (lista_Alunos[i].matricula == matriculaBusca) {
            
            for (int j = i; j < contAlunos - 1; j++) {
                lista_Alunos[j] = lista_Alunos[j + 1];
            }
            
            return EXC_SUCESSO;
        }
    }

    return INEXISTENTE;
}

//PROFESSOR
int menuProfessor(){
    int opcao;
    printf("\n");
    printf("<===== Menu Professor =====>\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Listar por sexo\n");
    printf("4 - Listar por nome\n");
    printf("5 - Listar por data\n");
    printf("6 - Atualizar\n");
    printf("7 - Excluir\n");
    printf("Escolha uma opção: ");

    scanf("%d", &opcao);
    return opcao;
}

int cadastrarProfessor(Professor lista_Professor[], int contProfessores) {
    
    if (contProfessores == TAMPROFESSOR) {
        return LISTA_CHEIA;
    }

    printf("Insira a matrícula: ");
    scanf("%d", &lista_Professor[contProfessores].matricula);
    getchar();
    
    if (!validarMatricula(lista_Professor[contProfessores].matricula)) {
        return MATRICULA_INVALIDA;
    }

    printf("Insira o nome: ");
    fgets(lista_Professor[contProfessores].nome, TAM_NOME, stdin);
    lista_Professor[contProfessores].nome[strcspn(lista_Professor[contProfessores].nome, "\n")] = '\0';

    printf("Insira o sexo (M/F): ");
    scanf("%c", &lista_Professor[contProfessores].sexo);
    getchar(); 

    if (!validarSexo(lista_Professor[contProfessores].sexo)) {
        return SEXO_INVALIDO;
    }

    printf("Insira a data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &lista_Professor[contProfessores].data_nascimento.dia, 
                      &lista_Professor[contProfessores].data_nascimento.mes, 
                      &lista_Professor[contProfessores].data_nascimento.ano);
    getchar(); 

    if (!validarData(lista_Professor[contProfessores].data_nascimento.dia, 
                     lista_Professor[contProfessores].data_nascimento.mes, 
                     lista_Professor[contProfessores].data_nascimento.ano)) {
        return DATA_INVALIDA;
    }

    printf("Insira o CPF do aluno (apenas os 11 numeros, sem pontos/tracos): ");
    fgets(lista_Professor[contProfessores].cpf, TAM_CPF, stdin);

    if (lista_Professor[contProfessores].cpf[strlen(lista_Professor[contProfessores].cpf) - 1] == '\n') {
        lista_Professor[contProfessores].cpf[strlen(lista_Professor[contProfessores].cpf) - 1] = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    if (!validarCPF(lista_Professor[contProfessores].cpf)) {
        return CPF_INVALIDO;
    }

    lista_Professor[contProfessores].ativo = 1;
    
    return CAD_SUCESSO;
}

void listarProfessores(Professor lista_Professor[], int contProfessores) {
    if (contProfessores == 0) {
        printf("\nNão há professores cadastrados no momento!\n");
        return; 
    }

    printf("\n~~~~~~~~ PROFESSORES ~~~~~~~~\n");
    
    for (int i = 0; i < contProfessores; i++) {
        printf("----------------------------------------\n");
        printf("Matrícula: %d\n", lista_Professor[i].matricula);
        printf("Nome: %s\n", lista_Professor[i].nome);
        
        printf("Sexo: %s\n", (lista_Professor[i].sexo == 'M' || lista_Professor[i].sexo == 'm') ? "Masculino" : "Feminino");
        
        printf("Data de Nascimento: %02d/%02d/%04d\n", 
               lista_Professor[i].data_nascimento.dia, 
               lista_Professor[i].data_nascimento.mes, 
               lista_Professor[i].data_nascimento.ano);
               
        printf("CPF: %s\n", lista_Professor[i].cpf);
    }
    printf("----------------------------------------\n");
}

void listarProfessoresPorSexo(Professor lista_Professor[], int contProfessores) {
    if (contProfessores == 0) {
        printf("\nNão há professores cadastrados no momento!\n");
        return;
    }

    char sexoBusca;
    printf("\nQual sexo deseja filtrar? (M)asculino ou (F)eminino: ");
    scanf(" %c", &sexoBusca);
    getchar(); 

    int buscaMasculino = (sexoBusca == 'M' || sexoBusca == 'm');
    int buscaFeminino = (sexoBusca == 'F' || sexoBusca == 'f');

    if (!buscaMasculino && !buscaFeminino) {
        printf("Opção inválida! Digite M ou F.\n");
        return;
    }

    int encontrou = 0; 
    
    printf("\n~~~~~~ PROFESSORES FILTRADOS POR SEXO ~~~~~~\n");

    for (int i = 0; i < contProfessores; i++) {
        int profMasculino = (lista_Professor[i].sexo == 'M' || lista_Professor[i].sexo == 'm');
        int profFeminino = (lista_Professor[i].sexo == 'F' || lista_Professor[i].sexo == 'f');

        if ((buscaMasculino && profMasculino) || (buscaFeminino && profFeminino)) {
            printf("----------------------------------------\n");
            printf("Matrícula: %d | Nome: %s\n", lista_Professor[i].matricula, lista_Professor[i].nome);
            printf("Data de Nascimento: %02d/%02d/%04d\n", 
                   lista_Professor[i].data_nascimento.dia, 
                   lista_Professor[i].data_nascimento.mes, 
                   lista_Professor[i].data_nascimento.ano);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum professor encontrado com este filtro.\n");
    }
    printf("----------------------------------------\n");
}

void listarProfessoresPorNome(Professor lista_Professor[], int contProfessores) {
    if (contProfessores == 0) {
        printf("\nNão há professores cadastrados!\n");
        return;
    }

    Professor lista_Ordenada[TAMPROFESSOR];
    for (int i = 0; i < contProfessores; i++) {
        lista_Ordenada[i] = lista_Professor[i]; 
    }

    for (int i = 0; i < contProfessores - 1; i++) {
        for (int j = i + 1; j < contProfessores; j++) {
            if (strcmp(lista_Ordenada[i].nome, lista_Ordenada[j].nome) > 0) {
                Professor profTemp = lista_Ordenada[i];
                lista_Ordenada[i] = lista_Ordenada[j];
                lista_Ordenada[j] = profTemp;
            }
        }
    }

    printf("\n~~~~~~ PROFESSORES ORDENADOS POR NOME ~~~~~~\n");
    for (int i = 0; i < contProfessores; i++) {
        printf("----------------------------------------\n");
        printf("Nome: %s\n", lista_Ordenada[i].nome);
        printf("Matrícula: %d | Sexo: %s\n", 
               lista_Ordenada[i].matricula, 
               (lista_Ordenada[i].sexo == 'M' || lista_Ordenada[i].sexo == 'm') ? "Masculino" : "Feminino");
        printf("Data de Nascimento: %02d/%02d/%04d\n", 
               lista_Ordenada[i].data_nascimento.dia, 
               lista_Ordenada[i].data_nascimento.mes, 
               lista_Ordenada[i].data_nascimento.ano);
    }
    printf("----------------------------------------\n");
}

void listarProfessoresPorData(Professor lista_Professor[], int contProfessores) {
    if (contProfessores == 0) {
        printf("\nNão há professores cadastrados!\n");
        return;
    }

    Professor lista_Ordenada[TAMPROFESSOR];
    for (int i = 0; i < contProfessores; i++) {
        lista_Ordenada[i] = lista_Professor[i];
    }

    for (int i = 0; i < contProfessores - 1; i++) {
        for (int j = i + 1; j < contProfessores; j++) {
            long data_i = (lista_Ordenada[i].data_nascimento.ano * 10000) + 
                          (lista_Ordenada[i].data_nascimento.mes * 100) + 
                           lista_Ordenada[i].data_nascimento.dia;

            long data_j = (lista_Ordenada[j].data_nascimento.ano * 10000) + 
                          (lista_Ordenada[j].data_nascimento.mes * 100) + 
                           lista_Ordenada[j].data_nascimento.dia;

            if (data_i > data_j) {
                Professor profTemp = lista_Ordenada[i];
                lista_Ordenada[i] = lista_Ordenada[j];
                lista_Ordenada[j] = profTemp;
            }
        }
    }

    printf("\n~~~~~~ PROFESSORES ORDENADOS POR DATA ~~~~~~\n");
    for (int i = 0; i < contProfessores; i++) {
        printf("----------------------------------------\n");
        printf("Data de Nascimento: %02d/%02d/%04d\n", 
               lista_Ordenada[i].data_nascimento.dia, 
               lista_Ordenada[i].data_nascimento.mes, 
               lista_Ordenada[i].data_nascimento.ano);
        printf("Nome: %s | Matrícula: %d\n", lista_Ordenada[i].nome, lista_Ordenada[i].matricula);
    }
    printf("----------------------------------------\n");
}

int atualizarProfessor(Professor lista_Professor[], int contProfessores) {
    int matriculaBusca;
    
    if (contProfessores == 0) return LISTA_VAZIA;

    printf("\nDigite a matrícula do professor que deseja atualizar: ");
    scanf("%d", &matriculaBusca);
    getchar(); 

    for (int i = 0; i < contProfessores; i++) {
        if (lista_Professor[i].matricula == matriculaBusca) {
            
            printf("~~~~ Professor Encontrado (%s) ~~~~\n", lista_Professor[i].nome);
            
            int novaMatricula;
            printf("Insira a nova matrícula: ");
            scanf("%d", &novaMatricula);
            getchar();
            if (!validarMatricula(novaMatricula)) return MATRICULA_INVALIDA;
            
            printf("Insira o novo nome: ");
            fgets(lista_Professor[i].nome, TAM_NOME, stdin);
            lista_Professor[i].nome[strcspn(lista_Professor[i].nome, "\n")] = '\0';

            char novoSexo;
            printf("Insira o novo sexo (M/F): ");
            scanf("%c", &novoSexo);
            getchar();
            if (!validarSexo(novoSexo)) return SEXO_INVALIDO;

            int d, m, a;
            printf("Insira a nova data de nascimento (DD MM AAAA): ");
            scanf("%d %d %d", &d, &m, &a);
            getchar();
            if (!validarData(d, m, a)) return DATA_INVALIDA;

            char novoCPF[TAM_CPF + 2];
            printf("Insira o novo CPF (11 dígitos): ");
            fgets(novoCPF, sizeof(novoCPF), stdin);
            if (novoCPF[strlen(novoCPF) - 1] == '\n') {
                novoCPF[strlen(novoCPF) - 1] = '\0';
            } else {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
            
            if (!validarCPF(novoCPF)) return CPF_INVALIDO;

            lista_Professor[i].matricula = novaMatricula;
            lista_Professor[i].sexo = novoSexo;
            lista_Professor[i].data_nascimento.dia = d;
            lista_Professor[i].data_nascimento.mes = m;
            lista_Professor[i].data_nascimento.ano = a;
            strcpy(lista_Professor[i].cpf, novoCPF);

            return ATL_SUCESSO;
        }
    }

    return INEXISTENTE;
}

int excluirProfessor(Professor lista_Professor[], int contProfessores) {
    int matriculaBusca;
    
    if (contProfessores == 0) return LISTA_VAZIA;

    printf("\nQual Professor deseja excluir? (digite a matrícula): ");
    scanf("%d", &matriculaBusca);
    getchar();

    if (!validarMatricula(matriculaBusca)) {
        return MATRICULA_INVALIDA;
    }

    for (int i = 0; i < contProfessores; i++) {
        if (lista_Professor[i].matricula == matriculaBusca) {
            
            for (int j = i; j < contProfessores - 1; j++) {
                lista_Professor[j] = lista_Professor[j + 1];
            }
            
            return EXC_SUCESSO;
        }
    }

    return INEXISTENTE;
}

//DISCIPLINA
int menuDisciplina(){
    int opcao;
    printf("\n");
    printf("<===== Menu Disciplina =====>\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar todas Disciplinas\n");
    printf("3 - Listar uma Disciplina\n");    
    printf("4 - Atualizar\n");
    printf("5 - Excluir\n");
    printf("6 - Inserir Aluno\n");
    printf("7 - Excluir Aluno\n");
    printf("Escolha uma opção: ");

    scanf("%d", &opcao);
    getchar();
    return opcao;
}

int cadastrarDisciplina(Disciplina lista_Disciplina[], int contDisciplina, Professor lista_Professor[], int contProfessores) {

    if (contProfessores == 0) return LISTA_VAZIA;
    
    if (contDisciplina == TAMDISCIPLINA) return LISTA_CHEIA;

    printf("\nInsira o código da disciplina (ex: INF029): ");
    fgets(lista_Disciplina[contDisciplina].codigo, TAM_CODIGO, stdin);
    lista_Disciplina[contDisciplina].codigo[strcspn(lista_Disciplina[contDisciplina].codigo, "\n")] = '\0';

    printf("Insira o nome da disciplina: ");
    fgets(lista_Disciplina[contDisciplina].nome, TAM_NOME, stdin);
    lista_Disciplina[contDisciplina].nome[strcspn(lista_Disciplina[contDisciplina].nome, "\n")] = '\0';

    printf("Insira o semestre (ex: 20241): ");
    scanf("%d", &lista_Disciplina[contDisciplina].semestre);
    getchar();

    if (!validarSemestre(lista_Disciplina[contDisciplina].semestre)) {
        return SEMESTRE_INVALIDO;
    }

    printf("Insira a matrícula do professor responsável: ");
    int matProf;
    scanf("%d", &matProf);
    getchar();

    int profExiste = 0;
    for (int i = 0; i < contProfessores; i++) {
        if (lista_Professor[i].matricula == matProf) {
            profExiste = 1;
            break;
        }
    }

    if (!profExiste) {
        return MATRICULA_INVALIDA;
    }

    lista_Disciplina[contDisciplina].matricula_professor = matProf;
    lista_Disciplina[contDisciplina].contAlunosMatriculados = 0;
    lista_Disciplina[contDisciplina].ativo = 1;

    return CAD_SUCESSO;
}

void listarDisciplina(Disciplina lista_Disciplina[], int contDisciplina, Professor lista_Professor[], int contProfessores) {
    
    if (contDisciplina == 0) {
        printf("\nNão há disciplinas cadastradas no momento!\n");
        return;
    }

    printf("\n~~~~~~~~ DISCIPLINAS ~~~~~~~~\n");

    for (int i = 0; i < contDisciplina; i++) {
        printf("-----------------------------------\n");
        printf("Código: %s\n", lista_Disciplina[i].codigo);
        printf("Nome: %s\n", lista_Disciplina[i].nome);

        int ano = lista_Disciplina[i].semestre / 10;
        int periodo = lista_Disciplina[i].semestre % 10;
        printf("Semestre: %d.%d\n", ano, periodo);

        char nomeProfessor[TAM_NOME] = "Desconhecido"; 
        
        for (int j = 0; j < contProfessores; j++) {
            if (lista_Professor[j].matricula == lista_Disciplina[i].matricula_professor) {
                strcpy(nomeProfessor, lista_Professor[j].nome);
                break;
            }
        }

        printf("Professor Responsável: %s (Matrícula: %d)\n", nomeProfessor, lista_Disciplina[i].matricula_professor);
        
        printf("Alunos Matriculados: %d / %d vagas preenchidas\n", lista_Disciplina[i].contAlunosMatriculados, TAMALUNOS);
    }
    printf("-----------------------------------\n");
}

void listarAlunosDaDisciplina(Disciplina lista_Disciplina[], int contDisciplina, Aluno lista_Alunos[], int contAlunos) {
    
    if (contDisciplina == 0) {
        printf("\nNão há disciplinas cadastradas!\n");
        return;
    }

    char codigoBusca[TAM_CODIGO + 2];
    printf("\nDigite o código da Disciplina que deseja detalhar: ");
    fgets(codigoBusca, sizeof(codigoBusca), stdin);
    codigoBusca[strcspn(codigoBusca, "\n")] = '\0';

    int achouDisciplina = 0;
    
    for (int i = 0; i < contDisciplina; i++) {
        if (strcmp(lista_Disciplina[i].codigo, codigoBusca) == 0) {
            achouDisciplina = 1;
            
            printf("\n~~~~~~ DETALHES DA DISCIPLINA ~~~~~~\n");
            printf("Disciplina: %s (%s)\n", lista_Disciplina[i].nome, lista_Disciplina[i].codigo);
            printf("Total de Alunos Matriculados: %d\n", lista_Disciplina[i].contAlunosMatriculados);
            printf("----------------------------------------\n");

            if (lista_Disciplina[i].contAlunosMatriculados == 0) {
                printf("Nenhum aluno matriculado nesta turma ainda.\n");
            } else {
                
                for (int j = 0; j < lista_Disciplina[i].contAlunosMatriculados; j++) {
                    int matBusca = lista_Disciplina[i].matriculas_alunos[j];

                    for (int k = 0; k < contAlunos; k++) {
                        if (lista_Alunos[k].matricula == matBusca) {
                            printf("- Matrícula: %d | Nome: %s\n", lista_Alunos[k].matricula, lista_Alunos[k].nome);
                            break; 
                        }
                    }
                }
            }
            printf("----------------------------------------\n");
            break; 
        }
    }

    if (!achouDisciplina) {
        printf("\nDisciplina Inexistente!\n");
    }
}

int atualizarDisciplina(Disciplina lista_Disciplina[], int contDisciplina, Professor lista_Professor[], int contProfessores) {
    
    if (contDisciplina == 0) return LISTA_VAZIA;

    char codigoBusca[TAM_CODIGO];
    
    printf("\nDigite o código da Disciplina que deseja atualizar: ");
    fgets(codigoBusca, sizeof(codigoBusca), stdin);
    codigoBusca[strcspn(codigoBusca, "\n")] = '\0'; 

    for (int i = 0; i < contDisciplina; i++) {
        
        if (strcmp(lista_Disciplina[i].codigo, codigoBusca) == 0) {
            
            printf("~~~~ Disciplina Encontrada: %s ~~~~\n", lista_Disciplina[i].nome);

            char novoCodigo[TAM_CODIGO];
            char novoNome[TAM_NOME];
            int novoSemestre;
            int novaMatriculaProf;

            printf("Insira o novo código (ex: INF029): ");
            fgets(novoCodigo, sizeof(novoCodigo), stdin);
            novoCodigo[strcspn(novoCodigo, "\n")] = '\0';

            printf("Insira o novo nome: ");
            fgets(novoNome, sizeof(novoNome), stdin);
            novoNome[strcspn(novoNome, "\n")] = '\0';

            printf("Insira o novo semestre (ex: 20241): ");
            scanf("%d", &novoSemestre);
            getchar();
            
            if (!validarSemestre(novoSemestre)) return SEMESTRE_INVALIDO;

            printf("Insira a matrícula do novo professor: ");
            scanf("%d", &novaMatriculaProf);
            getchar();

            int profExiste = 0;
            for (int j = 0; j < contProfessores; j++) {
                if (lista_Professor[j].matricula == novaMatriculaProf) {
                    profExiste = 1;
                    break;
                }
            }

            if (!profExiste) return MATRICULA_INVALIDA;

            strcpy(lista_Disciplina[i].codigo, novoCodigo);
            strcpy(lista_Disciplina[i].nome, novoNome);
            lista_Disciplina[i].semestre = novoSemestre;
            lista_Disciplina[i].matricula_professor = novaMatriculaProf;

            return ATL_SUCESSO;
        }
    }
    
    return INEXISTENTE; 
}

int excluirDisciplina(Disciplina lista_Disciplina[], int contDisciplina) {
    
    if (contDisciplina == 0) return LISTA_VAZIA;

    char codigoBusca[TAM_CODIGO];
    
    printf("\nDigite o código da Disciplina que deseja excluir: ");
    fgets(codigoBusca, sizeof(codigoBusca), stdin);
    codigoBusca[strcspn(codigoBusca, "\n")] = '\0';

    for (int i = 0; i < contDisciplina; i++) {
        
        if (strcmp(lista_Disciplina[i].codigo, codigoBusca) == 0) {
            
            for (int j = i; j < contDisciplina - 1; j++) {
                lista_Disciplina[j] = lista_Disciplina[j + 1];
            }
            
            return EXC_SUCESSO;
        }
    }

    return INEXISTENTE;
}

int inserirAlunoDisciplina(Disciplina lista_Disciplina[], int contDisciplina, Aluno lista_Alunos[], int contAlunos) {
    
    if (contDisciplina == 0 || contAlunos == 0) return LISTA_VAZIA;

    char codigoBusca[TAM_CODIGO];
    printf("\nDigite o código da Disciplina: ");
    fgets(codigoBusca, sizeof(codigoBusca), stdin);
    codigoBusca[strcspn(codigoBusca, "\n")] = '\0';


    for (int i = 0; i < contDisciplina; i++) {
        if (strcmp(lista_Disciplina[i].codigo, codigoBusca) == 0) {
            
            if (lista_Disciplina[i].contAlunosMatriculados == TAMALUNOS) {
                return LISTA_CHEIA;
            }

            int matAluno;
            printf("Digite a matrícula do aluno a ser inserido: ");
            scanf("%d", &matAluno);
            getchar();

            int alunoExiste = 0;
            for (int j = 0; j < contAlunos; j++) {
                if (lista_Alunos[j].matricula == matAluno) {
                    alunoExiste = 1;
                    break;
                }
            }
            if (!alunoExiste) return MATRICULA_INVALIDA;

            for (int j = 0; j < lista_Disciplina[i].contAlunosMatriculados; j++) {
                if (lista_Disciplina[i].matriculas_alunos[j] == matAluno) {
                    return ALUNO_DUPLICADO;
                }
            }

            lista_Disciplina[i].matriculas_alunos[lista_Disciplina[i].contAlunosMatriculados] = matAluno;
            lista_Disciplina[i].contAlunosMatriculados++;
            return CAD_SUCESSO;
        }
    }
    
    return INEXISTENTE;
}

int excluirAlunoDisciplina(Disciplina lista_Disciplina[], int contDisciplina) {
    
    if (contDisciplina == 0) return LISTA_VAZIA;

    char codigoBusca[TAM_CODIGO];
    printf("\nDigite o código da Disciplina: ");
    fgets(codigoBusca, sizeof(codigoBusca), stdin);
    codigoBusca[strcspn(codigoBusca, "\n")] = '\0';

    for (int i = 0; i < contDisciplina; i++) {
        if (strcmp(lista_Disciplina[i].codigo, codigoBusca) == 0) {
            
            if (lista_Disciplina[i].contAlunosMatriculados == 0) {
                return LISTA_VAZIA;
            }

            int matAluno;
            printf("Digite a matrícula do aluno a ser removido: ");
            scanf("%d", &matAluno);
            getchar();

            for (int j = 0; j < lista_Disciplina[i].contAlunosMatriculados; j++) {
                if (lista_Disciplina[i].matriculas_alunos[j] == matAluno) {
                    
                    for (int k = j; k < lista_Disciplina[i].contAlunosMatriculados - 1; k++) {
                        lista_Disciplina[i].matriculas_alunos[k] = lista_Disciplina[i].matriculas_alunos[k + 1];
                    }
                    
                    lista_Disciplina[i].contAlunosMatriculados--;
                    return EXC_SUCESSO;
                }
            }
            
            return INEXISTENTE;
        }
    }
    
    return INEXISTENTE;
}