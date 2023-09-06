#include <stdio.h>
#include <stdlib.h>

struct produto {
    char *nome;
    int quantidade;
    float preco;
    float total;
};

int main() {

    struct produto listaprodutos[5];
    float total;
    int i;
    for ( i = 0; i < 5; i++) {
    listaprodutos[i].nome = malloc(50);
        printf("Informe o nome do produto: ");
        scanf(" %[^\n]", listaprodutos[i].nome);

        printf("Informe a quantidade do produto: ");
        scanf("%d", &listaprodutos[i].quantidade);

        printf("Informe o valor unitário do produto: ");
        scanf("%f", &listaprodutos[i].preco);

        listaprodutos[i].total = listaprodutos[i].preco * listaprodutos[i].quantidade;

        total = total + listaprodutos[i].total;
    }

    for (i = 0; i < 5; i++) {
        printf("%s - %d - R$ %.2f \n", listaprodutos[i].nome, listaprodutos[i].quantidade, listaprodutos[i].total);
    }

    printf("O total do valor de compras foi de: R$ %.2f ", total);

    return 0;
}

