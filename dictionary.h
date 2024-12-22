#ifndef DICIONARIO_H
#define DICIONARIO_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char *verb;
    char *infinitive;
    char *simple_past;
    char *past_participle;
    char *meaning;
} word;


typedef struct node{
    word *info;
    struct node *left; // filho à esquerda
    struct node *right; // filho à direita
    int height; // altura do no
} Node;


typedef struct{
    Node *root;
} dicionario;


void CreateEmpty(dicionario *dic);
int CreateWord(word *wrd);
Node* InsertWord(Node **root, word *new_word);
Node* Remove(Node *root, const char *verb);
Node* Buscar(Node *root, const char *verb);
void FreeVerbs(Node *root);
void ExibirArvore(Node *root);


#endif
