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
 
noCod *DoisFilhos(noCod *root){
            if(root==NULL) //É nulo
                return NULL;
            else if(root->esq == NULL) //A esquerda do subelemento é nula?
                    return root;
            else
                return DoisFilhos(root->esq);
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
            aux = DoisFilhos((*raiz)->dir); //Chama o procedimento dois filhos e aux recebe o valor de resultado
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

void pesquisaOrdemSimetrica(noCod *raiz){

	
	if(raiz == NULL){
          return;	
        }
            
        pesquisaOrdemSimetrica(raiz->esq);
        printf("%d\n",raiz->valor);
        pesquisaOrdemSimetrica(raiz->dir);
}

/*/
void mostrar(long int posicaoPesq,FILE *arqTex){
	char bufferLeitura[1000];
	
	//Ler 
	fseek(arqTex,posicaoPesq,0);
    fgets(bufferLeitura,1000,arqTex);
    printf("\n\nInformações encontradas:\n");
    printf("\n\n\%s\n\n",bufferLeitura);
    
}
 
 /*/
//__________________________________Fim da parte da árvore para codigo ______________________________________________________________________________________
/*/
//Estrutura dos nós para nome
typedef struct noNome{
        struct noNome *esq;
        struct noNome *dir;
        char nome[50];
        long int posicao;
}noNome;
 
//Procedimento para inserir nó
void inserirNo(noNome **raiz,char elemento,long int posicao){//Recebe o ponteiro da raiz e o elemento
        //Se a raiz é nula (Primeira vez que for inserir, ou a cada noCodvo elemento a inserir), 
		if(*raiz == NULL) {
            noNome *aux = (noNome *)malloc(sizeof(noNome)); //A criação do auxiliar é para fazer as operações, para não usar a raiz
            strcpy(aux->nome,elemento);
            aux->posicao = posicao;
            aux->dir = aux->esq = NULL;  //Os nós da direita e da esquerda são nulos para permitir a inserção neles depois.
            *raiz = aux;  //A raiz vira auxiliar;
            printf("Elemento %s foi inserido com sucesso.\n",elemento);
            return;
        }
       //Para inserir elementos com uma raiz não nula
        if(elemento < (*raiz)->valor) {   //O elemento a inserir é menor que o valor do elemento contido na raiz?
            inserirNo(&(*raiz)->esq,elemento);  //Recursividade vai alocar o nó a esquerda
            return;
        }
        if(elemento > (*raiz)->valor) {//O elemento a inserir é maior que o valor do elemento contido na raiz?
            inserirNo(&(*raiz)->dir,elemento);
            return;
        }
        //Se o elemento já existir na arvore ele vai passar por todos os if's
        printf("Elemento %d ja existe na arvore.\n",elemento);
}
 
noNome *DoisFilhos(noNome *root){
            if(root==NULL) //É nulo
                return NULL;
            else if(root->esq == NULL) //A esquerda do subelemento é nula?
                    return root;
            else
                return DoisFilhos(root->esq);
}
 
void removerNo(noNome **raiz,char elemento)
{
        if(elemento < (*raiz)->valor){
            removerNo(&(*raiz)->esq,elemento);
        }
        else if(elemento > (*raiz)->valor){
            removerNo(&(*raiz)->dir,elemento);
        }
        else if((*raiz)->esq!=NULL && (*raiz)->dir!=NULL){//No caso de um nó ter subfilhos dos dois lados 
            noNome *aux= NULL;
            aux = DoisFilhos((*raiz)->dir); //Chama o procedimento dois filhos e aux recebe o valor de resultado
            (*raiz)->valor = aux->valor;   //Substitui o velor pelo valor da var auxilair
            removerNo(&(*raiz)->dir,(*raiz)->valor); //Remove a raiz
        }
        else {
            noNome *aux = (*raiz);
            if((*raiz)->esq==NULL) {
                (*raiz) = (*raiz)->dir;
            }
            else {
                *raiz = (*raiz)->esq;
            }
            free(aux);
        }
}
 
void pesquisaOrdemSimetrica(noNome *raiz)
{
        if(raiz == NULL)
            return;
        pesquisaOrdemSimetrica(raiz->esq);
        printf("%d\n",raiz->valor);
        pesquisaOrdemSimetrica(raiz->dir);
}
 
void pesquisaPosOrdem(noNome *raiz)
{
        if(raiz == NULL)
            return;
        pesquisaPosOrdem(raiz->esq);
        pesquisaPosOrdem(raiz->dir);
        printf("%d\n",raiz->valor);
}
 
void pesquisaPreOrdem(noNome *raiz)
{
        if(raiz == NULL)
            return;
        printf("%d\n",raiz->valor);
        pesquisaPreOrdem(raiz->esq);
        pesquisaPreOrdem(raiz->dir);
}

//________________________________________________Fim da parte da árvore por nome ___________________________________________________________________________
//Estrutura dos nós para codigo
typedef struct noPred{
        struct noCod *esq;
        struct noCod *dir;
        int valorPred;
        long int posicao;
}noPred;
 
//Procedimento para inserir nó
void inserirNo(noPred **raiz,int elemento,long int posicao){//Recebe o ponteiro da raiz e o elemento
        //Se a raiz é nula (Primeira vez que for inserir, ou a cada noCodvo elemento a inserir), 
		if(*raiz == NULL) {
            noPred *aux = (noPred *)malloc(sizeof(noPred)); //A criação do auxiliar é para fazer as operações, para não usar a raiz
            aux->valorPredPred = elemento;
            aux->posicao = posicao;
            aux->dir = aux->esq = NULL;  //Os nós da direita e da esquerda são nulos para permitir a inserção neles depois.
            *raiz = aux;  //A raiz vira auxiliar;
            printf("Elemento %d foi inserido com sucesso.\n",elemento);
            return;
        }
       //Para inserir elementos com uma raiz não nula
        if(elemento < (*raiz)->valorPred) {   //O elemento a inserir é menor que o valor do elemento contido na raiz?
            inserirNo(&(*raiz)->esq,elemento);  //Recursividade vai alocar o nó a esquerda
            return;
        }
        if(elemento > (*raiz)->valorPred) {//O elemento a inserir é maior que o valor do elemento contido na raiz?
            inserirNo(&(*raiz)->dir,elemento);
            return;
        }
        //Se o elemento já existir na arvore ele vai passar por todos os if's
        printf("Elemento %d ja existe na arvore.\n",elemento);
}
 
noCod *DoisFilhos(noCod *root){
            if(root==NULL) //É nulo
                return NULL;
            else if(root->esq == NULL) //A esquerda do subelemento é nula?
                    return root;
            else
                return DoisFilhos(root->esq);
}
 
void removerNo(noCod **raiz,int elemento)
{
        if(elemento < (*raiz)->valorPred){
            removerNo(&(*raiz)->esq,elemento);
        }
        else if(elemento > (*raiz)->valorPred){
            removerNo(&(*raiz)->dir,elemento);
        }
        else if((*raiz)->esq!=NULL && (*raiz)->dir!=NULL){//No caso de um nó ter subfilhos dos dois lados 
            noCod *aux= NULL;
            aux = DoisFilhos((*raiz)->dir); //Chama o procedimento dois filhos e aux recebe o valorPred de resultado
            (*raiz)->valorPred = aux->valorPred;   //Substitui o velor pelo valorPred da var auxilair
            removerNo(&(*raiz)->dir,(*raiz)->valorPred); //Remove a raiz
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
 
void pesquisaOrdemSimetrica(noCod *raiz)
{
        if(raiz == NULL)
            return;
        pesquisaOrdemSimetrica(raiz->esq);
        printf("%d\n",raiz->valorPred);
        pesquisaOrdemSimetrica(raiz->dir);
}
 
void pesquisaPosOrdem(noCod *raiz)
{
        if(raiz == NULL)
            return;
        pesquisaPosOrdem(raiz->esq);
        pesquisaPosOrdem(raiz->dir);
        printf("%d\n",raiz->valorPred);
}
 
void pesquisaPreOrdem(noCod *raiz)
{
        if(raiz == NULL)
            return;
        printf("%d\n",raiz->valorPred);
        pesquisaPreOrdem(raiz->esq);
        pesquisaPreOrdem(raiz->dir);
}
/*/
