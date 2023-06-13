#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação do espaço em memório
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das sting

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("digite um sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //permite colocar acentuação
		
	//inicio criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final criação de variáveis/string
	
	printf("Digite o cpf a ser consultado: "); //informação que o usuário deseja saber
	scanf("%s",cpf);
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler
	
	if(file == NULL) //se o arquivo não existir aparecerá a mensagem que não foi localizado
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //se o arquivo existir aparecera as informações
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	//inicio criação de variáveis/string
	char cpf[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //informação que o usuário deseja deletar
	scanf("%s",cpf);
	
	remove(cpf); //apaga o cpf
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler 
	if(file == NULL) //se o artuivo não existir aparecerá que nao existe
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
	}
	else //se existir aparecerá que o arquivo foi deletado
	{
		printf("O usuário foi deletado!.\n");
		system("pause");
	}
}

int main()
{
	int opcao = 0; //definindo as variaveis
	int x = 1;
	
	for(x=1; x=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("\t4 - Sair do sistema \n\n");
		printf("Opção: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n ");
			return 0;
			break;
			
			default:
			printf("Essa opção não esta disponivel!\n ");
			system("pause");
			break;
		} //fim da seleção	
	}
}
