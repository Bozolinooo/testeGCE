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
#include <stack>
#include <time.h>
#include <bits/stdc++.h>

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

int bfsVertice(char **mat_adj, int* ordem, int* visitado, int n_vertices, long int v, int k){
	int i, j;
	stack<int> pilha;
	
	visitado[v] = 1;
	ordem[k++] = v;
	pilha.push(v);
	
    while(!pilha.empty()){
		i = pilha.top();
		pilha.pop();
		
		for(j = 0; j < n_vertices; j++){
			if(mat_adj[i][j] == 1){
				if(visitado[j] == 0){
					visitado[j] = 1;
					ordem[k++] = j;
					pilha.push(j);
				}
			}
		}
	}
	
	return k;
}

void bfs(char **mat_adj, int *ordem, int n_vertices, long int inicio){
	int i, k = 0;
	int *visitado = (int *) malloc (n_vertices * sizeof(int));

	for(i = 0; i < n_vertices; i++){
		visitado[i] = 0;
	}
	
	
	k = bfsVertice(mat_adj, ordem, visitado, n_vertices, inicio, k);
	
	for(i = 0; i < n_vertices; i++){
		if(visitado[i] == 0){
			k = bfsVertice(mat_adj, ordem, visitado, n_vertices, i, k);
		}
	}
	
	free(visitado);
}

int ver_isomorfismo(int n_vertices, char **mat_adj_orientada, char **mat_adj_orientada2, int *permutacao){
	int i, j;
	
	for(i = 0; i < n_vertices; i++)
		for(j = 0; j < n_vertices; j++)
			if(mat_adj_orientada[i][j] != mat_adj_orientada2[permutacao[i]][permutacao[j]])
				return 0;
	
	return 1;
}

long int inteiro_orientacao(char **mat_adj, char **mat_adj_orientada, int n_vertices, int n_arestas){
	long int saida = 0;
	int orientacao[n_arestas], i, j, cont = 0;
	
	for(i = 0; i < n_vertices; i++){
		for(j = i + 1; j < n_vertices; j++){
			if(mat_adj[i][j] != 0){
				if(mat_adj_orientada[i][j] == mat_adj[i][j] || mat_adj_orientada[j][i] == -mat_adj[i][j]){
					orientacao[cont] = 0;
				} else{
					orientacao[cont] = 1;
				}
				cont++;
			}
		}
	}
	
	for(i = 0; i < n_arestas; i++)
		saida += orientacao[i] * pow(2, i);
	
	return saida;
}

