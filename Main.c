#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<windows.h>
#include "tratamento.h"
#include "arvore_abp.c"

/*/
void pesquisaCod(noCod *raizCod,FILE *arqTex){
    //Declaração de variaveis
    char bufferLeitura[500];
    int codPesq=0;
    noCod *resultado;
 
	printf("\nDigite o código a ser pesquisado:\n\n");
    scanf("%d",&codPesq);
    resultado=busca(raizCod,codPesq);
    if(resultado!=NULL){
    printf("\nCódigo encontrado! %d\n",resultado->valor);
    printf("\nPosição no Ftell %ld\n",resultado->posicao);
    system("pause");
    //Mostrar dados da pesquisa
    rewind(arqTex);
	fseek(arqTex,resultado->posicao,0);
	fgets(bufferLeitura,500,arqTex);
	printf("\n\nDados encontrados:\n\n");
	printf("\n\n\%s\n\n",bufferLeitura);
	system("pause");
	return;	
    }
  
}/*/

main () {
	
    //Definir local para portugues para utilizar caracteres pt-br
    setlocale(LC_ALL,"Portuguese");
    
	
	//Declaração de variaveis
	char bufferLeitura[1000];
	char nomeArq[60];
	int TotalCursos=0;
	long int posicao=0;
	int op=0;
	char curso[60];
	int codigo=0;
	int predio=0;
	
	//Criando variavel da arvore binaria
    no *raizCod = NULL;
    no *raizNome=NULL;
    no *raizPred=NULL;
   
	
	//FilePointer para o arquivo de texto 
	FILE *arqTex;
	fflush(stdin);
	printf("\nDigite o nome do arquivo a ser aberto e sua extensão:");
	gets(nomeArq);
	arqTex=fopen(nomeArq,"r");
	Verificar(nomeArq,arqTex);//Verifica se o arquivo foi aberto
	//Ver quantos codigos foram lidos
	fgets(bufferLeitura,1000,arqTex);//Desprezar o cabeçalho
	while(fgets(bufferLeitura,1000,arqTex) != NULL){
		TotalCursos++;
	}
	//Alocando memoria 
	printf("\nQuantidade de Cursos Lidos: %d\n\n\n",TotalCursos);
	rewind(arqTex);
	//Ler o arquivo e passar os dados para a struct
	fgets(bufferLeitura,1000,arqTex);//Desprezar o cabeçalho
	while(!feof(arqTex)){
		fgets(bufferLeitura,1000,arqTex);
		//posicao=ftell(arqTex);
		codigo=atoi(strtok(bufferLeitura, ";")); 
	    strcpy(curso,strtok(NULL,";"));
	    predio=atoi(strtok(NULL, ";")); 
	    inserirNo(&raizCod,codigo,curso,predio,1);
	    inserirNo(&raizNome,codigo,curso,predio,2);
	    inserirNo(&raizPred,codigo,curso,predio,3);
	}
	rewind(arqTex);//Até aqui o arquivo foi lido somente
    system("pause");
    system("cls");
    pesquisaOrdemSimetrica(raizCod);
    system("pause");
    system("cls");
    pesquisaOrdemSimetrica(raizNome);
    system("pause");
    system("cls");
    pesquisaOrdemSimetrica(raizPred);
	system("pause");
    system("cls");
    
//______________________________________________Função para o menu de opções
//Declaração de variaveis

int opcao=0;


	while (opcao!=4){
		system("cls");
	    printf("\n================================Menu de consulta=============================\n\n");
		opcao=menu_opcoes();
	    system ("cls");
	       switch (opcao){
	       	  case 1:{
	       	     //pesquisaCod(raizCod,arqTex);
	       	  	 break;
	       	  }
	       	  case 2:{
	       	  	 // MunNome(TotalMun,indexNomeMun,arqMun,TotEstCod);
	       	  	 break;
	       	  }
	       	  case 3:{
                 //ProcNumMunEst(arqMun,arqEst,indEstCnpj,indEstCod,TotalMun,TotEstCod,TotEstCnpj);
	       	  	break;
	       	  }
			  
			case -1:{
			  	break;
			  }
		  }
	 }
//Fim do menu

    printf("\n\n\nFim do programa!!!\n\n");
    free(raizCod);
    system("pause");
	fclose(arqTex);
}
