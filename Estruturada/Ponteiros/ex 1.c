#include <stdio.h>

void maior(float *p_t, int tam);
void leitura(float *p_t, int tam);
float media(float *p_t, int tam);
void inferiores(float *p_t, int tam, float media);

int main()
{
    int dias;

    printf("digite quantos dias voce quer no mês: \n");
    scanf("%i", &dias);

    float temperaturas[dias];

    leitura(temperaturas, dias);
    maior(temperaturas, dias);

    printf("a media eh:\n%0.2f", media(temperaturas, dias));

    inferiores(temperaturas, dias, media(temperaturas, dias));
    return 0;
}

void leitura(float *p_t, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("temperatura do dia %i:\n", i+1);
        scanf("%f", p_t+i);
    }
    
}

void maior(float *p_t, int tam)
{
    float inicial = *p_t;
    int posicao;
    for (int i = 0; i < tam; i++)
    {
        if (inicial < *(p_t+i))
        {
            inicial = *(p_t+i);
            posicao = i;
        }
    }
    
    printf("o maior numero eh %0.2f no dia %i\n", inicial, posicao+1);
    
}

float media(float *p_t, int tam)
{
    float media = 0;

    for (int i = 0; i < tam; i++)
    {
        media += *(p_t+i); 
    }
    
    return media/tam;
}

void inferiores(float *p_t, int tam, float media)
{
    for (int i = 0; i < tam; i++)
    {
        if(*(p_t+i) < media)
            printf("\nno dia %i e a temperatura foi %0.2f graus", i+1, *(p_t+i));
    }
    
}