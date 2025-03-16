#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100], str_invertida[100];
    int i, j, tamanho, palindromo = 1, tem_espaco = 0;

    printf("Digite uma palavra ou frase: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            tem_espaco = 1;
            break;
        }
    }

    if (tem_espaco) {
        printf("Voce digitou uma frase.\n");
    } else {
        printf("Voce digitou uma palavra.\n");
    }

    tamanho = strlen(str);
    j = 0;
    for (i = 0; i < tamanho; i++) {
        if (isalnum(str[i])) {
            str_invertida[j] = tolower(str[i]);
            j++;
        }
    }
    printf("Forma invertida: ");
    for (i = tamanho - 1; i >= 0; i--) {
        printf("%c", str_invertida[i]);
    }
    printf("\n");
    str_invertida[j] = '\0';
    tamanho = strlen(str_invertida);

    for (i = 0; i < tamanho / 2; i++) {
        if (str_invertida[i] != str_invertida[tamanho - i - 1]) {
            palindromo = 0;
            break;
        }
    }

    if (palindromo) {
        if (tem_espaco) {
            printf("A frase e um palindromo.\n");
        } else {
            printf("A palavra e um palindromo.\n");
        }
    } else {
        if (tem_espaco) {
            printf("A frase nao e um palindromo.\n");
        } else {
            printf("A palavra nao e um palindromo.\n");
        }
    }

    return 0;
}
