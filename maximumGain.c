typedef	struct lista{
    char valor;
    struct lista *proximo, *anterior;
}Lista;

void inserir(Lista **lista, char num);
int contadorXY(Lista **lista, int *ptrx, int *ptry, char n, char m);

int maximumGain(char *s, int x, int y) {

    Lista *lista = NULL;

    int opcao, valor, resultado = 0, *ptrx, *ptry, verificador = 0, ponteirox = 0, ponteiroy = 0;
    char n = 'a', m = 'b';

    while((*s) != '\0'){
        inserir(&lista, *s);
        *s++;
    }

    ptrx = &ponteirox;
    ptry = &ponteiroy;

    do{
        if(x > y){
            verificador = contadorXY(&lista, ptrx, ptry, n, m);
        }
        else{
            verificador = contadorXY(&lista, ptrx, ptry, m, n);
        }
    }while(verificador);

    if(x > y){
        resultado = (*ptrx*y) + (*ptry*x);
    }
    else{
        resultado = (*ptrx*x) + (*ptry*y);
    }

    return resultado;
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

int contadorXY(Lista **lista, int *ptrx, int *ptry, char n, char m){
    Lista *remover1 = NULL, *remover2 = NULL, *item = *lista, *anterior = NULL;

    if(item){
        while(item && item->proximo){
            int verificador = 0;

            if(item->valor == n && item->proximo->valor == m){
                (*ptry)++;
                verificador++;

                remover1 = item;
                remover2 = item->proximo;
                
                if(anterior){
                    anterior->proximo = item->proximo->proximo;
                }
                else{
                    *lista = item->proximo->proximo;
                }
                
                free(remover1);
                free(remover2);

                return verificador;
            }
            else{
                anterior = item;
                item = item->proximo;
            }
        }

        item = *lista;

        while(item && item->proximo){
            int verificador = 0;

            if(item->valor == m && item->proximo->valor == n){
                (*ptrx)++;
                verificador++;

                remover1 = item;
                remover2 = item->proximo;

                if(anterior){
                    anterior->proximo = item->proximo->proximo;
                }
                else{
                    *lista = item->proximo->proximo;
                }
                
                free(remover1);
                free(remover2);
                
                return verificador;
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
