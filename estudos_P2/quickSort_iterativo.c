#include <stdio.h>
#include <stdlib.h>



void imprimeVetor(int *v, int n){

    for(int i=0; i<n; i++){
        printf("|%d| ", v[i]);
    }
    printf("\n");
}

int partition(int *v, int l, int r){
    int x,i,j,aux;

    x = v[r];
    i = l-1;

    for (j = l; j < r; j++){
        if (v[j] <= x){
            i = i+1;
            aux = v[j];
            v[j] = v[i];
            v[i] = aux;
        }
    }

    aux = v[i+1];
    v[i+1] = v[r];
    v[r] = aux;

    return i+1;
}


// void quickSort(int *v, int l, int r){
//     int t,j;

//     int *pilha_l = (int*) malloc ((r-l+1)* sizeof(int));
//     int *pilha_r = (int*) malloc ((r-l+1) * sizeof(int));

//     pilha_l[0]=l;
//     pilha_r[0]=r;
//     t=0;
    
//     printf("\npilha_l: ");
//     for(int i=0;i<1;i++){
//         printf("|%d| ",pilha_l[i]);
//     }

//     printf("\npilha_l: ");
//     for(int i=0;i<1;i++){
//         printf("|%d| ",pilha_r[i]);
//     }
//     printf("\ncomecando\n________________________________________________________\n");
//     while (t >= 0){
//         l = pilha_l[t];
//         r = pilha_r[t];
//         t--;
//         printf("\nt=%d\n",t);
//         printf("ja incrementou l e r:\n");
//         printf("l:%d e r:%d\n",l,r);
//         printf("\npilha_l: ");
//         for(int i=0;i<5;i++){
//             printf("|%d| ",pilha_l[i]);
//         }

//         printf("\npilha_l: ");
//         for(int i=0;i<5;i++){
//             printf("|%d| ",pilha_r[i]);
//         }

//         if (l<r){
//             j = partition(v,l,r);

//             t++;
//             pilha_l[t]=l;
//             pilha_r[t]=j-1;
//             printf("\nt=%d\n",t);
//             printf("\npilha_l: ");
//             for(int i=0;i<5;i++){
//                 printf("|%d| ",pilha_l[i]);
//             }
//             printf("\npilha_l: ");
//             for(int i=0;i<5;i++){
//                 printf("|%d| ",pilha_r[i]);
//             }


//             t++;
//             pilha_l[t]=j+1;
//             pilha_r[t]=r;
//             printf("\nt=%d\n",t);
//             printf("\npilha_l: ");
//             for(int i=0;i<5;i++){
//                 printf("|%d| ",pilha_l[i]);
//             }

//             printf("\npilha_l: ");
//             for(int i=0;i<5;i++){
//                 printf("|%d| ",pilha_r[i]);
//             }
//         }
//         printf("\n\nfinaliza o while!\n\n");
//         printf("\n________________________________________________________\n");
//     }

//     free(pilha_l);
//     free(pilha_r);
// }



void quickSort(int *v, int l, int r){
    int t,j;

    int *pilha_l = (int*) malloc ((r-l+1)* sizeof(int));
    int *pilha_r = (int*) malloc ((r-l+1) * sizeof(int));

    pilha_l[0]=l;
    pilha_r[0]=r;
    t=0;

    while (t >= 0){
        l = pilha_l[t];
        r = pilha_r[t];
        t--;

        if (l<r){
            j = partition(v,l,r);

            t++;
            pilha_l[t]=l;
            pilha_r[t]=j-1;

            t++;
            pilha_l[t]=j+1;
            pilha_r[t]=r;
        }
    }

    free(pilha_l);
    free(pilha_r);
}

int main(){
    int v[7];

    v[0]=3;
    v[1]=4;
    v[2]=9;
    v[3]=2;
    v[4]=5;
    v[5]=1;
    v[6]=8;
    

    quickSort(v,0,6);
    printf("\nvetor ordenado: ");
    imprimeVetor(v,7);
    printf("\n");

    return 0;
} 
