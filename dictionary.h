/* Alunos: Marinaldo da Costa Barroso Filho, Carlos Eduardo Evangelista
   Curso: Ciência da Computação
   Trabalho 1: Dicionário de Verbos irregulares Inglês-Português organizado com uma Lista */
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um verbo irregular
typedef struct {
    char *verb; //verbo 
    char *infinitive;       // Infinitivo
    char *simple_past;      // Passado Simples
    char *past_participle;  // Particípio Passado
    char *meaning;          // Significado
} word;

// Nó para lista ligada
typedef struct node {
    struct node *prox;
    word *info;
} Node;

// Estrutura principal do dicionário
typedef struct {
    Node *Head;
} dictionary;

// Funções do TAD
void CreateEmpty(dictionary *d);
int Empty(Node *d);
int CreateWord(word *w);
int InsertWord(Node **d, word *w);
int InsertDicionary(dictionary *d, word *w);
int FreeVerbs(dictionary *d);
int Show(dictionary *d);
#endif
