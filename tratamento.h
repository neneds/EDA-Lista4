/*/Procedimentos e funcoes para tratamentos dentro do programa/*/

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