void orientacao_app(char **mat_adj, char **mat_adj_orientada, int *ordem, int n_vertices, int tipo){
	int i, j;
	int adj1[3], adjMenos1[3], adj3[3], adjMenos3[3], k, cont, dado, cont2;
	vector< pair <int, char>> adjs(3);
	
	for(i = 0; i < n_vertices; i++)
		for(j = 0; j < n_vertices; j++)
			mat_adj_orientada[i][j] = 0;
	
	adj1[0] = 1;
	adj1[1] = 1;
	adj1[2] = -1;
	
	adjMenos1[0] = 1;
	adjMenos1[1] = -1;
	adjMenos1[2] = -1;
	
	adj3[0] = 1;
	adj3[1] = 1;
	adj3[2] = 1;
	
	adjMenos3[0] = -1;
	adjMenos3[1] = -1;
	adjMenos3[2] = -1;

	k = 0;
	for(j = 0; j < n_vertices; j++){
		if(mat_adj[ordem[0]][j] == 1){
			
			if(tipo == 1){
				mat_adj_orientada[ordem[0]][j] = adj1[k];
				mat_adj_orientada[j][ordem[0]] = -adj1[k++];
			} else if(tipo == -1){
				mat_adj_orientada[ordem[0]][j] = adjMenos1[k];
				mat_adj_orientada[j][ordem[0]] = -adjMenos1[k++];
			} else if(tipo == 3){
				mat_adj_orientada[ordem[0]][j] = adj3[k];
				mat_adj_orientada[j][ordem[0]] = -adj3[k++];
			} else if(tipo == -3){
				mat_adj_orientada[ordem[0]][j] = adjMenos3[k];
				mat_adj_orientada[j][ordem[0]] = -adjMenos3[k++];
			}
			
		}
	}
	
	for(i = 1; i < n_vertices; i++){
		cont = k = cont2 = 0;
		adjs.clear();
		
		for(j = 0; j < n_vertices; j++) {
			if(mat_adj_orientada[ordem[i]][j] == 1 || mat_adj_orientada[ordem[i]][j] == -1){
				adjs[k].first = j;
				adjs[k].second = mat_adj_orientada[ordem[i]][j];
				k++;
				cont2++;
			}
				
			
			cont += mat_adj_orientada[ordem[i]][j];
		}
		
		if(cont2 == 1 && cont == 1){
			dado = rand() % 3 + 1;
			k = 1;
			
			if(dado == 1){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first){
						mat_adj_orientada[ordem[i]][j] = adj1[k];
						mat_adj_orientada[j][ordem[i]] = -adj1[k];
						k++;
					}
				}
				
			} else if(dado == 2){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first){
						mat_adj_orientada[ordem[i]][j] = adjMenos1[k];
						mat_adj_orientada[j][ordem[i]] = -adjMenos1[k];
						k++;
					}
				}
				
			} else if(dado == 3){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first){
						mat_adj_orientada[ordem[i]][j] = adj3[k];
						mat_adj_orientada[j][ordem[i]] = -adj3[k];
						k++;
					}
				}
				
			}
			
		} else if(cont2 == 1 && cont == -1){
			dado = rand() % 3 + 1;
			k = 0;
			
			if(dado == 1){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first){
						mat_adj_orientada[ordem[i]][j] = adj1[k];
						mat_adj_orientada[j][ordem[i]] = -adj1[k];
						k++;
					}
				}
				
			} else if(dado == 2){
			
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first){
						mat_adj_orientada[ordem[i]][j] = adjMenos1[k];
						mat_adj_orientada[j][ordem[i]] = -adjMenos1[k];
						k++;
					}
				}
				
			} else if(dado == 3){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first){
						mat_adj_orientada[ordem[i]][j] = adjMenos3[k];
						mat_adj_orientada[j][ordem[i]] = -adjMenos3[k];
						k++;
					}
				}
				
			}
			
		} else if(cont2 == 2 && cont == 2){
			dado = rand() % 2 + 1;
			
			if(dado == 1){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first && j != adjs[1].first){
						mat_adj_orientada[ordem[i]][j] = -1;
						mat_adj_orientada[j][ordem[i]] = 1;
					}
				}
				
			} else if(dado == 2){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first && j != adjs[1].first){
						mat_adj_orientada[ordem[i]][j] = 1;
						mat_adj_orientada[j][ordem[i]] = -1;
					}
				}
				
			}
			
		} else if(cont2 == 2 && cont == 0){
			dado = rand() % 2 + 1;
			
			if(dado == 1){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first && j != adjs[1].first){
						mat_adj_orientada[ordem[i]][j] = 1;
						mat_adj_orientada[j][ordem[i]] = -1;
					}
				}
				
			} else if(dado == 2){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first && j != adjs[1].first){
						mat_adj_orientada[ordem[i]][j] = -1;
						mat_adj_orientada[j][ordem[i]] = 1;
					}
				}
				
			} 
		}
		
	}
	
}

