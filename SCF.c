// v5 - chave unificada, validacao e suporte a minusculas
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Chaves fixas por enquanto
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

int main() {
    // Teste direto, sem menu ainda
    printf("Testando com ZACARIAS:\n");
    criptografar("ZACARIAS");

    return 0;
}