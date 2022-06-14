//Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct node {
    int dado;
    struct node *next;
}Node;

typedef struct list {
    Node *start;
    Node *end;
}List;

typedef struct stack {
    Node *node;
    struct stack *next;
}Stack;
// =======================================
//            Menu Configuration
// =======================================
int menu();
int listMenu(int numberList);
// =======================================
//       Initialize Configuration
// =======================================
void initialize(List *list1, List *list2, List *list3, Stack *stack1, Stack *stack2);
void initializeStack(Stack *stack);
void initializeList(List *list);
// =======================================
//         List Configuration
// =======================================
int insertStart(List *list, int dado);
int insertEnd(List *list, int dado);
int mergerList(List *list, List *list3);
int removeList(List *list, int dado);
void printList(List list);
int passList(List list, Stack *stack); // -> List Configuration for Stack
// =======================================
//         Stack Configuration
// =======================================
int pushStack(Stack *stack, Node *no);
void printStack(Stack stack);
int checkIntersection(Stack stack1, Stack stack2, List *list); // -> Check Intersection With Stack and List

int main(){
    system("cls");
    int menuOption, listMenuOption, dado;
    List list1, list2, list3;
    Stack stack1, stack2;
    initialize(&list1, &list2, &list3, &stack1, &stack2);
    do {
        menuOption = menu();
        switch (menuOption){
            case 1:
                system("cls");
                do{
                    listMenuOption = listMenu(1);
                    switch (listMenuOption){
                        case 1:
                            system("cls");
                            printf("Digite um numero: ");
                            scanf("%d", &dado);
                            if(insertStart(&list1, dado)){
                                system("cls");
                                printf("Insercao realizado com "ANSI_COLOR_GREEN "sucesso" ANSI_COLOR_RESET"!\n");
                            }else{
                                system("cls");
                                printf(ANSI_COLOR_RED "Falha" ANSI_COLOR_RESET" na insercao!\n");
                            }
						break;
                        case 2:
                            system("cls");
                            printf("Digite um numero: ");
                            scanf("%d", &dado);
                            if(insertEnd(&list1, dado)){
                                system("cls");
                                printf("Insercao realizado com "ANSI_COLOR_GREEN "sucesso" ANSI_COLOR_RESET"!\n");
                            }else{
                                system("cls");
                                printf(ANSI_COLOR_RED "Falha" ANSI_COLOR_RESET" na insercao!\n");
                            }
						break;
                        case 3:
                            system("cls");
                            printList(list1);
						break;
                        case 4:
                            system("cls");
                            printList(list1);
                            printf("Digite um numero: ");
                            scanf("%d", &dado);
                            system("cls");
                            printf(ANSI_COLOR_RED "%d" ANSI_COLOR_RESET" removido(s)!\n", removeList(&list1, dado));
						break;
                    }
                } while (listMenuOption != 5);
                system("cls");
            break;
            case 2:
                system("cls");
                do{
                    listMenuOption = listMenu(2);
                    switch (listMenuOption){
                        case 1:
                            system("cls");
                            printf("Digite um numero: ");
                            scanf("%d", &dado);
                            if(insertStart(&list2, dado)){
                                system("cls");
                                printf("Insercao realizado com "ANSI_COLOR_GREEN "sucesso" ANSI_COLOR_RESET"!\n");
                            }else{
                                system("cls");
                                printf(ANSI_COLOR_RED "Falha" ANSI_COLOR_RESET" na insercao!\n");
                            }
						break;
                        case 2:
                            system("cls");
                            printf("Digite um numero: ");
                            scanf("%d", &dado);
                            if(insertEnd(&list2, dado)){
                                system("cls");
                                printf("Insercao realizado com "ANSI_COLOR_GREEN "sucesso" ANSI_COLOR_RESET"!\n");
                            }else{
                                system("cls");
                                printf(ANSI_COLOR_RED "Falha" ANSI_COLOR_RESET" na insercao!\n");
                            }
						break;
                        case 3:
                            system("cls");
                            printList(list2);
						break;
                        case 4:
                            system("cls");
                            printList(list2);
                            printf("Digite um numero: ");
                            scanf("%d", &dado);
                            system("cls");
                            printf(ANSI_COLOR_RED "%d" ANSI_COLOR_RESET" removido(s)!\n", removeList(&list2, dado));
						break;
                    }
                } while (listMenuOption != 5);
                system("cls");
            break;
            case 3:
                system("cls");
                do{
                    listMenuOption = listMenu(3);
                    switch (listMenuOption){
                        case 1:
                            system("cls");
                            printf("Digite um numero: ");
                            scanf("%d", &dado);
                            if(insertStart(&list3, dado)){
                                system("cls");
                                printf("Insercao realizado com "ANSI_COLOR_GREEN "sucesso" ANSI_COLOR_RESET"!\n");
                            }else{
                                system("cls");
                                printf(ANSI_COLOR_RED "Falha" ANSI_COLOR_RESET" na insercao!\n");
                            }
						break;
                        case 2:
                            system("cls");
                            printf("Digite um numero: ");
                            scanf("%d", &dado);
                            if(insertEnd(&list3, dado)){
                                system("cls");
                                printf("Insercao realizado com "ANSI_COLOR_GREEN "sucesso" ANSI_COLOR_RESET"!\n");
                            }else{
                                system("cls");
                                printf(ANSI_COLOR_RED "Falha" ANSI_COLOR_RESET" na insercao!\n");
                            }
						break;
                        case 3:
                            system("cls");
                            printList(list3);
						break;
                        case 4:
                            system("cls");
                            printList(list3);
                            printf("Digite um numero: ");
                            scanf("%d", &dado);
                            system("cls");
                            printf(ANSI_COLOR_RED "%d" ANSI_COLOR_RESET" removido(s)!\n", removeList(&list3, dado));
						break;
                    }
                } while (listMenuOption != 5);
                system("cls");
            break;
            case 4:
                system("cls");
                if(mergerList(&list1, &list3)){
                    printf("Merge lista 1 realizado com "ANSI_COLOR_GREEN "sucesso" ANSI_COLOR_RESET"!\n");
                }else{
                    printf(ANSI_COLOR_RED "Falha" ANSI_COLOR_RESET" Lista 1!\n");
                }
                if(mergerList(&list2, &list3)){
                    printf("Merge lista 2 realizado com "ANSI_COLOR_GREEN "sucesso" ANSI_COLOR_RESET"!\n");
                }else{
                    printf(ANSI_COLOR_RED "Falha" ANSI_COLOR_RESET" Lista 2!\n");
                }
            break;
            case 5:
                system("cls");
                if(passList(list1, &stack1)){
                    printf("Lista 1 empilhada realizado com "ANSI_COLOR_GREEN "sucesso" ANSI_COLOR_RESET"!\n");
                }else{
                    printf(ANSI_COLOR_RED "Falha " ANSI_COLOR_RESET "lista 1 - ");
                    printStack(stack1);
                }
                if(passList(list2, &stack2)){
                    printf("Lista 2 empilhada realizado com "ANSI_COLOR_GREEN "sucesso" ANSI_COLOR_RESET"!\n");
                }else{
                    printf(ANSI_COLOR_RED "Falha " ANSI_COLOR_RESET "lista 2 - ");
                    printStack(stack2);
                }
            break;
            case 6:
                system("cls");
                printf(ANSI_COLOR_YELLOW "Lista 1\n" ANSI_COLOR_RESET);
                printList(list1);
                printf(ANSI_COLOR_YELLOW "Lista 2\n" ANSI_COLOR_RESET);
                printList(list2);
                printf(ANSI_COLOR_YELLOW "Lista 3\n" ANSI_COLOR_RESET);
                printList(list3);
                if (checkIntersection(stack1, stack2, &list3) != 0){
                    printf("Ponto de interccao" ANSI_COLOR_BLUE " ->" ANSI_COLOR_RESET " %d\n", checkIntersection(stack1, stack2, &list3));
                }
                menuOption = 7;
                system("PAUSE");
            break;
        }
    } while (menuOption != 7 );
    
    return 0;
}

