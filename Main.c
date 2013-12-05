
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include "opcoes.c"




main () {
	
    //Definir local para portugues para utilizar caracteres pt-br
    setlocale(LC_ALL,"Portuguese");
    
	
	//Declaração de variaveis
	char bufferLeitura[1000];
	char nomeArq[60];
	int TotalCursos=0;
	int op=0,ver=0;
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
	printf("\nQuantidade de Cursos Lidos: %d\n\n\n",TotalCursos);
	rewind(arqTex); //Voltar o arquivo para o começo
	getch();
	
	//Ler o arquivo e passar os dados para a struct
	fgets(bufferLeitura,1000,arqTex);//Desprezar o cabeçalho
	while(!feof(arqTex)){
		fgets(bufferLeitura,1000,arqTex);
		codigo=atoi(strtok(bufferLeitura, ";")); //O strtok lê até encontrar o ;
	    strcpy(curso,strtok(NULL,";"));
	    predio=atoi(strtok(NULL, ";")); 
	    inserirNo(&raizCod,codigo,curso,predio,1);  //Inserir os dados lidos nas três arvores, o que as diferencia é o metodo de ordenação
	    inserirNo(&raizNome,codigo,curso,predio,2);
	    inserirNo(&raizPred,codigo,curso,predio,3);
	}
	rewind(arqTex);//Até aqui o arquivo foi lido somente
	fclose(arqTex);
    system("pause");
    imprimirArvores(raizCod,raizNome,raizPred);
    
    
    
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
	       	     pesquisaCod(raizCod);
	       	  	 break;
	       	  }
	       	  case 2:{
	       	  	 deletar(raizCod,raizNome,raizPred);
	       	  	 //Pergunta se o usuário quer ver as arvores depois da exclusao
                 printf("\nDeseja ver as árvores depois da exclusão? 1-Sim 2- Não\n\n");
                 scanf("%d",&ver);
                 if(ver==1){
                 	imprimirArvores(raizCod,raizNome,raizPred);
                 }
                 ver=0;
	       	  	 break;
	       	  }
	       	  case 3:{
	       	  	 char nomeCod[60];
	       	  	 strcpy(nomeCod,"Arquivo Ordenado por Codigo.txt");
	       	  	 char nomeNome[60];
	       	  	 strcpy(nomeNome,"Arquivo Ordenado por Nome.txt");
	       	  	 char nomePred[60];
	       	  	 strcpy(nomePred,"Arquivo Ordenado por Predio.txt");
	       	  	 
	       	  	 FILE *arqSaida;
	       	  	 //Para gravar o arquivo ordenado Por códigos
	             arqSaida=fopen(nomeCod,"w");
                 gravaArq(raizCod,arqSaida);
                 fclose(arqSaida);
                 //gravaArq(raizNome,2);
                 //gravaArq(raizPred,3);
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
}
