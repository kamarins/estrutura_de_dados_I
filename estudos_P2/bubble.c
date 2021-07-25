#include <stdio.h>

void imprimeVetor(int *v){

    for(int i=0; i<6; i++){
        printf("|%d| ", v[i]);
    }
}

//código sem printf
void bubblesort(int *v, int n){
    int aux; 
    int troca = 0;
    for (int i=0;i<n;i++){
        for (int j=1; j < n-i; j++){

            if(v[j] < v[j-1]){
               
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
                troca++;
            }
            
        }
        if (troca == 0){
            return ;
        }
    }

}

// void bubblesort(int *v, int n){
//     int aux; 
//     int troca = 0;
//     for (int i=0;i<n;i++){
//         printf("Inicia Iteracao!!!!!\n");
//         imprimeVetor(v);
//         printf("\n i= %d",i);

//         for (int j=1; j < n-i; j++){
//             printf("\n j=%d,",j);
//             printf(" v[%d]=%d",j,v[j]);

//             printf("\n j-1= %d,",j-1);
//             printf(" v[%d]= %d\n\n",j-1,v[j-1]);

//             if(v[j] < v[j-1]){
//                 printf("TROCA!\n");
//                 aux = v[j];
//                 v[j] = v[j-1];
//                 v[j-1] = aux;

//                 imprimeVetor(v);

//             }
            
//         }
//         if (troca == 0){
//             printf("ja ta ordenado!");
//             return ;
//         }

//     }
// }



int main(){
    int v[6];
    v[0]=1;
    v[1]=2;
    v[2]=3;
    v[3]=4;
    v[4]=5;
    v[5]=6;

    bubblesort(v,6);
    printf("\nvetor ordenado: ");
    imprimeVetor(v);
    printf("\n");
    return 0;

}
