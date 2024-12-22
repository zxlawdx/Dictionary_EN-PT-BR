#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

int main() {
    dictionary dic;
    word wrd;
    int opc;

    // Inicializa o dicionário como vazio
    CreateEmpty(&dic);

    do {
        // Exibe o menu de opções
        printf("Bem-vindo ao dicionario de verbos irregulares!\n");
        printf("Criado por Marinaldo da Costa Barroso Filho e Carlos Eduardo Evangelista dos Santos\n");
        printf("(1) - Inserir um verbo novo\n");
        printf("(2) - Exibir todos os verbos existentes no dicionario\n");
        printf("(3) - Buscar um verbo\n");
        printf("(4) - Remover um verbo\n");
        printf("(0) - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        // Limpa o buffer de entrada
        while (getchar() != '\n');

        // Processa a opção escolhida
        switch (opc) {
        case 1:
            // Inserir um verbo
            if (InsertDicionary(&dic, &wrd)) {
                printf("Verbo inserido com sucesso!\n");
            } else {
                printf("Erro ao inserir o verbo.\n");
            }
            printf("-- Pressione Enter para continuar --");
            getchar(); // Pausa para o usuário visualizar
            system("cls"); // Limpa a tela no Windows (use "clear" se for no Linux)
            break;

        case 2:
            // Exibir todos os verbos
            if (!Show(&dic)) {
                printf("O dicionario esta vazio.\n");
            }
            printf("-- Pressione Enter para continuar --");
            getchar();
            system("cls");
            break;

        case 3: {
            // Buscar um verbo
            char verbo[50];
            printf("Digite o verbo que voce deseja buscar: ");
            scanf(" %49[^\n]", verbo);
            while (getchar() != '\n'); // Limpa o buffer
            if (!Search(dic.Head, verbo)) {
                printf("Verbo '%s' nao encontrado.\n", verbo);
            }
            printf("-- Pressione Enter para continuar --");
            getchar();
            system("cls");
            break;
        }

        case 4: {
            // Remover um verbo
            char verboRem[50];
            printf("Digite o verbo que voce deseja remover: ");
            scanf(" %49[^\n]", verboRem);
            while (getchar() != '\n'); // Limpa o buffer
            dic.Head = Remove(dic.Head, verboRem);
            printf("Verbo '%s' removido, se existia.\n", verboRem);
            printf("-- Pressione Enter para continuar --");
            getchar();
            system("cls");
            break;
        }

        case 0:
            // Sair do programa
            printf("Encerrando o programa...\n");
            break;

        default:
            // Opção inválida
            printf("Opcao invalida! Tente novamente.\n");
            printf("-- Pressione Enter para continuar --");
            getchar();
            system("cls");
            break;
        }

        // Libera recursos temporários após cada iteração
        FreeVerbs(&dic);

    } while (opc != 0);

    return 0;
}
