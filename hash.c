#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

/* unsigned long valorString(const char *str) {
    unsigned long valor = 0;
    for (int i = 0; str[i] != '\0'; i++)
        valor += (unsigned char)str[i];
    return valor;
} */

unsigned long valorString(const char *str) {
    unsigned long valor = 7;
    int tam = strlen(str);

    for (int i = 0; i < tam; i++) {
        valor = 31UL * valor + (unsigned char)str[i];
    }

    return valor;
}

int chaveMultiplicacao(unsigned long chave, int tamanho) {
    const double A = 0.6180339887;
    double val = chave * A;
    val = val - (long)val;
    return (int)(tamanho * val);
}

unsigned long hashSenha(const char *senha) {
    return valorString(senha);
}

Hash* criaHash(int tamanho) {
    Hash *h = (Hash*) malloc(sizeof(Hash));
    if (!h) return NULL;

    h->tamanho = tamanho;
    h->tabela = (Usuario**) malloc(tamanho * sizeof(Usuario*));
    if (!h->tabela) {
        free(h);
        return NULL;
    }

    for (int i = 0; i < tamanho; i++)
        h->tabela[i] = NULL;

    return h;
}

Usuario* buscaHash(Hash *h, const char *username) {
    if (!h) return NULL;

    unsigned long chave = valorString(username);
    int pos = chaveMultiplicacao(chave, h->tamanho);

    Usuario *atual = h->tabela[pos];
    while (atual != NULL) {
        if (strcmp(atual->username, username) == 0)
            return atual;
        atual = atual->prox;
    }
    return NULL;
}

// Inserção com encadeamento separado
int insereHash(Hash *h, const char *username, const char *senha) {
    if (!h) return 0;

    if (buscaHash(h, username) != NULL)
        return 0; // já existe

    unsigned long chaveUser = valorString(username);
    int pos = chaveMultiplicacao(chaveUser, h->tamanho);

    Usuario *novo = (Usuario*) malloc(sizeof(Usuario));
    if (!novo) return 0;

    strcpy(novo->username, username);
    novo->hashSenha = hashSenha(senha);
    novo->prox = h->tabela[pos];
    h->tabela[pos] = novo;

    return 1;
}

int removeHash(Hash *h, const char *username) {
    if (!h) return 0;

    unsigned long chave = valorString(username);
    int pos = chaveMultiplicacao(chave, h->tamanho);

    Usuario *atual = h->tabela[pos];
    Usuario *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->username, username) == 0) {

            if (anterior == NULL)
                h->tabela[pos] = atual->prox;
            else
                anterior->prox = atual->prox;

            free(atual);
            return 1;
        }

        anterior = atual;
        atual = atual->prox;
    }

    return 0;
}

void imprimeHash(Hash *h) {
    if (!h) return;

    printf("\n=== TABELA HASH ===\n");

    for (int i = 0; i < h->tamanho; i++) {
        printf("[%02d] ", i);

        Usuario *atual = h->tabela[i];

        if (!atual) {
            printf("(vazio)\n");
            continue;
        }

        while (atual != NULL) {
            printf("-> %s (hash=%lu) ", atual->username, atual->hashSenha);
            atual = atual->prox;
        }
        printf("\n");
    }
}

void liberaHash(Hash *h) {
    if (!h) return;

    for (int i = 0; i < h->tamanho; i++) {
        Usuario *atual = h->tabela[i];
        while (atual) {
            Usuario *aux = atual;
            atual = atual->prox;
            free(aux);
        }
    }

    free(h->tabela);
    free(h);
}

// Parte-Cadastro
void cadastrarUsuario(Hash *h) {
    char username[TAM_USERNAME];
    char senha[TAM_SENHA];

    printf("Username: ");
    scanf("%s", username);
    printf("Senha: ");
    scanf("%s", senha);

    if (insereHash(h, username, senha))
        printf("Usuario cadastrado!\n");
    else
        printf("Erro ao cadastrar (ou usuario já existe).\n");
}

// Parte-Login
void loginUsuario(Hash *h) {
    char username[TAM_USERNAME];
    char senha[TAM_SENHA];

    printf("Username: ");
    scanf("%s", username);
    printf("Senha: ");
    scanf("%s", senha);

    Usuario *u = buscaHash(h, username);

    if (!u) {
        printf("Usuario nao encontrado.\n");
        return;
    }

    if (u->hashSenha == hashSenha(senha))
        printf("Login bem-sucedido!\n");
    else
        printf("Senha incorreta.\n");
}

void removerUsuario(Hash *h) {
    char username[TAM_USERNAME];

    printf("Username para remover: ");
    scanf("%s", username);

    if (removeHash(h, username))
        printf("Usuario removido.\n");
    else
        printf("Usuario nao encontrado.\n");
}
