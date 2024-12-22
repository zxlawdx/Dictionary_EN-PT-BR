/* 
   Alunos: Marinaldo da Costa Barroso Filho e Carlos Eduardo Evangelista dos Santos
   Curso: Ciência da Computação 
   Trabalho 1: Dicionário de Verbos Irregulares Inglês-Português
   organizado com uma Lista Dinamicamente Encadeada
   Estrutura de Dados I -- 2024 -- DACC/UNIR
   Profa. Carolina Watanabe 
   Compilador: MinGW versão 6.0.3-1 ** Sistema Operacional: Windows 
*/
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
int InsertWord(Node **d);
int InsertDicionary(dictionary *d);
int FreeVerbs(dictionary *d);
int Show(dictionary *d);
Node* Search(Node* word, char* wordKey);
Node* Remove(Node* word, char* wordKey);
#endif
