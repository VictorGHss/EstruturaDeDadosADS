#include <stdio.h>
#include <stdlib.h>

// estutura do N�
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// estrutura da pilha
typedef struct {
    No* topo;
} Pilha;

// cria pilha vazia
Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));  // aloca memoria para a pilha
    pilha->topo = NULL;
    return pilha;
}

// incluir um elemento
void incluir(Pilha* pilha, int valor) {
    No* novo = (No*)malloc(sizeof(No));  // Aloca mem�ria para um novo n�
    novo->valor = valor;
    novo->proximo = pilha->topo;         // O pr�ximo do novo n� aponta para o antigo topo e o novo n� se torna o topo  da fila
    pilha->topo = novo;
    printf("Elemento %d adicionado ao topo da pilha.\n", valor);
}

// excluir um elemento da pilha
void excluir(Pilha* pilha) {
    if (pilha->topo == NULL) {  // Se a pilha estiver vazia
        printf("Pilha vazia! Nenhum elemento para excluir.\n");
        return;
    }

    No* temp = pilha->topo;
    pilha->topo = temp->proximo;  // salva o n� do topo e tualiza o topo para o pr�ximo n�
    printf("Elemento %d removido do topo da pilha.\n", temp->valor);
    free(temp);  // libera a memoria do n� removido
}

// consultar o topo da pilha
void consultarTopo(Pilha* pilha) {
    if (pilha->topo == NULL) {  // Se a pilha estiver vazia
        printf("Pilha vazia! Nenhum elemento no topo.\n");
    } else {
        printf("Elemento no topo da pilha: %d\n", pilha->topo->valor);
    }
}

int main() {
    Pilha* pilha = criarPilha();
    int opcao, valor;

    do {
        // Menu de op��es
        printf("\n1 - Incluir elemento\n2 - Excluir elemento\n3 - Consultar topo\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:  // Incluir
                printf("Digite o valor a ser inclu�do: ");
                scanf("%d", &valor);
                incluir(pilha, valor);
                break;
            case 2:  // Excluir
                excluir(pilha);
                break;
            case 3:  // Consultar topo
                consultarTopo(pilha);
                break;
            case 0:  // Sair
                printf("Saindo...\n");
                break;
            default:
                printf("Op��o inv�lida!\n");
        }
    } while (opcao != 0);  // repete ate escolher sair

    while (pilha->topo != NULL) {
        excluir(pilha);  // remove todos os elementos restantes
    }
    free(pilha);  // libera a mem�ria da estrutura da pilha

    return 0;
}
