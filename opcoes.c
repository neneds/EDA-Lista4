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
    no *noPesqCod;
 
	printf("\nDigite o código a ser pesquisado:\n\n");
    scanf("%d",&codPesq);
    noPesqCod=busca(raizCod,codPesq);
    //noPesqPred=busca(raizCod,codPesq);
    if(noPesqCod!=NULL){
      removerNo(&raizCod,codPesq);
      //removerNo(&raizNome,codPesq);
      //removerNo(&raizPred,noPesqCod->predio);
      return;
    }
    else
    printf("\nA pesquisa não foi válida!!!\n\n");
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

//Mostrar arvore
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
void gravaArq(no *raiz,int op3){
	
	char nomeSalvar[60];
	//Copiando os nomes para salvar os arquivos de acordo com o valor da variavel op3 passado
	if(op3==1){
	   strcpy(nomeSalvar,"Arquivo Ordenado por Codigo.txt");
	}
	 else if(op3==2){
	 	strcpy(nomeSalvar,"Arquivo Ordenado por Nome.txt");
	 }
	 else if(op3==3){
	 	strcpy(nomeSalvar,"Arquivo Ordenado por Predio.txt");
	 }
	
	FILE *arqSaida;
	arqSaida=fopen(nomeSalvar,"w");
		
		if(raiz == NULL){
          fclose(arqSaida);	
          if(arqSaida==NULL){
        	 printf("\nArquivo %s Gravado\n\n",nomeSalvar);
          }
		  return;
		  
        }
           
        gravaArq(raiz->esq,op3);
        fprintf(arqSaida,"%d\t%s\t%d\n",raiz->valor,raiz->nome,raiz->predio);
        gravaArq(raiz->dir,op3);
        
       
}

