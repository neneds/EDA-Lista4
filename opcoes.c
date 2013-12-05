/*/
Universidade de Brasília - FGA
Disciplina: EDA
Professor: Nilton
Alunos: Dennis Lúcio Merli Rodrigues - 13/0044130  - GitHub: https://github.com/neneds
        Iago Mendes
        
/*/


//Arquivo com as funcoes e procedimentos para o funcionamento do programa
#include "arvore_abp.c"

void pesquisaCod(no *raizCod){
    //Declaração de variaveis
    int codPesq=0;
    no *resultado;
 
	printf("\nDigite o código a ser pesquisado:\n\n");
    scanf("%d",&codPesq);
    resultado=busca(raizCod,codPesq);
    if(resultado!=NULL){
	    printf("\nCódigo encontrado! %d\n",resultado->valor);
	    system("pause");
	    //Mostrar dados da pesquisa
		printf("\n\nDados encontrados:\n\n");
		printf("\nCódigo: %d\tCurso: %s\tPrédio: %d\n",resultado->valor,resultado->nome,resultado->predio);
		system("pause");
		return;	
    }
}//Fim do procedimento

//Procedimento para deletar 
void deletar(no *raizCod,no *raizNome,no *raizPred){
	//Declaração de variaveis
    int codPesq=0;
    char nomePesq[50];
    no *noPesqCod;
    FILE *excluir;
    excluir=fopen("ch.txt","w"); //Pegar dados da posição excluida e armazenar no arquivo ch.txt
 
	printf("\nDigite o código a ser pesquisado:\n\n");
    scanf("%d",&codPesq);
    noPesqCod=busca(raizCod,codPesq);
    //Se a posicao existe na arvore de códigos
    if(noPesqCod!=NULL){
      fprintf(excluir,"\nCódigo: %d\tCurso: %s\tPrédio: %d\n",noPesqCod->valor,noPesqCod->nome,noPesqCod->predio);
      strcpy(nomePesq,noPesqCod->nome); //Copia o nome guardado no ponteiro retornado pela busca, para envia-lo para a exclusão na árvore de nomes
      removerNoCod(&raizCod,codPesq);
      removerNoNome(&raizNome,nomePesq);
      removerNoPred(&raizPred,noPesqCod->predio);
      printf("\n\nCódigo %d e suas informações removidas!!\n\n",codPesq);
      fclose(excluir);
      return;
    }
    else
    printf("\nPesquisa inválida!\n\n");
    fclose(excluir);
    getch();
    return;
}

//Funcao para o menu
int menu_opcoes(){
	int op;
	printf("\nMenu de opções\n\n");

	printf("\n1-Exibir um registro (Mostrar Nome e Prédio), informando o código do curso a ser exibido\n");
    printf("\n2-Excluir um registro. O usuário informará o código do curso a ser excluído;\n");
    printf("\n3-Gravar arquivos de saída\n");
    printf("\n4-Sair\n");
    printf("\n      Digite a sua escolha: ");
    scanf("%d",&op);
     if((op<1)||(op>4)){
     	printf("\n\nOpção não existente\n");
     	op=-1;
     	return (op);
     }
    return (op);
}//Fim da função de Opções


//Verificar se arquivo aberto  não é nulo
void Verificar(char *nomeArquivo,FILE *abrArq){
	if(abrArq==NULL){
    	printf("\nProblemas na abertura do arquivo %s\n",nomeArquivo);
    	exit(1);
    }
    else
     printf("\nArquivo aberto com sucesso!\n\n");
     return;

}

//Mostrar arvores
void mostrarArvore(no *raiz){

        if(raiz == NULL){
          return;	
         }
           
        mostrarArvore(raiz->esq);
        printf("%d\t%s\t%d\n",raiz->valor,raiz->nome,raiz->predio);
        mostrarArvore(raiz->dir);
}

//Procedimento para mostrar as árvores
void imprimirArvores(no *raizCod,no *raizNome,no *raizPred){
	system("cls");
	printf("\nArquivo ordenado por código\n\n");
    mostrarArvore(raizCod);
    getch();
    system("cls");
    printf("\nArquivo ordenado por Nome\n\n");
    mostrarArvore(raizNome);
    getch();
    system("cls");
    printf("\nArquivo ordenado por Prédio\n\n");
    mostrarArvore(raizPred);
    getch();
    system("cls");
    return;
}
//Grava a arvore no arquivo
void gravaArq(no *raiz,FILE *arqSaida){
	
		if(raiz == NULL){
		  return;
		}
        //Enquanto a raiz não for nula  
        gravaArq(raiz->esq,arqSaida);
        fprintf(arqSaida,"\nCódigo: %d\tCurso: %s\tPrédio: %d\n",raiz->valor,raiz->nome,raiz->predio);
        gravaArq(raiz->dir,arqSaida);
        
        printf("\nArquivo gravado!!\n");
        return;
}

