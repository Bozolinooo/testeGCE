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
	
	int l, i, j, k, n_vertices, n_grafos, n_arestas, n_totalO, size, sim;
	int tipo1, tipoMenos1, tipo3, tipoMenos3, t1, t2, t3, t4, cont, cont2, p, r, s, primeiro_grafo;
	string name;
	
	char **mat_adj;
	char **mat_adj_orientada;
	char **mat_adj_orientada2;
	vector<int> livres_isomorfismo;
	int *tipo1G;
	int *tipoMenos1G;
	int *tipo3G;
	int *tipoMenos3G;
	int *v1;
	int *v2;
	int *v3;
	int *v4;
	
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
		printf("Grafo %d\n", primeiro_grafo + l);
		fflush(stdout);
		
		for(i = 0; i < n_vertices; i++)
			for(j = 0; j < n_vertices; j++)
				mat_adj[i][j] = entrada[l][i][j];
		
		//~ n_arestas = n_arestas_matriz(mat_adj, n_vertices, 0);
		n_totalO = pow(2, n_arestas);
		
		livres_isomorfismo.clear();
		livres_isomorfismo.push_back(0);
		
		printf("0\n");
		fflush(stdout);
		
		for(i = 1; i < n_totalO; i++){
			gerar_orientacao(mat_adj, mat_adj_orientada, n_vertices, i, n_arestas);
			
			size = livres_isomorfismo.size();
			sim = -1;
			
			for(p = 0; p < size; p++){
				gerar_orientacao(mat_adj, mat_adj_orientada2, n_vertices, livres_isomorfismo[p], n_arestas);
				
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
					
					for(r = 0; r < n_vertices; r++)
						permutacao[r] = 0;
					
					if(t1 == 0){
						
						tipoMenos1G = (int *) malloc (tipoMenos1 * sizeof(int));
						tipo3G = (int *) malloc (tipo3 * sizeof(int));
						tipoMenos3G = (int *) malloc (tipoMenos3 * sizeof(int));
						v2 = (int *) malloc (tipoMenos1 * sizeof(int));
						v3 = (int *) malloc (tipo3 * sizeof(int));
						v4 = (int *) malloc (tipoMenos3 * sizeof(int));
						
						tipoMenos1 = tipo3 = tipoMenos3 = 0;
						
						for(r = 0; r < n_vertices; r++){
							cont = 0;
							
							for(s = 0; s < n_vertices; s++){
								cont += mat_adj_orientada2[r][s];
							}
							
							if(cont == -1){
								
								v2[tipoMenos1] = r;
								tipoMenos1++;
								
							} else if(cont == 3){
								
								v3[tipo3] = r;
								tipo3++;
								
							} else if(cont == -3){
								
								v4[tipoMenos3] = r;
								tipoMenos3++;
								
							}					
						}
						
						
							
						for(r = 0; r < tipoMenos1; r++)
							tipoMenos1G[r] = r;
							
						do{
							
							for(r = 0; r < tipo3; r++)
								tipo3G[r] = r;
							
							do{
								
								for(r = 0; r < tipoMenos3; r++)
									tipoMenos3G[r] = r;
								
								do{
									
									for(r = 0; r < tipoMenos1; r++)
										permutacao[v2[r]] = v2[tipoMenos1G[r]];
										
									for(r = 0; r < tipo3; r++)
										permutacao[v3[r]] = v3[tipo3G[r]];
									
									for(r = 0; r < tipoMenos3; r++)
										permutacao[v4[r]] = v4[tipoMenos3G[r]];
										
									sim = ver_isomorfismo(n_vertices, mat_adj_orientada, mat_adj_orientada2, permutacao);
						
									if(sim == 1)
										break;
									
								} while(next_permutation(tipoMenos3G, tipoMenos3G + tipoMenos3));
								
								if(sim == 1)
									break;
								
							} while(next_permutation(tipo3G, tipo3G + tipo3));
							
							if(sim == 1)
								break;
							
						} while(next_permutation(tipoMenos1G, tipoMenos1G + tipoMenos1));
							
						free(tipoMenos1G);
						free(tipo3G);
						free(tipoMenos3G);
						free(v2);
						free(v3);
						free(v4);
						
					} else if(t2 == 0){
						
						tipo1G = (int *) malloc (tipo1 * sizeof(int));
						tipo3G = (int *) malloc (tipo3 * sizeof(int));
						tipoMenos3G = (int *) malloc (tipoMenos3 * sizeof(int));
						v1 = (int *) malloc (tipo1 * sizeof(int));
						v3 = (int *) malloc (tipo3 * sizeof(int));
						v4 = (int *) malloc (tipoMenos3 * sizeof(int));
						
						tipo1 = tipo3 = tipoMenos3 = 0;
						
						for(r = 0; r < n_vertices; r++){
							cont = 0;
							
							for(s = 0; s < n_vertices; s++){
								cont += mat_adj_orientada2[r][s];
							}
							
							if(cont == 1){
								
								v1[tipo1] = r;
								tipo1++;
								
							} else if(cont == 3){
								
								v3[tipo3] = r;
								tipo3++;
								
							} else if(cont == -3){
								
								v4[tipoMenos3] = r;
								tipoMenos3++;
								
							}					
						}
						
						for(r = 0; r < tipo1; r++)
							tipo1G[r] = r;
						
						do{

							for(r = 0; r < tipo3; r++)
								tipo3G[r] = r;
							
							do{
								
								for(r = 0; r < tipoMenos3; r++)
									tipoMenos3G[r] = r;
								
								do{
									
									for(r = 0; r < tipo1; r++)
										permutacao[v1[r]] = v1[tipo1G[r]];
										
									for(r = 0; r < tipo3; r++)
										permutacao[v3[r]] = v3[tipo3G[r]];
									
									for(r = 0; r < tipoMenos3; r++)
										permutacao[v4[r]] = v4[tipoMenos3G[r]];
										
									sim = ver_isomorfismo(n_vertices, mat_adj_orientada, mat_adj_orientada2, permutacao);
						
									if(sim == 1)
										break;
									
								} while(next_permutation(tipoMenos3G, tipoMenos3G + tipoMenos3));
								
								if(sim == 1)
									break;
								
							} while(next_permutation(tipo3G, tipo3G + tipo3));
							
							if(sim == 1)
								break;
							
						} while(next_permutation(tipo1G, tipo1G + tipo1));
						
						free(tipo1G);
						free(tipo3G);
						free(tipoMenos3G);
						free(v1);
						free(v3);
						free(v4);
						
					} else if(t3 == 0){
						
						tipo1G = (int *) malloc (tipo1 * sizeof(int));
						tipoMenos1G = (int *) malloc (tipoMenos1 * sizeof(int));
						tipoMenos3G = (int *) malloc (tipoMenos3 * sizeof(int));
						v1 = (int *) malloc (tipo1 * sizeof(int));
						v2 = (int *) malloc (tipoMenos1 * sizeof(int));
						v4 = (int *) malloc (tipoMenos3 * sizeof(int));
						
						tipo1 = tipoMenos1 = tipoMenos3 = 0;
						
						for(r = 0; r < n_vertices; r++){
							cont = 0;
							
							for(s = 0; s < n_vertices; s++){
								cont += mat_adj_orientada2[r][s];
							}
							
							if(cont == 1){
								
								v1[tipo1] = r;
								tipo1++;
								
							} else if(cont == -1){
								
								v2[tipoMenos1] = r;
								tipoMenos1++;
								
							} else if(cont == -3){
								
								v4[tipoMenos3] = r;
								tipoMenos3++;
								
							}					
						}
						
						for(r = 0; r < tipo1; r++)
							tipo1G[r] = r;
						
						do{
							
							for(r = 0; r < tipoMenos1; r++)
								tipoMenos1G[r] = r;
								
							do{
													
								for(r = 0; r < tipoMenos3; r++)
									tipoMenos3G[r] = r;
								
								do{
									
									for(r = 0; r < tipo1; r++)
										permutacao[v1[r]] = v1[tipo1G[r]];
									
									for(r = 0; r < tipoMenos1; r++)
										permutacao[v2[r]] = v2[tipoMenos1G[r]];
									
									for(r = 0; r < tipoMenos3; r++)
										permutacao[v4[r]] = v4[tipoMenos3G[r]];
										
									sim = ver_isomorfismo(n_vertices, mat_adj_orientada, mat_adj_orientada2, permutacao);
						
									if(sim == 1)
										break;
									
								} while(next_permutation(tipoMenos3G, tipoMenos3G + tipoMenos3));
								
								if(sim == 1)
									break;
								
							} while(next_permutation(tipoMenos1G, tipoMenos1G + tipoMenos1));
							
							if(sim == 1)
								break;
							
						} while(next_permutation(tipo1G, tipo1G + tipo1));
						
						free(tipo1G);
						free(tipoMenos1G);
						free(tipoMenos3G);
						free(v1);
						free(v2);
						free(v4);
						
					} else if(t4 == 0){
						
						tipo1G = (int *) malloc (tipo1 * sizeof(int));
						tipoMenos1G = (int *) malloc (tipoMenos1 * sizeof(int));
						tipo3G = (int *) malloc (tipo3 * sizeof(int));
						v1 = (int *) malloc (tipo1 * sizeof(int));
						v2 = (int *) malloc (tipoMenos1 * sizeof(int));
						v3 = (int *) malloc (tipo3 * sizeof(int));
						
						tipo1 = tipoMenos1 = tipo3 = 0;
						
						for(r = 0; r < n_vertices; r++){
							cont = 0;
							
							for(s = 0; s < n_vertices; s++){
								cont += mat_adj_orientada2[r][s];
							}
							
							if(cont == 1){
								
								v1[tipo1] = r;
								tipo1++;
								
							} else if(cont == -1){
								
								v2[tipoMenos1] = r;
								tipoMenos1++;
								
							} else if(cont == 3){
								
								v3[tipo3] = r;
								tipo3++;
								
							}					
						}
						
						for(r = 0; r < tipo1; r++)
							tipo1G[r] = r;
						
						do{
							
							for(r = 0; r < tipoMenos1; r++)
								tipoMenos1G[r] = r;
								
							do{
								
								for(r = 0; r < tipo3; r++)
									tipo3G[r] = r;
								
								do{

										
									for(r = 0; r < tipo1; r++)
										permutacao[v1[r]] = v1[tipo1G[r]];
									
									for(r = 0; r < tipoMenos1; r++)
										permutacao[v2[r]] = v2[tipoMenos1G[r]];
										
									for(r = 0; r < tipo3; r++)
										permutacao[v3[r]] = v3[tipo3G[r]];
										
									sim = ver_isomorfismo(n_vertices, mat_adj_orientada, mat_adj_orientada2, permutacao);
						
									if(sim == 1)
										break;									
									
								} while(next_permutation(tipo3G, tipo3G + tipo3));
								
								if(sim == 1)
									break;
								
							} while(next_permutation(tipoMenos1G, tipoMenos1G + tipoMenos1));
							
							if(sim == 1)
								break;
							
						} while(next_permutation(tipo1G, tipo1G + tipo1));
						
						free(tipo1G);
						free(tipoMenos1G);
						free(tipo3G);
						free(v1);
						free(v2);
						free(v3);
						
					} else if(t1 == 0 && t2 == 0){
						
						tipo3G = (int *) malloc (tipo3 * sizeof(int));
						tipoMenos3G = (int *) malloc (tipoMenos3 * sizeof(int));
						v3 = (int *) malloc (tipo3 * sizeof(int));
						v4 = (int *) malloc (tipoMenos3 * sizeof(int));
						
						tipo3 = tipoMenos3 = 0;
						
						for(r = 0; r < n_vertices; r++){
							cont = 0;
							
							for(s = 0; s < n_vertices; s++){
								cont += mat_adj_orientada2[r][s];
							}
							
							if(cont == 3){
								
								v3[tipo3] = r;
								tipo3++;
								
							} else if(cont == -3){
								
								v4[tipoMenos3] = r;
								tipoMenos3++;
								
							}					
						}

						for(r = 0; r < tipo3; r++)
							tipo3G[r] = r;
						
						do{
							
							for(r = 0; r < tipoMenos3; r++)
								tipoMenos3G[r] = r;
							
							do{
									
								for(r = 0; r < tipo3; r++)
									permutacao[v3[r]] = v3[tipo3G[r]];
								
								for(r = 0; r < tipoMenos3; r++)
									permutacao[v4[r]] = v4[tipoMenos3G[r]];
									
								sim = ver_isomorfismo(n_vertices, mat_adj_orientada, mat_adj_orientada2, permutacao);
					
								if(sim == 1)
									break;
								
							} while(next_permutation(tipoMenos3G, tipoMenos3G + tipoMenos3));
							
							if(sim == 1)
								break;
							
						} while(next_permutation(tipo3G, tipo3G + tipo3));
						
						free(tipo3G);
						free(tipoMenos3G);
						free(v3);
						free(v4);
						
					} else if(t1 == 0 && t3 == 0){
						
						tipoMenos1G = (int *) malloc (tipoMenos1 * sizeof(int));
						tipoMenos3G = (int *) malloc (tipoMenos3 * sizeof(int));
						v2 = (int *) malloc (tipoMenos1 * sizeof(int));
						v4 = (int *) malloc (tipoMenos3 * sizeof(int));
						
						tipoMenos1 = tipoMenos3 = 0;
						
						for(r = 0; r < n_vertices; r++){
							cont = 0;
							
							for(s = 0; s < n_vertices; s++){
								cont += mat_adj_orientada2[r][s];
							}
							
							if(cont == -1){
								
								v2[tipoMenos1] = r;
								tipoMenos1++;
								
							} else if(cont == -3){
								
								v4[tipoMenos3] = r;
								tipoMenos3++;
								
							}					
						}
						

						for(r = 0; r < tipoMenos1; r++)
							tipoMenos1G[r] = r;
							
						do{
							
								
							for(r = 0; r < tipoMenos3; r++)
								tipoMenos3G[r] = r;
							
							do{
								
								for(r = 0; r < tipoMenos1; r++)
									permutacao[v2[r]] = v2[tipoMenos1G[r]];									
								
								for(r = 0; r < tipoMenos3; r++)
									permutacao[v4[r]] = v4[tipoMenos3G[r]];
									
								sim = ver_isomorfismo(n_vertices, mat_adj_orientada, mat_adj_orientada2, permutacao);
					
								if(sim == 1)
									break;
								
							} while(next_permutation(tipoMenos3G, tipoMenos3G + tipoMenos3));
							
							if(sim == 1)
								break;
							
						} while(next_permutation(tipoMenos1G, tipoMenos1G + tipoMenos1));

						
						free(tipoMenos1G);
						free(tipoMenos3G);
						free(v2);
						free(v4);
						
					} else if(t1 == 0 && t4 == 0){
						
						tipoMenos1G = (int *) malloc (tipoMenos1 * sizeof(int));
						tipo3G = (int *) malloc (tipo3 * sizeof(int));
						v2 = (int *) malloc (tipoMenos1 * sizeof(int));
						v3 = (int *) malloc (tipo3 * sizeof(int));
						
						tipoMenos1 = tipo3 = 0;
						
						for(r = 0; r < n_vertices; r++){
							cont = 0;
							
							for(s = 0; s < n_vertices; s++){
								cont += mat_adj_orientada2[r][s];
							}
							
							if(cont == -1){
								
								v2[tipoMenos1] = r;
								tipoMenos1++;
								
							} else if(cont == 3){
								
								v3[tipo3] = r;
								tipo3++;
								
							}				
						}
						
							
						for(r = 0; r < tipoMenos1; r++)
							tipoMenos1G[r] = r;
							
						do{
							
							for(r = 0; r < tipo3; r++)
								tipo3G[r] = r;
							
							do{

								for(r = 0; r < tipoMenos1; r++)
									permutacao[v2[r]] = v2[tipoMenos1G[r]];
									
								for(r = 0; r < tipo3; r++)
									permutacao[v3[r]] = v3[tipo3G[r]];
																		
								sim = ver_isomorfismo(n_vertices, mat_adj_orientada, mat_adj_orientada2, permutacao);
						
								if(sim == 1)
									break;
								
							} while(next_permutation(tipo3G, tipo3G + tipo3));
							
							if(sim == 1)
								break;
							
						} while(next_permutation(tipoMenos1G, tipoMenos1G + tipoMenos1));

						
						free(tipoMenos1G);
						free(tipo3G);
						free(v2);
						free(v3);
						
					} else if(t2 == 0 && t3 == 0){
						
						tipo1G = (int *) malloc (tipo1 * sizeof(int));
						tipoMenos3G = (int *) malloc (tipoMenos3 * sizeof(int));
						v1 = (int *) malloc (tipo1 * sizeof(int));
						v4 = (int *) malloc (tipoMenos3 * sizeof(int));
						
						tipo1 = tipoMenos3 = 0;
						
						for(r = 0; r < n_vertices; r++){
							cont = 0;
							
							for(s = 0; s < n_vertices; s++){
								cont += mat_adj_orientada2[r][s];
							}
							
							if(cont == 1){
								
								v1[tipo1] = r;
								tipo1++;
								
							} else if(cont == -3){
								
								v4[tipoMenos3] = r;
								tipoMenos3++;
								
							}					
						}
						
						for(r = 0; r < tipo1; r++)
							tipo1G[r] = r;
						
						do{
	
							for(r = 0; r < tipoMenos3; r++)
								tipoMenos3G[r] = r;
							
							do{
								
								for(r = 0; r < tipo1; r++)
									permutacao[v1[r]] = v1[tipo1G[r]];
								
								for(r = 0; r < tipoMenos3; r++)
									permutacao[v4[r]] = v4[tipoMenos3G[r]];
									
								sim = ver_isomorfismo(n_vertices, mat_adj_orientada, mat_adj_orientada2, permutacao);
					
								if(sim == 1)
									break;
								
							} while(next_permutation(tipoMenos3G, tipoMenos3G + tipoMenos3));
							
							if(sim == 1)
								break;
							
						} while(next_permutation(tipo1G, tipo1G + tipo1));
						
						free(tipo1G);
						free(tipoMenos3G);
						free(v1);
						free(v4);
						
					} else if(t2 == 0 && t4 == 0){
						
						tipo1G = (int *) malloc (tipo1 * sizeof(int));
						tipo3G = (int *) malloc (tipo3 * sizeof(int));
						v1 = (int *) malloc (tipo1 * sizeof(int));
						v3 = (int *) malloc (tipo3 * sizeof(int));
						
						tipo1 = tipo3 = 0;
						
						for(r = 0; r < n_vertices; r++){
							cont = 0;
							
							for(s = 0; s < n_vertices; s++){
								cont += mat_adj_orientada2[r][s];
							}
							
							if(cont == 1){
								
								v1[tipo1] = r;
								tipo1++;
								
							} else if(cont == 3){
								
								v3[tipo3] = r;
								tipo3++;
								
							}					
						}
						
						for(r = 0; r < tipo1; r++)
							tipo1G[r] = r;
						
						do{
								
							for(r = 0; r < tipo3; r++)
								tipo3G[r] = r;
							
							do{

								for(r = 0; r < tipo1; r++)
									permutacao[v1[r]] = v1[tipo1G[r]];

									
								for(r = 0; r < tipo3; r++)
									permutacao[v3[r]] = v3[tipo3G[r]];
									
								sim = ver_isomorfismo(n_vertices, mat_adj_orientada, mat_adj_orientada2, permutacao);
					
								if(sim == 1)
									break;
								
							} while(next_permutation(tipo3G, tipo3G + tipo3));
							
							if(sim == 1)
								break;
							
						} while(next_permutation(tipo1G, tipo1G + tipo1));
						
						free(tipo1G);
						free(tipo3G);
						free(v1);
						free(v3);
						
					} else if(t3 == 0 && t4 == 0){
						
						tipo1G = (int *) malloc (tipo1 * sizeof(int));
						tipoMenos1G = (int *) malloc (tipoMenos1 * sizeof(int));
						v1 = (int *) malloc (tipo1 * sizeof(int));
						v2 = (int *) malloc (tipoMenos1 * sizeof(int));
						
						tipo1 = tipoMenos1 = 0;
						
						for(r = 0; r < n_vertices; r++){
							cont = 0;
							
							for(s = 0; s < n_vertices; s++){
								cont += mat_adj_orientada2[r][s];
							}
							
							if(cont == 1){
								
								v1[tipo1] = r;
								tipo1++;
								
							} else if(cont == -1){
								
								v2[tipoMenos1] = r;
								tipoMenos1++;
								
							}					
						}
						
						for(r = 0; r < tipo1; r++)
							tipo1G[r] = r;
						
						do{
							
							for(r = 0; r < tipoMenos1; r++)
								tipoMenos1G[r] = r;
								
							do{						
										
								for(r = 0; r < tipo1; r++)
									permutacao[v1[r]] = v1[tipo1G[r]];
								
								for(r = 0; r < tipoMenos1; r++)
									permutacao[v2[r]] = v2[tipoMenos1G[r]];
									
								sim = ver_isomorfismo(n_vertices, mat_adj_orientada, mat_adj_orientada2, permutacao);
					
								if(sim == 1)
									break;	
								
							} while(next_permutation(tipoMenos1G, tipoMenos1G + tipoMenos1));
							
							if(sim == 1)
								break;
							
						} while(next_permutation(tipo1G, tipo1G + tipo1));
						
						free(tipo1G);
						free(tipoMenos1G);
						free(v1);
						free(v2);
						
					} else {
						
						tipo1G = (int *) malloc (tipo1 * sizeof(int));
						tipoMenos1G = (int *) malloc (tipoMenos1 * sizeof(int));
						tipo3G = (int *) malloc (tipo3 * sizeof(int));
						tipoMenos3G = (int *) malloc (tipoMenos3 * sizeof(int));
						v1 = (int *) malloc (tipo1 * sizeof(int));
						v2 = (int *) malloc (tipoMenos1 * sizeof(int));
						v3 = (int *) malloc (tipo3 * sizeof(int));
						v4 = (int *) malloc (tipoMenos3 * sizeof(int));
						
						tipo1 = tipoMenos1 = tipo3 = tipoMenos3 = 0;
						
						for(r = 0; r < n_vertices; r++){
							cont = 0;
							
							for(s = 0; s < n_vertices; s++){
								cont += mat_adj_orientada2[r][s];
							}
							
							if(cont == 1){
								
								v1[tipo1] = r;
								tipo1++;
								
							} else if(cont == -1){
								
								v2[tipoMenos1] = r;
								tipoMenos1++;
								
							} else if(cont == 3){
								
								v3[tipo3] = r;
								tipo3++;
								
							} else if(cont == -3){
								
								v4[tipoMenos3] = r;
								tipoMenos3++;
								
							}					
						}
						
						for(r = 0; r < tipo1; r++)
							tipo1G[r] = r;
						
						do{
							
							for(r = 0; r < tipoMenos1; r++)
								tipoMenos1G[r] = r;
								
							do{
								
								for(r = 0; r < tipo3; r++)
									tipo3G[r] = r;
								
								do{
									
									for(r = 0; r < tipoMenos3; r++)
										tipoMenos3G[r] = r;
									
									do{
										
										for(r = 0; r < tipo1; r++)
											permutacao[v1[r]] = v1[tipo1G[r]];
										
										for(r = 0; r < tipoMenos1; r++)
											permutacao[v2[r]] = v2[tipoMenos1G[r]];
											
										for(r = 0; r < tipo3; r++)
											permutacao[v3[r]] = v3[tipo3G[r]];
										
										for(r = 0; r < tipoMenos3; r++)
											permutacao[v4[r]] = v4[tipoMenos3G[r]];
											
										sim = ver_isomorfismo(n_vertices, mat_adj_orientada, mat_adj_orientada2, permutacao);
							
										if(sim == 1)
											break;
										
									} while(next_permutation(tipoMenos3G, tipoMenos3G + tipoMenos3));
									
									if(sim == 1)
										break;
									
								} while(next_permutation(tipo3G, tipo3G + tipo3));
								
								if(sim == 1)
									break;
								
							} while(next_permutation(tipoMenos1G, tipoMenos1G + tipoMenos1));
							
							if(sim == 1)
								break;
							
						} while(next_permutation(tipo1G, tipo1G + tipo1));
						
						free(tipo1G);
						free(tipoMenos1G);
						free(tipo3G);
						free(tipoMenos3G);
						free(v1);
						free(v2);
						free(v3);
						free(v4);
					}
					
				} else {
					sim = 0;
				}	
				
				if(sim == 1)
					break;
			}
			
			if(sim == 0) {
				printf("%d\n", i);
				fflush(stdout);
				livres_isomorfismo.push_back(i);
			}
			
		}
		
		//~ size = livres_isomorfismo.size();
		
		//~ for(i = 0; i < size; i++){
			//~ printf("%d\n", livres_isomorfismo[i]);
			//~ fflush(stdout);
		//~ }
		
	}
	
	free(permutacao);
	limpa_memoria_matriz(mat_adj);
	limpa_memoria_matriz(mat_adj_orientada);
	
	return 0;
}
