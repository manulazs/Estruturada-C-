#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dados
{
    int reg;
    char produto[20];
    int qtde;
    float preco;
} dados;

void aloca_1(dados **p);
void cadastro(dados *p, int num);
int grava(dados *p);
int verifica();
void mostra(dados *p, int num);

int main()
{
    char i;
    int num = 0;
    dados *p = NULL;

    aloca_1(&p);
    num = verifica();
    do
    {
        cadastro(p, num + 1);
        num++;

        printf("deseja registrar ou parar (s/n)\n");
        scanf("%c", &i);
        fflush(stdin);

    } while (i == 's');

    mostra(p, num);
    return 0;
}

void aloca_1(dados **p)
{

    if ((*p = (dados *)realloc(*p, sizeof(dados))) == NULL)
    {
        printf("aloca 1 ai e da errado otario");
        exit(1);
    }
}

void cadastro(dados *p, int num)
{
    p->reg = num;
    printf("\nregistro: %i", p->reg);

    printf("\nProduto: ");
    gets(p->produto);
    fflush(stdin);

    printf("Estoque: ");
    scanf("%i", &p->qtde);
    fflush(stdin);

    printf("preco: ");
    scanf("%f", &p->preco);
    fflush(stdin);

    grava(p);
}

int grava(dados *p)
{
    FILE *pf = NULL;
    if ((pf = fopen("estoque.bin", "ab")) == NULL)
    {
        printf("deu ruim");
        return 0;
    }

    fwrite(p, sizeof(dados), 1, pf);
    fclose(pf);
    return 1;
}

int verifica()
{
    long int num = 0;

    FILE *pf = NULL;
    if ((pf = fopen("estoque.bin", "rb")) == NULL)
        return num;

    fseek(pf, 0, 2);
    num = ftell(pf) / sizeof(dados);
    fclose(pf);

    return num;
}

void mostra(dados *p, int num)
{
    FILE *pf = NULL;

    if ((pf = fopen("estoque.bin", "rb")) == NULL)
    {
        printf("deu rui");
        exit(1);
    }

    for (int i = 0; i < num; i++)
    {
        fseek(pf, i*sizeof(dados), 0);
        fread(p, sizeof(dados), 1, pf);
        printf("\nregistro: %i\nproduto: %s\nquantidade: %i\npreco: %f\n", p->reg, p->produto, p->qtde, p->preco);
    }

    fclose(pf);
}