#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct musica {
    char *nome;
    float duracao;
    char *artista;
} musica;

typedef struct Item {
    musica valor;
    struct Item* proximo;
    struct Item* anterior;
} Item;

Item* criarItem(musica valor) {
    Item * novoItem = malloc(sizeof(Item));
    novoItem->valor = valor;
    novoItem->proximo = NULL;
    novoItem->anterior = NULL;

    return novoItem;
}

void adicionarItem(Item** inicio, musica valor){
    Item* novoItem = criarItem(valor);

    if (*inicio == NULL) {
        *inicio = novoItem;
    } else {
        Item* atual = *inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoItem;
    }
}

void exibirLista(Item** inicio) {
    Item* item = *inicio;
    while (item != NULL) {
        musica musica1 = item->valor;
        printf("Nome da musica: %s \n", musica1.nome);
        printf("Tempo de duracao da musica: %.2f \n", musica1.duracao);
        printf("Nome do artista: %s \n", musica1.artista);

        item = item->proximo;
    }
}

musica criarMusica() {
    musica musica1;
    musica1.nome = malloc(50);

    printf("Informe o nome da musica: ");
    scanf(" %[^\n]", musica1.nome);

    printf("Informe o tempo de duracao da musica: ");
    scanf("%f", &musica1.duracao);

    musica1.artista = malloc(50);
    printf("Informe o nome do artista: ");
    scanf(" %[^\n]", musica1.artista);

    return musica1;
}

void removerItem(Item** inicio, int pos) {
    Item* atual = *inicio;

    if (pos == 0) {
        *inicio = atual->proximo;
        free(atual);
        return;
    }

    int i = 0;

    while (atual->proximo != NULL && i < pos - 1) {
        atual = atual->proximo;
        i++;
    }

    if (atual != NULL) {
        Item* itemRemover = atual->proximo;
        atual->proximo = itemRemover->proximo;
        free(itemRemover);
    } else {
        printf("Posição inválida para remoção.\n");
    }
}

int main() {
    char continuar = 'N';
    Item * inicio = NULL;
    do {
        musica musica1 = criarMusica();
        adicionarItem(&inicio, musica1);

        printf("Deseja continuar? (s/n) ");
        scanf(" %c", &continuar);

    } while (toupper(continuar) == 'S');

    exibirLista(&inicio);

    removerItem(&inicio, 0);
    printf("Removendo item da posição 0\n");
    printf("Lista após a remoção:\n");

    exibirLista(&inicio);

    return 0;
}