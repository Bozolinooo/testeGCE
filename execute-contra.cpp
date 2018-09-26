#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]){
	int n_threads, n_grafos, n_vertices, i, k;
	char mensagem[200];
	
	sscanf(argv[1], "%d", &n_vertices);
	sscanf(argv[2], "%d", &n_threads);
	sscanf(argv[3], "%d", &n_grafos);
	
	sprintf(mensagem, "gcc showg.c -o showg");
	system(mensagem);
	
	sprintf(mensagem, "g++ contra-exemplo.cpp -o contra-exemplo");
	system(mensagem);
	
	if(n_threads >= n_grafos){
		
		for(i = 0; i < n_grafos; i++){
			
			sprintf(mensagem, "./showg -A -p%d-%d cub%02d.g6 > entrada%d.txt", i + 1, i + 1, n_vertices, i + 1);
			system(mensagem);
			
			sprintf(mensagem, "./contra-exemplo %d %d < entrada%d.txt > saidaContraExemplo%dv%d.out &", n_vertices, n_grafos, i + 1,n_vertices, i + 1);
			system(mensagem);
			
		}
		
	} else {
		k = n_grafos / n_threads;
		
		for(i = 0; i < n_threads - 1; i++){
			
			sprintf(mensagem, "./showg -A -p%d-%d cub%02d.g6 > entrada%d.txt", (i * k) + 1, (i + 1) * k, n_vertices, i + 1);
			system(mensagem);
			
			sprintf(mensagem, "./contra-exemplo %d %d < entrada%d.txt > saidaContraExemplo%dv%d.out &", n_vertices, n_grafos, i + 1,n_vertices, i + 1);
			system(mensagem);
			
		}
		
		sprintf(mensagem, "./showg -A -p%d-%d cub%02d.g6 > entrada%d.txt", (i * k) + 1, ((i + 1) * k) + (n_grafos % n_threads), n_vertices, i + 1);
		system(mensagem);
			
		sprintf(mensagem, "./contra-exemplo %d %d < entrada%d.txt > saidaContraExemplo%dv%d.out &", n_vertices, n_grafos, i + 1,n_vertices, i + 1);
		system(mensagem);
	}
	
	return 0;
}

