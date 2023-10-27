//codigo baseado no problema da mochila sem restrição inpirado no código exemplo disponível em https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/
#include <stdio.h>

// Macro para encontrar o valor máximo entre dois números
#define max(a, b) ((a) > (b) ? (a) : (b))

// Função para resolver o problema da Mochila Ilimitada
int mochilaIlimitada(int tempoDisponivel, int duracoes[], int pontuacoes[], int n) {
    int tabela[tempoDisponivel + 1];
    tabela[0] = 0;

    // Preenche a tabela usando programação dinâmica
    for (int t = 1; t <= tempoDisponivel; t++) {
        int maxPontuacao = 0;
        for (int i = 0; i < n; i++) {
            if (duracoes[i] <= t) {
                int pontuacaoComItem = pontuacoes[i] + tabela[t - duracoes[i]];
                maxPontuacao = max(maxPontuacao, pontuacaoComItem);
            }
        }
        tabela[t] = maxPontuacao;
    }

    return tabela[tempoDisponivel];
}

int main() {
    int numAtracoes, tempoDisponivel;
    int duracoes[101], pontuacoes[101];
    int instancia = 1;

    while (1) {
        // Leitura do número de atrações e do tempo disponível
        scanf("%d %d", &numAtracoes, &tempoDisponivel);
        if (numAtracoes == 0 && tempoDisponivel == 0)
            break;

        // Leitura das durações e pontuações de cada atração
        for (int i = 0; i < numAtracoes; i++) {
            scanf("%d %d", &duracoes[i], &pontuacoes[i]);
        }

        // Chama a função para encontrar a pontuação máxima com o tempo disponível
        int resultado = mochilaIlimitada(tempoDisponivel, duracoes, pontuacoes, numAtracoes);

        // Imprime a saída formatada conforme o especificado
        printf("Instancia %d\n", instancia++);
        printf("%d\n\n", resultado);
    }

    return 0;
}