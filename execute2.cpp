#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]){
	int n_threads, n_grafos, n_vertices, i, k;
	char mensagem[200];
	
	sscanf(argv[1], "%d", &n_vertices);
	sscanf(argv[2], "%d", &n_threads);
	sscanf(argv[3], "%d", &n_grafos);
	
	sprintf(mensagem, "g++ isomorfismoParcial2.cpp -o isomorfismoParcial2");
	system(mensagem);
	
	if(n_threads >= n_grafos){
		
		for(i = 0; i < n_grafos; i++){
			
			sprintf(mensagem, "./showg -A -p%d-%d cub%02d.g6 > entrada%d.txt", i + 1, i + 1, n_vertices, i + 1);
			system(mensagem);
			
			sprintf(mensagem, "./isomorfismoParcial2 %d %d %d %d < entrada%d.txt > Parical2saida%dv%d.out &", n_vertices, 1, i + 1, ((n_vertices * 3) / 2), i + 1, n_vertices, i + 1);
			system(mensagem);
			
		}
		
	} else {
		k = n_grafos / n_threads;
		
		for(i = 0; i < n_threads - 1; i++){
			
			sprintf(mensagem, "./showg -A -p%d-%d cub%02d.g6 > entrada%d.txt", (i * k) + 1, (i + 1) * k, n_vertices, i + 1);
			system(mensagem);
			
			sprintf(mensagem, "./isomorfismoParcial2 %d %d %d %d < entrada%d.txt > Parical2saida%dv%d.out &", n_vertices, k, (i * k) + 1, (n_vertices * 3) / 2, i + 1, n_vertices, i + 1);
			system(mensagem);
			
		}
		
		sprintf(mensagem, "./showg -A -p%d-%d cub%02d.g6 > entrada%d.txt", (i * k) + 1, ((i + 1) * k) + (n_grafos % n_threads), n_vertices, i + 1);
		system(mensagem);
			
		sprintf(mensagem, "./isomorfismoParcial2 %d %d %d %d < entrada%d.txt > Parical2saida%dv%d.out &", n_vertices, k + (n_grafos % n_threads), (i * k) + 1, (n_vertices * 3) / 2, i + 1, n_vertices, i + 1);
		system(mensagem);
	}
	
	return 0;
}

