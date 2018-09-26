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

#define NUM_THREADS 4

using namespace std;

sem_t semaforo, s2, s3, s4;
pthread_mutex_t mutex1, mutex2, mutex3;
int n_vertices, n_grafos, n_arestas, tipo3, tipoMenos3, tipo1, tipoMenos1, sim;
int orientacao1G, orientacao2G, orientacao3G, orientacao4G, fat1, fat2, fat3, fat4;
int *tipo1G;
int *tipoMenos1G;
int *tipo3G;
int *tipoMenos3G;
vector<int> livres_isomorfismo;
char** mat_adj_orientada;
char** mat_adj_orientada2;

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

int fatorial(int n){
	int ret = 1;
	
	for(int i = 1; i <= n; ++i)
		ret *= i;
	
	return ret;
}

void ithPermutation(int n, int i, int *permutacao){
	int j, k = 0;
	int *fact = (int *) malloc (n * sizeof(int));
 
	fact[k] = 1;
	while(++k < n)
	  fact[k] = fact[k - 1] * k;

	for(k = 0; k < n; ++k){
	  permutacao[k] = i / fact[n - 1 - k];
	  i = i % fact[n - 1 - k];
	}

   
	for(k = n - 1; k > 0; --k)
	  for(j = k - 1; j >= 0; --j)
		 if(permutacao[j] <= permutacao[k])
			permutacao[k]++;

	free(fact);
}

int ver_isomorfismo(char **mat_adj_orientada, char **mat_adj_orientada2, int *permutacao){
	int i, j;
	
	for(i = 0; i < n_vertices; i++)
		for(j = 0; j < n_vertices; j++)
			if(mat_adj_orientada[i][j] != mat_adj_orientada2[permutacao[i]][permutacao[j]])
				return 0;
	
	return 1;
}

void shiftRight(int *a, int s, int e){
	int temp = a[e];
	for(int i = e; i > s; i--){
		a[i] = a[i - 1];
	}
	a[s] = temp;
}

void kthPermutation(int n, int k, int *permutacao){
	int *nums = (int *) malloc (n * sizeof(int));
	int *factorial = (int *) malloc (n * sizeof(int));
	
	factorial[0] = 1;
	factorial[1] = 1;
	nums[0] = 1;
	
	for (int i = 2; i <= n; i++) {
		nums[i - 1] = i;
		factorial[i] = i * factorial[i - 1];
	}
	
	if(k <= 1){
		for(int i = 0; i < n_vertices; i++)
			permutacao[i] = nums[i];
		
		free(nums);
		free(factorial);
		
		return;
	}
	if(k >= factorial[n]){
		
		
		for(int i = 0, l = n_vertices - 1; i < n_vertices; i++, l--)
			permutacao[i] = nums[l];
		
		free(nums);
		free(factorial);
		
		return;
	}
	
	k -= 1;
	for(int i = 0; i < n - 1; i++){
		int fact = factorial[n - i - 1];
		int index = (k / fact);
		
		shiftRight(nums, i, i + index);
		k = k - fact * index;
	}
	
	for(int i = 0; i < n_vertices; i++)
		permutacao[i] = nums[i];
		
	free(nums);
	free(factorial);
}

void *chamadora ( void *pt){
	int orientacao1, orientacao2, orientacao3, orientacao4, i, k;
	int *v1 = (int *) malloc (tipo1 * sizeof(int));
	int *v2 = (int *) malloc (tipoMenos1 * sizeof(int));
	int *v3 = (int *) malloc (tipo3 * sizeof(int));
	int *v4 = (int *) malloc (tipoMenos3 * sizeof(int));
	int *permutacao = (int *) malloc (n_vertices * sizeof(int));
	
	while(1){
		
		pthread_mutex_lock(&mutex3);
		
		if(sim == 1){
			pthread_mutex_unlock(&mutex3);
			free(v1);
			free(v2);
			free(v3);
			free(v4);
			free(permutacao);
			pthread_exit(NULL);
		}
		
		pthread_mutex_unlock(&mutex3);
		
		pthread_mutex_lock(&mutex1);
		
		if(orientacao4G == fatorial(n_vertices)){
			pthread_mutex_unlock(&mutex1);
			free(v1);
			free(v2);
			free(v3);
			free(v4);
			free(permutacao);
			pthread_exit(NULL);
		}
		
		//~ sem_post(&s2);
		
		//~ sem_wait(&s3);
		
		//~ orientacao1 = orientacao1G; 
		//~ orientacao2 = orientacao2G; 
		//~ orientacao3 = orientacao3G;
		orientacao4 = orientacao4G;
		
		orientacao4G++;
		
		//~ if(orientacao4G == fat4){
			//~ orientacao3G++;
			//~ orientacao4G = 0;
			
			//~ if(orientacao3G == fat3){
				//~ orientacao2G++;
				//~ orientacao3G = 0;
				
				//~ if(orientacao2G == fat2){
					//~ orientacao1G++;
					//~ orientacao2G = 0;
				//~ }
			//~ }
		//~ }
		
		//~ sem_post(&s3);
		pthread_mutex_unlock(&mutex1);
		
		//~ ithPermutation(tipo1, orientacao1, v1);
		//~ ithPermutation(tipoMenos1, orientacao2, v2);
		//~ ithPermutation(tipo3, orientacao3, v3);
		//~ ithPermutation(tipoMenos3, orientacao4, v4);
		
		//~ for(i = 0; i < tipo1; i++)
			//~ permutacao[tipo1G[i]] = tipo1G[v1[i]];
		
		//~ for(i = 0; i < tipoMenos1; i++)
			//~ permutacao[tipoMenos1G[i]] = tipoMenos1G[v2[i]];
		
		//~ for(i = 0; i < tipo3; i++)
			//~ permutacao[tipo3G[i]] = tipo3G[v3[i]];
		
		//~ for(i = 0; i < tipoMenos3; i++)
			//~ permutacao[tipoMenos3G[i]] = tipoMenos3G[v4[i]];
		
		
		kthPermutation(n_vertices, orientacao4, permutacao);
			
		k = ver_isomorfismo(mat_adj_orientada, mat_adj_orientada2, permutacao);
		
		pthread_mutex_lock(&mutex2);
		
		//~ if(sim != 1)
			sim = k;
		
		pthread_mutex_unlock(&mutex2);
			
		
	}
}

