#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *v, int n){

    for(int i=0; i<n; i++){
        printf("|%d| ", v[i]);
    }
    printf("\n");
}


//l = left
//r = rigth

// void merge(int *v, int l, int m, int r){
//     int size_l;
//     int size_r;
//     int i,j,k;

//     size_l = (m - l + 1);
//     size_r = (r - m);

//     printf("size_l = %d \n", size_l);
//     printf("size_r = %d \n", size_r);
//     printf("\n");

//     int *vet_l = (int*) malloc (size_l * sizeof(int));
//     int *vet_r = (int*) malloc (size_r * sizeof(int));

//     for (i=0; i<size_l;i++){
//         vet_l[i]=v[i+l];
//     }

//     printf("vetor l: ");
//     imprimeVetor(vet_l,size_l);
//     printf("\n");

//     for (j=0; j<size_r;j++){
//         vet_r[j]=v[m+j+1];
//     }
    
//     printf("vetor r: ");
//     imprimeVetor(vet_r,size_r);
//     printf("\n");
//     i=0;
//     j=0;

//     for (k=l; k<=r;  k++){

//         if (i == size_l){
//             v[k]=vet_r[j++];
//             imprimeVetor(v,7);
//             printf("sai 1 if\n\n");
//         }
//         else if(j == size_r){
//             v[k]= vet_l[i++];
//             imprimeVetor(v,7);
//             printf("sai 2 if\n\n");
//         }
//         else if(vet_l[i] < vet_r[j]){
//             v[k]= vet_l[i++];
//             imprimeVetor(v,7);
//             printf("sai 3 if \n\n");
//         }
//         else {
//             v[k]=vet_r[j++];
//             imprimeVetor(v,7);
//              printf("sai 4 if\n\n");
//         }
//     }

//     free(vet_l);
//     free(vet_r);

// } 

// void mergesort(int *v, int l, int r){
//     int m;
//     if (l<r){
//         m = (l+r)/2;
//         printf("m = %d,",m);
//         printf("l = %d,",l);
//         printf("r = %d\n\n",r);

//         mergesort(v,l,m);
//         printf("__________________________________________________\n");

//         mergesort(v,m+1,r);
//         printf("__________________________________________________\n");
//         merge(v,l,m,r);
//     }
// }

void merge(int *v, int l, int m, int r){
    int size_l;
    int size_r;
    int i,j,k;

    size_l = (m - l + 1);
    size_r = (r - m);

    int *vet_l = (int*) malloc (size_l * sizeof(int));
    int *vet_r = (int*) malloc (size_r * sizeof(int));

    for (i=0; i<size_l;i++){
        vet_l[i]=v[i+l];
    }

    for (j=0; j<size_r;j++){
        vet_r[j]=v[m+j+1];
    }
    

    i=0;
    j=0;

    for ( k = l; k <= r;  k++){

        if (i == size_l){
            v[k]=vet_r[j++];
        }
        else if(j == size_r){
            v[k]= vet_l[i++];
        }
        else if(vet_l[i] < vet_r[j]){
            v[k]= vet_l[i++];

        }
        else {
            v[k]=vet_r[j++];

        }
    }

    free(vet_l);
    free(vet_r);

} 


void mergesort(int *v, int l, int r){
    int m;
    if (l<r){
        m = (l+r)/2;

        mergesort(v,l,m);
        mergesort(v,m+1,r);
        merge(v,l,m,r);
    }
}

int main(){
    int v[7];

    v[0]=4;
    v[1]=0;
    v[2]=5;
    v[3]=7;
    v[4]=9;
    v[5]=1;
    v[6]=3;
    v[7]=2;

    mergesort(v,0,6);
    printf("\nvetor ordenado: ");
    imprimeVetor(v,8);
    printf("\n");
    return 0;

}