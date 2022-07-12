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

void order(Register *reg, int numberList);

int main()
{
    int numberList, result;
    char search[MAX_DESCRIPTION];
    printf("Records number = ");
    scanf("%d", &numberList);
    printf("Search = ");
    fflush(stdin);
    gets(search);
    fflush(stdin);

    Register *reg = (Register *)malloc(numberList * sizeof(Register));

    for (int i = 0; i < numberList; i++)
    {
        printf("\nRegister.ID = ");
        scanf("%d", &reg[i].id);
        printf("Register.Description = ");
        fflush(stdin);
        gets(reg[i].description);
    }

    order(reg, numberList);

    printf("\n==================================================================\n");

    for (int i = 0; i < numberList; i++)
    {
        printf("\nRegister.ID = %d\n", reg[i].id);
        printf("Register.Description = %s\n", reg[i].description);
    }

    printf("\n==================================================================\n");

    for (int i = 0; i < numberList; i++)
    {
        result = strcmp(reg[i].description, search);
        if (result == 0)
        {
            printf("\n==================================================================\n");
            printf("\n\t\tRegister.ID = %d\n", reg[i].id);
            printf("\t\tRegister.Description = %s\n", reg[i].description);
            printf("\n==================================================================\n");
            break;
        }
    }
    return 0;
}

void order(Register *reg, int numberList)
{
    for (int x = 0; x < numberList; x++)
    {
        for (int i = 0; i < numberList; i++)
        {
            if ((reg[i].id > reg[i + 1].id) && (i + 1 < numberList))
            {
                Register temp = reg[i];
                reg[i] = reg[i + 1];
                reg[i + 1] = temp;
            }
        }
    }
}