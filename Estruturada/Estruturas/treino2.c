#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede
{
    int quarto; // número do quarto
    char nome[80];
    int acompanhante; // quantidade de acompanhantes
    char categoria;   // [S]olteiro / [F]amiliar
    int dias;         // tempo de permanência – em dias
} hospede;

typedef struct quarto
{
    int num;        // número do quarto , 15 no total
    char categoria; // [S]olteiro / [F]amiliar
    char status;    // [L]ivre / [O]cupado
} quarto;

void quartos(quarto *p);

void alocah(hospede **p, int tam);

void alocaq(quarto **p, int tam);

void registro(hospede *p, quarto *q, int tam);

void buscaquarto(quarto *p, hospede *q);

void buscapessoa(quarto *p, hospede *q);

const float price_sol = 45;
const float price_fam = 80;

int main()
{
    int i, tam = 0;
    hospede *hos = NULL;
    quarto *qua = NULL;
    char ver = 's';
    quartos(qua);

    do
    {
        printf("check in (1)\n check out (2)\n");
        scanf("%i", &i);
        fflush(stdin);
        switch (i)
        {
        case 1:
            alocah(&hos, tam + 1);
            registro(hos, qua, tam);
            tam++;

            break;

        case 2:

            break;
        }
        printf("deseja cadastrar mais um quarto? s/n\n");
        scanf("%c", &ver);
        fflush(stdin);
    } while (ver == 's');
}

void alocah(hospede **p, int tam)
{
    if ((*p = (hospede *)realloc(*p, tam * sizeof(hospede))) == NULL)
    {
        printf("deu ruim1");
        exit(1);
    }
}

void alocaq(quarto **p, int tam)
{
    if ((*p = (quarto *)realloc(*p, tam * sizeof(quarto))) == NULL)
    {
        printf("deu ruim2");
        exit(1);
    }
}

void registro(hospede *p, quarto *q, int tam)
{

    printf("qual seu nome?\n");
    gets((p + tam)->nome);
    fflush(stdin);

    printf("quantas pessoas estão com voce?\n");
    scanf("%i", &(p + tam)->acompanhante);
    fflush(stdin);

    if ((p + tam)->acompanhante > 0)
        (p + tam)->categoria = 'f';

    else
        (p + tam)->categoria = 's';

    printf("quantos dias deseja ficar?\n");
    scanf("%i", &(p+tam)->dias);
    fflush(stdin);

    buscaquarto(q, p);
}

void quartos(quarto *p)
{
    static int num = 100;
    for (int i = 0; i < 14; i++)
    {
        alocaq(p, i + 1);
        if (i < 5)
        {
            (p + i)->num = num;
            (p + i)->categoria = 'f';
            (p + i)->status = 'l';
        }

        else
        {
            (p + i)->num = num;
            (p + i)->categoria = 's';
            (p + i)->status = 'l';
        }

        num++;
    }
}

void buscaquarto(quarto *p, hospede *q)
{
    int i;
    for (i = 0; i < 15; i++)
    {
        if ((p + i)->categoria == (q + i)->categoria && (p + i)->status == 'l')
        {
            printf("quarto disponivel de numero %i\n", (p + i)->num);
            (p + i)->status = 'o';
            (q + i)->quarto = (p + i)->num;
            return;
        }
    }

    printf("sem quartos disponiveis para seu tipo\n");
}

void buscapessoa(quarto *p, hospede *q)
{
    char nome[30];
    printf("qual o seu nome?\n");
    gets(nome);
    fflush(stdin);

    for (int i = 0; i < 15; i++)
    {
        if (strcmp(nome, (q + i)->nome) == 0)
        {
            if ((p + i)->categoria == 's')
                printf("o quarto de numero %i foi liberado! O valor para o checkout eh de %f", (p + i)->num, price_sol * (q + i)->dias);

            else
                printf("o quarto de numero %i foi liberado! O valor para o checkout eh de %f", (p + i)->num, price_fam * (q + i)->dias);

            (p+i)->status = 'l';
            exit(1);
        }
    }

    printf("quarto com seu nome não encontrado");
}