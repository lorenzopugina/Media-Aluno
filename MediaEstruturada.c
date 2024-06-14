#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    typedef struct {
        char nome[102];
        int ra;
        float nota1;
        float nota2;
    } aluno;

    int numAlunos;
    scanf("%d", &numAlunos);
    getchar();

    aluno *alunos = (aluno*)malloc(numAlunos * sizeof(aluno));

    for (int i = 0; i < numAlunos; i++) {
        fgets(alunos[i].nome, 102, stdin);
            // Remover o \n que o fgets salva
            int len = strlen(alunos[i].nome);
            if (len > 0 && alunos[i].nome[len - 1] == '\n') {
                alunos[i].nome[len - 1] = '\0';
            }
        scanf("%d", &alunos[i].ra);
        getchar();
        scanf("%f", &alunos[i].nota1);
        getchar();
        scanf("%f", &alunos[i].nota2);
        getchar();
    }

    for (int i = 0; i < numAlunos; i++) {
        printf("%d\t%s\t%.2f\n", alunos[i].ra, alunos[i].nome, (alunos[i].nota1 + alunos[i].nota2)/2);
    }

    free(alunos);

    return 0;
}
