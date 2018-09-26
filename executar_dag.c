#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

int main(int argc, char **argv) 
{
	int j, n_vertices, n_grafos, primeiro, ultimo;
	char mensagem[200];
	
	sscanf(argv[1], "%d", &n_vertices);
	sscanf(argv[2], "%d", &n_grafos);
	
	sprintf(mensagem, "g++ DAG.cpp -o DAG");	
	system(mensagem);
	
	primeiro = 1;
	ultimo = n_grafos / 6;
	
	for(j = 0; j < 5; j++) {
		
		sprintf(mensagem, "./showg -A -p%d-%d cub%02d.g6 > entrada%d.txt", primeiro, ultimo, n_vertices, j);
		system(mensagem);
			
		sprintf(mensagem, "./DAG %d %d < entrada%d.txt > saida%dDAG.out &", n_vertices, n_grafos / 6, j, j);	
		system(mensagem);
		
		primeiro = ultimo + 1;
		ultimo = (j + 2) * (n_grafos / 6);
	}
	
	primeiro = ultimo + 1;
	ultimo += (6 * (n_grafos / 6)) + (n_grafos % 6);
	
	sprintf(mensagem, "./showg -A -p%d-%d cub%02d.g6 > entrada%d.txt", primeiro, ultimo, n_vertices, j);
	system(mensagem);
	
	sprintf(mensagem, "./DAG %d %d < entrada%d.txt > saida%dDAG.out &", n_vertices, (n_grafos / 6) + (n_grafos % 6), j, j);	
	system(mensagem);
	
	return 0;
}


