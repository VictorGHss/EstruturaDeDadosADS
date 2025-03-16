#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100], str_sem_vogais[100];
    int i, j = 0, tem_espaco = 0;

    printf("Digite uma palavra ou frase: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            tem_espaco = 1;
            break;
        }
    }

    for (i = 0; str[i] != '\0'; i++) {
        if (tolower(str[i]) != 'a' && tolower(str[i]) != 'e' &&
            tolower(str[i]) != 'i' && tolower(str[i]) != 'o' &&
            tolower(str[i]) != 'u') {
            str_sem_vogais[j] = str[i];
            j++;
        }
    }
    str_sem_vogais[j] = '\0';

    if (tem_espaco) {
        printf("A frase sem vogais e: %s\n", str_sem_vogais);
    } else {
        printf("A palavra sem vogais e: %s\n", str_sem_vogais);
    }

    return 0;
}
