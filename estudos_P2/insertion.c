#include <stdio.h>

void imprimeVetor(int *v){

    for(int i=0; i<6; i++){
        printf("|%d| ", v[i]);
    }
}

void insertionSort(int *v, int n){
    int aux;
    int j;

    for (int i=1; i<n; i++){
        aux = v[i];
        j = i-1;

        while (j>=0 && aux<v[j]){
            v[j+1] = v[j];
            j=j-1;
        }
        v[j+1]=aux;
    }
}

// void insertionSort(int *v, int n){
//     int aux;
//     int j;

//     for (int i=1; i<n; i++){
//         aux = v[i];
//         j = i-1;
//         printf("______________________________________________");
//         printf("\n i=%d\n j=%d\n aux=%d\n v[%d]=%d\n\n" ,i,j,aux,j,v[j]);

       
//         while (j>=0 && aux<v[j]){
            
//             printf("Entrei aqui e vou arredar!!!\n");
//             v[j+1] = v[j];
//             j=j-1;
//             printf("\n");
//         }
//         v[j+1]=aux;
//         imprimeVetor(v);
//         printf("vetor arrastado para o valor de i=%d\n", i);
//         printf("\n");
//     }
// }

int main(){
    int v[6];
    v[0]=5;
    v[1]=7;
    v[2]=6;
    v[3]=2;
    v[4]=1;
    v[5]=0;

    insertionSort(v,6);
    printf("\nvetor ordenado: ");
    imprimeVetor(v);
    printf("\n");

    return 0;
}