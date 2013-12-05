#include <stdio.h>
#include <stdlib.h>

//Estrutura dos n�s 
typedef struct no{
        struct no *esq;
        struct no *dir;
        int valor;  //Codigo
        char nome[60];
        int predio;
}no;
 
//Procedimento para inserir n�
void inserirNo(no **raiz, int codigo,char curso[],int predio,int op){//Recebe o ponteiro da raiz e o elemento  
	    //Se a raiz � nula (Primeira vez que for inserir, ou a cada novo elemento a inserir), 
		if(*raiz == NULL) {
            no *aux = (no *)malloc(sizeof(no)); //A cria��o do auxiliar � para fazer as opera��es, para n�o usar a raiz
            aux->valor = codigo;
            strcpy(aux->nome,curso);
            aux->predio=predio;
            aux->dir = aux->esq = NULL;  //Os n�s da direita e da esquerda s�o nulos para permitir a inser��o neles depois.
            *raiz = aux;  //A raiz vira auxiliar;
            //printf("Elemento %d\t %s\t %d foi inserido com sucesso.\n",aux->valor,aux->nome,aux->predio);
            return;
        }
       //Para inserir elementos com uma raiz n�o nula
       //Para a arvore de c�digos
       else
       switch(op){
       	 case 1:{
       	 	if(codigo< (*raiz)->valor) {   //O valor do codigo a inserir � menor que o valor do codigo contido na raiz?
	            inserirNo(&(*raiz)->esq,codigo,curso,predio,op);  //Recursividade vai alocar o n� a esquerda
	            return;
            }
             if(codigo> (*raiz)->valor) {//O valor do codigo a inserir a inserir � maior que o valor do elemento contido na raiz?
	            inserirNo(&(*raiz)->dir,codigo,curso,predio,op);
	            return;
            }
       	 	break;
       	 }
       	 case 2:{
       	 	if(strcmp(curso,(*raiz)->nome)<=0) {   //O nome a inserir � menor em compara�ao de string que do nome contido na raiz?
	            inserirNo(&(*raiz)->esq,codigo,curso,predio,op);  //Recursividade vai alocar o n� a esquerda
	            return;
            }
             if(strcmp(curso,(*raiz)->nome)>0) {//O elemento a inserir � maior em compara�ao de string que do nome contido na raiz?
	            inserirNo(&(*raiz)->dir,codigo,curso,predio,op);
	            return;
            }
       	 	break;
       	 }
       	 case 3:{
       	 	if(predio< (*raiz)->predio) {   //O predio a inserir � menor que o valor do elemento contido na raiz?
	            inserirNo(&(*raiz)->esq,codigo,curso,predio,op);  //Recursividade vai alocar o n� a esquerda
	            return;
            }
             if(predio> (*raiz)->predio) {//O predio a inserir � maior que o valor do elemento contido na raiz?
	            inserirNo(&(*raiz)->dir,codigo,curso,predio,op);
	            return;
            }
       	 	break;
       	 }
       };

        //Se o elemento j� existir na arvore ele vai passar por todos os if's
       // printf("Elemento %d ja existe na arvore.\n",codigo);
}

 
no *DoisFilhos(no *raiz){
            if(raiz==NULL) //� nulo
                return NULL;
            else if(raiz->esq == NULL) //A esquerda do subelemento � nula?
                    return raiz;
            else
                return DoisFilhos(raiz->esq);
}
 
void removerNo(no **raiz,int elemento){
	
        if(elemento < (*raiz)->valor){
            removerNo(&(*raiz)->esq,elemento);
        }
        else if(elemento > (*raiz)->valor){
            removerNo(&(*raiz)->dir,elemento);
        }
        else if((*raiz)->esq!=NULL && (*raiz)->dir!=NULL){//No caso de um n� ter subfilhos dos dois lados 
            no *aux= NULL;
            aux = DoisFilhos((*raiz)->dir); //Chama o procedimento dois filhos e aux recebe o valor de resultado
            (*raiz)->valor = aux->valor;   //Substitui o velor pelo valor da var auxilair
            removerNo(&(*raiz)->dir,(*raiz)->valor); //Remove a raiz
        }
        else {
            no *aux = (*raiz);
            if((*raiz)->esq==NULL) {
                (*raiz) = (*raiz)->dir;
            }
            else {
                *raiz = (*raiz)->esq;
            }
            free(aux);
        }
}
 
no *busca(no *raiz,int codigo){
	no *auxiliar;
	auxiliar=raiz;
        
		if(auxiliar!=NULL){
        	if(codigo==auxiliar->valor){
        		return auxiliar;
        	}else
        	if(codigo<auxiliar->valor){
        		return busca(auxiliar->esq,codigo);
        	}
        	else{
        	  return busca(auxiliar->dir,codigo);	
        	}
        	
        }
        printf("\nC�digo n�o encontrado!!!\n\n");
        getch();
        return NULL;
          
}

