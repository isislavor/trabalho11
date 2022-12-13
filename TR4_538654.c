#include "ordvetor.h"

VETORORD*VETORD_create(int n,COMP*compara){
    VETORORD*vetor=malloc(sizeof(VETORORD));
    vetor->N=n;
    vetor->P=0;
    vetor->elems=malloc(n*sizeof(void*));
    vetor->comparador=compara;
    return vetor;
}

void VETORD_add(VETORORD* vetor, void* newelem) {
	if (vetor->P < vetor->N) {
		int posicao = vetor->P;

		for (int i = 0; i < vetor->P; i++) {
			if (vetor->comparador(vetor->elems[i], newelem) == -1) {
				posicao = i;
				break;
			}
		}

		for (int i = vetor->P; i > posicao; i--) {
			vetor->elems[i-1] = vetor->elems[i];
		}

		vetor->elems[posicao] = newelem;
		vetor->P++;
	}	
}
void* VETORD_remove(VETORORD* vetor) {
	void* menor = vetor->elems[0];

	for (int i = 0;i < vetor->P - 1;i++){
		vetor->elems[i] = vetor->elems[i + 1];
        }
	
	vetor->P--;

	return menor;
}
