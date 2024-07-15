#include <stdio.h>
#include <stdlib.h>

typedef	struct lista{
    char valor;
    struct lista *proximo, *anterior;
}Lista;

void inserir(Lista **lista, char num);
void imprimir(Lista *lista);
int contadorXY(Lista **lista, int *ptr1, int *ptr2, char n, char m);

int main(){

    Lista *lista = NULL;
    int opcao, valor, resultado = 0, *ptr1, *ptr2, verificador = 0;
    char *s = "cdbcbbaaabab", n = 'a', m = 'b';

    int ponteiro1 = 0;
    int ponteiro2 = 0;

    int x = 4;
    int y = 5;

    //Insere a string na lista
    while(*s != '\0'){
        inserir(&lista, *s);
        s++;
    }
    //Linka os ponteiros às variaveis para fazer incremento
    ptr1 = &ponteiro1;
    ptr2 = &ponteiro2;
    
    do{
        printf("\nEscolha uma opcao:\n0 - Sair\n1 - Remover AB/BA\n2 - Imprimir\n");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                //Looping para removida dos elementos BA ou AB
                do{
                    //Testa a prioridade, caso x valha mais que Y, AB terá prioridade na retirada, caso contrário será o BA
                    if(x > y){
                        verificador = contadorXY(&lista, ptr1, ptr2, n, m);
                    }
                    else{
                        verificador = contadorXY(&lista, ptr1, ptr2, m, n);
                    }
                }while(verificador);
                break;
            case 2:
                imprimir(lista);
                break;
            default:
                if(opcao != 0){
                    printf("\nOpcao invalida, tente novamente!\n");
                }
                break;
        }
    }while(opcao != 0);

    //Testa prioridade para saber qual peso deve ser multiplicar cada variavel
    if(x > y){
        resultado = (*ptr1*y) + (*ptr2*x);
    }
    else{
        resultado = (*ptr1*x) + (*ptr2*y);
    }
    printf("\nO resultado da soma de X e Y foi igual a: %d\n",resultado);
    printf("\nFim do programa!\n");

    return 0;
}

void inserir(Lista **lista, char num){

    Lista *aux, *item = malloc(sizeof(Lista));

    if(item){
        item->proximo = NULL;
        item->valor = num;
        if(*lista == NULL){
            *lista = item;
        }
        else{
            aux = *lista;
            while(aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = item;
        }
    }
    else{
        printf("\nErro ao alocar memoria!\n");
    }
}

void imprimir(Lista *lista){
    printf("\n-----------------LISTA-----------------\n\n");
    while(lista){
        printf("%c",lista->valor);
        lista = lista->proximo;
    }
    printf("\n\n--------------FIM DA LISTA-------------");
}

int contadorXY(Lista **lista, int *ptr1, int *ptr2, char n, char m){
    Lista *remover = NULL, *item = *lista, *anterior = NULL;

    if(item){
        while(item && item->proximo){
            //Como n tem o valor 'a' e m o valor 'b' esse condicional testa se encontramos a subpalabra AB
            if(item->valor == n && item->proximo->valor == m){
                //Caso tenha encontrado, incrementamos o valor do ponteiro
                (*ptr2)++;

                remover = item;
                
                if(anterior){
                    anterior->proximo = item->proximo->proximo;
                }
                else{
                    *lista = item->proximo->proximo;
                }
                
                free(remover->proximo);
                free(remover);

                return 1;
            }
            else{
                anterior = item;
                item = item->proximo;
            }
        }
        //Atribui o valor da lista ao ponteiro item para utilizar o looping novamente com o valor atualizado.
        item = *lista;

        while(item && item->proximo){
            //Como n tem o valor 'a' e m o valor 'b' esse condicional testa se encontramos a subpalabra BA
            if(item->valor == m && item->proximo->valor == n){
                (*ptr1)++;

                remover = item;
                
                if(anterior){
                    anterior->proximo = item->proximo->proximo;
                }
                else{
                    *lista = item->proximo->proximo;
                }
                
                free(remover->proximo);
                free(remover);
                
                return 1;
            }
            else{
                anterior = item;
                item = item->proximo;
            }
        }
    }
    else{
        printf("\nErro ao alocar memoria!\n");
    }

    return 0;
}
