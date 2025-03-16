#include <stdio.h>

int main() { // especificar o retorno da função
    int x, *p, **q;
    p = &x;
    q = &p;
    x = 10;

    printf("\n%d\n", **q); // para desreferenciar q 2 vezes

    return 0;
}
