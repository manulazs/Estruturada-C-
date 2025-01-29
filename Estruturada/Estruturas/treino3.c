#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct pessoa
{
    char nome[31];
    char fone[21];
    data nasc;
} pessoa;

void aloca(pessoa **p, int tam);
void cadastro(pessoa *p, int tam);
void busca(pessoa *p, int tam);
void printa(pessoa *p, int tam);

int main()
{
    int tam = 0, i;
    pessoa *p = NULL;

    do
    {
        printf("digite o que voce quer fazer \n(1) - cadastro\n(2) - busca\n(3) - finalizar e mostrar tudo\n");
        scanf("%i", &i);
        fflush(stdin);
        switch (i)
        {
        case 1:
            aloca(&p, tam+1);
            cadastro(p, tam);
            tam++;
            break;

        case 2:
            busca(p, tam);
            break;

        case 3:
            printa(p, tam);
            break;
        }
        
        

    } while (i != 3);

    return 0;
}

void aloca(pessoa **p, int tam)
{
    if ((*p = (pessoa *)realloc(*p, tam * sizeof(pessoa))) == NULL)
    {
        printf("deu bem ruim");
        exit(1);
    }
}

void cadastro(pessoa *p, int tam)
{
    printf("qual seu nome?\n");
    gets((p+tam)->nome);
    fflush(stdin);

    printf("qual seu numero de celular?\n");
    gets((p+tam)->fone);
    fflush(stdin);

    printf("qual sua data de nascimento? (ano, mes e dia)\n");
    scanf("%i %i %i", &(p+tam)->nasc.ano, &(p+tam)->nasc.mes, &(p+tam)->nasc.dia);
    fflush(stdin);
}

void busca(pessoa *p, int tam)
{
    printf("qual o nome da pessoa que voce deseja buscar?\n");
    char nome[30];
    gets(nome);
    fflush(stdin);

    for (int i = 0; i < tam; i++)
    {
        if (strcmp(nome, (p+i)->nome) == 0)
        {
            printf("o numero dessa pessoa eh: %s", (p+i)->fone);
            return;
        }
        
    }
    
}

void printa(pessoa *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("nome: %s\nnumero: %s\nnascimento (ano, mes e dia): %i %i %i\n\n\n", (p+i)->nome, (p+i)->fone, (p+i)->nasc.ano, (p+i)->nasc.mes, (p+i)->nasc.dia);
    }
    
}