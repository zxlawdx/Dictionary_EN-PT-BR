#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"


int main() {
    dicionario dic;
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
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);


        // Limpa o buffer de entrada
        while (getchar() != '\n');


        // Processa a opção escolhida
        switch (opc) {
        case 1: {
            // Inserir um verbo
            word *novaPlvr = (word *)malloc(sizeof(word));
            if (novaPlvr) {
                if (CreateWord(novaPlvr)) {
                    if (InsertWord(&dic.root, novaPlvr)) {
                        printf("Verbo inserido com sucesso!\n");
                    } else {
                        free(novaPlvr);
                        printf("Erro ao inserir o verbo (possivelmente já existente).\n");
                    }
                } else {
                    free(novaPlvr);
                    printf("Erro ao criar a palavra.\n");
                }
            } else {
                printf("Erro ao alocar memória para nova palavra.\n");
            }
            printf("-- Pressione Enter para continuar --");
            getchar(); // Pausa para o usuário visualizar
            system("cls"); // Use "clear" para Linux/macOS
            break;
        }


        case 2:
            // Exibir todos os verbos
            if (dic.root) {
                ExibirArvore(dic.root);
            } else {
                printf("Dicionario esta vazio!\n");
            }
            printf("-- Pressione Enter para continuar --");
            getchar();
            system("cls"); // Use "clear" para Linux/macOS
            break;


        case 3: {
            // Buscar um verbo
            char verbo[50];
            printf("Digite o verbo que voce deseja buscar: ");
            scanf(" %49[^\n]", verbo);
            while (getchar() != '\n'); // Limpa o buffer


            Node *resultado = Buscar(dic.root, verbo);
            if (resultado) {
                printf("Verbo encontrado!\n");
                printf("Verbo: %s\n", resultado->info->verb);
                printf("Infinitivo: %s\n", resultado->info->infinitive);
                printf("Passado Simples: %s\n", resultado->info->simple_past);
                printf("Particípio Passado: %s\n", resultado->info->past_participle);
                printf("Significado: %s\n", resultado->info->meaning);
            } else {
                printf("Verbo '%s' nao encontrado.\n", verbo);
            }
            printf("-- Pressione Enter para continuar --");
            getchar();
            system("cls"); // Use "clear" para Linux/macOS
            break;
        }


        case 4: {
            // Remover um verbo
            char verboRem[50];
            printf("Digite o verbo que voce deseja remover: ");
            scanf(" %49[^\n]", verboRem);
            while (getchar() != '\n'); // Limpa o buffer


            dic.root = Remove(dic.root, verboRem);
            printf("Verbo '%s' removido com sucesso.\n", verboRem);
            printf("-- Pressione Enter para continuar --");
            getchar();
            system("cls"); // Use "clear" para Linux/macOS
            break;
        }


        case 0:
            // Sair do programa
            printf("Encerrando o programa...\n");
            FreeVerbs(dic.root); // Libera todos os verbos
            break;


        default:
            // Opção inválida
            printf("Opcao invalida! Tente novamente.\n");
            printf("-- Pressione Enter para continuar --");
            getchar();
            system("cls"); // Use "clear" para Linux/macOS
            break;
        }


    } while (opc != 0);


    return 0;
}