// =======================================
//            Menu Configuration
// =======================================
int menu(){
	int op;
    printf("========================\n");
    printf(ANSI_COLOR_YELLOW "\tDesafio\n" ANSI_COLOR_RESET);
    printf("========================\n");
	printf("\n "ANSI_COLOR_RED "1" ANSI_COLOR_RESET" - Primeira Lista");
	printf("\n "ANSI_COLOR_RED "2" ANSI_COLOR_RESET" - Segunda Lista");
	printf("\n "ANSI_COLOR_RED "3" ANSI_COLOR_RESET" - Terceira Lista");
	printf("\n "ANSI_COLOR_RED "4" ANSI_COLOR_RESET" - Merge Lista");
	printf("\n "ANSI_COLOR_RED "5" ANSI_COLOR_RESET" - Empilhar Lista");
	printf("\n "ANSI_COLOR_RED "6" ANSI_COLOR_RESET" - Ponto de interccao");
	printf("\n "ANSI_COLOR_RED "7" ANSI_COLOR_RESET" - Sair\n");
    printf("\n-> ");
	scanf("%d", &op);
	return op;
}
int listMenu(int numberList){
	int op;
    printf("========================\n");
    printf(ANSI_COLOR_YELLOW "\t%d Lista\n" ANSI_COLOR_RESET, numberList);
    printf("========================\n");

	printf("\n "ANSI_COLOR_RED "1" ANSI_COLOR_RESET" - Inserir no Inicio");
	printf("\n "ANSI_COLOR_RED "2" ANSI_COLOR_RESET" - Inserir no Fim");
	printf("\n "ANSI_COLOR_RED "3" ANSI_COLOR_RESET" - Mostrar Lista");
	printf("\n "ANSI_COLOR_RED "4" ANSI_COLOR_RESET" - Remover itens");
	printf("\n "ANSI_COLOR_RED "5" ANSI_COLOR_RESET" - Sair\n");
    printf("\n-> ");
	scanf("%d", &op);
	return op;
}
// =======================================
//       Initialize Configuration
// =======================================
void initialize(List *list1, List *list2, List *list3, Stack *stack1, Stack *stack2){
    initializeList(list1);
    initializeList(list2);
    initializeList(list3);
    initializeStack(stack1);
    initializeStack(stack2);
}
void initializeStack(Stack *stack) {
    stack->node = NULL;
    stack->next = NULL;
}
void initializeList(List *list) {
    list->start = NULL;
    list->end = NULL;
}
// =======================================
//         List Configuration
// =======================================
int insertStart(List *list, int dado) {
    Node *new = malloc(sizeof(Node));
    new->dado = dado;

    if (new == NULL){
        return 0;
    }
    if (list->start == NULL){
        list->start = new;
        list->end = new;
        list->end->next = NULL;
    } else {
        new->next = list->start;
        list->start = new;
    }
    return 1;
}
int insertEnd(List *list, int dado) {
    Node *new = malloc(sizeof(Node));
    new->dado = dado;

    if (new == NULL) {
        return 0;
    }
	if(list->start == NULL){
		list->start = new;
		list->end = new;
		list->end->next = NULL;
	}else{
		list->end->next = new;
		list->end = new;
		list->end->next = NULL;
	}

	return 1;
}
int mergerList(List *list, List *list3){
    if(list->start == NULL){
        return 0;
    } else {
        list->end->next = list3->start;
    }
    return 1;
}
int removeList(List *list, int dado) {
    Node *aux;
    Node *before;
    int del = 0;
	
	aux = list->start;
	before = NULL;

	while(aux != NULL){
		if(aux->dado == dado){
			del++;
			if(aux == list->start){
				list->start = aux->next;
				free(aux);
				aux = list->start;
			}else if(aux == list->end){
				before->next = NULL;
				list->end = before;
				free(aux);
				aux = NULL;
			}else{
				before->next = aux->next;
				free(aux);
				aux = before->next;
			}
		}else{
			before = aux;
			aux = aux->next;
		}
	}
	
	return del;
}
void printList(List list){
    Node *aux;
    if(list.start == NULL){
        return;
    } else {
        aux = list.start;
        printf("========================\n");
        while(aux != NULL){
            printf("%d ", aux->dado);
            // printf("%p ", aux);
            aux = aux->next;
        }
        printf("\n========================\n\n");
    }
}
int passList(List list, Stack *stack){
    Node *aux;
    if(list.start == NULL){
        return 0;
    } else {
        aux = list.start;
        while(aux != NULL){
            pushStack(stack, aux);
            aux = aux->next;
        }
    }
    return 1;
}
// =======================================
//         Stack Configuration
// =======================================
int pushStack(Stack *stack, Node *no) {
    Stack *new = (Stack *) malloc(sizeof(Stack));
	if(new == NULL)
	   return 0;

	new->node = no;
	new->next = stack->next;
	stack->next = new;
	return 1;
}
void printStack(Stack stack) {
    Stack *aux = stack.next;
    if(aux == NULL){
		printf("Lista esta vazia!\n");
	  	return;
	}
    while(aux != NULL){
		printf("%d ", aux->node->dado);
		// printf("%p ", &aux->node->dado);
		aux = aux->next;
	}
	printf("\n");
}
int checkIntersection(Stack stack1, Stack stack2,  List *list){
    Stack *auxStack1 = stack1.next;
    Stack *auxStack2 = stack2.next;
    int intersection = 0;
    while (auxStack1 != NULL){
        while (auxStack2 != NULL){
            if ((&auxStack1->node->dado == &list->start->dado) && (&auxStack2->node->dado == &list->start->dado)){
                intersection = auxStack1->node->dado;
                return intersection;
            }
            auxStack2 = auxStack2->next;
        }
        auxStack1 = auxStack1->next;
        auxStack2 = stack2.next;
    }
    return intersection;
}