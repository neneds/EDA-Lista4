#include <stdio.h>
#include <stdlib.h>

//Estrutura dos n�s para codigo
typedef struct noCod{
        struct noCod *esq;
        struct noCod *dir;
        int valor;
        long int posicao;
}noCod;
 
//Procedimento para inserir n�
void inserirNo(noCod **raiz,int elemento,long int posicao){//Recebe o ponteiro da raiz e o elemento
        //Se a raiz � nula (Primeira vez que for inserir, ou a cada noCodvo elemento a inserir), 
		if(*raiz == NULL) {
            noCod *aux = (noCod *)malloc(sizeof(noCod)); //A cria��o do auxiliar � para fazer as opera��es, para n�o usar a raiz
            aux->valor = elemento;
            aux->posicao = posicao;
            aux->dir = aux->esq = NULL;  //Os n�s da direita e da esquerda s�o nulos para permitir a inser��o neles depois.
            *raiz = aux;  //A raiz vira auxiliar;
            printf("Elemento %d foi inserido com sucesso.\n",elemento);
            return;
        }
       //Para inserir elementos com uma raiz n�o nula
        if(elemento < (*raiz)->valor) {   //O elemento a inserir � menor que o valor do elemento contido na raiz?
            inserirNo(&(*raiz)->esq,elemento,posicao);  //Recursividade vai alocar o n� a esquerda
            return;
        }
        if(elemento > (*raiz)->valor) {//O elemento a inserir � maior que o valor do elemento contido na raiz?
            inserirNo(&(*raiz)->dir,elemento,posicao);
            return;
        }
        //Se o elemento j� existir na arvore ele vai passar por todos os if's
        printf("Elemento %d ja existe na arvore.\n",elemento);
}
 
noCod *DoisFilhosCod(noCod *root){
            if(root==NULL) //� nulo
                return NULL;
            else if(root->esq == NULL) //A esquerda do subelemento � nula?
                    return root;
            else
                return DoisFilhosCod(root->esq);
}
 
void removerNo(noCod **raiz,int elemento)
{
        if(elemento < (*raiz)->valor){
            removerNo(&(*raiz)->esq,elemento);
        }
        else if(elemento > (*raiz)->valor){
            removerNo(&(*raiz)->dir,elemento);
        }
        else if((*raiz)->esq!=NULL && (*raiz)->dir!=NULL){//No caso de um n� ter subfilhos dos dois lados 
            noCod *aux= NULL;
            aux = DoisFilhosCod((*raiz)->dir); //Chama o procedimento dois filhos e aux recebe o valor de resultado
            (*raiz)->valor = aux->valor;   //Substitui o velor pelo valor da var auxiliar
            (*raiz)->posicao = aux->posicao; 
            removerNo(&(*raiz)->dir,(*raiz)->valor); //Remove a raiz
        }
        else {
            noCod *aux = (*raiz);
            if((*raiz)->esq==NULL) {
                (*raiz) = (*raiz)->dir;
            }
            else {
                *raiz = (*raiz)->esq;
            }
            free(aux);
        }
}
/*/
void pesquisaCod(noCod *raiz){

	
	if(raiz == NULL){
          return;	
        }
            
        pesquisaCod(raiz->esq);
        printf("%d\n",raiz->valor);
        printf("Posicao no FTell %ld\n",raiz->posicao);
        pesquisaCod(raiz->dir);
}
/*/
noCod* busca(noCod *raiz, int codigo){
     //N� auxiliar para a pesquisa
    noCod *auxiliar;
	auxiliar=raiz;
	
	while (auxiliar) { 
            
      if (auxiliar->valor=codigo){ //Faz a compara��o de strings
	    return auxiliar;
	  } 
            
       else
         if(auxiliar->dir!=NULL){
         	auxiliar=auxiliar->dir;
         }
        else
         if(auxiliar->esq!=NULL){
         	auxiliar=auxiliar->esq;
         }

    }
}
//__________________________________Fim da parte da �rvore para codigo ______________________________________________________________________________________/*/

