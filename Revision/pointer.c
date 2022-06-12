//Develop by Filipe Silva

#include<stdio.h>
#include<stdlib.h>

int main(){
    int x = 10, y = 20;

    int *ponteiro;
    ponteiro = &x;
    printf("\nValor da variavel X = %d -> Declaracao sem utilizar ponteiro = X", x); // Valor de X
    printf("\nValor da variavel X = %d -> Declaracao utilizando ponteiro = *ponteiro", *ponteiro); // Valor de X
    printf("\n\nEndereco da memoria em que X esta armazenado = %d -> Declaracao sem utilizar ponteiro = &x", &x); // Endereco de X
    printf("\nEndereco da memoria em que X esta armazenado = %d -> Declaracao utilizando ponteiro = ponteiro", ponteiro); // Endereco de X
    printf("\n\nEndereco da memoria em que o ponteiro esta armazenado = %d -> = &ponteiro", &ponteiro); // Endereco do Ponteiro 


    printf("\n========================================================================================================\n");

    int *ponteiro2;
    ponteiro2 = y;
    printf("\n%d", y);
    // printf("\n%d", *ponteiro2);
    // printf("\n%d", ponteiro2 + 2);
    printf("\n%d", y);
    printf("\n%d", &ponteiro2);
    
    
    printf("\n========================================================================================================\n");

    ponteiro = &y;
    ponteiro2 = x;

    printf("%d %d %d %d", x, y, ponteiro2, *2ponteiro);
return 0;
}