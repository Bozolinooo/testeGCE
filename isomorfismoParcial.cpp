#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <cmath>

using namespace std;

void converte_inteiro_base(long int num, int *resultado, int base){
	int j = 0;
	
	while(num != 0){
		resultado[j] = num % base;
		num = num / base;
		j++;
	}
	
}

void gerar_orientacao(char** mat_adj, char** mat_adj_orientada, int n_vertices, long int num_orientacao, int n_arestas){
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

void limpa_memoria_matriz (char** mat_adj){
	free(*mat_adj);
	free(mat_adj);
}

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

int ver_isomorfismo(int n_vertices, char **mat_adj_orientada, char **mat_adj_orientada2, int *permutacao){
	int i, j;
	
	for(i = 0; i < n_vertices; i++)
		for(j = 0; j < n_vertices; j++)
			if(mat_adj_orientada[i][j] != mat_adj_orientada2[permutacao[i]][permutacao[j]])
				return 0;
	
	return 1;
}

int main(int argc, char *argv[]) {
	
	int l, i, j, k, n_vertices, n_grafos, n_arestas, sim;
	int tipo1, tipoMenos1, tipo3, tipoMenos3, t1, t2, t3, t4, cont, cont2, r, s, primeiro_grafo;
	long int p1, p2, n_totalO, size;
	string name;
	
	char **mat_adj;
	char **mat_adj_orientada;
	char **mat_adj_orientada2;
	vector<long int> livres_isomorfismo;
	
	sscanf(argv[1], "%d", &n_vertices);
	sscanf(argv[2], "%d", &n_grafos);
	sscanf(argv[3], "%d", &primeiro_grafo);
	sscanf(argv[4], "%d", &n_arestas);
	
	char entrada[n_grafos][n_vertices][n_vertices];
	int *permutacao = (int *) malloc (n_vertices * sizeof(int));
	
	mat_adj = cria_matriz(n_vertices);
	mat_adj_orientada = cria_matriz(n_vertices);
	mat_adj_orientada2 = cria_matriz(n_vertices);
	
	for(l = 0; l < n_grafos; l++){
	
		getline(cin, name);
		getline(cin, name);
		
		for(i = 0; i < n_vertices; i++) {
			for(j = 0; j < n_vertices; j++) {
				cin >> k;
				
				entrada[l][i][j] = k;
			}
		}
		
		getline(cin, name);
	}
	
	for(l = 0; l < n_grafos; l++){
		printf("%d\n", primeiro_grafo + l);
		fflush(stdout);
		
		for(i = 0; i < n_vertices; i++)
			for(j = 0; j < n_vertices; j++)
				mat_adj[i][j] = entrada[l][i][j];
		
		//~ n_arestas = n_arestas_matriz(mat_adj, n_vertices, 0);
		n_totalO = pow(2, n_arestas);
		
		livres_isomorfismo.clear();
		livres_isomorfismo.push_back(0);
		
		//~ printf("0\n");
		//~ fflush(stdout);
		
		for(p1 = 1; p1 < n_totalO; p1++){
			gerar_orientacao(mat_adj, mat_adj_orientada, n_vertices, p1, n_arestas);
			
			size = livres_isomorfismo.size();
			sim = -1;
			
			for(p2 = 0; p2 < size; p2++){
				gerar_orientacao(mat_adj, mat_adj_orientada2, n_vertices, livres_isomorfismo[p2], n_arestas);
				
				tipo1 = tipoMenos1 = tipo3 = tipoMenos3 = 0;
				t1 = t2 = t3 = t4 = 0;
				
				for(r = 0; r < n_vertices; r++){
					cont = cont2 = 0;
					
					for(s = 0; s < n_vertices; s++){
						cont += mat_adj_orientada2[r][s];
						cont2 += mat_adj_orientada[r][s];
					}
					
					if(cont == 1){
						tipo1++;
					} else if(cont == -1){
						tipoMenos1++;
					} else if(cont == 3){
						tipo3++;
					} else if(cont == -3){
						tipoMenos3++;
					}
					
					if(cont2 == 1){
						t1++;
					} else if(cont2 == -1){
						t2++;
					} else if(cont2 == 3){
						t3++;
					} else if(cont2 == -3){
						t4++;
					}
					
				}
				
				if((t1 == tipo1) && (t2 == tipoMenos1) && (t3 == tipo3) && (t4 == tipoMenos3)){
					
					sim = 1;
					
				} else {
					sim = 0;
				}	
				
				if(sim == 1)
					break;
			}
			
			if(sim == 0) {
				livres_isomorfismo.push_back(p1);
			}
			
		}
		
		size = livres_isomorfismo.size();
		
		printf("%ld ", size);
		
		for(i = 0; i < size; i++){
			printf("%ld ", livres_isomorfismo[i]);
			fflush(stdout);
		}
		printf("\n");
	}
	
	free(permutacao);
	limpa_memoria_matriz(mat_adj);
	limpa_memoria_matriz(mat_adj_orientada);
	
	return 0;
}

