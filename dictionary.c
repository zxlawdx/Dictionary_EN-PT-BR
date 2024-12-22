#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Calcula a altura do nó
int Height(Node *no) {
    return no ? no->height : 0;
}


// Calcula o fator de balanceamento
int GetBalance(Node *no) {
    if (!no) return 0;
    return Height(no->left) - Height(no->right);
}


// Realiza rotação à direita
Node *RotateRight(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;


    x->right = y;
    y->left = T2;


    y->height = 1 + (Height(y->left) > Height(y->right) ? Height(y->left) : Height(y->right));
    x->height = 1 + (Height(x->left) > Height(x->right) ? Height(x->left) : Height(x->right));


    return x;
}


// Realiza rotação à esquerda
Node *RotateLeft(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;


    y->left = x;
    x->right = T2;


    x->height = 1 + (Height(x->left) > Height(x->right) ? Height(x->left) : Height(x->right));
    y->height = 1 + (Height(y->left) > Height(y->right) ? Height(y->left) : Height(y->right));


    return y;
}


// Inicializa o dicionário vazio
void CreateEmpty(dicionario *dic) {
    dic->root = NULL;
}


// Cria e preenche uma nova palavra
int CreateWord(word *wrd) {
    wrd->verb = (char *)malloc(50 * sizeof(char));
    wrd->infinitive = (char *)malloc(50 * sizeof(char));
    wrd->simple_past = (char *)malloc(50 * sizeof(char));
    wrd->past_participle = (char *)malloc(50 * sizeof(char));
    wrd->meaning = (char *)malloc(100 * sizeof(char));


    if (!wrd->verb || !wrd->infinitive || !wrd->simple_past || !wrd->past_participle || !wrd->meaning)
        return 0;


    printf("Digite o verbo: ");
    scanf(" %49[^\n]", wrd->verb);
    printf("Digite o infinitivo: ");
    scanf(" %49[^\n]", wrd->infinitive);
    printf("Digite o passado simples: ");
    scanf(" %49[^\n]", wrd->simple_past);
    printf("Digite o participio passado: ");
    scanf(" %49[^\n]", wrd->past_participle);
    printf("Digite o significado: ");
    scanf(" %99[^\n]", wrd->meaning);


    return 1;
}


// Insere uma nova palavra na árvore
Node* InsertWord(Node **root, word *new_word) {
    if (!*root) {
        *root = (Node *)malloc(sizeof(Node));
        if (!*root) return NULL;


        (*root)->info = new_word;
        (*root)->left = (*root)->right = NULL;
        (*root)->height = 1;
        return *root;
    }


    // Inserção recursiva
    if (strcmp(new_word->verb, (*root)->info->verb) < 0) {
        (*root)->left = InsertWord(&(*root)->left, new_word);
    } else if (strcmp(new_word->verb, (*root)->info->verb) > 0) {
        (*root)->right = InsertWord(&(*root)->right, new_word);
    } else {
        // Verbo já existe
        printf("O verbo '%s' já existe no dicionário!\n", new_word->verb);
        return *root;
    }


    // Atualiza a altura do nó
    (*root)->height = 1 + (Height((*root)->left) > Height((*root)->right) ? Height((*root)->left) : Height((*root)->right));


    // Obtém o fator de balanceamento
    int balance = GetBalance(*root);


    // Balanceamento
    // Rotação à direita
    if (balance > 1 && strcmp(new_word->verb, (*root)->left->info->verb) < 0)
        return RotateRight(*root);


    // Rotação à esquerda
    if (balance < -1 && strcmp(new_word->verb, (*root)->right->info->verb) > 0)
        return RotateLeft(*root);


    // Rotação dupla (esquerda-direita)
    if (balance > 1 && strcmp(new_word->verb, (*root)->left->info->verb) > 0) {
        (*root)->left = RotateLeft((*root)->left);
        return RotateRight(*root);
    }


    // Rotação dupla (direita-esquerda)
    if (balance < -1 && strcmp(new_word->verb, (*root)->right->info->verb) < 0) {
        (*root)->right = RotateRight((*root)->right);
        return RotateLeft(*root);
    }


    return *root;
}


