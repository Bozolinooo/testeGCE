#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;


void combinationUtil(int* arr, int data[], int start, int end, int index, int r){ 
	int i, j;
   
    if(index == r){
		
		//~ do{	
			
			for(j = 0; j < r; j++) 
				printf("%d ", data[j]); 
        
			printf("\n"); 			
						
		//~ }while(next_permutation(data, data + r));
       
        
        return; 
    } 
  
    
    for (i = start; i <= end && end-i+1 >= r-index; i++){ 
        data[index] = arr[i]; 
        combinationUtil(arr, data, i + 1, end, index + 1, r); 
    } 
} 

void printCombination(int* arr, int n, int r){ 
    int data[r]; 
 
    combinationUtil(arr, data, 0, n-1, 0, r); 
} 

int main () {
	int i;
	int *arr = (int *) malloc (5 * sizeof(int));
		
	for(i = 0; i < 5; i ++)
		arr[i] = i + 1;
		
	
	for(i = 3; i <= 5; i++) 
		printCombination(arr, 5, i);
	
	free(arr);
	
	return 0;
}

