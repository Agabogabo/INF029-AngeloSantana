#include <stdio.h>

//tamanhos
#define TAMALUNOS 3
#define TAM_NOME 256
#define TAM_DATA 12
#define TAM_CPF 12
#define TAMPROFESSOR 3
#define TAM_CODIGO 7
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

//funções
int menuPrincipal();

int menuAluno();
int cadastrarAluno(lista_Alunos, contAlunos);
void listarAlunos(lista_Alunos, contAlunos);
int atualizarAluno(lista_Alunos, contAlunos);
int excluirAluno(lista_Alunos, contAlunos);

int menuProfessor();
int cadastrarProfessor(lista_Professor, contProfessores);
void listarProfessores(lista_Professor, contProfessores);
int atualizarProfessor(lista_Professor, contProfessores);
int excluirProfessor(lista_Professor, contProfessores);

int menuDisciplina();
int cadastrarDisciplina(lista_Disciplina, contDisciplina, contProfessores, lista_Professor);
void listarDisciplina(lista_Disciplina, contDisciplina, lista_Professor);
int atualizarDisciplina(lista_Disciplina, contDisciplina, lista_Professor, contProfessores);
int excluirDisciplina(lista_Disciplina, contDisciplina);

//estruturas
typedef struct{
    int matricula;
    char nome[TAM_NOME];
    char sexo[TAM_NOME];
    char data[TAM_DATA];
    char cpf[TAM_CPF];
    int ativo;
}Aluno;

typedef struct{
    int matricula;
    char nome[TAM_NOME];
    char sexo[TAM_NOME];
    char data[TAM_DATA];
    char cpf[TAM_CPF];
    int ativo;
}Professor;

typedef struct{
    int semestre;
    char nome[TAM_NOME];
    char codigo[TAM_CODIGO];
    char nome_professor[TAM_NOME];
    int ativo;
}Disciplina;

