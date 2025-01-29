#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda
{
    int reg;
    char nome[80];
    float nota;
} agenda;

void aloca(agenda **p, int tam);
void cadastro(agenda *p);
void mostra(agenda *p);

int main()
{
    agenda *p = NULL;
    int opn, cont = 0, cont2;

    do
    {
        printf("\ncadastro[1]\nmostrar[2]\nfinalizar[3]\n");
        scanf("%i", &opn);
        fflush(stdin);
        switch (opn)
        {
        case 1:
            aloca(&p, cont + 1);
            cadastro(p+cont);
            cont++;
            break;

        case 2:
            printf("digite o numero de registro da sua agenda que deseja acessar:\n");
            scanf("%i", &cont2);
            mostra(p+cont2-1);
        }

    } while (opn != 3);

    return 0;
}

void aloca(agenda **p, int tam)
{
    if ((*p = (agenda *)realloc(*p, tam * sizeof(agenda))) == NULL)
    {
        exit(1);
    }
}

void cadastro(agenda *p)
{
    printf("digite seu nome:\n");
    gets(p->nome);
    fflush(stdin);

    static int rnum = 1;
    p->reg = rnum;
    rnum++;

    printf("digite sua nota:\n");
    scanf("%f", &p->nota);

    printf("agenda cadastrada com sucesso!\n seu numero de registro eh: %i\n", p->reg);
}

void mostra(agenda *p)
{
    printf(" seu nome eh: %s e sua nota eh: %f", p->nome, p->nota);
}