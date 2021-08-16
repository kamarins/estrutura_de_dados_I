#include "aula11_vetor.h"
//implementação por vetor
void Pilha_Inicia(Pilha * pilha){
    pilha->tamanho = 0;
}

int Pilha_Eh_Vazia(Pilha *pilha){
    if (pilha->tamanho == 0)
        return 1; //a pilha esta vazia
    
    return 0;
}

 //inserir
int Pilha_Push(Pilha *pilha, Item item){ 
    
    //verificar se o tamanho da pilha é menos que o tamanho maximo
    //se sim, insere o item, se nao, retorna 0
    if(pilha->tamanho < N){
        pilha->itens[pilha->tamanho++]  = item; //adiciona-se o item na ultima posicao, por isso utiliza o pilha->tamanho
        //pilha->tamanho++; ->>> executa e dps atualiza

        return 1;
    }

    return 0;
   
}

int Pilha_Pop(Pilha *pilha, Item *item){ //remove elemento

    if(Pilha_Eh_Vazia(pilha)){
        return 0;
    }

    //pilha->tamanho--; 
    (*item) = pilha->itens[--pilha->tamanho]; //executa a subtracao em pilha tamanho e dps executa a operacao
    

    return 1;
}
void Pilha_Tamanho(Pilha *pilha){
    return pilha->tamanho;
}
