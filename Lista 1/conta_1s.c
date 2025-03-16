#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int count = 0, i;

    printf("Digite a string que possua '1's: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '1') {
            count++;
        }
    }

    printf("O numero de '1's na string e: %d\n", count);

    return 0;
}
