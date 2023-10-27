#include <stdio.h>

int main() {
    int bolas[50]; // vetor para armazenar a quantidade máxima de bolas que podem ser colocadas para cada N (1 a 50)

    // Pré-calcula a quantidade máxima de bolas para cada N
    for (int i = 1; i <= 50; i++) {
        bolas[i] = (i + 1) * (i + 1) / 2 - 1;
    }

    int t; // Número de casos de teste
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n; // Número de varetas disponíveis
        scanf("%d", &n);

        printf("%d\n", bolas[n]);
    }
    
    //A condicao "Imprima -1 se um número infinito de bolas pode ser colocado" não pode ser satisfeita pois determino a quantidade de casos testes, logo não é infinito

    return 0;
}