#include "dictionary.h"

// Inicializa o dicionário como vazio
void CreateEmpty(dictionary *dictionary) {
    dictionary->Head = NULL;
}

// Verifica se um nó está vazio
int Empty(Node *no) {
    return (no == NULL);
}

// Cria um novo verbo irregular preenchendo os campos
int CreateWord(word *word) {
    word->verb = (char *)malloc(50 * sizeof(char));
    word->infinitive = (char *)malloc(50 * sizeof(char));
    word->simple_past = (char *)malloc(50 * sizeof(char));
    word->past_participle = (char *)malloc(50 * sizeof(char));
    word->meaning = (char *)malloc(100 * sizeof(char));

    if (!word->infinitive || !word->simple_past || !word->past_participle || !word->meaning || !word->verb)
        return 0; // Falha na alocação
    printf("Digite o Verbo: ");
    scanf(" %49[^\n]", word->verb);
    printf("Digite o infinitivo: ");
    scanf(" %49[^\n]", word->infinitive);
    printf("Digite o passado simples: ");
    scanf(" %49[^\n]", word->simple_past);
    printf("Digite o participio passado: ");
    scanf(" %49[^\n]", word->past_participle);
    printf("Digite o significado: ");
    scanf(" %99[^\n]", word->meaning);

    return 1; // Sucesso
}

// Insere um novo nó na lista
int InsertWord(Node **node) {
    // Aloca um novo verbo
    word *new_word = (word *)malloc(sizeof(word));
    if (new_word == NULL) 
        return 0;

    // Preenche os campos do verbo usando `CreateWord`
    if (!CreateWord(new_word)) {
        free(new_word);
        return 0;
    }

    // Aloca um novo nó para a lista
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        // Libera o verbo em caso de falha na alocação do nó
        free(new_word->verb);
        free(new_word->infinitive);
        free(new_word->simple_past);
        free(new_word->past_participle);
        free(new_word->meaning);
        free(new_word);
        return 0;
    }

    // Insere o novo verbo no nó e ajusta a lista
    new_node->info = new_word;
    new_node->prox = *node; // Adiciona no início da lista
    *node = new_node;

    return 1; // Sucesso
}


// Insere uma palavra no dicionário
int InsertDicionary(dictionary *d) {
    return InsertWord(&(d->Head));
}

int FreeVerbs(dictionary *dictionary){

    Node *p = dictionary->Head;
    while(p != NULL){
        Node *q = p;
        p = p->prox;

        free((q)->info->verb);
        free((q)->info->infinitive);
        free((q)->info->simple_past);
        free((q)->info->past_participle);
        free((q)->info->meaning);

        free((q)->info);
        free(q);
    }

    dictionary->Head = NULL;

    return 1;
}

int Show (dictionary *d){
    if(Empty(d->Head)){
        printf("Dicionario esta vazio!\n");
        return 0;
    }
    
    Node *p = d->Head;
    while(p != NULL){
        printf("verbo: %s\n", p->info->verb);
        printf("infinitivo: %s\n", p->info->infinitive);
        printf("passado simples: %s\n", p->info->simple_past);
        printf("participio passado: %s\n", p->info->past_participle);
        printf("significado: %s\n", p->info->meaning);
        printf("-----------------------------------------------------\n");
        p = p->prox;
    }

    return 1;
}

Node *Search(Node *word, char* wordKey){
    if(word == NULL)
        return NULL;

    Node *current = word;
    while(current != NULL){
    if(strcmp(word->info->verb, wordKey) == 0){
            printf("Traducao para a palavra, '%s': ", wordKey);
            printf("%s\n", current->info->meaning );
            return current;
        }

        current = current->prox;
    }

    printf("A palavra %s nao encontrada no dicionario\n", wordKey);
    return NULL;
}

Node *Remove(Node *word, char* wordKey){
    if(word == NULL)
        return NULL;

    if(strcmp(word->info->verb, wordKey) == 0){ // 0 se iguais, 1 se diferentes
        Node* tmp = word->prox;

        free(word->info->verb);
        free(word->info->infinitive);
        free(word->info->simple_past);
        free(word->info->past_participle);
        free(word->info->meaning);

        free(word);

        return tmp;
    }
    word->prox = Remove(word->prox, wordKey);
    return word;
}
