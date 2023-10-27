#include <stdio.h>

int fib(int n, int *num_calls) {
    (*num_calls)++;  // Incrementa o contador de chamadas recursivas

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
        return fib(n - 1, num_calls) + fib(n - 2, num_calls);
}

int main() {
    int n;  // Número de casos de teste
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        int X;  // Valor de entrada
        scanf("%d", &X);

        int num_calls = 0;  // Inicia o contador
        int result = fib(X, &num_calls);

        printf("fib(%d) = %d calls = %d\n", X, num_calls - 1, result);
    }

    return 0;
}