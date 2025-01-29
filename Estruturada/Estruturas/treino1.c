#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente
{
    char nome[30];
    int conta;
    float saldo;
} cliente;

void aloca(cliente **p, int tam);

void registro(cliente *p, int tam);

void deposito(cliente *p, int tam);

void saque(cliente *p, int tam);

void printar(cliente *p, int tam);

int main()
{
    cliente *p = NULL;
    int tam = 0, i;

    do
    {
        printf("deseja criar uma conta (1), depositar (2), sacar (3) ou finalizar(4)?\n");
        scanf("%i", &i);
        fflush(stdin);

        switch (i)
        {
        case 1:
            aloca(&p, tam + 1);
            registro(p, tam);
            tam++;
            break;

        case 2:
            deposito(p, tam);
            break;

        case 3:
            saque(p, tam);
            break;
        }

        if(i == 4)
        {
            printar(p, tam);
        }

    } while (i != 4);
}

void aloca(cliente **p, int tam)
{
    if ((*p = (cliente *)realloc(*p, tam * sizeof(cliente))) == NULL)
    {
        printf("deu ruim");
    }
}

void registro(cliente *p, int tam)
{
    static int reg = 1000;
    printf("qual seu nome?\n");
    gets((p+tam)->nome);
    fflush(stdin);

    (p + tam)->conta = reg;
    printf("Seu numero de registro será:\n%i\n", (p + tam)->conta);
    reg++;
    (p + tam)->saldo = 0;
}

void deposito(cliente *p, int tam)
{
    int num, valor;
    printf("digite o numero de registro da conta\n");
    scanf("%i", &num);

    for (int i = 0; i < tam + 1; i++)
    {
        if (num == (p + i)->conta)
        {
            printf("digite o valor de deposito\n");
            scanf("%i", &valor);
            fflush(stdin);
            (p + i)->saldo += valor;
        }
    }
}

void saque(cliente *p, int tam)
{
    int num;
    float valor;
    printf("digite o numero de registro da conta\n");
    scanf("%i", &num);
    fflush(stdin);

    for (int i = 0; i < tam; i++)
    {
        if (num == (p + i)->conta)
        {
            printf("digite o valor do saque\n");
            scanf("%f", &valor);
            (p + i)->saldo -= valor;
        }
    }
}

void printar(cliente *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("a conta %i do dono %s possui %f reais \n\n", (p+i)->conta, (p+i)->nome, (p+i)->saldo);
    }
    
}