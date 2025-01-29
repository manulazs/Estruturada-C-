#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int i);
void recebe(int *p, int i);
void subtrai_aloca(int *p, int i, int **p2);
void verifica_par(int *p2, int i, int **p3, int x);
void printa(int *p, int i);
int main()
{

    int *p = NULL, contador = 0, *p2 = NULL, *p3 = NULL, x = 0;
    char verificador = 's';

    while (verificador == 's')
    {

        aloca(&p, contador);
        recebe(p, contador);
        printf("deseja continuar s/n:\n");
        scanf(" %c", &verificador);
        contador++;
    }

    subtrai_aloca(p, contador, &p2);

    for (int i = 0; i < contador; i++, x++)
    {
        verifica_par(p2, i, &p3, x);
    }

    printa(p3, contador);

    free(p);

    free(p2);

    free(p3);

    return 0;
}

void aloca(int **p, int i)
{
    if ((*p = (int *)realloc(*p, (i + 1) * sizeof(int))) == NULL)
    {
        printf("erro na memoria");
        exit(1);
    }
}

void recebe(int *p, int i)
{
    scanf("%i", p + i);
}

void subtrai_aloca(int *p, int i, int **p2)
{
    for (int o = 0; o < i; o++)
    {
        aloca(p2, o);
        *(*p2 + o) = *(p + o) - *(p + i - o - 1);
    }
}

void verifica_par(int *p2, int i, int **p3, int x)
{
    if (*(p2 + i) % 2 == 0)
    {
        aloca(p3, x);
        *(*p3 + x) = *(p2 + i);
    }
}

void printa(int *p, int i)
{
    for (int o = 0; o < i; o++)
    {
        printf("%i\n", *(p + o));
    }
}
