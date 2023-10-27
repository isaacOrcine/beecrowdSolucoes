#include <stdio.h>

// inicializa o n° de op e o "tamanho" da imagem
int pintar_imagem(int n, int m, int r, int c, int pixels[][m]) { 
    int operacoes = 0;
    int imagem[n][m];
    
    // Inicializa a imagem com pixels 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            imagem[i][j] = 0;
        }
    }
    
    // Percorre as posições possíveis para aplicar a operação de mudar de cor
    for (int i = 0; i < n - r + 1; i++) {
        for (int j = 0; j < m - c + 1; j++) {
            // Verifica se a cor do pixel na imagem é diferente do pixel desejado
            if (imagem[i][j] != pixels[i][j]) {
                operacoes++;
                
                // Realiza a operação de mudança de cor para todos os pixels do retângulo
                for (int x = i; x < i + r; x++) {
                    for (int y = j; y < j + c; y++) {
                        imagem[x][y] = 1 - imagem[x][y];
                    }
                }
            }
        }
    }
    
    // Verifica se a imagem resultante é igual à imagem desejada
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (imagem[i][j] != pixels[i][j]) {
                return -1; // Não é possível criar a pintura desejada
            }
        }
    }
    
    return operacoes;
}

int main() {
    int n, m, r, c;
    
    while (1) {
        scanf("%d %d %d %d", &n, &m, &r, &c);
        
        if (n == 0 && m == 0 && r == 0 && c == 0) {
            break;
        }
        
        int pixels[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%1d", &pixels[i][j]);
            }
        }
        
        int resultado = pintar_imagem(n, m, r, c, pixels);
        printf("%d\n", resultado);
    }
    
    return 0;
}