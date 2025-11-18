#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main() {
    int tamanho = 37;      
    Hash *h = criaHash(tamanho);

    if (!h) {
        printf("Erro ao criar tabela hash.\n");
        return 1;
    }

    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Cadastrar usuario\n");
        printf("2 - Login\n");
        printf("3 - Remover usuario\n");
        printf("4 - Imprimir tabela\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarUsuario(h); break;
            case 2: loginUsuario(h); break;
            case 3: removerUsuario(h); break;
            case 4: imprimeHash(h); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    liberaHash(h);
    
    return 0;
}
