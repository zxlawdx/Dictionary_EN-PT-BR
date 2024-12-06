#include "dictionary.h"

int main() {
    dictionary d;
    word w;
    CreateEmpty(&d);
    int opc;

    printf("Bem-vindo ao dicionário de verbos irregulares!\n");
    printf("(1)- Inserir um verbo Novo\n");
    printf("(2) Exibir verbos existentes\n");
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
        case 0:
            break;
        default:
            break;
        }
        FreeVerbs(&d);
    }
    
    return 0;
}
