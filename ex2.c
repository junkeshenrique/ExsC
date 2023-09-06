#include <stdio.h>

int main() {
    float lancamento[10];
    int i;
    float saldo;

    printf("Valor do seu saldo inicial: ");
    scanf("%f", &saldo);

    for (i = 0; i < 10; i++) {
        printf("Qual o valor do lançamento na posição %d:", i+1);
        scanf("%f", &lancamento[i]);
        saldo += lancamento[i];
    }

    printf("R$%.2f", saldo);
    
    return 0;
}
