#include <stdio.h>
#include <stdlib.h>

//Estrutura dos nós para codigo
typedef struct noCod{
        struct noCod *esq;
        struct noCod *dir;
        int valor;
        long int posicao;
}noCod;
 
//Procedimento para inserir nó
void inserirNo(noCod **raiz,int elemento,long int posicao){//Recebe o ponteiro da raiz e o elemento
        //Se a raiz é nula (Primeira vez que for inserir, ou a cada noCodvo elemento a inserir), 
		if(*raiz == NULL) {
            noCod *aux = (noCod *)malloc(sizeof(noCod)); //A criação do auxiliar é para fazer as operações, para não usar a raiz
            aux->valor = elemento;
            aux->posicao = posicao;
            aux->dir = aux->esq = NULL;  //Os nós da direita e da esquerda são nulos para permitir a inserção neles depois.
            *raiz = aux;  //A raiz vira auxiliar;
            printf("Elemento %d foi inserido com sucesso.\n",elemento);
            return;
        }
       //Para inserir elementos com uma raiz não nula
        if(elemento < (*raiz)->valor) {   //O elemento a inserir é menor que o valor do elemento contido na raiz?
            inserirNo(&(*raiz)->esq,elemento,posicao);  //Recursividade vai alocar o nó a esquerda
            return;
        }
        if(elemento > (*raiz)->valor) {//O elemento a inserir é maior que o valor do elemento contido na raiz?
            inserirNo(&(*raiz)->dir,elemento,posicao);
            return;
        }
        //Se o elemento já existir na arvore ele vai passar por todos os if's
        printf("Elemento %d ja existe na arvore.\n",elemento);
}
 
noCod *DoisFilhosCod(noCod *root){
            if(root==NULL) //É nulo
                return NULL;
            else if(root->esq == NULL) //A esquerda do subelemento é nula?
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
        else if((*raiz)->esq!=NULL && (*raiz)->dir!=NULL){//No caso de um nó ter subfilhos dos dois lados 
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
     //Nó auxiliar para a pesquisa
    noCod *auxiliar;
	auxiliar=raiz;

	
	while (auxiliar) { 
     if (auxiliar->valor==codigo){ //Faz a comparação de strings
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
//__________________________________Fim da parte da árvore para codigo ______________________________________________________________________________________/*/
//Estrutura dos nós para prédio
typedef struct noPred{
        struct noPred *esq;
        struct noPred *dir;
        int valorP;
        long int posicaoPred;
}noPred;
 
//Procedimento para inserir nó
void inserirNoPred(noPred **raizPred,int elementoPred,long int posicaoPred){//Recebe o ponteiro da raizPred e o elementoPred
        //Se a raizPred é nula (Primeira vez que for inserir, ou a cada noPredvo elementoPred a inserir), 
		if(*raizPred == NULL) {
            noPred *aux = (noPred *)malloc(sizeof(noPred)); //A criação do auxiliar é para fazer as operações, para não usar a raizPred
            aux->valorP = elementoPred;
            aux->posicaoPred = posicaoPred;
            aux->dir = aux->esq = NULL;  //Os nós da direita e da esquerda são nulos para permitir a inserção neles depois.
            *raizPred = aux;  //A raizPred vira auxiliar;
            printf("Prédio %d foi inserido com sucesso.\n",elementoPred);
            return;
        }
       //Para inserir elementoPreds com uma raizPred não nula
        if(elementoPred < (*raizPred)->valorP) {   //O elementoPred a inserir é menor que o valorP do elementoPred contido na raizPred?
            inserirNoPred(&(*raizPred)->esq,elementoPred,posicaoPred);  //Recursividade vai alocar o nó a esquerda
            return;
        }
        if(elementoPred > (*raizPred)->valorP) {//O elementoPred a inserir é maior que o valorP do elementoPred contido na raizPred?
            inserirNoPred(&(*raizPred)->dir,elementoPred,posicaoPred);
            return;
        }
        //Se o elementoPred já existir na arvore ele vai passar por todos os if's
        printf("Prédio %d ja existe na arvore.\n",elementoPred);
}
 
noPred *DoisFilhosPred(noPred *root){
            if(root==NULL) //É nulo
                return NULL;
            else if(root->esq == NULL) //A esquerda do subelementoPred é nula?
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
        else if((*raizPred)->esq!=NULL && (*raizPred)->dir!=NULL){//No caso de um nó ter subfilhos dos dois lados 
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
        printf("\nPrédio do curso%d\n",raizPred->valorP);
        //printf("posicaoPred no FTell %ld\n",raizPred->posicaoPred);
        mostraPred(raizPred->dir);
}


