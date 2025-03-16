#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0;     // declara variavel a e inicializa com valor de 0
    int *p = NULL; // declara ponteiro e inicia com null

    // a) faz P apoontar para A
    p = &a;

    // b) altera o valor de A para 2 usando o P
    *p = 2;

    // c) imprime valor de P e A
    printf("valor de P: %p\n", (void *)p);
    printf("valor de A: %d\n");

    return 0;
}