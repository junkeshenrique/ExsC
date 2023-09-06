#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct contatos {
    char *nome;
    int numero;
    char *endereco;
} contatos;

typedef struct Item {
    contatos valor;
    struct Item* proximo;
} Item;

Item* criarItem(contatos valor) {
    Item * novoItem = malloc(sizeof(Item));
    novoItem->valor = valor;
    novoItem->proximo = NULL;

    return novoItem;
}

void adicionarItem(Item** inicio, contatos valor){
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
        contatos contato = item->valor;
        printf("Nome do contato: %s \n", contato.nome);
        printf("Tempo o número do contato: %d \n", contato.numero);
        printf("Endereço do contato: %s \n", contato.endereco);

        item = item->proximo;
    }
}

contatos criarContato() {
    contatos contato;
    contato.nome = malloc(50);

    printf("Informe o nome: ");
    scanf(" %[^\n]", contato.nome);

    printf("Informe o número de telefone: ");
    scanf("%d", &contato.numero);

    contato.endereco = malloc(50);
    printf("Informe o endereço: ");
    scanf(" %[^\n]", contato.endereco);

    return contato;
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
        contatos contato = criarContato();
        adicionarItem(&inicio, contato);

        printf("Deseja continuar? (s/n) ");
        scanf(" %c", &continuar);

    } while (toupper(continuar) == 'S');

    exibirLista(&inicio);

    removerItem(&inicio, 0);
    printf("Removendo item da posição 0\n");
    printf("Lista após a remoção: \n");

    exibirLista(&inicio);

    return 0;
}