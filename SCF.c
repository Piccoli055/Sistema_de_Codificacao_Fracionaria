#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int letraParaNumero(char c) {
    return toupper(c) - 'A' + 1;
}

char numeroParaLetra(int n) {
    return 'A' + n - 1;
}

void criptografar(char texto[], int D, int A, int B) {
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
        int x = letraParaNumero(texto[i]);
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

void descriptografar(char cifra[], int D, int A, int B) {
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
        printf("%c", numeroParaLetra(x));
    }
    printf("\n");
}

void exemplos() {
    int D = 13, A = 23, B = 12;
    printf("\n  +================================+\n");
    printf("  |       EXEMPLOS  INTERNOS       |\n");
    printf("  |   Chave: %d %d %d              |\n", D, A, B);
    printf("  +================================+\n\n");
    printf("  Texto : ZACARIAS\n  ");
    criptografar("ZACARIAS", D, A, B);
    printf("\n  Texto : ola mundo (minusculas)\n  ");
    criptografar("ola mundo", D, A, B);
    printf("\n  Cifra : 23/12|23/156|23/52 23/84|23/156|23/39|23/156|23/12\n  ");
    descriptografar("23/12|23/156|23/52 23/84|23/156|23/39|23/156|23/12", D, A, B);
    printf("\n  Pressione qualquer tecla para voltar...");
    getchar();
}

int main() {
    int opcao;
    char entrada[500];
    int D, A, B;
    int rodando = 1;
    while (rodando) {
        printf("\n");
        printf("  +================================+\n");
        printf("  |              SCF               |\n");
        printf("  |  Sistema de Codificacao Frac.  |\n");
        printf("  +================================+\n");
        printf("  |  [1]  Criptografar             |\n");
        printf("  |  [2]  Descriptografar          |\n");
        printf("  |  [3]  Exemplos internos        |\n");
        printf("  |  [4]  Sair                     |\n");
        printf("  +================================+\n");
        printf("  Escolha: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao) {
            case 1:
                printf("\n  -- CRIPTOGRAFAR --\n");
                printf("  Seu texto        : ");
                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = '\0';
                printf("  Sua chave (D a b): ");
                scanf("%d %d %d", &D, &A, &B);
                getchar();
                if (D == 0 || B == 0) {
                    printf("\n  Chave invalida! D e b nao podem ser zero.\n");
                    printf("\n  Pressione qualquer tecla para voltar...");
                    getchar();
                    break;
                }
                printf("\n  ");
                criptografar(entrada, D, A, B);
                printf("  Chave utilizada  : %d %d %d\n", D, A, B);
                printf("\n  Pressione qualquer tecla para voltar...");
                getchar();
                break;
            case 2:
                printf("\n  -- DESCRIPTOGRAFAR --\n");
                printf("  Sua cifra        : ");
                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = '\0';
                printf("  Sua chave (D a b): ");
                scanf("%d %d %d", &D, &A, &B);
                getchar();
                if (D == 0 || B == 0) {
                    printf("\n  Chave invalida! D e b nao podem ser zero.\n");
                    printf("\n  Pressione qualquer tecla para voltar...");
                    getchar();
                    break;
                }
                printf("\n  ");
                descriptografar(entrada, D, A, B);
                printf("  Chave utilizada  : %d %d %d\n", D, A, B);
                printf("\n  Pressione qualquer tecla para voltar...");
                getchar();
                break;
            case 3:
                exemplos();
                break;
            case 4:
                printf("\n  Encerrando...\n");
                rodando = 0;
                break;
            default:
                printf("\n  Opcao invalida. Tente novamente.\n");
        }
    }
    return 0;
}
