#include <stdio.h> //Biclioteca de comunicação com o usuário
#include <stdlib.h> //Biclioteca de alocação de espaço de memória
#include <locale.h> //Biblioteca de alocações de texto por região 
#include <string.h>
	
	int registro() //Função responsavel por cadastrar os usuários no sistema
{	
	//Inicio de criação de variaveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
	//Final da criação de variaveis/string
	
		printf("Digite o cpf a ser cadastrado: "); //Coletando informações do usuário 
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
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

		system("pause");
}
	int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF do usuário a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
	if(file == NULL)
	{
		printf("Usuário deletado com sucesso!\n");
		printf("Usuário não encontrado no sistema.\n");
		system("pause");
	}	
}
	int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	char login[10]="admin";
	char senha[10]="admin";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
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
	
			printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha a opção desejada do menu: \n\n");
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n"); 
			printf("\t4 - Sair do menu\n \n");
			printf("Opção: "); //Fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usuário
	
			system("cls");
    	
    		switch(opcao) //Inicio da seleção
   			{
				case 1:
				registro();	// Chamada de funções
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
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;											
			}
		} //Fim da seleção
	}
	else
		printf("\nLogin e/ou senha incorreta!\n");
		system("pause");
		system("cls");
		main();
}
