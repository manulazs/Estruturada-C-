#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int cont);
void leitura(int *p, int cont);
void subtrair(int *p, int cont, int **p2, int *o);
void printar(int *p, int cont);

int main()
{
    int *p = NULL, *p2 = NULL, cont = 0, o = 0;
    char r = 's';

    while (r == 's')
    {
        aloca(&p, cont);
        leitura(p, cont);
        cont++;
        printf("quer continuar s/n:\n");
        scanf(" %c", &r);
    }

    subtrair(p, cont, &p2, &o);
    printar(p2, o);
    return 0;
}

void aloca(int **p, int cont)
{
    if ((*p = (int *)realloc(*p, (cont + 1) * sizeof(int))) == NULL)
    {
        printf("erro");
        exit(1);
    }
}
void leitura(int *p, int cont)
{
    printf("digite um numero:\n");
    scanf("%i", p + cont);
}
void subtrair(int *p, int cont, int **p2, int *o)
{
    int x = 1, y = 0, i;

    if (cont % 2 == 0)

    {
        for (i = 0; i < cont / 2; i++)
        {

            if ((*(p + x) - *(p + y)) % 2 == 0)
            {
                aloca(p2, *o);
                *(*p2 + *o) = *(p + x) - *(p + y);
                (*o)++;
            }
            x += 2;
            y += 2;
        }
    }

    if (cont % 2 != 0 && (*(p + cont - 1) % 2 == 0))
    {
        aloca(p2, *o);
        *(*p2 + *o) = *(p + cont - 1);
        (*o)++;
    }
}

void printar(int *p, int cont)
{
    for (int i = 0; i < cont; i++)
    {
        printf("%i\n", *(p + i));
    }
}
