#include <stdio.h>
#include <stdlib.h>

float* reverso(int n, float* v);

float* reverso(int n, float* v){
    float* v2 = (float* ) malloc(n * sizeof(float));

    if(v==NULL){
        printf("Memoria insuficiente.\n");
        exit(0);
    }

    for (int i = 0 ; i < n; i++){
        v2[i]=v[n-i-1];
    }
    return v2;
}

int main(){
    float *v, *v2;
    int n;

    printf("Digite a quantidade de posicoes do vetor: ");
    scanf("%i",&n);

    v = (float*) malloc(n * sizeof(float));//alocando memoria para o vetor
    if(v==NULL){
        printf("Memoria insuficiente.\n");
        return 1;
    }

    for (int i=0; i<n; i++){ //lendo o vetor
        printf("Posicao %i:",i+1);
        scanf("%f", &v[i]);
    }

    v2=reverso(n,v);

    printf("O vetor invertido eh:\n");
    for (int i=0; i<n; i++){
       printf("|%.0f\n", v2[i]);
    }

    free(v);
    free(v2);
    return 0;
}
