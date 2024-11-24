#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int partition(int arr[], int left, int right);
void quickSort(int values[], int left, int right);
void swap(int* a, int* b);

int main(int argc, char *argv[]){
	if(argc == 2){
		FILE *file = fopen(argv[1], "rb");
		
		if(file == NULL){
			printf("Erro open archive!\n");
			return -1;
		}

		int j = 0;
		int k = 0;
		fscanf (file, "%d", &j);   
		while (!feof (file))
		{  
			fscanf (file, "%d", &j);
			k++;      
		}

    	long unsigned int size = k;
		// printf("size : %d\n", size);

		int *buffer = (int *)malloc(size * sizeof(int));
		
		fseek(file, 0, SEEK_SET);

		int i = 0;
		int x = 0;
		fscanf (file, "%d", &x);   
		while (!feof (file))
		{  
			buffer[i] = x;
			fscanf (file, "%d", &x);
			i++;      
		}

		// for(int i = 0; i < size; i++){
		// 	printf("Antes : %d\n", buffer[i]);
		// }

		clock_t start = clock();
		quickSort(buffer, 0, size-1);
		clock_t end = clock();
		
		clock_t result = ((double)(end-start))/CLOCKS_PER_SEC;

		printf("Exec time: %lf\n", result);

		for(int i = 0; i < size; i++){
			printf("%d\n", buffer[i]);
		}

		fclose(file);
	}else{
		printf("Erro in arguments!\n");
		return -1;
	}
	return 0;
}

void quickSort(int values[], int left, int right){
	if (left < right) {
		//printf("quickSort    left : %d  -- right %d\n", left, right);
		int pivot = partition(values, left, right);
		//printf("pivo : %d\n", pivot);
		quickSort(values, left, pivot - 1);
		//printf("quick1  vleft : %d   --   vight : %d\n", values[0], values[pivot - 1]);
		quickSort(values, pivot + 1, right);	
		//printf("quick2  vleft : %d   --   vight : %d\n", values[pivot + 1], values[right]);
	}
}

void swap(int* a, int* b){
	//printf("swap\n");
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int arr[], int left, int right){
	//printf("partition\n");
	int mid = 0;
	mid = left+(right-left)/2;

    int pivot = arr[mid];
    //printf("valorNoPivo : %d  --- mid : %d\n", pivot, mid);
    swap(&arr[mid], &arr[right]);
    
	int i = left-1;
	// if(left - 1 > 0){
	// 	i = left - 1;
	// }
    //printf("left =  %d\n", i);
    for(int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}
