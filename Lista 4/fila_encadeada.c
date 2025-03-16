#include <stdio.h>
#include <stdlib.h>

typedef struct No // Estrutura do Nó
{
    int valor;
    struct No* proximo;
} No;

typedef struct // Estrutura da fila
{
    No* inicio;
    No* fim;
} Fila;

Fila* criarFila() //fila vazia
{
    Fila* fila = (Fila*)malloc(sizeof(Fila)); //aloca memoria para a fila
    fila->inicio = fila->fim = NULL; //inicializa inicio e fim
    return fila;
}

// Função para incluir um elemento na fila
void incluir(Fila* fila, int valor)
{
    No* novo = (No*)malloc(sizeof(No)); //aloca memoria para um novo Nó
    novo->valor = valor; //atribui valor ao Nó
    novo->proximo = NULL;

    if (fila->fim == NULL)   // se a fila ta vazia
    {
        fila->inicio = fila->fim = novo; //novo No = inicio e fim da fila
    }
    else
    {
        fila->fim->proximo = novo; //ultimo No aponta para o novo No, e o novo Nó se torna o ultimo da fila
        fila->fim = novo;
    }
    printf("Elemento %d adicionado.\n", valor);
}

// excluir um elemento da fila (FIFO)
void excluir(Fila* fila)
{
    if (fila->inicio == NULL)
    {
        printf("Fila vazia!\n");
        return;
    }

    No* temp = fila->inicio;
    fila->inicio = fila->inicio->proximo; //atualiza o inicio para o proximo Nó

    if (fila->inicio == NULL)   // Fila ficou vazia entao fim = NULL
    {
        fila->fim = NULL;
    }

    printf("Elemento %d removido.\n", temp->valor);
    free(temp); //libera a memoria do Nó removido
}

// consultar o primeiro
void consultarPrimeiro(Fila* fila)
{
    if (fila->inicio == NULL)
    {
        printf("Fila vazia!\n");
    }
    else
    {
        printf("Primeiro elemento: %d\n", fila->inicio->valor);
    }
}

// consultar o último
void consultarUltimo(Fila* fila)
{
    if (fila->fim == NULL)
    {
        printf("Fila vazia!\n");
    }
    else
    {
        printf("Último elemento: %d\n", fila->fim->valor);
    }
}

int main()
{
    Fila* fila = criarFila();
    int opcao, valor;

    do
    {
        printf("\n1 - Incluir\n2 - Excluir\n3 - Consultar primeiro\n4 - Consultar ultimo\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: //incluir
            printf("Valor: ");
            scanf("%d", &valor);
            incluir(fila, valor);
            break;
        case 2: // excluir
            excluir(fila);
            break;
        case 3: // consultar primeiro
            consultarPrimeiro(fila);
            break;
        case 4: // consultar ultimo
            consultarUltimo(fila);
            break;
        case 0: // sair
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }
    while (opcao != 0);

    while (fila->inicio != NULL)
    {
        excluir(fila);
    }
    free(fila);

    return 0;
}
