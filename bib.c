#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bib.h"

Adj *aloca_nova_adj (int id) {
	Adj *nova_adj;
	
	nova_adj = (Adj *) malloc (sizeof(Adj));
	
	if(nova_adj == NULL)
		exit(EXIT_FAILURE);
	
	nova_adj->id = id;
	nova_adj->prox = NULL;
	nova_adj->ant = NULL;
	
	return nova_adj;
}

pt_adjacencias nova_lista_adj () {
	pt_adjacencias novalistaadj = (pt_adjacencias) malloc (sizeof(Adjacencias));
	
	if(novalistaadj == NULL)
		exit(EXIT_FAILURE);
	
	novalistaadj->head = aloca_nova_adj(-2);
	novalistaadj->tail = aloca_nova_adj(-2);
	
	
	novalistaadj->head->ant = novalistaadj->tail;
	novalistaadj->tail->prox = novalistaadj->head;
	
	return novalistaadj;
}

int lista_adj_vazia (pt_adjacencias pt_adj) {
	if(pt_adj->head->ant == pt_adj->tail)
		return 1;

	return 0;
}

void insere_adj (pt_adjacencias pt_adj, Adj *nova_adj) {
	Adj *aux = pt_adj->tail->prox;
	
	
	aux = pt_adj->tail->prox;
	aux->ant->prox = nova_adj;
	nova_adj->ant = aux->ant;
	nova_adj->prox = aux;
	aux->ant = nova_adj;
}

Adj *remove_adj (pt_adjacencias pt_adj) {
	if(lista_adj_vazia(pt_adj) == 1 || pt_adj == NULL)
		return NULL;
	 
	Adj *adj_ret = pt_adj->head->ant;
	
	pt_adj->head->ant = pt_adj->head->ant->ant;
	adj_ret->ant->prox = pt_adj->head;
	
	adj_ret->prox = NULL;
	adj_ret->ant = NULL;
	
	return adj_ret;
}

Adj *remove_adj_e (pt_adjacencias pt_adj, int id) {
	if(lista_adj_vazia(pt_adj) == 1 || pt_adj == NULL)
		return NULL;
		
	Adj *adj_ret = pt_adj->tail->prox;
	
	while(adj_ret != pt_adj->head) {
		if(adj_ret->id == id){
			adj_ret->ant->prox = adj_ret->prox;
			adj_ret->prox->ant = adj_ret->ant;
			adj_ret->prox = NULL;
			adj_ret->ant = NULL;
			break;
		}
		
		adj_ret = adj_ret->prox;
	}
	
	return adj_ret;
}

Vertice *aloca_novo_vertice (int id) {
	Vertice *novo_vertice;
	
	novo_vertice = (Vertice *) malloc (sizeof(Vertice));
	
	if(novo_vertice == NULL)
		exit(EXIT_FAILURE);
	
	novo_vertice->id = id;
	novo_vertice->adjs = nova_lista_adj();
	novo_vertice->prox = NULL;
	novo_vertice->ant = NULL;
	
	return novo_vertice;
}

pt_lista_vertices nova_lista_vertices () {
	pt_lista_vertices novalistavertices = (pt_lista_vertices) malloc (sizeof(Vertice));
	
	if(novalistavertices == NULL)
		exit(EXIT_FAILURE);
	
	novalistavertices->head = aloca_novo_vertice(-2);
	novalistavertices->tail = aloca_novo_vertice(-2);
	
	
	novalistavertices->head->ant = novalistavertices->tail;
	novalistavertices->tail->prox = novalistavertices->head;
	
	return novalistavertices;
}

int lista_vertices_vazia (pt_lista_vertices pt_vertices) {
	if(pt_vertices->head->ant == pt_vertices->tail)
		return 1;

	return 0;
}

