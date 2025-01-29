#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
void recebe(float *p, int tam);


int main()
{
    float *ptr = NULL;
    int i;

    printf("quantos numeros voce quer digitar:\n");
    scanf("%i", &i);

    aloca(&ptr, i);
    recebe(ptr, i);

    return 0;
}

void aloca(float **p, int tam)
{
    if((*p = (float*) realloc(*p, (tam*sizeof(float)))) == NULL)
    {
        printf("erro na memoria");
        exit(1);
    }
    printf("endereco: %u \n", *p);
}

void recebe(float *p, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("endereco: %u \n", p+i);
        scanf("%f", p+i);
    }
}
