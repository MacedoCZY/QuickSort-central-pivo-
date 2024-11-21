#include <stdio.h>
int main(int argc, char *argv[]){
	//printf("%d\n", argc);
	if(argc == 2){
		FILE *file = fopen(argv[1], "r");
		if(file == NULL){
			printf("Erro open archive!\n");
			return -1;
		}
		
		int buffer;
		while(feof(file) == 0){
			fread(&buffer, sizeof(int), 1, file);
			printf("%d\n", buffer);
		}

		fclose(file);
	}else{
		printf("Erro in arguments!\n");
		return -1;
	}
}
