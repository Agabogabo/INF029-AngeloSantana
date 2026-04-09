#include <stdio.h>

#define TAMALUNOS 3

typedef struct{
    int matricula;
    char sexo;
    int ativo;
}Aluno;

int main (){
    int sair = 0;

    while(!sair){
        int opcao;
        int contAlunos;

        printf("Escolha uma opção:\n");
        printf("0 - Sair\n");
        printf("1 - Alunos\n");
        printf("2 - Professores\n");
        printf("3 - Disciplinas\n");

        scanf("%d", &opcao);
        switch(opcao){
            case 0:{
                sair = 1;
                break;
            }

            case 1:{
                int sairAluno = 0;

                while(!sairAluno){
                    int opcaoAluno;
                    Aluno lista_Alunos[TAMALUNOS];
                    

                    printf("<===== Menu Alunos =====>\n");
                    printf("Escolha uma opção:\n");
                    printf("0 - Sair\n");
                    printf("1 - Cadastrar\n");
                    printf("2 - Listar\n");
                    printf("3 - Atualizar\n");
                    printf("4 - Excluir\n");
                    
                    scanf("%d", &opcaoAluno);
                    switch(opcaoAluno){
                        case 0:{
                            sairAluno = 1;
                            break;
                        }
                        
                        case 1:{
                            if(contAlunos == TAMALUNOS){
                                printf("LISTA CHEIA!!!");
                            }else{
                                lista_Alunos[contAlunos].ativo = 1;
                                printf("Insira a matícula:");
                                scanf("%d", &lista_Alunos[contAlunos].matricula);

                                printf("Insira o sexo:");
                                scanf(" %c", &lista_Alunos[contAlunos].sexo);
                                printf("Matrícula concluída com sucesso!\n");
                                contAlunos++;
                            }
                            break;                            
                        }

                        case 2:{
                            if(contAlunos == 0){
                                printf("Não tem Alunos para listar!");
                            }else{
                                for(int i = 0; i < contAlunos; i++){
                                printf("Matrícula: %d, Sexo %c\n", lista_Alunos[i].matricula, lista_Alunos[i].sexo);
                                }
                            }
                            break;
                        }

                    }
                }
                break;    
            }
            
            case 2:{
                printf("<===== Menu Professores =====>\n");
                break;
            }

            case 3:{
                printf("<===== Menu Disciplias =====>\n");
                break;
            }

            default:{
                printf("<<<<< Sessão inválida! >>>>>\n");
            }
        }

    }
    
}