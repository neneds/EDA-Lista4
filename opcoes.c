//Arquivo com as funcoes e procedimentos para o funcionamento do programa
#include "arvore_abp.c"

void pesquisaCod(no *raizCod){
    //Declara��o de variaveis
    int codPesq=0;
    no *resultado;
 
	printf("\nDigite o c�digo a ser pesquisado:\n\n");
    scanf("%d",&codPesq);
    resultado=busca(raizCod,codPesq);
    if(resultado!=NULL){
	    printf("\nC�digo encontrado! %d\n",resultado->valor);
	    system("pause");
	    //Mostrar dados da pesquisa
		printf("\n\nDados encontrados:\n\n");
		printf("\nC�digo: %d\tCurso: %s\tPr�dio: %d\n",resultado->valor,resultado->nome,resultado->predio);
		system("pause");
		return;	
    }
}//Fim do procedimento

//Procedimento para deletar 
void deletar(no *raizCod,no *raizNome,no *raizPred){
	//Declara��o de variaveis
    int codPesq=0;
    no *noPesq;
 
	printf("\nDigite o c�digo a ser pesquisado:\n\n");
    scanf("%d",&codPesq);
    noPesq=busca(raizCod,codPesq);
    if(noPesq!=NULL){
      removerNo(&raizCod,codPesq);
      //removerNo(&raizNome,codPesq);
      //removerNo(&raizPred,codPesq);
      return;
    }
    else
    printf("\nA pesquisa n�o foi v�lida!!!\n\n");
    return;
}

//Funcao para o menu
int menu_opcoes(){
	int op;
	printf("\nMenu de op��es\n\n");

	printf("\n1-Exibir um registro (Mostrar Nome e Pr�dio), informando o c�digo do curso a ser exibido\n");
    printf("\n2-Excluir um registro. O usu�rio informar� o c�digo do curso a ser exclu�do;\n");
    printf("\n3-Gravar arquivos de sa�da\n");
    printf("\n4-Sair\n");
    printf("\n      Digite a sua escolha: ");
    scanf("%d",&op);
     if((op<1)||(op>4)){
     	printf("\n\nOp��o n�o existente\n");
     	op=-1;
     	return (op);
     }
    return (op);
}//Fim da fun��o de Op��es


//Verificar se arquivo aberto  n�o � nulo
void Verificar(char *nomeArquivo,FILE *abrArq){
	if(abrArq==NULL){
    	printf("\nProblemas na abertura do arquivo %s\n",nomeArquivo);
    	exit(1);
    }
    else
     printf("\nArquivo aberto com sucesso!\n\n");
     return;

}
