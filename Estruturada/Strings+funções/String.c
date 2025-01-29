#include <stdio.h>
#include <string.h>

void inverter (char invertido[], char invertido2[]);
void salvar (char a[], char b[]);

int main()
{
    char texto[30], texto2[30];
    gets(texto);
    inverter(texto, texto2);
}

void inverter (char invertido[], char invertido2[])
{
    salvar(invertido, invertido2);
    for(int i = 0;i <= strlen(invertido2) ; i++)
        printf("%c", invertido2[i]);
}

void salvar (char a[], char b[])
{
    int c = 0;
    for(int o = strlen(a) - 1; o >= 0; o--)
    {
        b[c] = a[o];

        if(a[o] < 91 && a[o] > 65 )
        {
            b[c] = a[o] + 32;
        }
        c++;
    }
    b[c] = '\0';

}