#include <stdio.h>

typedef struct _Adj {
	int id;
	struct _Adj *prox;
	struct _Adj *ant;
}Adj;

typedef struct _Adjacencias {
	Adj *head;
	Adj *tail;
}Adjacencias;

typedef Adjacencias *pt_adjacencias;

typedef struct _Vertice {
	int id;
	pt_adjacencias adjs;
	struct _Vertice *prox;
	struct _Vertice *ant;
}Vertice;

typedef struct _Lista_Vertices {
	Vertice *head;
	Vertice *tail;
}Lista_Vertices;

typedef Lista_Vertices *pt_lista_vertices;

/*************************************** Estrutura Lista ***************************************/

/* id -> Identificador de um vértice.
 * Retorno -> Nó do tipo adj que foi alocado.
 * Cria um novo nó do tipo adjacência que será acossiado a uma lista de adjacências
 * de um vértice.*/
Adj *aloca_nova_adj(int id);

/* Retorno -> Lista de nós do tipo Adj que foi criada.
 * Cria uma nova lista de adjacências que será acossiada a um vértice.*/
pt_adjacencias nova_lista_adj();

/* pt_adj -> Ponteiro para uma lista de adjacências.
 * Retorno -> 1 se a lista está vazia, 0 caso contrário.
 * Verifica se a lista de adjacências está vazia*/
int lista_adj_vazia(pt_adjacencias pt_adj);

/* pt_adj -> Ponteiro para uma lista de adjacências.
 * nova_adj -> Nó do tipo Adj que é criado por aloca_nova_adj().
 * Associa uma adjacência a uma lista de adjacências.
 * */
void insere_adj(pt_adjacencias pt_adj, Adj *nova_adj);

/* pt_adj -> Ponteiro para uma lista de adjacências.
 * Retorno -> Nó do tipo Adj que foi removido.
 * Remove a ultima adjacência inserida na lista*/
Adj *remove_adj(pt_adjacencias pt_adj);

/* pt_adj -> Ponteiro para uma lista de adjacências.
 * adj -> Identificador da adjacência a ser removida.
 * Retorno -> Nó do tipo Adj que foi removido.
 * Remove a adjacência especificada nos parametros se ela existir, caso contrário
 * retorna pt_adj->head*/
Adj *remove_adj_e(pt_adjacencias pt_adj, int id);// Precisa de testes e função similar para vértices
Vertice *aloca_novo_vertice (int id);
pt_lista_vertices nova_lista_vertices();
int lista_vertices_vazia (pt_lista_vertices pt_vertices);
void insere_vertice (pt_lista_vertices pt_vertices, Vertice *novo_vertice);
Vertice *remove_vertice (pt_lista_vertices pt_vertices);
Vertice *remove_vertice_e (pt_lista_vertices pt_vertices, int id);

/***********************************************************************************************/
/* Operacões Lista*/
int insere_adj_vertice(pt_lista_vertices pt_vertices, int vertice, int adj);
int preenche_lista_adj(pt_lista_vertices pt_vertices, FILE *arquivo, char *n_grafo);
void mostra_lista_grafo(pt_lista_vertices pt_vertices);
char* retorna_adjs_vertice(pt_lista_vertices pt_vertices, int vertice);
pt_lista_vertices matriz_para_lista (char** mat_adj, int n_vertices);

/* Estrutura Matriz */
char** cria_matriz (int n_vertices);
void limpa_memoria_matriz (char** mat_adj);
char** preenche_mat_adj (FILE *arquivo, char *n_grafo, int *n_vertices); // Falta ler matrizes de grafos orientados

/*Operações Matriz */
char** lista_para_matriz( pt_lista_vertices pt_vertices, int n_vertices, char orientado);
void gera_vet_matriz_triang_sup (char** mat_adj, int n_vertices, char *vet_triang_sup);
char** gera_matriz_completa (char* vet_triang_sup, int n_vertices, char orientado);
int n_arestas_matriz(char** mat_adj, int n_vertices, int orientado);
void converte_inteiro_base(int num, int *resultado, int base);
void gerar_orientacao(char** mat_adj, char** mat_adj_orientada, int n_vertices, int num_orientacao, int n_arestas);
int ver_colorcao(char *vet_triang_sup, int *combinacao, int n_vertices);

