#include <pthread.h>
#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 4

pthread_mutex_t mutex1;

struct thread_data{
	char *message1;
	char *message2;
};

void *PrintHello(void *threadarg)
{  
	char hello_msg[200], hello_msg1[200];
	struct thread_data *my_data;
	
	my_data = (struct thread_data *) threadarg;
	strcpy(hello_msg, my_data->message1);
	strcpy(hello_msg1, my_data->message2);
	
	pthread_mutex_lock(&mutex1);
	system(hello_msg);
	system(hello_msg1);
	pthread_mutex_unlock(&mutex1);
	
	pthread_exit(NULL);
}

struct thread_data thread_data_array[NUM_THREADS];

int main(int argc, char **argv) 
{
	int j,t,
		n_vertices[7] = {4, 6, 8, 10, 12, 14, 16},
		n_grafos[7] = {1, 2, 5, 19, 85, 509, 4060};
	
	pthread_t threads[NUM_THREADS];
	
	pthread_mutex_init(&mutex1, NULL);
	
	for(t = 0; t < NUM_THREADS; t++) {
		thread_data_array[t].message1 = (char *) malloc (200 * sizeof(char));
		thread_data_array[t].message2 = (char *) malloc (200 * sizeof(char));
	}
	
	
	sprintf(thread_data_array[0].message1, "./showg -A -p1-1 cub08.g6 > entrada1.txt");
	
	sprintf(thread_data_array[0].message2, "./isomorfismo2 8 1 1 < entrada1.txt > saida8V1.out &");	
	
	sprintf(thread_data_array[1].message1, "./showg -A -p2-2 cub08.g6 > entrada2.txt");
	
	sprintf(thread_data_array[1].message2, "./isomorfismo2 8 1 2 < entrada2.txt > saida8V2.out");	
	
	sprintf(thread_data_array[2].message1, "./isomorfismo2 -A -p3-3 cub08.g6 > entrada3.txt");
	
	sprintf(thread_data_array[2].message2, "./isomorfismo2 8 1 3 < entrada3.txt > saida8V3.out");	
	
	sprintf(thread_data_array[3].message1, "./showg -A -p4-5 cub08.g6 > entrada4.txt");
	
	sprintf(thread_data_array[3].message2, "./isomorfismo2 8 2 4 < entrada4.txt > saida8V4.out");	
	
	
	for(t = 0; t < NUM_THREADS; t++){
		pthread_create(&threads[t], NULL, PrintHello, (void *) &thread_data_array[t]);
	}
	
	for(t = 0; t < NUM_THREADS; t++)
		pthread_join(threads[t], NULL);
		
	pthread_mutex_destroy(&mutex1);
	
	return 0;
}


