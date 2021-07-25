#include <stdio.h>


void imprimeVetor(int *v, int n){

    for(int i=0; i<n; i++){
        printf("|%d| ", v[i]);
    }
    printf("\n");
}

void shellSort(int *v, int n){
    int h,aux,j;
    for ( h=1; h<n;){
        h = (3*h) + 1; //valor inicial de h
    }
    printf("O vetor inicial eh:");
    imprimeVetor(v,7);
    printf("\nh = %d", h);
    do{
        h = (h-1)/3; //atualiza h
        printf("\nnovo h= %d\n\n",h);
        for(int i=h; i<n; i++){
            aux = v[i];
            j=i;
            while (v[j-h] > aux){
        
                v[j] = v[j - h];
                j = j - h;

                if (j < h){
                    break;
                }
            }
            v[j]= aux;
             imprimeVetor(v,7);
            
        }
    } while (h != 1);

}



// void shellSort(int *v, int n){
//     int h,aux,j;
//     for ( h=1; h<n;){
//         h = (3*h) + 1; //valor inicial de h
//     }

//     do{
//         h = (h-1)/3; //atualiza h
//         for(int i=h; i<n; i++){
//             aux = v[i];
//             j=i;
//             while (v[j-h] > aux){
//                 v[j] = v[j - h];
//                 j = j - h;

//                 if (j < h){
//                     break;
//                 }
//             }
//             v[j]= aux;
//         }
//     } while (h != 1);

// }


int main(){
    int v[7];

    v[0]=3;
    v[1]=4;
    v[2]=9;
    v[3]=2;
    v[4]=5;
    v[5]=1;
    v[6]=8;
    

    shellSort(v,7);
    printf("\nvetor ordenado: ");
    imprimeVetor(v,7);
    printf("\n");


    return 0;
}