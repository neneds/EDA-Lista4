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

void mostraCod(noCod *raiz){
  int comp=0;
	
	if(raiz == NULL){
          return;	
        }
            
        mostraCod(raiz->esq);
        printf("\nCodigo do curso %d\n",raiz->valor);
        //printf("Posicao no FTell %ld\n",raiz->posicao);
        mostraCod(raiz->dir);
}

noCod* busca(noCod *raiz, int codigo){
     //N� auxiliar para a pesquisa
    noCod *auxiliar;
	auxiliar=raiz;

	
	while (auxiliar) { 
     if (auxiliar->valor==codigo){ //Faz a compara��o de strings
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
//Estrutura dos n�s para pr�dio
typedef struct noPred{
        struct noPred *esq;
        struct noPred *dir;
        int valorP;
        long int posicaoPred;
}noPred;
 
//Procedimento para inserir n�
void inserirNoPred(noPred **raizPred,int elementoPred,long int posicaoPred){//Recebe o ponteiro da raizPred e o elementoPred
        //Se a raizPred � nula (Primeira vez que for inserir, ou a cada noPredvo elementoPred a inserir), 
		if(*raizPred == NULL) {
            noPred *aux = (noPred *)malloc(sizeof(noPred)); //A cria��o do auxiliar � para fazer as opera��es, para n�o usar a raizPred
            aux->valorP = elementoPred;
            aux->posicaoPred = posicaoPred;
            aux->dir = aux->esq = NULL;  //Os n�s da direita e da esquerda s�o nulos para permitir a inser��o neles depois.
            *raizPred = aux;  //A raizPred vira auxiliar;
            printf("Pr�dio %d foi inserido com sucesso.\n",elementoPred);
            return;
        }
       //Para inserir elementoPreds com uma raizPred n�o nula
        if(elementoPred < (*raizPred)->valorP) {   //O elementoPred a inserir � menor que o valorP do elementoPred contido na raizPred?
            inserirNoPred(&(*raizPred)->esq,elementoPred,posicaoPred);  //Recursividade vai alocar o n� a esquerda
            return;
        }
        if(elementoPred > (*raizPred)->valorP) {//O elementoPred a inserir � maior que o valorP do elementoPred contido na raizPred?
            inserirNoPred(&(*raizPred)->dir,elementoPred,posicaoPred);
            return;
        }
        //Se o elementoPred j� existir na arvore ele vai passar por todos os if's
        printf("Pr�dio %d ja existe na arvore.\n",elementoPred);
}
 
noPred *DoisFilhosPred(noPred *root){
            if(root==NULL) //� nulo
                return NULL;
            else if(root->esq == NULL) //A esquerda do subelementoPred � nula?
                    return root;
            else
                return DoisFilhosPred(root->esq);
}
 
void removerNoPred(noPred **raizPred,int elementoPred)
{
        if(elementoPred < (*raizPred)->valorP){
            removerNoPred(&(*raizPred)->esq,elementoPred);
        }
        else if(elementoPred > (*raizPred)->valorP){
            removerNoPred(&(*raizPred)->dir,elementoPred);
        }
        else if((*raizPred)->esq!=NULL && (*raizPred)->dir!=NULL){//No caso de um n� ter subfilhos dos dois lados 
            noPred *aux= NULL;
            aux = DoisFilhosPred((*raizPred)->dir); //Chama o procedimento dois filhos e aux recebe o valorP de resultado
            (*raizPred)->valorP = aux->valorP;   //Substitui o velor pelo valorP da var auxiliar
            (*raizPred)->posicaoPred = aux->posicaoPred; 
            removerNoPred(&(*raizPred)->dir,(*raizPred)->valorP); //Remove a raizPred
        }
        else {
            noPred *aux = (*raizPred);
            if((*raizPred)->esq==NULL) {
                (*raizPred) = (*raizPred)->dir;
            }
            else {
                *raizPred = (*raizPred)->esq;
            }
            free(aux);
        }
}

void mostraPred(noPred *raizPred){
  int comp=0;
	
	if(raizPred == NULL){
          return;	
        }
            
        mostraPred(raizPred->esq);
        printf("\nPr�dio do curso%d\n",raizPred->valorP);
        //printf("posicaoPred no FTell %ld\n",raizPred->posicaoPred);
        mostraPred(raizPred->dir);
}


