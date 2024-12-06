# Dicionário Inglês-Português de Verbos Irregulares

## Universidade Federal de Rondônia 
**Estrutura de Dados I**  
**Trabalho: Dicionário Inglês-Português de Verbos Irregulares**  
**Dados de Entrega: 23/12/2024**

### Descrição do Projeto

Este projeto tem como objetivo uma implementação de um **Dicionário Inglês-Português de Verbos Irregulares**, utilizando como base uma lista de verbos irregulares em inglês, disponível em [Tabela de Verbos Irregulares da Wizard](https://www.wizard.com.br/idiomas/tabela-de-verbos-irregulares-em-ing). O programa permite armazenar, manipular e pesquisar verbos irregulares, suas conjugações e traduções em português. O sistema oferece um menu interativo, onde o usuário pode buscar verbos, adicionar novos, e removidos registros.

### Objetivos do Projeto

1. **Manipulação de Verbos Irregulares**: O dicionário permite armazenar e buscar verbos irregulares, suas conjugações no infinitivo, passado simples, particípio passado e seus significativos em português.
2. **Estrutura de Dados**: Ó projeto eua o conceito de **Listas Encadeadas Dinâmicas** para armazenar os verbos e suas informações, e oferece operações básicas sobre uma lista.
3. **Menu Interativo**: O usuário pode interagir com o programa através de um menu que permite:
   - Verbos Buscar.
   - Inserir novos verbos.
   - Verbos removedores.
   - Listar todos os verbos no dicionário.
4. **Persistência de Dados**: Ao fez o programa, os dados inseridos são salvos em um arquivo texto, garantindo que como alterações sejam preservadas.

### Requisitos

O sistema será implementado com os seguintes **tipos abstratos de dados** (TADs):
- **TAD Lista**: Representação de uma lista encadeada para armazenar os verbos.
  - Operações básicas:
    - Criar uma lista vazia.
    - Inserir um novo verbo.
    - Removedor um verbo.
    - Buscar um verbo.
    - Listar todos os verbos.
    - Destruir uma lista.

### Funcionalidades do Programa

1. **Carregar os verbos de um arquivo**: O programa permite carregar os verbos de um arquivo de texto e armazená-los na lista. Cada verbo será composto pelo seu **infinitivo**, **passado simples**, **particípio passado** e seu **significado**.
2. **Verbos Buscar**: O usuário pode buscar um verbo no dicionário. Se o verbo existir, o programa exibirá suas conjugações e seu significado. Se o verbo não for encontrado, o programa exibirá uma mensagem indicando isso.
3. **Inserir novos verbos**: O usuário pode adicionar novos verbos e suas conjugações ao dicionário.
4. **Remover verbos**: O programa permanente que o usuário remove um verbo do dicionário.
5. **Listar todos os verbos**: O programa pode listar todos os verbos armazenados no dicionário, exibindo suas conjugações e significados.
6. **Salvar alterações**: Ao fez o programa, todas como alterações feitas no dicionário (inclusões, remoções) são salvas no arquivo de texto, para garantir que os dados sejam preservados entre execuções.

### Estrutura de Dados

- **Tipo de Dados `palavra`**: Para armazenar as informações de um verbo irregular.
  `c
 typedef struct {
 char *verbo; // Verbo
 char *infinitivo; // Infinitivo
 char *simples_passado; // Passado Simples
 char *past_participle; // Particípio Passado
 char *significado; // Significado em português
 Palavra };
  `

- **Tipo de Dados `Não`**: Representação de um nó na lista encadeada.
  `c
 typedef struct node {
 struct node * prox; // Ponteiro para o próximo nó
 palavra *info; // Ponteiro para os dados do verbo
 Não };
  `

- **Tipo de Dados `dicionário`**: Representação do dicionário, que contém a lista encadeada.
  `c
 typedef struct {
 Nó *Cabeça; // Ponteiro para o início da lista de verbos
 dicionário };
  `

### Funcionalidades do Menu

O cardápio do programa permitido as seguintes operações:

1. **Inserir um verbo**:
   - O programa pedirá ao usuário para inserir como conjugações e o significado do verbo e o adicionará ao dicionário.
   
2. **Exibir todos os verbos**:
   - O programa listará todos os verbos armazenados no dicionário, mostrando suas conjugações e significados.
   
3. **Buscar um verbo**:
   - O usuário poderá digitar o verbo desejado e o sistema exibirá suas conjugações e significado se o verbo para o encontro no dicionário.
   
4. **Removedor um verbo**:
   - O programa permitido a remoção de um verbo da lista, se o verbo existente no dicionário.

5. **Sair e salvar alterações**:
   - Quando o programa para o fechado, todas como alterações (inclusões e remoções) são salvas no arquivo texto para que os dados não sejam perdidos.

### TAD Lista

A implementação do TAD Lista é fé usando **listas encadeadas dinâmicas**, com as seguintes operações:

1. **Criar_Vazia**: Cria uma lista vazia, inicializando o ponteiro da cabeça como `NULO`.
2. **Inserir**: Adiciona um novo verbo na lista.
3. **Removedor**: Removedor um verbo da lista.
4. **Imprimir/Listar**: Exibe todos os verbos da lista.
5. **Buscar**: Pesquisa um verbo na lista e exibe suas conjugações e significado.
6. **Destruir**: Libera toda a memória alocada pela lista.

### Como Compilar e Executar

1. **Compilar o código**:
   - Certifique-se de ter o compilador C (como `gcc` ou `clang`) instalado.
   - Compile o côdigo com o seguinte comando:
     `bash
 dicionário gcc -o dicionário.c
     `
   
2. **Executar o programa**:
   - Após compilar, executar o programa com o segundo comando:
     `bash
 . ./dicionário
     `

### Estrutura de Arquivos

O projeto contém os seguintes arquivos principais:

- **dicionário.h**: Cabeçalho que definem como estruturas de dados e declara como funções do dicionário.
- **dicionário.c**: Implementação das funções relacionadas à manipulação dos verbos e da lista encadeada.
- **principal.c**: Programa cliente que utiliza como funções do dicionário e permite interação com o usuário.
- **verbo.txt**: Arquivo de texto onde os verbos e suas informações serão armazenados e lidos.

### Conclusão

Este projeto oferece uma maneira simples de criar um inglês, utilizando 
