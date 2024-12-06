#include "dictionary.h"

// Inicializa o dicionário como vazio
void CreateEmpty(dictionary *d) {
    d->Head = NULL;
}

// Verifica se um nó está vazio
int Empty(Node *d) {
    return (d == NULL);
}

// Cria um novo verbo irregular preenchendo os campos
int CreateWord(word *w) {
    w->verb = (char *)malloc(50 * sizeof(char));
    w->infinitive = (char *)malloc(50 * sizeof(char));
    w->simple_past = (char *)malloc(50 * sizeof(char));
    w->past_participle = (char *)malloc(50 * sizeof(char));
    w->meaning = (char *)malloc(100 * sizeof(char));

    if (!w->infinitive || !w->simple_past || !w->past_participle || !w->meaning || !w->verb)
        return 0; // Falha na alocação
    printf("Digite o Verbo:");
    scanf(" %49[^\n]", w->verb);
    printf("Digite o infinitivo: ");
    scanf(" %49[^\n]", w->infinitive);
    printf("Digite o passado simples: ");
    scanf(" %49[^\n]", w->simple_past);
    printf("Digite o particípio passado: ");
    scanf(" %49[^\n]", w->past_participle);
    printf("Digite o significado: ");
    scanf(" %99[^\n]", w->meaning);

    return 1; // Sucesso
}

// Insere um novo nó na lista
int InsertWord(Node **d, word *w) {
    if ((*d) == NULL) {
        if(!CreateWord(w))
            return 0;
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) return 0;

        new_node->info = w;
        new_node->prox = NULL;
        *d = new_node;
        return 1;
    }
    return InsertWord(&((*d)->prox), w);
}

// Insere uma palavra no dicionário
int InsertDicionary(dictionary *d, word *w) {
    return InsertWord(&(d->Head), w);
}

int FreeVerbs(dictionary *d){
    Node *p, *q;
    p = d->Head;
    while(p != NULL){
        q = p;
        p = p->prox;
        free(q);
    }
    free(p);

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