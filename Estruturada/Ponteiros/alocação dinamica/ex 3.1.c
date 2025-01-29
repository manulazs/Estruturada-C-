#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int i);
void receba(float **p, int i);
void printa(float *p, int i);

int main()
{
    float *p_i = NULL;
    char x = 'S';
    int i = 0;
    
    while (x != 'N')
    {
        receba(&p_i, i);
        i++;
        printf("Digite S para continuar e N para parar \n");
        scanf(" %c", &x);
    }
    
    printa(p_i, i);

    return 0;
}

void aloca(float **p, int i)
{
    if((*p = (float*) realloc(*p, sizeof(float) * (i + 1))) == NULL)
    {
        printf("erro na memoria");
        exit(1);
    }
}

void receba(float **p, int i)
{
    aloca(p, i);
    scanf("%f", (*p) + i);
}

void printa(float *p, int i)
{
    for(int o = 0; o < i; o++)
    {
        printf("%f\n", *(p + o));
    }
}