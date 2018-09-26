#include <stdio.h>
#include <algorithm>    
#include <stdlib.h>
#include <time.h>

using namespace std;

int main (){
  
	long int num = 64;
	int *resultado = (int *) malloc (7 * sizeof(int));
	int base = 2;
	int j = 0;
	
	while(num != 0){
		resultado[j] = num % base;
		num = num / base;
		j++;
	}
	
	for(j = 0; j < 6; j++)
		printf("%d ", resultado[j]);
	
	printf("\n");

	return 0;
}
