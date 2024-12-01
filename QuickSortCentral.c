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

		fclose(file);

		clock_t start, end;
		
		start = clock();
		
		quickSort(buffer, 0, size-1);
		
		end = clock();
		
		double result = ((double)(end - start))/CLOCKS_PER_SEC;

		printf("Exec time: %.6f\n", result);
		
		file = fopen("resultado.txt", "w+");
		for(int i = 0; i < size; i++){
			fprintf(file, "%d\n", buffer[i]);
		}
		fclose(file);
		free(buffer);
	}else{
		printf("Erro in arguments!\n");
		return -1;
	}
	return 0;
}

void quickSort(int values[], int left, int right){ // O(log n) chamadas recursivas
	if (left < right) { // O(1) - condição de parada
		int pivot = partition(values, left, right); // O(n) - custo do particionamento
		quickSort(values, left, pivot - 1); // O(log n) - chamada recursiva para o lado esquerdo
		quickSort(values, pivot + 1, right); // O(log n) - chamada recursiva para o lado direito
	}
}

void swap(int* a, int* b){ // O(1) - troca de dois elementos
	int aux = *a; // O(1)
    *a = *b; // O(1)
    *b = aux; // O(1)
}

int partition(int arr[], int left, int right){ // O(n) - custo do particionamento
	int mid = 0; // O(1)
	mid = left+(right-left)/2; // O(1)

    int pivot = arr[mid]; // O(1)
    swap(&arr[mid], &arr[right]); // O(1) - troca o pivô com o último elemento
    
	int i = left-1; // O(1)
	for(int j = left; j < right; j++) { // O(n) - loop que percorre o array
        if (arr[j] <= pivot) { // O(1) - comparação
            i++; // O(1)
            swap(&arr[i], &arr[j]); // O(1) - troca
        }
    }
    
    swap(&arr[i + 1], &arr[right]); // O(1) - troca final
    return i + 1; // O(1)
}
