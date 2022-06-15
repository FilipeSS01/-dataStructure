#include <stdio.h>
#include <stdlib.h>

struct node
{
	int dado;
	struct node *prox;
};

struct Lista
{
	struct node *inicio;
	struct node *fim;
} Lista;

void inicializar(struct Lista *lista);
int inserirInicio(struct Lista *lista, int dado);
int inserirFim(struct Lista *lista, int dado);
int mostrar(struct Lista lista);
int remover(struct Lista *lista, int dado);
int menu();

int main()
{
	struct Lista lista;
	inicializar(&lista);

	// inserirInicio(&lista, 1);
	inserirInicio(&lista, 2);
	inserirInicio(&lista, 2);
	inserirInicio(&lista, 2);
	// inserirInicio(&lista, 3);
	inserirFim(&lista, 2);
	inserirFim(&lista, 2);
	inserirFim(&lista, 5);
	// inserirFim(&lista, 2);

	mostrar(lista);
	remover(&lista, 2);
	mostrar(lista);
	//   remover(&lista,1);
	//   mostrar(lista);
	//   remover(&lista,5);
	//   mostrar(lista);

	return 0;
}

void inicializar(struct Lista *lista)
{
	lista->inicio = NULL;
	lista->fim = NULL;
}

int inserirInicio(struct Lista *lista, int dado)
{
	struct node *novo = malloc(sizeof(struct node));

	if (novo == NULL)
		return 0;

	novo->dado = dado;

	if (lista->inicio == NULL)
	{
		lista->inicio = novo;
		lista->fim = novo;
		(lista->fim)->prox = lista->inicio;
	}
	else
	{
		novo->prox = lista->inicio;
		lista->inicio = novo;
		lista->fim->prox = lista->inicio;
	}

	return 1;
}

int inserirFim(struct Lista *lista, int dado)
{
	struct node *novo = malloc(sizeof(struct node));
	novo->dado = dado;

	if (novo == NULL)
		return 0;

	if (lista->inicio == NULL)
	{
		lista->inicio = novo;
		lista->fim = novo;
		lista->fim->prox = lista->inicio;
	}
	else
	{
		lista->fim->prox = novo;
		lista->fim = novo;
		lista->fim->prox = lista->inicio;
	}

	return 1;
}

int remover(struct Lista *lista, int dado)
{
	struct node *aux;
	struct node *ant;
	int qtdDel = 0;

	aux = lista->inicio;
	ant = NULL;

	do
	{
		if (aux->dado == dado)
		{
			qtdDel++;
			if (aux == lista->inicio)
			{
				lista->inicio = aux->prox;
				lista->fim->prox = lista->inicio;
				free(aux);
				aux = lista->inicio;
			}
			else if (aux == lista->fim)
			{
				lista->fim = ant;
				lista->fim->prox = lista->inicio;
				free(aux);
				aux = lista->inicio;
			}
			else
			{
				ant->prox = aux->prox;
				free(aux);
				aux = ant->prox;
			}
		}
		else
		{
			ant = aux;
			aux = aux->prox;
		}
	} while (aux != lista->inicio);

	return qtdDel;
}

int mostrar(struct Lista lista)
{
	struct node *aux;

	if (lista.inicio == NULL)
	{
		return 0;
	}
	else
	{
		aux = lista.inicio;
		do
		{
			printf("%d ", aux->dado);
			aux = aux->prox;
		} while (aux != lista.inicio);
	}
	printf("\n");
	return 1;
}