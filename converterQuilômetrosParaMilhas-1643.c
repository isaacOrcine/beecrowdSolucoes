#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ull;

int fib[110];

int main(){   
    int i;
    fib[1] = 1;
    fib[2] = 2;

    // Calculando a sequência de Fibonacci até a 45ª posição ja é suficiente
    for (i = 3; i < 46; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];

    int num_distancias, distancia, milhas;

    // Lendo o número de distâncias que Bruce quer converter
    scanf("%d", &num_distancias);

    while (num_distancias--){
        // Lendo a distância em quilômetros (distancia) a ser convertida para milhas
        scanf("%d", &distancia);

        i = 45;//+ que 25000 esperado pela entrada
        milhas = 0;

        // Convertendo distancia para a representação de Fibonacci e calculando a distância em milhas (milhas)
        while (i > 1){
            if (fib[i] <= distancia){
                distancia -= fib[i], milhas += fib[i - 1];
            }
            --i;
        }

        // Imprimindo a distância em milhas
        printf("%d\n", milhas);
    }

    return 0;
}