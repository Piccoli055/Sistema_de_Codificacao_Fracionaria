#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Chaves ainda fixas, mas ja pensando em mudar isso
int D = 13;
int A = 23;
int B = 12;

int mdc(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int letraPraNumero(char c) {
    return toupper(c) - 'A' + 1;
}

char numeroPraLetra(int n) {
    return 'A' + n - 1;
}

void criptografar(char texto[]) {
    int i;
    int primeiro = 1;

    printf("Cifra: ");

    for (i = 0; i < strlen(texto); i++) {
        if (texto[i] == ' ') {
            printf(" ");
            primeiro = 1;
            continue;
        }

        if (!isalpha(texto[i])) continue;

        int x = letraPraNumero(texto[i]);

        int num = A * x;
        int den = D * B;

        int d = mdc(num, den);
        num = num / d;
        den = den / d;

        if (!primeiro) printf("|");
        printf("%d/%d", num, den);
        primeiro = 0;
    }

    printf("\n");
}

void descriptografar(char cifra[]) {
    int i = 0;

    printf("Texto: ");

    while (i < strlen(cifra)) {
        if (cifra[i] == ' ') {
            printf(" ");
            i++;
            continue;
        }

        int num = 0, den = 0;
        while (i < strlen(cifra) && cifra[i] != '/') {
            num = num * 10 + (cifra[i] - '0');
            i++;
        }
        i++;
        while (i < strlen(cifra) && cifra[i] != '|' && cifra[i] != ' ') {
            den = den * 10 + (cifra[i] - '0');
            i++;
        }
        if (cifra[i] == '|') i++;

        int resultado_num = num * B * D;
        int resultado_den = den * A;

        int d = mdc(resultado_num, resultado_den);
        int x = resultado_num / d / (resultado_den / d);

        printf("%c", numeroPraLetra(x));
    }

    printf("\n");
}

int main() {
    int opcao;
    char entrada[500];

    int rodando = 1;
    while (rodando) {
        printf("\n=== ENIGMA FRAC DUAL ===\n");
        printf("Chave D: %d | Chave Frac: %d/%d\n\n", D, A, B);
        printf("1 - Criptografar\n");
        printf("2 - Descriptografar\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Digite o texto: ");
                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = '\0';
                criptografar(entrada);
                printf("\nPressione qualquer tecla para voltar...");
                getchar();
                break;

            case 2:
                printf("Digite a cifra: ");
                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = '\0';
                descriptografar(entrada);
                printf("\nPressione qualquer tecla para voltar...");
                getchar();
                break;

            case 3:
                printf("Encerrando...\n");
                rodando = 0;
                break;

            default:
                printf("Opcao invalida.\n");
        }
    }

    return 0;
}