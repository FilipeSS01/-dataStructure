// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRIPTION 50

typedef struct reg
{
    int id;
    char description[MAX_DESCRIPTION];
} Register;

int main()
{
    int numberList, test;
    char search[MAX_DESCRIPTION];
    scanf("%d", &numberList);
    printf("Search = ");
    fflush(stdin);
    gets(search);

    Register *reg = (Register *)malloc(numberList * sizeof(Register));

    for (int i = 0; i < numberList; i++)
    {
        printf("\nRegister.ID = ");
        scanf("%d", &reg[i].id);
        printf("Register.Description = ");
        fflush(stdin);
        gets(reg[i].description);
    }

    printf("\n==================================================================\n");

    for (int i = 0; i < numberList; i++)
    {
        printf("\nRegister.ID = %d\n", reg[i].id);
        printf("Register.Description = %s\n", reg[i].description);
    }

    for (int i = 0; i < numberList; i++)
    {
        // strncmp(reg[i].description, );
        strncmp(search, reg)
    }

    printf("Search %s", search);
    return 0;
}