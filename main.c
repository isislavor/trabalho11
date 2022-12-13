#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

//Função de comparação dos ponteiros
int myCOMP(void* x, void* y){
	int ptx = *((int*)x);
	int pty = *((int*)y);
	if(ptx - pty < 5){
		return -1;
	}else{
		if(ptx - pty > 5) return 1;
		else return 0;
	}
}

//Função para imprimir a estrutura do vetor
void print(void** vet, int P){
	int i;
	printf("VETOR DE %d TAMANHO:\n", P);
	for(i = 0; i < P; i++){
		printf(" %d ", *((int*)vet[i]));
	}
	printf("\n");
}

int main(){
   	VETORORD* vet = VETORD_create(10, myCOMP);
   	
   	int* x;
   	int i;
   	
   	printf("INCLUINDO... \n");
	for(i = 0; i < vet->N; i++){
		x = malloc(sizeof(int));
		*x = i*10;
		VETORD_add(vet, x);
	}
	
	print(vet->elems, vet->P);
  
  	printf("REMOVENDO!");
  	VETORD_remove(vet);
  	
	print(vet->elems, vet->P);
   
	return 0;  
}


#include <time.h>
int comparar(void* x, void* y) {
	int intX = *((int*) x);
	int intY = *((int*) y);
	if (intX < intY) {
		return 1;
	} else if(intX == intY) {
		return 0;
	} 
	
	return -1;
}
int main() {
	int VETOR_SIZE = 0;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &VETOR_SIZE);
	VETORORD* vector = VETORD_create(VETOR_SIZE, comparar);
	int numbers[VETOR_SIZE];
	double time_spent = 0.0;
  clock_t begin = clock();

  
  //adicionar elementos
	for (int i = 0; i < VETOR_SIZE; i++) {
		int temp;
		printf("Digite algo: ");
		scanf("%d", &temp);
		numbers[i] = temp;
		VETORD_add(vector, &numbers[i]);
	}
	
	printf("VETOR ORIGINAL: ");
	for (int i = 0; i < vector->P; i++) {
		printf("%d - ", *((int*) vector->elems[i]));
	}
	printf("FIM\n");
  remover elementos
	for (int i = 0; i < 5; i++) {
		VETORD_remove(vector);
	}
	printf("LISTA FINAL: ");
	for (int i = 0; i < vector->P; i++) {
		printf("%d - ", *((int*) vector->elems[i]));
	}
	printf("FIM\n");
	clock_t end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nTempo decorrido: %lf segundos!\n", time_spent);
	return 0;
}
*/