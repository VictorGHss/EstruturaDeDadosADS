#include <stdio.h>
#include <stdlib.h>

// estutura do Nó
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
    No* novo = (No*)malloc(sizeof(No));  // Aloca memória para um novo nó
    novo->valor = valor;
    novo->proximo = pilha->topo;         // O próximo do novo nó aponta para o antigo topo e o novo nó se torna o topo  da fila
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
    pilha->topo = temp->proximo;  // salva o nó do topo e tualiza o topo para o próximo nó
    printf("Elemento %d removido do topo da pilha.\n", temp->valor);
    free(temp);  // libera a memoria do nó removido
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
        // Menu de opções
        printf("\n1 - Incluir elemento\n2 - Excluir elemento\n3 - Consultar topo\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:  // Incluir
                printf("Digite o valor a ser incluído: ");
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
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);  // repete ate escolher sair

    while (pilha->topo != NULL) {
        excluir(pilha);  // remove todos os elementos restantes
    }
    free(pilha);  // libera a memória da estrutura da pilha

    return 0;
}
