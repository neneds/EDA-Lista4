/*/Procedimentos e funcoes para tratamentos dentro do programa/*/

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

