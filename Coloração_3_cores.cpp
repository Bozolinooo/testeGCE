#include <bits/stdc++.h>

#define NUM_THREADS 4

using namespace std;

char t3[3][3];

int NISOT3[] =  {0, 0, 0,
				1, 0, 1,};
				
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

void orienta_torneio3 (int n_torneio) {
		int i, j, cont = 0;

		for(i = 0; i < 3; i++)
				for(j = 0; j < 3; j++)
						t3[i][j] = 0;
		
		for(i = 0; i < 3; i++){
				for(j = i + 1; j < 3; j++){
					if(NISOT3[cont + (3 * n_torneio)] == 0){
						t3[i][j]= 1;
						t3[j][i]= -1;
					}
					else{
						t3[i][j] = -1;
						t3[j][i] = 1;
					}
					
					cont++;
				}
		}
}

int take2(int n, int el, vector<int> v, int n_vertices, int n_cores2, char** mat_adj_orientada, char** torneio, int* coloracao) {

	v.push_back(el);
	
	int i, p, size = v.size();
	
	for(p = 0; p < size - 1; p++){
		if(mat_adj_orientada[p][size - 1] != 0) {
			if(torneio[v[p]][v[size - 1]] != mat_adj_orientada[p][size - 1])
				return 0;
		}
	}
	
	if(n == n_vertices - 1){
		
		for(i = 0; i < n_vertices; i++)
			coloracao[i] = v[i];
		
		return 1; 
	}
	

	for(i = 0; i < n_cores2; i++) {
		if(take2(n + 1, i, v, n_vertices, n_cores2, mat_adj_orientada, torneio, coloracao) == 1)
			return 1;
		
	}
	
	return 0;
}

int main(int argc, char *argv[]) {
	int n_vertices, n_grafos, n_arestas, n_totalO, sim, i, j, l, k, p, r;
	int* coloracao;
	char** mat_adj;
	char** mat_adj_orientada;
	char** torneio3;
	vector<int> v;
	string name;
	
	sscanf(argv[1], "%d", &n_vertices);
	sscanf(argv[2], "%d", &n_grafos);
	
	mat_adj = cria_matriz(n_vertices);
	mat_adj_orientada = cria_matriz(n_vertices);
	torneio3 = cria_matriz(3);
	coloracao = (int *) malloc (n_vertices * sizeof(int));
	
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
	
	for(l = 0; l < n_grafos; l++){
		
		for(i = 0; i < n_vertices; i++)
			for(j = 0; j < n_vertices; j++)
				mat_adj[i][j] = entrada[l][i][j];
		
		n_arestas = n_arestas_matriz(mat_adj, n_vertices, 0);
		n_totalO = pow(2, n_arestas);
		
		for(i = 0; i < n_totalO; i++){
			gerar_orientacao(mat_adj, mat_adj_orientada, n_vertices, i, n_arestas);
			
			for(j = 0; j < 2; j++){
				orienta_torneio3(j);
				
				for(p = 0; p < 3; p++)
					for(r = 0; r < 3; r++)
						torneio3[p][r] = t3[p][r];
				
				sim = 0;
				
				for(k = 0; k < 3; k++)
					if(take2(0, k, v, n_vertices, 3, mat_adj_orientada, torneio3, coloracao) == 1) {
						sim = 1;
						break;
					}
				
				v.clear();
								
				if(sim == 1){
					for(p = 0; p < n_vertices; p++){
						for(r = 0; r < n_vertices; r++){
							printf("%2d ", mat_adj_orientada[p][r]);
							fflush(stdout);
						}
						printf("\n");
						fflush(stdout);
					}
					
					printf("\n");
					fflush(stdout);
					
					for(p = 0; p < n_vertices; p++){
						printf("%d ", coloracao[p]);
						fflush(stdout);
					}
					
					printf("\n");
					fflush(stdout);
					
					break;
				}
				
			}
			
		}
	
	
	}
	
	free(coloracao);
	limpa_memoria_matriz(mat_adj);
	limpa_memoria_matriz(mat_adj_orientada);
	limpa_memoria_matriz(torneio3);
	
	return 0;
}
