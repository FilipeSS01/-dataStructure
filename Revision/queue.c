#include<stdio.h>
#include<stdlib.h>

struct queue {
    int dado;
    struct queue * prox;
};
        
struct fila {
    struct queue *inicio;
    struct queue *fim;
};

void inicia ( struct fila * f ){
    f->inicio = NULL;
    f->fim = NULL;
}

void insere ( struct fila * f , int valor ){
	struct queue *novo;
	if ((novo = (struct queue*) malloc(sizeof( struct queue)))==NULL)
		printf ("Impossível alocar a memoria\n");
	else {
		novo->dado = valor;
		novo->prox = NULL;

		if (f->inicio == NULL) {
			f->inicio = novo;
			f->fim = novo;
		}
		else {
			(f->fim)-> prox = novo;
			f->fim = novo;
		}
	}							
}

int retira ( struct fila * f ) {
   
    struct queue *aux = f->inicio;
    int rem = aux->dado;
    f->inicio = aux->prox;
    free(aux);
    return rem; 
}

void apresentaFila( struct fila *f)
{
     struct queue *aux;
     aux = f->inicio;
 
     while(aux != NULL)
     {
         printf ("Dado = %3d\n",(aux->dado));
       	aux = aux->prox;
       
	 }
    
}

int buscar ( struct fila *f, int valor){
    struct queue *aux;
    aux = f->inicio;
    int count = 0;
    while(aux != NULL) {
        if ( aux->dado == valor){
            return count;
        } else {
            aux = aux->prox;
        }
        count++;
    }
    return -1;
}

void mostrarBusca (struct fila *f, int position) {
    struct queue *aux;
    int count = 0;
    aux = f->inicio;
    while (aux != NULL){
        if(position == -1) {
            printf("Nao existe o dado");
            break;
        }else if (count == position){
           printf ("Dado = %3d\n",(aux->dado));
           break;
        }
        aux = aux->prox;
        count++;
    }
}

int main(){
    struct fila f;
    int valor = 0;
    inicia(&f);
    insere(&f,10);
    insere(&f,7);
    insere(&f,8);
    insere(&f,1);
    
    getchar();
    apresentaFila(&f);
    // printf("retira = %d\n",retira(&f));
    // getchar();
    // printf("retira = %d\n",retira(&f));
    // getchar();
    // printf("retira = %d\n",retira(&f));
    // apresentaFila(&f);
    // printf("retira = %d\n",retira(&f));
    // apresentaFila(&f);
    // getchar();
    printf("\n");
    scanf("%d", &valor);
    mostrarBusca(&f, buscar(&f, valor));
}