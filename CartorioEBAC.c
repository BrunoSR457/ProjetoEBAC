#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string


int registro() //Fun��o respon�avel por registrar os usu�rios no sistema
{
	//Inicil da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de vari�veis/string
	
	printf("digite o cpf para cadastro: "); //Coletando infirma��o do usu�rio
	scanf("%s", cpf); //%s refere-se �s string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo sendo que "w" o escreve
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo sendo que "a" o atualiza
	fprintf(file, ","); //Adiciona um texto
	fclose(file); //Fecha o arquivo
	
	printf("digite o nome a ser registrado: "); //coleta a informa��o do usu�rio
	scanf("%s",nome); //escaneia a string de acordo com os requisitos
	
	file = fopen(arquivo, "a"); //Abre o arquivo sendo que "a" o atualiza
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo sendo que "a" o atualiza
	fprintf(file, ","); //salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	printf("digite o sobrenome a ser registrado: "); //coleta a informa��o do usu�rio
	scanf("%s",sobrenome); //escaneia a string de acordo com os requisitos
	
	file = fopen(arquivo, "a"); //Abre o arquivo sendo que "a" o atualiza
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo sendo que "a" o atualiza
	fprintf(file, ","); //salva o valor da variavel
	fclose(file); //Fecha o arquivo

	printf("digite o cargo a ser cadastrado: "); //coleta a informa��o do usu�rio
	scanf("%s",cargo); //escaneia a string de acordo com os requisitos
	
	file = fopen(arquivo, "a"); //Abre o arquivo sendo que "a" o atualiza
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	system("pause"); //pausa o sistema em determinada tela
}

int consulta() //Fun��o respon�avel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "portuguese");  //Definindo a linguagem
	
	char cpf[40]; //determinando uma vari�vel/string
	char conteudo[200];//determinando uma vari�vel/string
	
	printf("digite o cpf a ser consultado: "); //coleta a informa��o do usu�rio
	scanf("%s",cpf); //escaneia a string de acordo com os requisitos
	
	FILE *file; //Fun��o que determina o uso de um arquivo
	file = fopen(cpf,"r"); //Abre determinado aquivo sendo q "r" o l� 
	
	if(file == NULL) //condi��o que compara o arquivo a nulo
	{
		printf("Cpf invalido, tente novamente! \n"); //Valida a escolha do usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) //condi��o que compara o arquivo a nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n"); //Valida a escolha do usu�rio
		printf("%s", conteudo); //escaneia a string de acordo com os requisitos
		printf("\n\n"); //pula linhas apenas por est�tica
	}
	
	system("pause"); //pausa o sistema em determinada tela
}

int deletar() //Fun��o respon�avel por deletar os usu�rios no sistema
{
	char cpf[40]; //determinando uma vari�vel/string
	
	printf("digite o cpf a ser deletado: "); //coleta a informa��o do usu�rio
	scanf("%s",cpf); //escaneia a string de acordo com os requisitos
	
	remove(cpf); //exclui determinado arquivo
	
	FILE *file; //Fun��o que determina o uso de um arquivo
	file = fopen(cpf, "r"); //Abre determinado aquivo sendo q "r" o l�
	
	if(file == NULL) //condi��o que compara o arquivo a nulo
	{
		printf("O usu�rio deletado/n�o existe!\n"); //Valida a escolha do usu�rio
		system("pause"); //pausa o sistema em determinada tela
	}
		
}

int main() //fun��o principal
{
	
	int opcao=0;  //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //Limpa a tela do usu�rio
	
		setlocale(LC_ALL, "portuguese");  //Definindo a linguagem
	
		printf(" ===> CART�RIO EBAC <===\n\n");  //In�cio do menu/exibe uma mensagem para o usu�rio
		printf(" v Selecione uma das op��es abaixo v\n\n"); //exibi uma mensagem para o usu�rio
		printf("\t > Registrar nomes <\n"); //exibe uma mensagem para o usu�rio
		printf("\t > Consultar nomes <\n"); //exibe uma mensagem para o usu�rio
		printf("\t >  deletar nomes  <\n\n\n"); //exibe uma mensagem para o usu�rio
		printf("Op��o: "); //Fim do menu
	
		scanf("%d" , &opcao);  //Armazenado a escolha do usu�rio
	
		system("cls"); //Limpa a tela do usu�rio
		
		switch(opcao)  //in�cio da sele��o
		{
			case 1: //chamada de fun��es
			registro();
			break;
			
			case 2: //chamada de fun��es
			consulta();
			break;
			
			case 3: //chamada de fun��es
			deletar();
			break;
			
			default: //chamada de fun��es
			printf("Op��o indispon�vel!\n");
			system("pause");
			break;  //Fim da sele��o
				
		}  
	
	}
}