void orientacao_app2(char **mat_adj, char **mat_adj_orientada, int *ordem, int n_vertices, int tipo1, int tipoMenos1, int tipo3, int tipoMenos3){

	int i, j;
	int adj1[3], adjMenos1[3], adj3[3], adjMenos3[3], k, cont, dado, cont2;
	vector< pair <int, char>> adjs(3);
	
	for(i = 0; i < n_vertices; i++)
		for(j = 0; j < n_vertices; j++)
			mat_adj_orientada[i][j] = 0;
	
	adj1[0] = 1;
	adj1[1] = 1;
	adj1[2] = -1;
	
	adjMenos1[0] = 1;
	adjMenos1[1] = -1;
	adjMenos1[2] = -1;
	
	adj3[0] = 1;
	adj3[1] = 1;
	adj3[2] = 1;
	
	adjMenos3[0] = -1;
	adjMenos3[1] = -1;
	adjMenos3[2] = -1;

	k = 0;
	for(j = 0; j < n_vertices; j++){
		if(mat_adj[ordem[0]][j] == 1){
			
			if(tipo == 1){
				mat_adj_orientada[ordem[0]][j] = adj1[k];
				mat_adj_orientada[j][ordem[0]] = -adj1[k++];
			} else if(tipo == -1){
				mat_adj_orientada[ordem[0]][j] = adjMenos1[k];
				mat_adj_orientada[j][ordem[0]] = -adjMenos1[k++];
			} else if(tipo == 3){
				mat_adj_orientada[ordem[0]][j] = adj3[k];
				mat_adj_orientada[j][ordem[0]] = -adj3[k++];
			} else if(tipo == -3){
				mat_adj_orientada[ordem[0]][j] = adjMenos3[k];
				mat_adj_orientada[j][ordem[0]] = -adjMenos3[k++];
			}
			
		}
	}
	
	for(i = 1; i < n_vertices; i++){
		cont = k = cont2 = 0;
		adjs.clear();
		
		for(j = 0; j < n_vertices; j++) {
			if(mat_adj_orientada[ordem[i]][j] == 1 || mat_adj_orientada[ordem[i]][j] == -1){
				adjs[k].first = j;
				adjs[k].second = mat_adj_orientada[ordem[i]][j];
				k++;
				cont2++;
			}
				
			
			cont += mat_adj_orientada[ordem[i]][j];
		}
		
		if(cont2 == 1 && cont == 1){
			dado = rand() % 3 + 1;
			k = 1;
			
			if(dado == 1){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first){
						mat_adj_orientada[ordem[i]][j] = adj1[k];
						mat_adj_orientada[j][ordem[i]] = -adj1[k];
						k++;
					}
				}
				
			} else if(dado == 2){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first){
						mat_adj_orientada[ordem[i]][j] = adjMenos1[k];
						mat_adj_orientada[j][ordem[i]] = -adjMenos1[k];
						k++;
					}
				}
				
			} else if(dado == 3){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first){
						mat_adj_orientada[ordem[i]][j] = adj3[k];
						mat_adj_orientada[j][ordem[i]] = -adj3[k];
						k++;
					}
				}
				
			}
			
		} else if(cont2 == 1 && cont == -1){
			dado = rand() % 3 + 1;
			k = 0;
			
			if(dado == 1){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first){
						mat_adj_orientada[ordem[i]][j] = adj1[k];
						mat_adj_orientada[j][ordem[i]] = -adj1[k];
						k++;
					}
				}
				
			} else if(dado == 2){
			
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first){
						mat_adj_orientada[ordem[i]][j] = adjMenos1[k];
						mat_adj_orientada[j][ordem[i]] = -adjMenos1[k];
						k++;
					}
				}
				
			} else if(dado == 3){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first){
						mat_adj_orientada[ordem[i]][j] = adjMenos3[k];
						mat_adj_orientada[j][ordem[i]] = -adjMenos3[k];
						k++;
					}
				}
				
			}
			
		} else if(cont2 == 2 && cont == 2){
			dado = rand() % 2 + 1;
			
			if(dado == 1){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first && j != adjs[1].first){
						mat_adj_orientada[ordem[i]][j] = -1;
						mat_adj_orientada[j][ordem[i]] = 1;
					}
				}
				
			} else if(dado == 2){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first && j != adjs[1].first){
						mat_adj_orientada[ordem[i]][j] = 1;
						mat_adj_orientada[j][ordem[i]] = -1;
					}
				}
				
			}
			
		} else if(cont2 == 2 && cont == 0){
			dado = rand() % 2 + 1;
			
			if(dado == 1){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first && j != adjs[1].first){
						mat_adj_orientada[ordem[i]][j] = 1;
						mat_adj_orientada[j][ordem[i]] = -1;
					}
				}
				
			} else if(dado == 2){
				
				for(j = 0; j < n_vertices; j++){
					if(mat_adj[ordem[i]][j] == 1 && j != adjs[0].first && j != adjs[1].first){
						mat_adj_orientada[ordem[i]][j] = -1;
						mat_adj_orientada[j][ordem[i]] = 1;
					}
				}
				
			} 
		}
		
	}

}

