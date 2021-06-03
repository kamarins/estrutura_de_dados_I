#include <stdio.h>
int main()
{
    double M[12][12];//utilize esta matriz para ler os 144 numeros reais
    double soma=0.0, media=0.0;
    char O;
    int i,j,limite=11;

    scanf("%s", &O);

    for (i = 0; i <= 11; i++){
        for (j=0; j<= 11; j++){
            scanf("%lf", &M[i][j]);
        }
    }

    for(i=0; i<= 4 ; i++){
        for (j=i+1;j<limite;j++){
            soma += M[i][j];
        }
        limite--;
    }
        
    if ( O == 'S'){
        printf("%.1lf\n", soma);
    } else if (O == 'M'){
            media = soma / 30.0;
            printf("%.1lf\n", media);
        }


    return 0;//não remova
}
