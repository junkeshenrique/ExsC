#include <stdio.h>
#include <stdlib.h>

struct aluno {
    char *nome;
    float nota;
};

int main() {

    struct aluno alunos[3];
    int i;


    for(i = 0; i < 3; i++) {
        alunos[i].nome = malloc(50);

        printf("Informe o nome do aluno: ");
        scanf(" %[^\n]", alunos[i].nome);

        printf("Informe a nota do aluno: ");
        scanf("%f", &alunos[i].nota);
}

    for (i = 0; i < 3; i++) {
        if (alunos[i].nota >= 7){
            printf("Aluno: %s está aprovado com nota %.2f \n", alunos[i].nome, alunos[i].nota);
        } else {
            printf("Aluno: %s está reprovado com nota %.2f \n", alunos[i].nome, alunos[i].nota);
        }
    }
    return 0;
}

