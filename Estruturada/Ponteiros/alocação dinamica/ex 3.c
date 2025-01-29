#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int i);
void receba(float **p, int i);
void printa(float *p, int i);
float media(float **p, int i);
void comparacao(float media, float **p, float **p2, int i);

int main()
{
    float *p_i = NULL, *p_me = NULL, med;
    char x = 'S';
    int i = 0;

    while (x != 'N' && x != 'n')
    {
        printf("digite um numero:\n");
        receba(&p_i, i);
        i++;
        printf("Digite S para continuar e N para parar \n");
        scanf(" %c", &x);
    }

    printa(p_i, i);

    med = media(&p_i, i);
    printf("media:\n%f\n", med);

    comparacao(med, &p_i, &p_me, i);

    return 0;
}

void aloca(float **p, int i)
{
    if ((*p = (float *)realloc(*p, (i + 1) * sizeof(float))) == NULL)
    {
        printf("erro na memoria");
        exit(1);
    }
}

void receba(float **p, int i)
{
    aloca(p, i);
    scanf("%f", *p + i);
}

void printa(float *p, int i)
{
    for (int o = 0; o < i; o++)
    {
        printf("%f\n", *(p + o));
    }
}

float media(float **p, int i)
{

    float med = 0;
    for (int o = 0; o < i; o++)
    {
        med += *(*p + o);
    }

    return med / i;
}

void comparacao(float media, float **p, float **p2, int i)
{
    int x = 0;
    for (int o = 0; o < i; o++)
    {
        if (media > *(*p + o))
        {
            aloca(p2, x);
            *(*p2 + x) = *(*p + o);
            printf("%f", *(*p2 + x));
            x++;
        }
    }
}