Node* EncontrarMenor(Node *no){
    while(no->left){
        no = no->left;
    }


    return no;
}


Node *Remove(Node *root, const char *verb) {
    if (!root) {
        printf("Verbo '%s' nao encontrado.\n", verb);
        return root; // Nó não encontrado, retorna o próprio root
    }


    // Navega pela árvore para encontrar o nó a ser removido
    if (strcmp(verb, root->info->verb) < 0) {
        root->left = Remove(root->left, verb); // Verbo está na subárvore esquerda
    } else if (strcmp(verb, root->info->verb) > 0) {
        root->right = Remove(root->right, verb); // Verbo está na subárvore direita
    } else {
        // Verbo encontrado, proceder com a remoção


        // Caso 1: Nó com apenas um filho ou nenhum
        if (!root->left || !root->right) {
            Node *temp = root->left ? root->left : root->right;


            // Caso nenhum filho
            if (!temp) {
                temp = root;
                root = NULL;
            } else {
                // Copia o único filho
                *root = *temp;
            }


            free(temp->info->verb);
            free(temp->info->infinitive);
            free(temp->info->simple_past);
            free(temp->info->past_participle);
            free(temp->info->meaning);
            free(temp->info);
            free(temp);
        } else {
            // Caso 2: Nó com dois filhos


            // Encontra o sucessor em ordem (o menor nó na subárvore direita)
            Node *temp = EncontrarMenor(root->right);


            // Copia os dados do sucessor para o nó atual
            word *temp_word = root->info;
            root->info = temp->info;
            temp->info = temp_word;


            // Remove o sucessor
            root->right = Remove(root->right, temp->info->verb);
        }
    }


    // Caso base: se a árvore ficou vazia após remoção
    if (!root) return root;


    // Atualiza a altura do nó
    root->height = 1 + (Height(root->left) > Height(root->right) ? Height(root->left) : Height(root->right));


    // Calcula o fator de balanceamento
    int balance = GetBalance(root);


    // Balanceia a árvore AVL


    // Caso 1: Esquerda-Esquerda
    if (balance > 1 && GetBalance(root->left) >= 0) {
        return RotateRight(root);
    }


    // Caso 2: Esquerda-Direita
    if (balance > 1 && GetBalance(root->left) < 0) {
        root->left = RotateLeft(root->left);
        return RotateRight(root);
    }


    // Caso 3: Direita-Direita
    if (balance < -1 && GetBalance(root->right) <= 0) {
        return RotateLeft(root);
    }


    // Caso 4: Direita-Esquerda
    if (balance < -1 && GetBalance(root->right) > 0) {
        root->right = RotateRight(root->right);
        return RotateLeft(root);
    }


    return root; // Retorna o nó raiz balanceado
}




// Busca um verbo na árvore
Node *Buscar(Node *root, const char *verb) {
    if (!root || strcmp(verb, root->info->verb) == 0)
        return root;


    if (strcmp(verb, root->info->verb) < 0)
        return Buscar(root->left, verb);


    return Buscar(root->right, verb);
}


// Exibe os verbos na árvore em ordem
void ExibirArvore(Node *root) {
    if (!root) return;


    ExibirArvore(root->left);


    printf("Verbo: %s\nInfinitivo: %s\nPassado Simples: %s\nParticipio Passado: %s\nSignificado: %s\n",
           root->info->verb, root->info->infinitive, root->info->simple_past,
           root->info->past_participle, root->info->meaning);


    ExibirArvore(root->right);
}


// Libera a memória de todos os verbos
void FreeVerbs(Node *root) {
    if (!root) return;


    FreeVerbs(root->left);
    FreeVerbs(root->right);


    free(root->info->verb);
    free(root->info->infinitive);
    free(root->info->simple_past);
    free(root->info->past_participle);
    free(root->info->meaning);
    free(root->info);
    free(root);
}
