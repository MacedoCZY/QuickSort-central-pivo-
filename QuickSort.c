#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc == 2){
		FILE *file = fopen(argv[1], "rb");
		
		if(file == NULL){
			printf("Erro open archive!\n");
			return -1;
		}

		fseek(file, 0, SEEK_END);

    	int size = ftell(file);
		char buffer[size];
		int work[size];

		fseek(file, 0, SEEK_SET);

		printf("Size %d\n", size);

		int i = 0;
		while(feof(file) == 0) {
        	fread(buffer, sizeof(char), sizeof(buffer), file);
			work[i] = atoi(buffer);
			printf("%s", buffer);
			i++;
    	}


		fclose(file);
	}else{
		printf("Erro in arguments!\n");
		return -1;
	}
	return 0;
}
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    // Escolhendo o pivô como o elemento central
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];
    
    // Movendo o pivô para o final
    swap(&arr[mid], &arr[high]);
    
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    // Colocando o pivô de volta na posição correta
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        // Recursivamente ordena os elementos antes e depois da partição
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: \n");
    printArray(arr, n);
    
    quicksort(arr, 0, n - 1);
    
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}