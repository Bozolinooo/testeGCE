#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

char t4[4][4];
int maior_ciclo, maior_caminho;
int topo;
int pilha[100];
int* n_ciclos;
int* n_caminhos;

int NISOT4[] = {0, 0, 0, 0, 0, 0,
				0, 0, 0, 1, 0, 1,
				1, 0, 0, 0, 1, 0,
				1, 0, 0, 1, 0, 0,};
			
				
void p_clear(){
	topo = -1;
}

void p_push(int v){
	topo++;
	pilha[topo] = v;
}

int p_pop(){
	if(topo == -1){
		printf("Pilha Vazia\n");
		fflush(stdout);
	}
	
	int k = pilha[topo];
	topo--;
	
	return k;
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

void limpa_memoria_matriz (char** mat_adj){
	free(*mat_adj);
	free(mat_adj);
}

char** cria_matriz (int n_vertices) {
	char* valores = (char *) malloc ((n_vertices * n_vertices) * sizeof(char));
	char** linhas = (char **) malloc (n_vertices * sizeof(char*));
	int i;
	
	if((valores == NULL) || (linhas == NULL)) {
		printf("falha malloc");
		exit(EXIT_FAILURE);
	}
	
	for(i = 0; i < n_vertices; i++)
		linhas[i] = valores + i*n_vertices;
	
	return linhas;
}

void orienta_torneio4 (int n_torneio) {
		int i, j, cont = 0;

		for(i = 0; i < 4; i++)
				for(j = 0; j < 4; j++)
						t4[i][j] = 0;
		
		for(i = 0; i < 4; i++){
				for(j = i + 1; j < 4; j++){
					if(NISOT4[cont + (6 * n_torneio)] == 0){
						t4[i][j]= 1;
						t4[j][i]= -1;
					}
					else{
						t4[i][j] = -1;
						t4[j][i] = 1;
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

int bfsVertice(char **mat_adj_orientada, int* visitado, int n_vertices, int v){
	int i, j, flag;
	p_clear();
	
	visitado[v] = 1;
	p_push(v);
	
    while(topo != -1){
		i = pilha[topo];
		flag = 0;
		
		for(j = 0; j < n_vertices; j++){
			if(mat_adj_orientada[i][j] == 1){
				if(visitado[j] == 1 && j == pilha[0]){
					
					if(topo > maior_ciclo){
						maior_ciclo = topo + 1;
					}
				}
				if(visitado[j] == 0){
					visitado[j] = 1;
					p_push(j);
					flag = 1;
					break;
				}
			}
		}
		
		if(flag == 0){
			visitado[i] = 2;
			p_pop();
		}
	}
	
	return 0;
}

int bfs(char **mat_adj_orientada, int n_vertices, int inicio){
	int i;
	int *visitado = (int *) malloc (n_vertices * sizeof(int));
	
	for(i = 0; i < n_vertices; i++){
		visitado[i] = 0;
	}
	
	bfsVertice(mat_adj_orientada, visitado, n_vertices, inicio);
	
	for(i = 0; i < n_vertices; i++){
		if(visitado[i] == 0){
			bfsVertice(mat_adj_orientada, visitado, n_vertices, i);
		}
	}
	
	free(visitado);
	return 0;
}

void combinationUtil(char** mat_adj_orientada, int* arr, int data[], int start, int end, int index, int r){ 
	int i, j, count;
   
    if(index == r){
		
		do{	
			
			if(mat_adj_orientada[data[r - 1]][data[0]] == 1){
				
				count = 0;
				
				for(j = 0; j < r - 1; j++){
					if(mat_adj_orientada[data[j]][data[j + 1]] == 1){
						count++;
					} else {
						break;
					}
				}
				
				if(count == r - 1){
					n_ciclos[r]++;
					
					//~ for(j = 0; j < r; j++){
						//~ printf("%d ", data[j]);
						//~ fflush(stdout);
					//~ }
					//~ printf("\n");
					//~ fflush(stdout);
				}
			} else {
				count = 0;
				
				for(j = 0; j < r - 1; j++){
					if(mat_adj_orientada[data[j]][data[j + 1]] == 1){
						count++;
					} else {
						break;
					}
				}
				
				if(count == r - 1){
					n_caminhos[r]++;
					
					//~ for(j = 0; j < r; j++){
						//~ printf("%d ", data[j]);
						//~ fflush(stdout);
					//~ }
					//~ printf("\n");
					//~ fflush(stdout);
				}
			}
						
		}while(next_permutation(data, data + r));
       
        
        return; 
    } 
  
    
    for (i = start; i <= end && end-i+1 >= r-index; i++){ 
        data[index] = arr[i]; 
        combinationUtil(mat_adj_orientada, arr, data, i + 1, end, index + 1, r); 
    } 
} 

void printCombination(char** mat_adj_orientada, int* arr, int n, int r){ 
    int data[r]; 
 
    combinationUtil(mat_adj_orientada, arr, data, 0, n-1, 0, r); 
}

int main(int argc, char *argv[]) {
	int n_vertices, n_grafos, i, j, l, k, p, r, sim, p1, r1, k1, count, count2, count3, count4, count5, l1, n_c, n_ca;
	char**mat_adj;
	char**mat_adj_orientada;
	char** torneio4 = cria_matriz(4);
	vector<int> entrada1;
	vector<int> v;
	string name;
	int teste[4];
	int sim1[4];
	
	sscanf(argv[1], "%d", &n_vertices);
	sscanf(argv[2], "%d", &n_grafos);
	
	mat_adj = cria_matriz(n_vertices);
	mat_adj_orientada = cria_matriz(n_vertices);
	
	char entrada[n_grafos][n_vertices][n_vertices];
	int* coloracao = (int *) malloc (n_vertices * sizeof(int));
	int* coloracao2 = (int *) malloc (n_vertices * sizeof(int));
	int* arr = (int *) malloc (n_vertices * sizeof(int));
	n_ciclos = (int *) malloc ((n_vertices + 1) * sizeof(int));
	n_caminhos = (int *) malloc ((n_vertices + 1) * sizeof(int));
	
	for(l = 0; l < n_vertices; l++)
		arr[l] = l;
	
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
		
		//~ count3 = 0;
		count4 = 0;
		
		for(i = 0; i < n_vertices; i++)
			for(j = 0; j < n_vertices; j++)
				mat_adj[i][j] = entrada[l][i][j];
		
		//~ cin >> k;
		//~ cin >> k;
		
		//~ for(p = 0; p < k; p++){
			//~ cin >> r;
			//~ entrada1.push_back(r);
		//~ }
		
		//~ for(p = 0; p < k; p++){
		for(p = 0; p < pow(2, ((n_vertices * 3) / 2)); p++){
			//~ gerar_orientacao(mat_adj, mat_adj_orientada, n_vertices, entrada1[p], ((n_vertices * 3) / 2));
			gerar_orientacao(mat_adj, mat_adj_orientada, n_vertices, p, ((n_vertices * 3) / 2));
			
			for(l1 = 0; l1 < 4; l1++) {
				orienta_torneio4(l1);
				sim1[l1] = 0;
			
				for(p1 = 0; p1 < 4; p1++)
					for(r1 = 0; r1 < 4; r1++)
						torneio4[p1][r1] = t4[p1][r1];
				
				
				sim = 0;
				
				for(k1 = 0; k1 < 4; k1++)
					if(take2(0, k1, v, n_vertices, 4, mat_adj_orientada, torneio4, coloracao) == 1) {
						sim = 1;
						break;
					}
					
				v.clear();
					
				if(sim == 1){
					sim1[l1] = 1;
					
					if(l1 == 2){
						for(p1 = 0; p1 < n_vertices; p1++)
							coloracao2[p1] = coloracao[p1];
					}
				}
			}
			
			if(sim1[2] == 1 && sim1[0] == 0 && sim1[1] == 0 && sim1[3] == 0){
					
					//~ count3++;
					
					//~ if(count3%50 == 0){
						count4++;
						
						maior_ciclo = -1;	
						maior_caminho = -1;
						n_c = 0;
						n_ca = 0;
						
						for(p1 = 0; p1 < n_vertices + 1; p1++)
							n_ciclos[p1] = n_caminhos[p1] = 0;
						
						for(p1 = 3; p1 <= n_vertices; p1++) {
							printCombination(mat_adj_orientada, arr, n_vertices, p1);
						}
						
						for(p1 = 3; p1 <= n_vertices; p1++){
							if(n_ciclos[p1] > 0)
								if(p1 > maior_ciclo)
									maior_ciclo = p1;
							
							n_c += n_ciclos[p1] / p1;
						}
						
						for(p1 = 2; p1 <= n_vertices; p1++){
							if(n_caminhos[p1] > 0)
								if(p1 > maior_caminho)
									maior_caminho = p1;
							
							n_ca += n_caminhos[p1] / p1;
						}	
							
						for(p1 = 0; p1 < n_vertices; p1++){
							for(r1 = 0; r1 < n_vertices; r1++){
								printf("%2d ", mat_adj_orientada[p1][r1]);
								fflush(stdout);
							}
								
							printf("\n");
							fflush(stdout);
						}
						
						for(p1 = 0; p1 < n_vertices; p1++){
							printf("%d ", coloracao2[p1]);
							fflush(stdout);
						}
						
						printf("\n");
						fflush(stdout);
						
						printf("%d %d %d %d\n", maior_ciclo, n_c, maior_caminho, n_ca);
						fflush(stdout);
						
						for(p1 = 0; p1 < 4; p1++)
							teste[p1] = 0;
					
						for(p1 = 0; p1 < n_vertices; p1++){
							count = 0;
							
							for(r1 = 0; r1 < n_vertices; r1++)
								if(mat_adj_orientada[p1][r1] == 1)
									count++;
							
							printf("%d ", count);
							fflush(stdout);
							
							teste[count]++;
						}
						
						printf("\n");
						fflush(stdout);	
					
				//~ }
			}
			if(count4 == 1)
				break;
		}
		
		entrada1.clear();
	}
	
	limpa_memoria_matriz(mat_adj);
	limpa_memoria_matriz(mat_adj_orientada);
	limpa_memoria_matriz(torneio4);
	free(coloracao);
	free(coloracao2);
	free(arr);
	free(n_ciclos);
	free(n_caminhos);

	return 0;
}
