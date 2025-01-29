#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
void recebe(float *p);
void aumenta_printa(float *p);

int main()
{
    float *prt=NULL;

    aloca(&prt, 10);
    recebe(prt);
    aumenta_printa(prt);
    return 0;
}

void aloca(float **p, int tam)
{
    if((*p=(float*)realloc(*p, tam*sizeof(float))) == NULL)
    {
        printf("erro na memoria dog\n");
        exit(1);
    }

    printf("endereco: %u\n", *p);
}

void recebe(float *p)
{
    for(int i = 0; i < 10;i++)
    {
        printf("endereco: %u\n", p+i);
        scanf("%f", p+i);
    }
}

void aumenta_printa(float *p)
{
    for(int i = 0; i < 10; i++)
    {
        *(p+i) += 30;
        printf("%f\n", *(p+i));
    }
}