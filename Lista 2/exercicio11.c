#include <stdio.h>

int main() {
    int y, *p, x; // declaracao de variaveis

    y = 0; // y começa com seu valor 0
    p = &y; // p é atribuido ao endereço de y
    x = *p; // x é atribuido o valor apontado por p (x=y)
    x = 4; // x é atribuido o valor de 4
    (*p)++; // o valor apontado por p é incrementado em 1
    x--; // o valor é decrementado em 1 (x=3)
    (*p) += x; // valor apontado por p é incrementado por x

    printf ("y = %d \n", y); // imprime o valor de y, que é 4.

}
