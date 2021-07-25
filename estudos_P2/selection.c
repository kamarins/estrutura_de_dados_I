#include <stdio.h>

void imprimeVetor(int *v){

    for(int i=0; i<6; i++){
        printf("|%d| ", v[i]);
    }
}

void selectionSort(int *v, int n){
    int min;
    int aux;
    
    for (int i=0; i<n; i++){
        min = i;

        for (int j=i+1; j < n; j++){

            if(v[j] < v[min]){
             //pega o menor valor do vetor
               min = j;
            }
        
        }
        if( i != min){
            aux = v[i];
            v[i] = v[min];
            v[min] = aux;
        }

        
    }
}


// void selectionSort(int *v, int n){
//     int min;
//     int aux;
    
//     for (int i=0; i<n; i++){
//         printf("\n\nInicia Iteracao!!!!!\n");
//         imprimeVetor(v);
//         min = i;
//         printf("\no menor valor é o valor da posicao i: v[%d] = %d\n\n",min, v[min]);
//         for (int j=i+1; j < n; j++){

//             printf("estamos em v[%d]= %d \n", j ,v[j]);
//             printf("e v[min] esta em v[%d]=%d",min,v[min]);
            

//             if(v[j] < v[min]){
//                 //pega a posicao do menor valor do vetor
             
//                 printf("\n\nTroca a posicao do menor valor,");
//                 min = j;
//             }

//             printf("\n o menor valor esta em: v[%d]= %d \n\n",min,v[min]);
//         }

//         printf("TROCA!\n");
//         aux = v[i];
//         v[i] = v[min];
//         v[min] = aux;
//         imprimeVetor(v);
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

    selectionSort(v,6);
    printf("\nvetor ordenado: ");
    imprimeVetor(v);
    printf("\n");
    
    return 0;
}