void insere_vertice (pt_lista_vertices pt_vertices, Vertice *novo_vertice) {
	Vertice *aux = pt_vertices->tail->prox;
	
	
	aux = pt_vertices->tail->prox;
	aux->ant->prox = novo_vertice;
	novo_vertice->ant = aux->ant;
	novo_vertice->prox = aux;
	aux->ant = novo_vertice;
}

Vertice *remove_vertice (pt_lista_vertices pt_vertices) {
	if(lista_vertices_vazia(pt_vertices) == 1 || pt_vertices == NULL)
		return NULL;
	 
	Vertice *vertice_ret = pt_vertices->head->ant;
	
	pt_vertices->head->ant = pt_vertices->head->ant->ant;
	vertice_ret->ant->prox = pt_vertices->head;
	
	vertice_ret->prox = NULL;
	vertice_ret->ant = NULL;
	
	return vertice_ret;
}

Vertice *remove_vertice_e (pt_lista_vertices pt_vertices, int id) {
	
	if(lista_vertices_vazia(pt_vertices) == 1 || pt_vertices == NULL)
		return NULL;
		
	Vertice *vertice_ret = pt_vertices->tail->prox;
	
	while(vertice_ret != pt_vertices->head) {
		if(vertice_ret->id == id){
			vertice_ret->ant->prox = vertice_ret->prox;
			vertice_ret->prox->ant = vertice_ret->ant;
			vertice_ret->prox = NULL;
			vertice_ret->ant = NULL;
			break;
		}
		
		vertice_ret = vertice_ret->prox;
	}
	
	return vertice_ret;
}

int insere_adj_vertice(pt_lista_vertices pt_vertices, int vertice, int adj) {
	Vertice *aux = pt_vertices->tail->prox;
	
	while(aux != pt_vertices->head) {
		if(aux->id == vertice) {
			insere_adj(aux->adjs, aloca_nova_adj(adj));
			return 1;
		}
		
		aux = aux->prox;
	}
	
	return 0;
}

int preenche_lista_adj(pt_lista_vertices pt_vertices, FILE *arquivo, char *n_grafo){
	char linha[101];
	char *numero = (char *) malloc (100 * sizeof(char));
	int vertice, adj, i, k;
	
	if(numero == NULL)
		exit(EXIT_FAILURE);
	
	while((fgets(linha, sizeof(linha), arquivo)) != NULL){
		
		if(strcmp(linha, n_grafo) == 0) {
			fgets(linha, sizeof(linha), arquivo);
			
			while(1){
				if(strcmp(fgets(linha, sizeof(linha), arquivo), "$$\n") == 0)
					break;
					
				for(i = 0, k = 0; i < strlen(linha); i++){
					if(linha[i] == ':'){
						vertice = atoi(numero);
						insere_vertice(pt_vertices, aloca_novo_vertice(vertice));
						break;
					}
					if(linha[i] != ' '){
						numero[k] = linha[i];
						k++;
					}
				}
				
				i += 2;
				k = 0;
				numero[0] = '\0';
				
				
				while(linha[i] != ';'){
					if(linha[i] != ' '){
						numero[k] = linha[i];
						k++;
					}
					if((linha[i + 1] == ' ') || (linha[i + 1] == ';')){
						
						adj = atoi(numero);
						numero[0] = '\0';
						k = 0;
						
						insere_adj_vertice(pt_vertices, vertice, adj);
					} 
					
					i++;
				}
			}
			
			break;
		}
		
	}
	
	return 0;
}

void mostra_lista_grafo(pt_lista_vertices pt_vertices) {
	Vertice *aux = pt_vertices->head->ant;
	Adj *aux2;
	
	while(aux != pt_vertices->tail) {
		printf("%d -> ", aux->id);
		
		aux2 = aux->adjs->head->ant;
		
		while(aux2 != aux->adjs->tail){
			printf("%d ", aux2->id);
			
			aux2 = aux2->ant;
		}
		printf("\n");
		
		aux = aux->ant;
	}
	
}

