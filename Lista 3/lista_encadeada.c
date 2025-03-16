#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No{
    int data;
    struct No *next;
} No;

No* criaLista(){
    return NULL;
}

No* insereInicio(No *head, int valor){
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->data = valor;
    novoNo->next = head;
    return novoNo;
}

void imprimirLista(No* head){
    printf("Lista: ");
    for (No *atual = head; atual!= NULL; atual = atual->next)
        printf("%d", atual->data);
    printf("\n");
}

No* excluirInicio(No *head){
    if (head){
        No *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

void imprimirDiv3(No *head){
    printf("Divisao por 3: ");
    for (No *atual = head; atual!= NULL; atual = atual->next)
    if (atual->data % 3 == 0) printf("%d ", atual->data);
    printf("\n");
}

void imprimirPrimeiroUltimo(No *head){
        printf("Primeiro: %d\n", head->data);
    No *ultimo = head;
    while (ultimo->next) ultimo = ultimo->next;
    printf("Ultimo: %d\n", ultimo->data);
}

bool existeNumero(No *head, int n) {
    for (No *atual = head; atual != NULL; atual = atual->next)
        if (atual->data == n) return true;
    return false;
}

No *limparLista(No *head){
    while (head){
        No *temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}

int main() {
    No *lista = criaLista();

    lista = insereInicio(lista, 20);
    lista = insereInicio(lista, 42);
    lista = insereInicio(lista, 4);

    imprimirLista(lista);
    imprimirPrimeiroUltimo(lista);
    imprimirDiv3(lista);

    printf("Numero 42 %s na lista.\n", existeNumero(lista, 42) ? "existe" : "nao existe");
    printf("numero 69 %s na lista.\n", existeNumero(lista, 69) ? "exite" : "nao existe");

    lista = excluirInicio(lista);
    imprimirLista(lista);

    lista = limparLista(lista);
    imprimirLista(lista);

    return 0;
}