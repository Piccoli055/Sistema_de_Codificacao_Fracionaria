# SCF — Sistema de Codificação Fracionária

Algoritmo de criptografia em C que transforma texto em frações matemáticas reversíveis usando duas chaves numéricas.

---

## Como compilar

```bash
gcc -o SCF SCF.c
```

## Como executar

```bash
./SCF
```

---

## Como usar

O programa pede três números como chave:

```
Sua chave (D a b): 13 23 12
```

### Criptografar

```
Seu texto        : ola mundo
Sua chave (D a b): 13 23 12

Cifra: 23/12|23/156|23/52 23/84|23/156|23/39|23/156|23/12
```

### Descriptografar

```
Sua cifra        : 23/12|23/156|23/52 23/84|23/156|23/39|23/156|23/12
Sua chave (D a b): 13 23 12

Texto: OLA MUNDO
```

> A chave usada para criptografar deve ser a mesma para descriptografar.