char* retorna_adjs_vertice(pt_lista_vertices pt_vertices, int vertice) {
	Vertice *aux = pt_vertices->head->ant;
	Adj *aux2;
	int cont = 0;
	char *adjs = NULL;
	
	while(aux != pt_vertices->tail) {
		if(aux->id == vertice) {
			aux2 = aux->adjs->head->ant;
			
			while(aux2 != aux->adjs->tail) {
				
				aux2 = aux2->ant;
				cont++;
				
			}
			
			int *adjs = (int *) malloc (cont * sizeof(int));
			aux2 = aux->adjs->head->ant;
			cont = 0;
			
			while(aux2 != aux->adjs->tail) {
				
				adjs[cont] = aux2->id;
				cont++;
				aux2 = aux2->ant;
				
			}
			
		}
		
		aux = aux->ant;
	}
	
	return adjs;
}

pt_lista_vertices matriz_para_lista (char** mat_adj, int n_vertices){
	pt_lista_vertices pt_vertices = nova_lista_vertices();
	int i, j;
	
	for(i = 0; i < n_vertices; i++){
		
		insere_vertice(pt_vertices, aloca_novo_vertice(i));
		
		for(j = 0; j < n_vertices; j++)
			if((mat_adj[i][j] == 1) || (mat_adj[i][j] == -1))
				insere_adj_vertice(pt_vertices, i, j);
		
	}
	
	return pt_vertices;
}


/**************************Matrizes**************************/

char** cria_matriz (int n_vertices) {
	char* valores = (char *) malloc ((n_vertices * n_vertices) * sizeof(char));
	char** linhas = (char **) malloc (n_vertices * sizeof(char*));
	int i;
	
	if((valores == NULL) || (linhas == NULL))
		exit(EXIT_FAILURE);
	
	for(i = 0; i < n_vertices; i++)
		linhas[i] = valores + i*n_vertices;
	
	return linhas;
}

void limpa_memoria_matriz (char** mat_adj){
	free(*mat_adj);
	free(mat_adj);
}

char** preenche_mat_adj (FILE *arquivo, char *n_grafo, int *n_vertices){
	char linha[101];
	char *numero = (char *) malloc (100 * sizeof(char));
	char **mat_adj;
	int i, k = 0, vertices;
	
	if(numero == NULL)
		exit(EXIT_FAILURE);
	
	while((fgets(linha, sizeof(linha), arquivo)) != NULL){
		
		if(strstr(linha, n_grafo) != NULL) {
				
			i = strlen(linha);
			i -= 2;
			
			
			while(linha[i - 1] != ' ')
				i--;
			
			
			while(1){
				numero[k] = linha[i];
				
				if(linha[i + 1] == '.')
					break;
				
				i++;
				k++;
				
			}
			
			vertices = atoi(numero);
			*n_vertices = vertices;
			numero[0] = '\0';
			k = i = 0;
			
			mat_adj = cria_matriz(vertices);
			
			while(1){
				if(strcmp(fgets(linha, sizeof(linha), arquivo), "\n") == 0)
					break;
				
				while(linha[k] != '\n'){
					
					mat_adj[i][k] = linha[k] - 48;
					k++;
					
				}
				
				k = 0;
				i++;
			}
			
			break;
		}
		
	}
	
	return mat_adj;
}
 
char** lista_para_matriz (pt_lista_vertices pt_vertices, int n_vertices, char orientado) {
	char **mat_adj = cria_matriz(n_vertices);
	Vertice *aux = pt_vertices->head->ant;
	Adj *aux2;
	int i, j;
	
	for(i = 0; i < n_vertices; i++)
		for(j = 0; j < n_vertices; j++)
			mat_adj[i][j] = 0;
	
	while(aux != pt_vertices->tail) {
		
		aux2 = aux->adjs->head->ant;
		
		while(aux2 != aux->adjs->tail) {
			
			if((orientado == 1) && (mat_adj[aux2->id][aux->id] == 1))
				mat_adj[aux->id][aux2->id] = -1;
			else
				mat_adj[aux->id][aux2->id] = 1;
			
			aux2 = aux2->ant;
			
		}
			
		
		
		aux = aux->ant;
	}
	
	return mat_adj;
}

