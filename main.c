#include "dictionary.h"

int main() {
    dictionary d;
    word w;
    CreateEmpty(&d);
    int opc;

    printf("Bem-vindo ao dicionário de verbos irregulares!\n");
    printf("(1) - Inserir um verbo Novo\n");
    printf("(2) - Exibir todos os verbos existentes no dicionario\n");
    printf("(3) - Buscar um verbo\n");
    printf("Remover um verbo\n");
    printf("z\n");
    scanf("%d", &opc);

    while (opc != 0){
        switch (opc){
        case 1:
            InsertDicionary(&d, &w);
            printf("--press enter--");
            getchar();
            getchar();
            system("clear");
            break;
        case 2:
            if(!Show(&d))
                printf("o dicionário está vazio\n");
            printf("--press enter--");
            getchar();
            getchar();
            system("clear");
            break;
        case 3:
            printf("Mostrar o verbo existente, caso contrario, dizer que nao achou\n");
            break;
        case 0:
            break;
        default:
            break;
        }
        FreeVerbs(&d);
    }
    
    return 0;
}
