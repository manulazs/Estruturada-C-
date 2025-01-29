#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct aluno
{
    char *nome;
    char *RA;
    float nota[2];
    float media;
} aluno;

void aloca(aluno **p, int tam);
void aloca_char(char **nome, int tam);
void cadastro(aluno *p, int tam);
void cadastro_nota(aluno *p, int tam);
void media(aluno *, int tam);
void printar(aluno *p, int tam);

int main()
{
    aluno *p = NULL;
    int opc, cont = 0;
    char op = 's';

    do
    {

        printf("digite o que deseja fazer \ncadastro de RA - 1 \ncadastro de nota - 2\nconsulta - 3\nfinalizar - 4\n");
        scanf("%i", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            cont++;
            aloca(&p, cont);
            cadastro(p, cont);
            Sleep(2000);
            system("cls");
            break;

        case 2:
            cadastro_nota(p, cont);
            Sleep(2000);
            system("cls");
            break;

        case 3:
            printar(p, cont);
            Sleep(2000);
            system("cls");
            break;

        case 4:
            Sleep(2000);
            op = 'n';
            break;
        }

    } while (op == 's');
}

void aloca(aluno **p, int tam)
{
    if ((*p = (aluno *)realloc(*p, tam * sizeof(aluno))) == NULL)
    {
        printf("deu ruim");
        exit(1);
    }
}

void cadastro(aluno *p, int tam)
{
    char ra[10], nome[40];

    printf("digite seu nome:");
    gets(nome);
    fflush(stdin);

    printf("digite seu ra:");
    gets(ra);
    fflush(stdin);
    (p + (tam - 1))->nome = NULL;
    (p + (tam - 1))->RA = NULL;

    aloca_char(&((p + (tam - 1))->nome), strlen(nome) + 1);
    aloca_char(&((p + (tam - 1))->RA), strlen(ra) + 1);

    strcpy((p + (tam - 1))->nome, nome);
    strcpy((p + (tam - 1))->RA, ra);

    printf("cadastro realizado com sucesso!\nnome: %s\nRA: %s\n", (p + (tam - 1))->nome, (p + (tam - 1))->RA);
}

void aloca_char(char **nome, int tam)
{
    if ((*nome = (char *)realloc(*nome, tam * sizeof(char))) == NULL)
    {
        printf("deu ruim");
        exit(1);
    }
}

void cadastro_nota(aluno *p, int tam)
{
    int i, x = 0;
    char ra[10];
    float notas[2];
    fflush(stdin);
    printf("digite o RA do aluno:\n");
    gets(ra);
    fflush(stdin);

    printf("digite a nota da prova 1 e 2:\n");
    scanf("%f", &notas[0]);
    scanf("%f", &notas[1]);
    fflush(stdin);

    for (i = 0; i < tam; i++)
    {
        if (strcmp((p + i)->RA, ra) == 0)
        {
            x++;
            (p + i)->nota[0] = notas[0];
            (p + i)->nota[1] = notas[1];
            
            printf("nota registrada com sucesso");
            media(p, i);
            break;
        }
    }

    if (x <= 0)
    {
        printf("RA nao cadastrado\n");
    }
    
}

void media(aluno *p, int tam)
{
    (p + tam - 1)->media = ((p + tam - 1)->nota[0] + (p + tam - 1)->nota[1]) / 2;
    printf("a media do RA %s, do nome %s eh: %f", (p + tam - 1)->RA, (p + tam - 1)->nome, (p + tam - 1)->media);
}

void printar(aluno *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("o senhor(a) %s, dono do RA %s, teve notas %f e %f, com media final %f\n\n", (p + i)->nome, (p + i)->RA, (p + i)->nota[0], (p + i)->nota[1], (p + i)->media);
    }
}