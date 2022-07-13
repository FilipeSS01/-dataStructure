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
void swap(Register *a, Register *b);
int partition(Register arr[], int low, int high);
void quickSort(Register arr[], int low, int high);
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
    quickSort(reg, 0, numberList - 1);
    print(reg, numberList);
    search(reg, numberList, key);

    return 0;
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
void swap(Register *a, Register *b)
{
    Register t = *a;
    *a = *b;
    *b = t;
}
int partition(Register arr[], int low, int high)
{
    char pivot[MAX_DESCRIPTION];
    strcpy(pivot, arr[high].description);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (strcmp(arr[j].description, pivot) <= 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(Register arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    int low, high, mid;
    low = 0;
    high = numberList - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (strcmp(key, reg[mid].description) < 0)
        {
            high = mid - 1;
        }
        else if (strcmp(key, reg[mid].description) > 0)
        {
            low = mid + 1;
        }
        else
        {
            printf("\n==================================================================\n");
            printf("\n\t\tRegister.ID = %d\n", reg[mid].id);
            printf("\t\tRegister.Description = %s\n", reg[mid].description);
            printf("\n==================================================================\n");
            break;
        }
    }
}