//INICIO
int main (){
    int sair = 0;
    int contAlunos = 0;
    int contProfessores = 0;
    int contDisciplina = 0;
    Aluno lista_Alunos[TAMALUNOS];
    Professor lista_Professor[TAMPROFESSOR];
    Disciplina lista_Disciplina[TAMDISCIPLINA];

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
                                    printf("LISTA CHEIA!!!\n");
                                    break;
                                }

                                case MATRICULA_INVALIDA:{
                                    printf("MATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case SEXO_INVALIDO:{
                                    printf("SEXO INVÁLIDO!!!\n");
                                    break;
                                }

                                case CPF_INVALIDO:{
                                    printf("CPF INVÁLIDO!\n");
                                }

                                case CAD_SUCESSO:{
                                    printf("Matrícula concluída com sucesso!\n");
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
                            retorno = atualizarAluno(lista_Alunos, contAlunos);

                            switch(retorno){
                                case MATRICULA_INVALIDA:{
                                    printf("MATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case SEXO_INVALIDO:{
                                    printf("SEXO INVÁLIDO!!!\n");
                                    break;
                                }

                                case ATL_SUCESSO:{
                                    printf("Atualização concluída com sucesso!\n");
                                    break;
                                }
                                
                                case INEXISTENTE:{
                                    printf("ALUNO INEXISTENTE!\n");
                                    break;
                                }
                            }
                            break;
                        }

                        case 4:{
                            retorno = excluirAluno(lista_Alunos, contAlunos);
                            switch(retorno){
                                case LISTA_VAZIA:{
                                    printf("Não existe nenhum aluno ainda(Clique em 1 - Cadastrar Aluno)\n");
                                    break;
                                }

                                case MATRICULA_INVALIDA:{
                                    printf("MATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case EXC_SUCESSO:{
                                    printf("Exclusão concluída com sucesso!\n");
                                    contAlunos--;
                                    break;
                                }
                                
                                case INEXISTENTE:{
                                    printf("ALUNO INEXISTENTE!\n");
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
                                    printf("LISTA CHEIA!!!\n");
                                    break;
                                }

                                case MATRICULA_INVALIDA:{
                                    printf("MATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case SEXO_INVALIDO:{
                                    printf("SEXO INVÁLIDO!!!\n");
                                    break;
                                }

                                case CPF_INVALIDO:{
                                    printf("CPF INVÁLIDO!\n");
                                }

                                case CAD_SUCESSO:{
                                    printf("Matrícula concluída com sucesso!\n");
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
                            retorno = atualizarProfessor(lista_Professor, contProfessores);

                            switch(retorno){
                                case MATRICULA_INVALIDA:{
                                    printf("MATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case SEXO_INVALIDO:{
                                    printf("SEXO INVÁLIDO!!!\n");
                                    break;
                                }

                                case ATL_SUCESSO:{
                                    printf("Atualização concluída com sucesso!\n");
                                    break;
                                }
                                
                                case INEXISTENTE:{
                                    printf("PROFESSOR INEXISTENTE!\n");
                                    break;
                                }
                            }
                            break;
                        }

                        case 4:{
                            retorno = excluirProfessor(lista_Professor, contProfessores);
                            switch(retorno){
                                case LISTA_VAZIA:{
                                    printf("Não existe nenhum professor ainda(Clique em 1 - Cadastrar Professor)\n");
                                    break;
                                }

                                case MATRICULA_INVALIDA:{
                                    printf("MATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case EXC_SUCESSO:{
                                    printf("Exclusão concluída com sucesso!\n");
                                    contProfessores--;
                                    break;
                                }
                                
                                case INEXISTENTE:{
                                    printf("ALUNO INEXISTENTE!\n");
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
                            retorno = cadastrarDisciplina(lista_Disciplina, contDisciplina, contProfessores, lista_Professor);

                            switch(retorno){
                                case LISTA_CHEIA:{
                                    printf("LISTA CHEIA!!!\n");
                                    break;
                                }

                                case SEMESTRE_INVALIDO:{
                                    printf("SEMESTRE INVÁLIDO!!!\n");
                                    break;
                                }

                                case MATRICULA_INVALIDA:{
                                    printf("MATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case CAD_SUCESSO:{
                                    printf("Matrícula concluída com sucesso!\n");
                                    contProfessores++;
                                    break;
                                }    
                            }
                            
                            break;                            
                        }

                        case 2:{
                            listarDisciplina(lista_Disciplina, contDisciplina, lista_Professor);
                            break;
                        }

                        case 3:{
                            retorno = atualizarDisciplina(lista_Disciplina, contDisciplina, lista_Professor, contProfessores);

                            switch(retorno){
                                case MATRICULA_INVALIDA:{
                                    printf("MATRÍCULA INVÁLIDA!!!\n");
                                    break;
                                }

                                case SEMESTRE_INVALIDO:{
                                    printf("SEMESTRE INVÁLIDO!!!\n");
                                    break;
                                }

                                case ATL_SUCESSO:{
                                    printf("Atualização concluída com sucesso!\n");
                                    break;
                                }
                                
                                case INEXISTENTE:{
                                    printf("DISCIPLINA INEXISTENTE!\n");
                                    break;
                                }
                            }
                            break;
                        }

                        case 4:{
                            retorno = excluirDisciplina(lista_Disciplina, contDisciplina);
                            switch(retorno){
                                case LISTA_VAZIA:{
                                    printf("Não existe nenhum disciplina ainda(Clique em 1 - Cadastrar Disciplina)\n");
                                    break;
                                }

                                case EXC_SUCESSO:{
                                    printf("Exclusão concluída com sucesso!\n");
                                    contProfessores--;
                                    break;
                                }
                                
                                case INEXISTENTE:{
                                    printf("DISCIPLINA INEXISTENTE!\n");
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
                break; 
            }

            default:{
                printf("<<<<< Sessão inválida! >>>>>\n");
            }
        }

    }
    
}

int menuPrincipal(){
    int opcao;
    printf("\n");
    printf("<===== Menu Principal =====>\n");
    printf("0 - Sair\n");
    printf("1 - Alunos\n");
    printf("2 - Professores\n");
    printf("3 - Disciplinas\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}

//ALUNO
int menuAluno(){
    int opcao;
    printf("\n");
    printf("<===== Menu Alunos =====>\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Atualizar\n");
    printf("4 - Excluir\n");
    printf("Escolha uma opção: ");

    scanf("%d", &opcao);
    return opcao;
}

int cadastrarAluno(Aluno lista_Alunos[], int contAlunos){
    int matricula;
    char sexo;
    char cpf[TAM_CPF];
    
    if(contAlunos == TAMALUNOS){
        return LISTA_CHEIA;
    }else{
        lista_Alunos[contAlunos].ativo = 1;
        printf("Insira a matrícula:");
        scanf("%d", &matricula);
        getchar();
        if(matricula < 0){
            return MATRICULA_INVALIDA;
        }else{
            printf("Insira o nome:");
            fgets(lista_Alunos[contAlunos].nome, TAM_NOME, stdin);
            int i = 0;
            while (lista_Alunos[contAlunos].nome[i] != '\n' && lista_Alunos[contAlunos].nome[i] != '\0') {
                i++;
            }
            lista_Alunos[contAlunos].nome[i] = '\0';

            printf("Insira o sexo (M)asculino (F)eminino:");
            scanf(" %c", &sexo);
            getchar();
            if(sexo != 'M' && sexo != 'F' && sexo != 'm' && sexo != 'f'){
                return SEXO_INVALIDO;
            }else{
                printf("Insira a data de nascimento(DD/MM/AAAA):");
                fgets(lista_Alunos[contAlunos].data, TAM_DATA, stdin);
                int i = 0;
                while (lista_Alunos[contAlunos].data[i] != '\n' && lista_Alunos[contAlunos].data[i] != '\0') {
                    i++;
                }
                lista_Alunos[contAlunos].data[i] = '\0';

                printf("Insira o CPF do aluno(sem pontos e traço):");
                fgets(lista_Alunos[contAlunos].cpf, TAM_CPF, stdin);
                int j = 0;
                while (lista_Alunos[contAlunos].cpf[j] != '\n' && lista_Alunos[contAlunos].cpf[j] != '\0') {
                    j++;
                }
                lista_Alunos[contAlunos].cpf[j] = '\0';

                lista_Alunos[contAlunos].matricula = matricula;
                if(sexo == 'M' || sexo == 'm'){
                    char masculino[] = "Masculino";
                    int i = 0;
                    while (masculino[i] != '\0' && i < TAM_NOME) {
                        lista_Alunos[contAlunos].sexo[i] = masculino[i];
                        i++;
                    }
                    lista_Alunos[contAlunos].sexo[i] = '\0';
                    return CAD_SUCESSO;
                }else if(sexo == 'F' || sexo == 'f'){
                    char feminino[] = "Feminino";
                    int i = 0;
                    while (feminino[i] != '\0' && i < TAM_NOME) {
                        lista_Alunos[contAlunos].sexo[i] = feminino[i];
                        i++;
                    }
                    lista_Alunos[contAlunos].sexo[i] = '\0';
                    return CAD_SUCESSO;
                }
            }    
        }
    }
}

void listarAlunos(Aluno lista_Alunos[], int contAlunos){
    if(contAlunos == 0){
        printf("Não tem Alunos para listar!\n");
    }else{
        for(int i = 0; i < contAlunos; i++){
        printf("\n");
        printf("~~~~~~~~ Aluno %d ~~~~~~~~\n", i);
        printf("Matrícula: %d\nNome: %s\nSexo: %s\nData de Nascimento: %s\nCPF: %s\n", lista_Alunos[i].matricula, lista_Alunos[i].nome, lista_Alunos[i].sexo, lista_Alunos[i].data, lista_Alunos[i].cpf);
        }
    }
}

int atualizarAluno(Aluno lista_Alunos[], int contAlunos){
    int matricula;
    char sexo;

    printf("Digite a matrícula de qual Aluno deseja atualizar:");
    scanf("%d", &matricula);
    int achou = 0;
    for(int i = 0; i < contAlunos; i++){
        if(matricula == lista_Alunos[i].matricula){
            printf("Insira a nova matrícula:");
            scanf("%d", &matricula);
            getchar();
            if(matricula < 0){
                return MATRICULA_INVALIDA;
            }else{
                printf("Insira o novo nome:");
                fgets(lista_Alunos[i].nome, TAM_NOME, stdin);
                int j = 0;

                while (lista_Alunos[i].nome[j] != '\n' && lista_Alunos[i].nome[j] != '\0') {
                    j++;
                }
                lista_Alunos[i].nome[j] = '\0';
                printf("Insira o novo sexo (M)asculino e (F)eminino:");
                scanf(" %c", &sexo);
                getchar();
                if(sexo != 'M' && sexo != 'F' && sexo != 'm' && sexo != 'f'){
                    return SEXO_INVALIDO;
                }else{
                    printf("Insira a nova data de nascimento(DD/MM/AAAA):");
                    fgets(lista_Alunos[i].data, TAM_DATA, stdin);
                    int j = 0;
                    while (lista_Alunos[i].data[j] != '\n' && lista_Alunos[i].data[j] != '\0') {
                        j++;
                    }
                    lista_Alunos[i].data[j] = '\0';

                    printf("Insira o CPF do aluno(sem pontos e traço):");
                    fgets(lista_Alunos[i].cpf, TAM_CPF, stdin);
                    int k = 0;
                    while (lista_Alunos[i].cpf[k] != '\n' && lista_Alunos[i].cpf[k] != '\0') {
                        k++;
                    }
                    lista_Alunos[i].cpf[k] = '\0';

                    lista_Alunos[i].matricula = matricula;
                    if(sexo == 'M' || sexo == 'm'){
                    char masculino[] = "Masculino";
                        int j = 0;
                        while (masculino[j] != '\0' && j < TAM_NOME) {
                            lista_Alunos[i].sexo[j] = masculino[j];
                            j++;
                        }
                        lista_Alunos[i].sexo[j] = '\0';
                        return CAD_SUCESSO;
                    }else if(sexo == 'F' || sexo == 'f'){
                        char feminino[] = "Feminino";
                        int j = 0;
                        while (feminino[j] != '\0' && j < TAM_NOME) {
                            lista_Alunos[i].sexo[j] = feminino[j];
                            j++;
                        }
                        lista_Alunos[i].sexo[j] = '\0';
                        return CAD_SUCESSO;
                    }
                }
            }
        }
    }
    if(achou == 0){
        return INEXISTENTE;
    }
}

int excluirAluno(Aluno lista_Alunos[], int contAlunos){
    int matricula;
    char sexo;
    int achou = 0;

    if(contAlunos == 0){
        return LISTA_VAZIA;
    }else{
        printf("Qual Aluno deseja excluir?(digite a matrícula):");
        scanf("%d", &matricula);
        if(matricula < 0){
            return MATRICULA_INVALIDA;
        }else{
            for(int i = 0; i < contAlunos; i++){
                if(matricula == lista_Alunos[i].matricula){
                    lista_Alunos[i].matricula = lista_Alunos[i + 1].matricula;

                    int j = 0;
                    while (lista_Alunos[i + 1].nome[j] != '\0' && j < TAM_NOME) {
                        lista_Alunos[i].nome[j] = lista_Alunos[i + 1].nome[j];
                        j++;
                    }
                    lista_Alunos[i].nome[j] = '\0';

                    int k = 0;
                    while (lista_Alunos[i + 1].sexo[k] != '\0' && k < TAM_NOME) {
                        lista_Alunos[i].sexo[k] = lista_Alunos[i + 1].sexo[k];
                        k++;
                    }
                    lista_Alunos[i].sexo[k] = '\0';

                    int l = 0;
                    while (lista_Alunos[i + 1].data[l] != '\0' && l < TAM_NOME) {
                        lista_Alunos[i].data[l] = lista_Alunos[i + 1].data[l];
                        l++;
                    }
                    lista_Alunos[i].data[l] = '\0';

                    int n = 0;
                    while (lista_Alunos[i + 1].cpf[n] != '\0' && n < TAM_NOME) {
                        lista_Alunos[i].cpf[n] = lista_Alunos[i + 1].cpf[n];
                        n++;
                    }
                    lista_Alunos[i].cpf[n] = '\0';
                    
                    achou = 1;
                    return EXC_SUCESSO;
                }
            }
        }
        if(achou == 0){
            return INEXISTENTE;
        }
    }
}

//PROFESSOR
int menuProfessor(){
    int opcao;
    printf("\n");
    printf("<===== Menu Professor =====>\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Atualizar\n");
    printf("4 - Excluir\n");
    printf("Escolha uma opção: ");

    scanf("%d", &opcao);
    return opcao;
}

int cadastrarProfessor(Professor lista_Professor[], int contProfessores){
    int matricula;
    char sexo;
    char cpf[TAM_CPF];
    
    if(contProfessores == TAMPROFESSOR){
        return LISTA_CHEIA;
    }else{
        lista_Professor[contProfessores].ativo = 1;
        printf("Insira a matrícula:");
        scanf("%d", &matricula);
        getchar();
        if(matricula < 0){
            return MATRICULA_INVALIDA;
        }else{
            printf("Insira o nome:");
            fgets(lista_Professor[contProfessores].nome, TAM_NOME, stdin);
            int i = 0;
            while (lista_Professor[contProfessores].nome[i] != '\n' && lista_Professor[contProfessores].nome[i] != '\0') {
                i++;
            }
            lista_Professor[contProfessores].nome[i] = '\0';

            printf("Insira o sexo (M)asculino (F)eminino:");
            scanf(" %c", &sexo);
            getchar();
            if(sexo != 'M' && sexo != 'F' && sexo != 'm' && sexo != 'f'){
                return SEXO_INVALIDO;
            }else{
                printf("Insira a data de nascimento(DD/MM/AAAA):");
                fgets(lista_Professor[contProfessores].data, TAM_DATA, stdin);
                int i = 0;
                while (lista_Professor[contProfessores].data[i] != '\n' && lista_Professor[contProfessores].data[i] != '\0') {
                    i++;
                }
                lista_Professor[contProfessores].data[i] = '\0';

                printf("Insira o CPF do professor(sem pontos e traço):");
                fgets(lista_Professor[contProfessores].cpf, TAM_CPF, stdin);
                int j = 0;
                while (lista_Professor[contProfessores].cpf[j] != '\n' && lista_Professor[contProfessores].cpf[j] != '\0') {
                    j++;
                }
                lista_Professor[contProfessores].cpf[j] = '\0';

                lista_Professor[contProfessores].matricula = matricula;
                if(sexo == 'M' || sexo == 'm'){
                    char masculino[] = "Masculino";
                    int i = 0;
                    while (masculino[i] != '\0' && i < TAM_NOME) {
                        lista_Professor[contProfessores].sexo[i] = masculino[i];
                        i++;
                    }
                    lista_Professor[contProfessores].sexo[i] = '\0';
                    return CAD_SUCESSO;
                }else if(sexo == 'F' || sexo == 'f'){
                    char feminino[] = "Feminino";
                    int i = 0;
                    while (feminino[i] != '\0' && i < TAM_NOME) {
                        lista_Professor[contProfessores].sexo[i] = feminino[i];
                        i++;
                    }
                    lista_Professor[contProfessores].sexo[i] = '\0';
                    return CAD_SUCESSO;
                }
            }    
        }
    }
}

void listarProfessores(Professor lista_Professor[], int contProfessores){
    if(contProfessores == 0){
        printf("Não tem Professores para listar!\n");
    }else{
        for(int i = 0; i < contProfessores; i++){
        printf("\n");
        printf("~~~~~~~~ Professor %d ~~~~~~~~\n", i);
        printf("Matrícula: %d\nNome: %s\nSexo: %s\nData de Nascimento: %s\nCPF: %s\n", lista_Professor[i].matricula, lista_Professor[i].nome, lista_Professor[i].sexo, lista_Professor[i].data, lista_Professor[i].cpf);
        }
    }
}

int atualizarProfessor(Professor lista_Professor[], int contProfessores){
    int matricula;
    char sexo;

    printf("Digite a matrícula de qual Professor deseja atualizar:");
    scanf("%d", &matricula);
    int achou = 0;
    for(int i = 0; i < contProfessores; i++){
        if(matricula == lista_Professor[i].matricula){
            printf("Insira a nova matrícula:");
            scanf("%d", &matricula);
            getchar();
            if(matricula < 0){
                return MATRICULA_INVALIDA;
            }else{
                printf("Insira o novo nome:");
                fgets(lista_Professor[i].nome, TAM_NOME, stdin);
                int j = 0;

                while (lista_Professor[i].nome[j] != '\n' && lista_Professor[i].nome[j] != '\0') {
                    j++;
                }
                lista_Professor[i].nome[j] = '\0';
                printf("Insira o novo sexo (M)asculino e (F)eminino:");
                scanf(" %c", &sexo);
                getchar();
                if(sexo != 'M' && sexo != 'F' && sexo != 'm' && sexo != 'f'){
                    return SEXO_INVALIDO;
                }else{
                    printf("Insira a nova data de nascimento(DD/MM/AAAA):");
                    fgets(lista_Professor[i].data, TAM_DATA, stdin);
                    int j = 0;
                    while (lista_Professor[i].data[j] != '\n' && lista_Professor[i].data[j] != '\0') {
                        j++;
                    }
                    lista_Professor[i].data[j] = '\0';

                    printf("Insira o CPF do aluno(sem pontos e traço):");
                    fgets(lista_Professor[i].cpf, TAM_CPF, stdin);
                    int k = 0;
                    while (lista_Professor[i].cpf[k] != '\n' && lista_Professor[i].cpf[k] != '\0') {
                        k++;
                    }
                    lista_Professor[i].cpf[k] = '\0';

                    lista_Professor[i].matricula = matricula;
                    if(sexo == 'M' || sexo == 'm'){
                    char masculino[] = "Masculino";
                        int j = 0;
                        while (masculino[j] != '\0' && j < TAM_NOME) {
                            lista_Professor[i].sexo[j] = masculino[j];
                            j++;
                        }
                        lista_Professor[i].sexo[j] = '\0';
                        return ATL_SUCESSO;
                    }else if(sexo == 'F' || sexo == 'f'){
                        char feminino[] = "Feminino";
                        int j = 0;
                        while (feminino[j] != '\0' && j < TAM_NOME) {
                            lista_Professor[i].sexo[j] = feminino[j];
                            j++;
                        }
                        lista_Professor[i].sexo[j] = '\0';
                        return ATL_SUCESSO;
                    }
                }
            }
        }
    }
    if(achou == 0){
        return INEXISTENTE;
    }
}

int excluirProfessor(Professor lista_Professor[], int contProfessores){
    int matricula;
    char sexo;
    int achou = 0;

    if(contProfessores == 0){
        return LISTA_VAZIA;
    }else{
        printf("Qual Professor deseja excluir?(digite a matrícula):");
        scanf("%d", &matricula);
        if(matricula < 0){
            return MATRICULA_INVALIDA;
        }else{
            for(int i = 0; i < contProfessores; i++){
                if(matricula == lista_Professor[i].matricula){
                    lista_Professor[i].matricula = lista_Professor[i + 1].matricula;

                    int j = 0;
                    while (lista_Professor[i + 1].nome[j] != '\0' && j < TAM_NOME) {
                        lista_Professor[i].nome[j] = lista_Professor[i + 1].nome[j];
                        j++;
                    }
                    lista_Professor[i].nome[j] = '\0';

                    int k = 0;
                    while (lista_Professor[i + 1].sexo[k] != '\0' && k < TAM_NOME) {
                        lista_Professor[i].sexo[k] = lista_Professor[i + 1].sexo[k];
                        k++;
                    }
                    lista_Professor[i].sexo[k] = '\0';

                    int l = 0;
                    while (lista_Professor[i + 1].data[l] != '\0' && l < TAM_NOME) {
                        lista_Professor[i].data[l] = lista_Professor[i + 1].data[l];
                        l++;
                    }
                    lista_Professor[i].data[l] = '\0';

                    int n = 0;
                    while (lista_Professor[i + 1].cpf[n] != '\0' && n < TAM_NOME) {
                        lista_Professor[i].cpf[n] = lista_Professor[i + 1].cpf[n];
                        n++;
                    }
                    lista_Professor[i].cpf[n] = '\0';
                    
                    achou = 1;
                    return EXC_SUCESSO;
                }
            }
        }
        if(achou == 0){
            return INEXISTENTE;
        }
    }
}

//DISCIPLINA
int menuDisciplina(){
    int opcao;
    printf("\n");
    printf("<===== Menu Disciplina =====>\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Atualizar\n");
    printf("4 - Excluir\n");
    printf("5 - Inserir Aluno\n");
    printf("6 - Excluir Aluno\n");
    printf("Escolha uma opção: ");

    scanf("%d", &opcao);
    return opcao;
}

int cadastrarDisciplina(Disciplina lista_Disciplina[], int contDisciplina, int contProfessores, Professor lista_Professor[]){
    int semestre;
    int matricula;
    
    if(contDisciplina == TAMDISCIPLINA){
        return LISTA_CHEIA;
    }else{
        lista_Disciplina[contDisciplina].ativo = 1;
        printf("Insira o semestre da disciplina:");
        scanf("%d", &semestre);
        getchar();
        if(semestre < 0){
            return SEMESTRE_INVALIDO;
        }else{
            printf("Insira o nome:");
            fgets(lista_Disciplina[contDisciplina].nome, TAM_NOME, stdin);
            int i = 0;
            while (lista_Disciplina[contDisciplina].nome[i] != '\n' && lista_Disciplina[contDisciplina].nome[i] != '\0') {
                i++;
            }
            lista_Disciplina[contDisciplina].nome[i] = '\0';

            printf("Insira o código da disciplina(ex: INF029):");
            fgets(lista_Disciplina[contDisciplina].codigo, TAM_CODIGO, stdin);
            int j = 0;
            while (lista_Disciplina[contDisciplina].codigo[j] != '\n' && lista_Disciplina[contDisciplina].codigo[j] != '\0') {
                j++;
            }
            lista_Disciplina[contDisciplina].codigo[j] = '\0';

            printf("Insira a matrícula do professor: ");
            scanf("%d", &matricula);
            int achou = 0;
            for(int i = 0; i < contProfessores; i++){
                if(lista_Professor[i].matricula == matricula){
                    int j = 0;
                    while (lista_Professor[i].nome[j] != '\0' && j < TAM_NOME) {
                        lista_Disciplina[contDisciplina].nome_professor[j] = lista_Professor[i].nome[j];
                        j++;
                    }
                    lista_Disciplina[contDisciplina].nome_professor[j] = '\0';
                    achou = 1;
                }
            }
            if(achou == 0){
                return MATRICULA_INVALIDA;
            }else{
                lista_Disciplina[contDisciplina].semestre = semestre;
                return CAD_SUCESSO;
            }
        }    
    }
}

void listarDisciplina(Disciplina lista_Disciplina[], int contDisciplina, Professor lista_Professor[]){
    if(contDisciplina == 0){
        printf("Não tem Professores para listar!\n");
    }else{
        for(int i = 0; i < contDisciplina; i++){
        printf("\n");
        printf("~~~~~~~~ Disciplina %d ~~~~~~~~\n", i);
        printf("Nome: %s\nCódigo: %s\n%dº Semestre\nProfessor: %s\n", lista_Disciplina[i].nome, lista_Disciplina[i].codigo, lista_Disciplina[i].semestre, lista_Disciplina[i].nome_professor);
        }
    }
}

int atualizarDisciplina(Disciplina lista_Disciplina[], int contDisciplina, Professor lista_Professor[], int contProfessores){
    int semestre;
    int matricula;
    char codigo[TAM_CODIGO];

    printf("Digite o código de qual Disciplina deseja atualizar:");
    fgets(codigo, TAM_CODIGO, stdin);
    int j = 0;
    while (codigo[j] != '\n' && codigo[j] != '\0') {
        j++;
    }
    codigo[j] = '\0';
    int achou = 0;
    int i = 0;
    while(i < contDisciplina && achou == 0){
        int igual = 0;
        for(int j = 0; j < TAM_CODIGO; j++){
            if(codigo[j] == lista_Disciplina[i].codigo[j]){
                igual++;
            }
        }
        if(igual == TAM_CODIGO){
            achou = 1;
        }
        i++;
    }
    
    if(achou == 0){
        return INEXISTENTE;
    }else{
        printf("Insira o novo semestre da disciplina:");
        scanf("%d", &semestre);
        getchar();
        if(semestre < 0){
            return SEMESTRE_INVALIDO;
        }else{
            printf("Insira o nome:");
            fgets(lista_Disciplina[i].nome, TAM_NOME, stdin);
            int j = 0;
            while (lista_Disciplina[i].nome[j] != '\n' && lista_Disciplina[contDisciplina].nome[j] != '\0') {
                j++;
            }
            lista_Disciplina[i].nome[j] = '\0';

            printf("Insira o código da disciplina(ex: INF029):");
            fgets(lista_Disciplina[i].codigo, TAM_CODIGO, stdin);
            int k = 0;
            while (lista_Disciplina[i].codigo[k] != '\n' && lista_Disciplina[i].codigo[k] != '\0') {
                k++;
            }
            lista_Disciplina[i].codigo[k] = '\0';

            achou = 0;
            for(int j = 0; j < contProfessores; j++){
                if(lista_Professor[j].matricula == matricula){
                    int k = 0;
                    while (lista_Professor[j].nome[k] != '\0' && j < TAM_NOME) {
                        lista_Disciplina[i].nome_professor[k] = lista_Professor[j].nome[k];
                        k++;
                    }
                    lista_Disciplina[i].nome_professor[k] = '\0';
                    achou = 1;
                }
            }
            if(achou == 0){
                return MATRICULA_INVALIDA;
            }else{
                lista_Disciplina[contDisciplina].semestre = semestre;
                return ATL_SUCESSO;
            }
        }
    }
}

int excluirDisciplina(Disciplina lista_Disciplina[], int contDisciplina){
    int semestre;
    int matricula;
    char codigo[TAM_CODIGO];

    if(contDisciplina == 0){
        return LISTA_VAZIA;
    }else{
        printf("Digite o código de qual Disciplina deseja excluir:");
        fgets(codigo, TAM_CODIGO, stdin);
        int j = 0;
        while (codigo[j] != '\n' && codigo[j] != '\0') {
            j++;
        }
        codigo[j] = '\0';
        int achou = 0;
        int i = 0;
        while(i < contDisciplina && achou == 0){
            int igual = 0;
            for(int j = 0; j < TAM_CODIGO; j++){
                if(codigo[j] == lista_Disciplina[i].codigo[j]){
                    igual++;
                }
            }
            if(igual == TAM_CODIGO){
                achou = 1;
            }
            i++;
        }
        
        if(achou == 0){
            return INEXISTENTE;
        }else{
            lista_Disciplina[i].semestre = lista_Disciplina[i + 1].semestre;

            int j = 0;
            while (lista_Disciplina[i + 1].nome[j] != '\0' && j < TAM_NOME) {
                lista_Disciplina[i].nome[j] = lista_Disciplina[i + 1].nome[j];
                j++;
            }
            lista_Disciplina[i].nome[j] = '\0';

            int k = 0;
            while (lista_Disciplina[i + 1].codigo[k] != '\0' && k < TAM_CODIGO) {
                lista_Disciplina[i].codigo[k] = lista_Disciplina[i + 1].codigo[k];
                k++;
            }
            lista_Disciplina[i].codigo[k] = '\0';

            int l = 0;
            while (lista_Disciplina[i + 1].nome_professor[l] != '\0' && l < TAM_NOME) {
                lista_Disciplina[i].nome_professor[l] = lista_Disciplina[i + 1].nome_professor[l];
                l++;
            }
            lista_Disciplina[i].nome_professor[l] = '\0';
            return EXC_SUCESSO;
        }
    }
}