void gera_vet_matriz_triang_sup (char** mat_adj, int n_vertices, char *vet_triang_sup){
	int i, j, k = 0;
	
	if(vet_triang_sup == NULL)
		exit(EXIT_FAILURE);
	
	for(i = 0; i < n_vertices; i++)
		for(j = 0; j < n_vertices; j++) 
			if(i < j) {	
				vet_triang_sup[k] = mat_adj[i][j];
				k++;
			}
		
}

/*
 * The equations going from linear index to (i,j) index are:
 * i = n - 2 - floor(sqrt(-8*k + 4*n*(n-1)-7)/2.0 - 0.5)
 * j = k + i + 1 - n*(n-1)/2 + (n-i)*((n-i)-1)/2
 * 
 * The inverse operation, from (i,j) index to linear index is:
 * k = (n*(n-1)/2) - (n-i)*((n-i)-1)/2 + j - i - 1
 */

char** gera_matriz_completa (char* vet_triang_sup, int n_vertices, char orientado){
	char** mat_adj = cria_matriz(n_vertices);
	int i, j, k;
	
	for(i = 0; i < n_vertices; i++)
		for(j = 0; j < n_vertices; j++)
			mat_adj[i][j] = 0;
	
	for(k = 0; k < (((n_vertices * n_vertices) - n_vertices) / 2); k++){
		i = n_vertices - 2 - floor(sqrt(-8*k + 4*n_vertices*(n_vertices-1)-7)/2.0 - 0.5);
		j = k + i + 1 - n_vertices*(n_vertices-1)/2 + (n_vertices-i)*((n_vertices-i)-1)/2;
		
		mat_adj[i][j] = vet_triang_sup[k];
		
		if((mat_adj[i][j] == 1) || (mat_adj[i][j] == -1)) {
			if(orientado == 1)
				mat_adj[j][i] = mat_adj[i][j] * -1;
			else 
				mat_adj[j][i] = mat_adj[i][j];
			
		}
		
			
	}
	
	return mat_adj;
}

int n_arestas_matriz(char** mat_adj, int n_vertices, int orientado){
	int i, j, k = 0;
	
	for(i = 0; i < n_vertices; i++)
		for(j = 0; j < n_vertices; j++) {
			if(orientado == 1) {
				if((mat_adj[i][j] == 1) || (mat_adj[i][j] == -1))
					k++;
				
			} else {
				if(mat_adj[i][j] == 1)
					k++;
			}
		}
	
	return k / 2;
}


void converte_inteiro_base(int num, int *resultado, int base){
	int j = 0;
	
	while(num != 0){
		resultado[j] = num % base;
		num = num / base;
		j++;
	}
	
}

void gerar_orientacao(char** mat_adj, char** mat_adj_orientada, int n_vertices, int num_orientacao, int n_arestas){
	int i, j, cont = 0;
	int orientacao[n_arestas];
	
	for(i = 0; i < n_arestas; i++)
		orientacao[i] = 0;
	
	for(i = 0; i < n_vertices; i++)
		for(j = 0;j < n_vertices; j++)
			mat_adj_orientada[i][j] = 0;
	
	converte_inteiro_base(num_orientacao, orientacao, 2);
	
	for(i = 0; i < n_vertices; i++){
		for(j = i + 1; j < n_vertices; j++){
			if(mat_adj[i][j] != 0){
				if (orientacao[cont] == 0){
					mat_adj_orientada[i][j] = mat_adj[i][j];
					mat_adj_orientada[j][i] = -mat_adj[i][j];
				} else{
					mat_adj_orientada[i][j] = -mat_adj[i][j];
					mat_adj_orientada[j][i] = mat_adj[i][j];
				}
				cont++;
			}
		}
	}
}

