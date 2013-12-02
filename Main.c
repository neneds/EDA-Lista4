#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<windows.h>
#include "tratamento.h"
#include "arvore_abp.c"

//Mostrar dados no arquivo
void mostrar(long int posicaoPesq,FILE *arqTex){
	char bufferLeitura[500];
	
	rewind(arqTex);
	fseek(arqTex,posicaoPesq,0);
	fgets(bufferLeitura,500,arqTex);
	printf("\n\nDados encontrados:\n\n");
	printf("\n\n\%s\n\n",bufferLeitura);
	system("pause");
	return;
}


//Funcao para pesquisa por codigo
void pesquisaCod(noCod *raizCod,FILE *arqTex){
    //Declaração de variaveis
    long int posicaoPesq=0;
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
    mostrar(resultado->posicao,arqTex);	
    }
    
}

main () {
	
	//Para fazer a janela do DOS ficar Fullscreen
/*/	
	HWND hWnd;
   SetConsoleTitle("Lista 4 - EDA");
   hWnd = FindWindow(NULL, "Lista 4 - EDA");
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD NewSBSize = GetLargestConsoleWindowSize(hOut);
    SMALL_RECT DisplayArea = {0, 0, 0, 0};
 
    SetConsoleScreenBufferSize(hOut, NewSBSize);
 
    DisplayArea.Right = NewSBSize.X - 1;
    DisplayArea.Bottom = NewSBSize.Y - 1;
 
    SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
 
    ShowWindow(hWnd, SW_MAXIMIZE);
/*/
    //Definir local para portugues para utilizar caracteres pt-br
    setlocale(LC_ALL,"Portuguese");
    
    //Struct para receber os dados do arquivo
    typedef struct{
    	int codigo;
    	char curso[60];
    	int predio;
	}DadosTexto;
	
	//Variavel do tipo struct 
	DadosTexto cursos;
	
	//Declaração de variaveis
	char bufferLeitura[1000];
	char nomeArq[60];
	int TotalCursos=0;
	long int posicao=0;
	int op=0,cont=0;
	
	//Criando variavel da arvore binaria
    noCod *raizCod = NULL;
    //noNome *raizNome = NULL;
	
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
	printf("\nQuantidade de Cursos Lidos: %d\n\n\n",TotalCursos);
	rewind(arqTex);
	//Ler o arquivo e passar os dados para a struct
	fgets(bufferLeitura,1000,arqTex);//Desprezar o cabeçalho
	while(!feof(arqTex)){
		fgets(bufferLeitura,1000,arqTex);
		posicao=ftell(arqTex);
		cursos.codigo=atoi(strtok(bufferLeitura, ";")); 
	    strcpy(cursos.curso,strtok(NULL,";"));
	    cursos.predio=atoi(strtok(NULL, ";")); 
	    inserirNo(&raizCod,cursos.codigo,posicao);
	    printf("\n Código:%d\tCurso: %s\tPrédio: %d\n",cursos.codigo,cursos.curso,cursos.predio);
	}
	rewind(arqTex);//Até aqui o arquivo foi lido somente
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
	       	     pesquisaCod(raizCod,arqTex);
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
    system("pause");
	fclose(arqTex);
}
