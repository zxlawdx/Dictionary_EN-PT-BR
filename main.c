#include "dictionary.h"

int main() {
    dictionary d;
    CreateEmpty(&d);
    int opc;

    printf("Bem-vindo ao dicionário de verbos irregulares!\n");

    do {
        printf("\nEscolha uma opção:\n");
        printf("(1) Inserir um verbo novo\n");
        printf("(2) Exibir verbos existentes\n");
        printf("(0) Sair\n");
        printf("Opção: ");
        scanf("%d", &opc);
        while (getchar() != '\n'); // Limpa o buffer do stdin

        switch (opc) {
        case 1: {
            word *new_word = (word *)malloc(sizeof(word));
            if (new_word == NULL) {
                printf("Erro ao alocar memória para o verbo.\n");
                break;
            }
            if (InsertDicionary(&d, new_word)) {
                printf("Verbo inserido com sucesso!\n");
            } else {
                printf("Falha ao inserir o verbo.\n");
                free(new_word);
            }
            printf("--press enter--");
            getchar();
            break;
        }
        case 2:
            if (!Show(&d))
                printf("O dicionário está vazio.\n");
            printf("--press enter--");
            getchar();
            break;
        case 0:
            printf("Saindo do programa...\n");
            FreeVerbs(&d);
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (opc != 0);

    return 0;
}