int ver_colorcao (char *vet_triang_sup, int *combinacao, int n_vertices){
	int i, j, k, l, valida, p, m, tam;
	
	valida = 1;
	tam = (((n_vertices * n_vertices) - n_vertices) / 2);
	
	for(p = 0; p < tam; p++){
		if(vet_triang_sup[p] == 1){
			i = n_vertices - 2 - floor(sqrt(-8 * p + 4 * n_vertices * (n_vertices - 1) - 7) / 2.0 -0.5);
			j = p + i + 1 - n_vertices * (n_vertices - 1) / 2 + (n_vertices - i) * ((n_vertices - i) - 1) / 2;
			
			if(combinacao[i] == combinacao[j]){
				valida = 0;
				break;
			}
			
			for(m = 0; m < tam; m++){
				if(p != m){
					k = n_vertices - 2 - floor(sqrt(-8 * m + 4 * n_vertices * (n_vertices - 1) - 7) / 2.0 -0.5);
					l = m + k + 1 - n_vertices * (n_vertices - 1) / 2 + (n_vertices - k) * ((n_vertices - k) - 1) / 2;
					
					if(vet_triang_sup[m] == 1){
						if((combinacao[i] == combinacao[l]) && (combinacao[j] == combinacao[k])){
							valida = 0;
							break;
						}
					} else if(vet_triang_sup[m] == -1){
						if((combinacao[i] == combinacao[k]) && (combinacao[j] == combinacao[l])){
							valida = 0;
							break;
						}
					}
					
				}
				
				if(valida == 0)
					break;
			}
			
		} else if(vet_triang_sup[p] == -1){
			i = n_vertices - 2 - floor(sqrt(-8 * p + 4 * n_vertices * (n_vertices - 1) - 7) / 2.0 -0.5);
			j = p + i + 1 - n_vertices * (n_vertices - 1) / 2 + (n_vertices - i) * ((n_vertices - i) - 1) / 2;
			
			if(combinacao[i] == combinacao[j]){
				valida = 0;
				break;
			}
			
			for(m = 0; m < tam; m++){
				if(p != m){
					k = n_vertices - 2 - floor(sqrt(-8 * m + 4 * n_vertices * (n_vertices - 1) - 7) / 2.0 -0.5);
					l = m + k + 1 - n_vertices * (n_vertices - 1) / 2 + (n_vertices - k) * ((n_vertices - k) - 1) / 2;
					
					if(vet_triang_sup[m] == 1){
						if((combinacao[j] == combinacao[l]) && (combinacao[i] == combinacao[k])){
							valida = 0;
							break;
						}
					} else if(vet_triang_sup[m] == -1){
						if((combinacao[j] == combinacao[k]) && (combinacao[i] == combinacao[l])){
							valida = 0;
							break;
						}
					}
					
				}
				
				if(valida == 0)
					break;
			}
		}
		
		if(valida == 0)
			break;
		
	}
				
	/*for(i = 0; i < n_vertices; i++){
		for(j = 0; j < n_vertices; j++){
			if(mat_adj[i][j] == 1){
				if(combinacao[i] == combinacao[j]){
					valida = 0;
					break;
				}
				
				for(k = 0; k < n_vertices; k++){
					for(l = 0; l < n_vertices; l++){
						if(mat_adj[i][j] == 1){
							if((k != i) && (l != j)){
								if(mat_adj[k][l] == 1){
									if((combinacao[i] == combinacao[l]) && (combinacao[j] == combinacao[k])){
										valida = 0;
										break;
									}
								} 
							}
						}  
					}
					
					if(valida == 0)
						break;
				}
				
			}
		}
		
		if(valida == 0)
			break;
	} */
	
	return valida;

}
