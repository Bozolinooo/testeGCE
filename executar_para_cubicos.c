#include <stdio.h>
#include <time.h> // 293891 segundps 12
#include <stdlib.h> // 7047 segundos 04 - 10, 114584 execução do peso das arestas 114 pra 14

int main(int argc, char **argv) 
{
	int j,
		n_vertices[6] = {4, 6, 8, 10, 12, 14},
		n_grafos[6] = {1, 2, 5, 19, 85, 509};
	char mensagem[200];
	time_t start, end;
    time_t run_time;
	
	start = time(NULL);
	
	
	for(j = 0; j < 6; j++) {
		
		sprintf(mensagem, "./showg -A cub%02d.g6 > entrada.txt", n_vertices[j]);
		system(mensagem);
		
		sprintf(mensagem, "./OCN7 %d %d 114 < entrada.txt >> qtdCores114ComTempo", n_vertices[j], n_grafos[j]);	
		system(mensagem);
		
		
		//~ for(i = 0; i < 456; i++){
			//~ sprintf(mensagem, "./teste %d %d %d < entrada.txt >> saida2.out", n_vertices[j], n_grafos[j], i);	
			//~ system(mensagem);
		//~ }
			
	}
	
	
	end = time(NULL);
    run_time = (end - start);
    
    printf("%ld Segundos\n", run_time);
	
	return 0;
}

