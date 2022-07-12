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

void read(Register *reg, int numberList);
void order(Register *reg, int numberList);
void print(Register *reg, int numberList);
void search(Register *reg, int numberList, char key[MAX_DESCRIPTION]);

int main()
{
    int numberList;
    char key[MAX_DESCRIPTION];

    printf("Records number = ");
    scanf("%d", &numberList);

    printf("Search = ");
    fflush(stdin);
    gets(key);

    Register *reg = (Register *)malloc(numberList * sizeof(Register));

    read(reg, numberList);
    order(reg, numberList);
    print(reg, numberList);
    search(reg, numberList, key);

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
void read(Register *reg, int numberList)
{
    for (int i = 0; i < numberList; i++)
    {
        printf("\nRegister.ID = ");
        scanf("%d", &reg[i].id);
        printf("Register.Description = ");
        fflush(stdin);
        gets(reg[i].description);
    }
}
void print(Register *reg, int numberList)
{
    printf("\n==================================================================\n");
    for (int i = 0; i < numberList; i++)
    {
        printf("\nRegister.ID = %d\n", reg[i].id);
        printf("Register.Description = %s\n", reg[i].description);
    }
    printf("\n==================================================================\n");
}
void search(Register *reg, int numberList, char key[MAX_DESCRIPTION])
{
    int result;
    for (int i = 0; i < numberList; i++)
    {
        result = strcmp(reg[i].description, key);
        if (result == 0)
        {
            printf("\n==================================================================\n");
            printf("\n\t\tRegister.ID = %d\n", reg[i].id);
            printf("\t\tRegister.Description = %s\n", reg[i].description);
            printf("\n==================================================================\n");
            break;
        }
    }
}
