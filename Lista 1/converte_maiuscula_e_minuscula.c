#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int i, tem_espaco = 0, opcao;

    printf("Digite uma palavra ou frase: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            tem_espaco = 1;
            break;
        }
    }

    printf("1. Converter maiusculas para minusculas\n");
    printf("2. Converter minusculas para maiusculas\n");
    printf("Digite qual operacao voce quer executar ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        for (i = 0; str[i] != '\0'; i++) {
            if (isupper(str[i])) {
                str[i] = tolower(str[i]);
            }
        }

        if (tem_espaco) {
            printf("Frase convertida para minusculas: %s\n", str);
        } else {
            printf("Palavra convertida para minusculas: %s\n", str);
        }
    } else if (opcao == 2) {
        for (i = 0; str[i] != '\0'; i++) {
            if (islower(str[i])) {
                str[i] = toupper(str[i]);
            }
        }

        if (tem_espaco) {
            printf("Frase convertida para minusculas: %s\n", str);
        } else {
            printf("Palavra convertida para minusculas: %s\n", str);
        }
    }
    return 0;
}