int main(int argc, char *argv[]) {
	
	int l, i, j, k, n_vertices, n_grafos, n_arestas, sim, t;
	int tipo1, tipoMenos1, tipo3, tipoMenos3, t1, t2, t3, t4, cont, cont2, r, s, primeiro_grafo, aux, aux2[4];
	long int p1, p2, size;
	string name;
	
	srand(time(NULL));
	
	char **mat_adj;
	char **mat_adj_orientada;
	char **mat_adj_orientada2;
	
	sscanf(argv[1], "%d", &n_vertices);
	sscanf(argv[2], "%d", &n_grafos);
	sscanf(argv[3], "%d", &primeiro_grafo);
	sscanf(argv[4], "%d", &n_arestas);
	
	char entrada[n_grafos][n_vertices][n_vertices];
	int *permutacao = (int *) malloc (n_vertices * sizeof(int));
	int *ordem = (int *) malloc (n_vertices * sizeof(int));
	vector<int> grafos_parcial[n_grafos];
	
	mat_adj = cria_matriz(n_vertices);
	mat_adj_orientada = cria_matriz(n_vertices);
	mat_adj_orientada2 = cria_matriz(n_vertices);
	aux2[0] = 1;
	aux2[1] = -1;
	aux2[2] = 3;
	aux2[3] = -3;
	
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
		cin >> k;
		
		cin >> i;
		
		for(j = 0; j < i; j++){
			cin >> t;
			grafos_parcial[k - 1].push_back(t);
		}
	}
	
	for(l = 0; l < n_grafos; l++){
		printf("%d\n", primeiro_grafo + l);
		fflush(stdout);
		
		for(i = 0; i < n_vertices; i++)
			for(j = 0; j < n_vertices; j++)
				mat_adj[i][j] = entrada[l][i][j];
				
		vector<long int> livres_isomorfismo[grafos_parcial[l].size()];
		
		for(t = 0; t < grafos_parcial[l].size(); t++){
		
			livres_isomorfismo[t].push_back(grafos_parcial[l][t]);
			gerar_orientacao(mat_adj, mat_adj_orientada2, n_vertices, livres_isomorfismo[t][0], n_arestas);
			
			tipo1 = tipoMenos1 = tipo3 = tipoMenos3 = 0;
			
			for(r = 0; r < n_vertices; r++){
				cont = 0;
				
				for(s = 0; s < n_vertices; s++){
					cont += mat_adj_orientada2[r][s];
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
			}
			
			for(p1 = 0; p1 < n_vertices; p1++){
				
				for(r = 0; r < n_vertices; r++)
					ordem[r] = r;
				
				bfs(mat_adj, ordem, n_vertices, p1);
				
				orientacao_app2(mat_adj, mat_adj_orientada, ordem, n_vertices, tipo1, tipoMenos1, tipo3, tipoMenos3);
				
			}
			
			
			for(p1 = 0; p1 < n_vertices; p1++){
				
				for(r = 0; r < n_vertices; r++)
					ordem[r] = r;
				
				bfs(mat_adj, ordem, n_vertices, p1);
				
				
				
				for(aux = 0; aux < 4; aux++){
					
					orientacao_app(mat_adj, mat_adj_orientada, ordem, n_vertices, aux2[aux]);
					
					//~ printf("\n\n");
					
					//~ for(r = 0; r < n_vertices; r++){
						//~ for(s = 0; s < n_vertices; s++)
							//~ printf("%2d ", mat_adj_orientada[r][s]);
							
						//~ printf("\n");
					//~ }
					
					//~ printf("\n\n");
					
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
							
							for(r = 0; r < n_vertices; r++)
								permutacao[r] = r;
							
							do{	
								
								sim = ver_isomorfismo(n_vertices, mat_adj_orientada, mat_adj_orientada2, permutacao);
									
								if(sim == 1){
									break;
								}
								

							}while(next_permutation(permutacao, permutacao + n_vertices));
							
						} else {
							sim = 0;
						}	
						
						if(sim == 1)
							break;
					}
					
					if(sim == 0) {
						livres_isomorfismo.push_back(inteiro_orientacao(mat_adj, mat_adj_orientada, n_vertices, n_arestas));
					}
				}
				
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
	
	free(ordem);
	free(permutacao);
	limpa_memoria_matriz(mat_adj);
	limpa_memoria_matriz(mat_adj_orientada);
	
	return 0;
}


