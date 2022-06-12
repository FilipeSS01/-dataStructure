//Develop by Filipe Silva

#include<stdio.h>
#include<stdlib.h>

typedef struct students {
    char nome[50];
    float n1, n2, media;
} students;

void readStructure(int count, students *student);

int main(void){
    int count = 0;
    students *student;
    printf("Quantidade de alunos: ");
    scanf("%d", &count);
    student = malloc(count * sizeof(students));
    readStructure(count, &student);
    free(student);
return 0;
}

void readStructure(int count, students *student){

    for (int i = 0; i < count; i++)
    {
        gets(student->nome[i]);
        scanf("%f", &student->n1[i]);
        scanf("%f", &student->n2[i]);
    }
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", student[i].nome);
        printf("%f\n", student[i].n1);
        printf("%f\n", student[i].n2);
    }
}