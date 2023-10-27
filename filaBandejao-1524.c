#include <stdio.h>
#include <stdlib.h>

// Função que chamo no qsort para ordenar decrescente
int compararDecrescente(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int *tamanhoFila, *distancias;
    int numeroPessoas, numeroGrupos, i, somaMinima;

    while (scanf("%d %d", &numeroPessoas, &numeroGrupos) != EOF) {
        // Verifica se o tamanho da fila e o número de grupos estão dentro da entrada esperada
        if (numeroPessoas <= 1 || numeroGrupos < 1 || numeroGrupos >= numeroPessoas || numeroPessoas > 1000) {
            printf("F\n");
            break;
        }

        // Alocação dinâmica dos vetores
        tamanhoFila = (int *)malloc(numeroPessoas * sizeof(int));
        distancias = (int *)malloc(numeroPessoas * sizeof(int));

        tamanhoFila[0] = 0; // A primeira posição da fila é sempre zero.
        distancias[0] = 0;

        for (int i = 1; i < numeroPessoas; i++) {
            scanf("%d", &tamanhoFila[i]);
            distancias[i] = tamanhoFila[i] - tamanhoFila[i - 1];
        }

        //ordena distancias em ordem decrecente 
        qsort(distancias, numeroPessoas, sizeof(int), compararDecrescente);

        somaMinima = 0;
        for (i = numeroGrupos - 1; i < numeroPessoas; i++) {
            somaMinima += distancias[i];
        }

        printf("%d\n", somaMinima);

        // Libera a memória alocada após o uso dos vetores
        free(tamanhoFila);
        free(distancias);
    }

    return 0;
}