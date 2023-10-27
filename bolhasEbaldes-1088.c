#include <stdio.h>
#include <stdlib.h>

long long int merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    long long int inversions = 0;

    i = left; // índice para percorrer a metade esquerda
    j = mid; // índice para percorrer a metade direita
    k = left; // índice para percorrer o array resultante

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i); // contabiliza as inversões
        }
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversions;
}

long long int mergeSort(int arr[], int temp[], int left, int right) {
    long long int inversions = 0;
    int mid;

    if (right > left) {
        mid = (right + left) / 2;

        inversions += mergeSort(arr, temp, left, mid); // inversões na metade esquerda
        inversions += mergeSort(arr, temp, mid + 1, right); // inversões na metade direita

        inversions += merge(arr, temp, left, mid + 1, right); // inversões entre as metades
    }

    return inversions;
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        int seq[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &seq[i]);
        }

        int* temp = (int*)malloc(n * sizeof(int)); // array temporário para o merge sort

        // conta as inversões usando o merge sort
        long long int num_inversoes = mergeSort(seq, temp, 0, n - 1);

        free(temp);

        // determina o vencedor
        char* vencedor;
        if (num_inversoes % 2 == 0) {
            vencedor = "Carlos";
        } else {
            vencedor = "Marcelo";
        }

        // imprime o resultado
        printf("%s\n", vencedor);
    }

    return 0;
}