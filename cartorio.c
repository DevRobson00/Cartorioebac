#include <stdio.h> //Biclioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biclioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o 
#include <string.h>
	
	int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{	
	//Inicio de cria��o de variaveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
	//Final da cria��o de variaveis/string
	
		printf("Digite o cpf a ser cadastrado: "); //Coletando informa��es do usu�rio 
		scanf("%s", cpf); // %s refere-se a string
	
		strcpy(arquivo, cpf); // Responsavel por copiar os valores da string
	
		FILE *file; //Criar o arquivo
		file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever 
		fprintf(file,cpf); //Salva o valor da variavel
		fclose(file); //Fecha o arquivo
	
		file = fopen(arquivo, "a"); // "a" responsavel por atualizar o arquivo
		fprintf(file,",");
		fclose(file);
	
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
	
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
	
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
	
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
	
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);	
	
		system("pause");
}
	int consulta()
{
		setlocale(LC_ALL, "Portuguese");
	
		char cpf[40];
		char conteudo[200];
	
		printf("Digite o cpf a ser consultado: ");
		scanf("%s",cpf);
	
		FILE *file;
		file = fopen(cpf,"r"); // "r" responsavel por ler o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

		system("pause");
}
	int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF do usu�rio a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
	if(file == NULL)
	{
		printf("Usu�rio deletado com sucesso!\n");
		printf("Usu�rio n�o encontrado no sistema.\n");
		system("pause");
	}	
}
	int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char login[10]="admin";
	char senha[10]="admin";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite seu login: ");
	scanf("%s",login);
	
	printf("Digite sua senha: ");
	scanf("%s",senha);
	
	comparacao = strcmp(login, "admin");
	comparacao = strcmp(senha, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");
	 	for(laco=1;laco=1;)
		{
	
			system("cls"); // Responsavel por limpar a tela
	    
			setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
			printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha a op��o desejada do menu: \n\n");
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n"); 
			printf("\t4 - Sair do menu\n \n");
			printf("Op��o: "); //Fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
			system("cls");
    	
    		switch(opcao) //Inicio da sele��o
   			{
				case 1:
				registro();	// Chamada de fun��es
				break;
				
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
				
				case 4:	
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;			

				default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;											
			}
		} //Fim da sele��o
	}
	else
		printf("\nLogin e/ou senha incorreta!\n");
		system("pause");
		system("cls");
		main();
}
