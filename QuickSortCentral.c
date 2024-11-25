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


		clock_t Ticks[2];
		Ticks[0] = clock();
		quickSort(buffer, 0, size-1);
		Ticks[1] = clock();
		double result = (Ticks[1] - Ticks[0]) * 1000 / CLOCKS_PER_SEC;

		printf("Exec time: %lf\n", result/1000);
	
		fclose(file);
		
		file = fopen("resultado.txt", "w+");
		for(int i = 0; i < size; i++){
			fprintf(file, "%d\n", buffer[i]);
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
		int pivot = partition(values, left, right);
		quickSort(values, left, pivot - 1);
		quickSort(values, pivot + 1, right);	
	}
}

void swap(int* a, int* b){
	int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int arr[], int left, int right){
	int mid = 0;
	mid = left+(right-left)/2;

    int pivot = arr[mid];
    swap(&arr[mid], &arr[right]);
    
	int i = left-1;
	for(int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}