int main(int argc, char *argv[]) {
	int l, i, j, k, n_totalO, size, p, r, s, cont, t1, t2, t3, t4, cont2;
	string name;
	pthread_t thread[NUM_THREADS];
	char** mat_adj;
	
	sscanf(argv[1], "%d", &n_vertices);
	sscanf(argv[2], "%d", &n_grafos);
	
	mat_adj = cria_matriz(n_vertices);
	mat_adj_orientada = cria_matriz(n_vertices);
	mat_adj_orientada2 = cria_matriz(n_vertices);
	
	char entrada[n_grafos][n_vertices][n_vertices];
	
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
	
	sem_init(&semaforo, 0, 1);
	sem_init(&s2, 0, 1);
	sem_init(&s3, 0, 1);
	sem_init(&s4, 0, 1);
	
	pthread_mutex_init(&mutex1, NULL);
	pthread_mutex_init(&mutex2, NULL);
	pthread_mutex_init(&mutex3, NULL);
	
	for(l = 0; l < n_grafos; l++){
		printf("%d/%d\n", l, n_grafos);
		fflush(stdout);
		
		livres_isomorfismo.clear();
		livres_isomorfismo.push_back(0);
		
		for(i = 0; i < n_vertices; i++)
			for(j = 0; j < n_vertices; j++)
				mat_adj[i][j] = entrada[l][i][j];
		
		n_arestas = n_arestas_matriz(mat_adj, n_vertices, 0);
		n_totalO = pow(2, n_arestas);
		
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
				
				tipo1G = (int *) malloc (tipo1 * sizeof(int));
				tipoMenos1G = (int *) malloc (tipoMenos1 * sizeof(int));
				tipo3G = (int *) malloc (tipo3 * sizeof(int));
				tipoMenos3G = (int *) malloc (tipoMenos3 * sizeof(int));
				
				tipo1 = tipoMenos1 = tipo3 = tipoMenos3 = 0;
				
				for(r = 0; r < n_vertices; r++){
					cont = 0;
					
					for(s = 0; s < n_vertices; s++)
						cont += mat_adj_orientada2[r][s];
					
					if(cont == 1){
						tipo1G[tipo1++] = r;
					} else if(cont == -1){
						tipoMenos1G[tipoMenos1++] = r;
					} else if(cont == 3){
						tipo3G[tipo3++] = r;
					} else if(cont == -3){
						tipoMenos3G[tipoMenos3++] = r;
					}
					
				}
				
				orientacao1G = orientacao2G = orientacao3G = orientacao4G = 0;
				fat1 = fatorial(tipo1);
				fat2 = fatorial(tipoMenos1);
				fat3 = fatorial(tipo3);
				fat4 = fatorial(tipoMenos3);
				
				if((t1 == tipo1) && (t2 == tipoMenos1) && (t3 == tipo3) && (t4 == tipoMenos3)){
				
					for(r = 0; r < NUM_THREADS; r++)
						pthread_create(&thread[r], NULL, chamadora, NULL);
					
					for(r = 0; r < NUM_THREADS; r++)
						pthread_join(thread[r], NULL);
				}
					
				free(tipo1G);
				free(tipoMenos1G);
				free(tipo3G);
				free(tipoMenos3G);
				
				if(sim == 1)
					break;
			}
			
			if(sim == 0)
				livres_isomorfismo.push_back(i);
		}
		
		size = livres_isomorfismo.size();
		
		for(i = 0; i < size; i++){
			printf("%d\n", livres_isomorfismo[i]);
			fflush(stdout);
		}
		
	}
	
	limpa_memoria_matriz(mat_adj);
	limpa_memoria_matriz(mat_adj_orientada);
	limpa_memoria_matriz(mat_adj_orientada2);
	
	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);
	pthread_mutex_destroy(&mutex3);
	
	return 0;
}
