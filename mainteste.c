#include<stdio.h>
#include<stdlib.h>
#include"ordvetor.h"


int comparacao(void*x,void*y){
    int xi=*((*int))x;
    int yi=*((*int)y);
    if (xi<yi){
        return 1;
    }
    else if(xi==yi){
        return 0;
    }
    else{
        return -1;
    }
}

int main (){
    const int vetortam =10;
    const int vetorremocao=2;

    VETORORD*vetor = VETORD_create(vetortam,comparacao);
    int vetorzinho[vetortam];

    printf("VETOR INICIALIZADO:");
    for (int i =0;i<vetortam;i++){
        vetorzinho[i]=rand()%vetortam;
        printf("%d-"vetorzinho[i]);
        }
        printf("FIM:)\n");

    for(int i=0;i<vetortam;i++){
        VETORD_add(vetor,&vetorzinho[i]);
    }
    printf("ITENS REMOVIDOS:");
    for (int=0;i<vetorremocao;i++){
        printf("%d-",*((int*)VETORD_remove(vetor)));
    }
    printf("FIM\n\n");

    printf("VETOR FINAL:");
    for(int i=0;i<vetor->P;i++){
        printf("%d-",*((int*)vetor->elems[i]));
    }
    printf("FIM\n");

    return 0;
}