#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

		fseek(file, 0, SEEK_END);

    	int size = (ftell(file)/2)+0.5;
		int buffer[size];
		printf("size : %d\n", size);
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

		for(int i = 0; i < size; i++){
			printf("%d\n", buffer[i]);
		}
		quickSort(buffer, 0, sizeof(buffer));

		fclose(file);
	}else{
		printf("Erro in arguments!\n");
		return -1;
	}
	return 0;
}

void quickSort(int values[], int left, int right){
	if (left < right) {
		printf("quickSort\n");
		int pivot = partition(values, left, right);
		quickSort(values, left, pivot - 1);
		quickSort(values, pivot + 1, right);	
	}
}

void swap(int* a, int* b){
	printf("swap\n");
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int arr[], int left, int right){
	printf("partition\n");
    int mid = left + (right - left) / 2;
    int pivot = arr[mid];
    
    swap(&arr[mid], &arr[right]);
    
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}
