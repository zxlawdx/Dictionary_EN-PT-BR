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
    printf("Digite o Verbo:");
    scanf(" %49[^\n]", word->verb);
    printf("Digite o infinitivo: ");
    scanf(" %49[^\n]", word->infinitive);
    printf("Digite o passado simples: ");
    scanf(" %49[^\n]", word->simple_past);
    printf("Digite o particípio passado: ");
    scanf(" %49[^\n]", word->past_participle);
    printf("Digite o significado: ");
    scanf(" %99[^\n]", word->meaning);

    return 1; // Sucesso
}

// Insere um novo nó na lista
int InsertWord(Node **node, word *wrd) {
    if ((*node) == NULL) { // vazio
        if(!CreateWord(wrd))
            return 0;
        Node *new_node = (Node *)malloc(sizeof(Node)); // nó temporário
        if (new_node == NULL) return 0;

        new_node->info = wrd; // nó
        new_node->prox = NULL; // nó folha
        *node = new_node;
        return 1;
    }
    return InsertWord(&((*node)->prox), wrd);
}

// Insere uma palavra no dicionário
int InsertDicionary(dictionary *d, word *w) {
    return InsertWord(&(d->Head), w);
}

int FreeVerbs(dictionary *dictionary){
    // Node *p, *q;
    // p = d->Head;
    // while(p != NULL){
    //     q = p;
    //     p = p->prox;
    //     free(q);
    // }
    // free(p);

    Node *p = dictionary->Head;
    while(p != NULL){
        Node *q = p;
        p = p->prox;

        free((q)->info->infinitive);
        free((q)->info->meaning);
        free((q)->info->past_participle);
        free((q)->info->simple_past);
        free((q)->info->verb);
        free((q)->info);
        free(q);
    }

    dictionary->Head = NULL;

    return 1;
}

int Show (dictionary *d){
    if(Empty(d->Head))
        return 0;
    
    Node *p;
    for(p = d->Head; p!= NULL; p = p->prox){
        printf("verbo: %s\n", p->info->verb);
        printf("infinitivo: %s\n", p->info->infinitive);
        printf("passado simples: %s\n", p->info->simple_past);
        printf("particípio passado: %s\n", p->info->past_participle);
        printf("significado: %s\n", p->info->meaning);
    }
}

Node *Remove(Node *word, char wordKey){
    if(word == NULL)
        return 0;

    if(strcmp(word->info->verb, wordKey) == 0){
        Node* tmp = word->prox;

        free(word->info->infinitive);
        free(word->info->meaning);
        free(word->info->past_participle);
        free(word->info->simple_past);
        free(word->info->verb);
        free(word->info);
        free(word);

        return tmp;
    }
    word->prox = Remove(word->prox, wordKey);
    return word;
}
