// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_STR 500

typedef struct words
{
    char str[MAX_STR];
} Words;

int splitMatrix(char *string, Words *words);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Words *words = (Words *)malloc(50 * sizeof(Words));
    char str[MAX_STR];
    int size = 0;
    fgets(str, sizeof(str), stdin);
    size = splitMatrix(str, words);

    return 0;
}

int splitMatrix(char *string, Words *words)
{
    int i = 0;

    char *token = strtok(string, " ");
    while (token != NULL)
    {
        strcpy(words[i].str, token);
        token = strtok(NULL, " ");
        i++;
    }

    return i;
}
