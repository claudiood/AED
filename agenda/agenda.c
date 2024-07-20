#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#define OPCAO (sizeof(int)) //Variavel para fazer a seleção no switch
#define TAMANHO_LISTA (sizeof(int)) //Tamanho da lista de contatos da agenda
#define CONTADOR (sizeof(int)) //Variavel para fazer um for
#define BUSCAR (sizeof(char)*15) // Variavel para buscar um nome na agenda

#define CONTROLE (OPCAO + TAMANHO_LISTA + CONTADOR + BUSCAR) //Tamanho das variaveis de controle

#define NOME (sizeof(char)*15) //Tamanho de um nome
#define IDADE (sizeof(int)) //Tamanho da idade
#define EMAIL (sizeof(char)*32) //Tamanho de um email

#define CONTATO (NOME + IDADE + EMAIL) // Tamanho de um contato -> Nome, Idade e Email

#define BASE (CONTROLE + CONTATO) // Tamanho do bloco de memória necessário
                                  // para armazenar as variaveis de controle
                                  // e o tamanho de um contato


void *inserir(void *pBuffer);
void imprimir(void *pBuffer);
void buscar(void *pBuffer);

int main(){
    
    void *pBuffer = malloc(BASE);

    *(int*)(pBuffer + OPCAO) = 0;

    for(;;){
        printf("\n#-----------------------------#");
        printf("\n1 - Adicionar Pessoa\n2 - Remover Pessoa\n3 - Buscar Pessoa\n4 - Listar Todos\n5 - Sair\n");
        printf("#-----------------------------#\n\n");
        scanf("%d",(int*)(pBuffer)); 

        switch(*(int*)(pBuffer)){
            case 1: // APENAS INSERE, NÃO ORDENA POR ORDEM ALFABETICA!
                pBuffer = inserir(pBuffer);
                break;
            case 2:
                //Remover Pessoa
                break;
            case 3: // BUSCAR -> FEITO
                buscar(pBuffer);
                break;
            case 4: // IMPRIMIR -> FEITO
                imprimir(pBuffer);
                break;
            case 5: // SAIR -> FEITO
                free(pBuffer);
                exit(0);
            default:
                if(*(int*)(pBuffer) < 1 || *(int*)(pBuffer) > 5){
                    printf("\nOpcao invalida. Tente novamente!\n");
                }
                break;
        }
    }

    return 0;
}

void *inserir(void *pBuffer){

    pBuffer = realloc(pBuffer, BASE + (CONTATO * (*(int*)(pBuffer + OPCAO)+1)));

    printf("\nDigite o primeiro nome: ");
    scanf("%s",(char*)(pBuffer + BASE + (CONTATO * (*(int*)(pBuffer + OPCAO)))));

    printf("Digite a idade: ");
    scanf("%d",(int*)(pBuffer + BASE + (CONTATO * (*(int*)(pBuffer + OPCAO)) + NOME)));

    printf("Digite o email: ");
    scanf("%s",(char*)(pBuffer + BASE + (CONTATO * (*(int*)(pBuffer + OPCAO)) + NOME + IDADE)));

    *(int*)(pBuffer + OPCAO) += 1;

    return pBuffer;
}

void imprimir(void *pBuffer){
    printf("#----------- AGENDA -----------#");
    if((*(int*)(pBuffer + OPCAO))){
            for((*(int*)(pBuffer + OPCAO + TAMANHO_LISTA)) = 0; (*(int*)(pBuffer + OPCAO + TAMANHO_LISTA)) < *(int*)(pBuffer + OPCAO); (*(int*)(pBuffer + OPCAO + TAMANHO_LISTA))++){
            printf("\nNome: %s\n",(char*)(pBuffer + BASE + (CONTATO * (*(int*)(pBuffer + OPCAO + TAMANHO_LISTA)))));
            printf("Idade: %d\n",*(int*)(pBuffer + BASE + (CONTATO * (*(int*)(pBuffer + OPCAO + TAMANHO_LISTA))) + NOME));
            printf("Email: %s\n",(char*)(pBuffer + BASE + (CONTATO * (*(int*)(pBuffer + OPCAO + TAMANHO_LISTA))) + NOME + IDADE));
        }
    }
    else{
        printf("\nA lista esta vazia!\n");
    }
    printf("#------------------------------#\n");
}

void buscar(void *pBuffer){ 

    printf("Digite o nome que voce deseja buscar: ");
    scanf("%s",(char*)(pBuffer + OPCAO + TAMANHO_LISTA + CONTADOR));

    for((*(int*)(pBuffer + OPCAO + TAMANHO_LISTA)) = 0; (*(int*)(pBuffer + OPCAO + TAMANHO_LISTA)) < *(int*)(pBuffer + OPCAO); (*(int*)(pBuffer + OPCAO + TAMANHO_LISTA))++){

        if(strcmp((char*)(pBuffer + BASE + (CONTATO * (*(int*)(pBuffer + OPCAO + TAMANHO_LISTA)))) , (char*)(pBuffer + OPCAO + TAMANHO_LISTA + CONTADOR)) == 0){
            printf("\nIdade: %d\n",*(int*)(pBuffer + BASE + (CONTATO * (*(int*)(pBuffer + OPCAO + TAMANHO_LISTA))) + NOME));
            printf("Email: %s\n\n",(char*)(pBuffer + BASE + (CONTATO * (*(int*)(pBuffer + OPCAO + TAMANHO_LISTA))) + NOME + IDADE));
        }
    }
}
