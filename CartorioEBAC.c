#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string


int registro() //Função responçavel por registrar os usuários no sistema
{
	//Inicil da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variáveis/string
	
	printf("digite o cpf para cadastro: "); //Coletando infirmação do usuário
	scanf("%s", cpf); //%s refere-se ás string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo sendo que "w" o escreve
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo sendo que "a" o atualiza
	fprintf(file, ","); //Adiciona um texto
	fclose(file); //Fecha o arquivo
	
	printf("digite o nome a ser registrado: "); //coleta a informação do usuário
	scanf("%s",nome); //escaneia a string de acordo com os requisitos
	
	file = fopen(arquivo, "a"); //Abre o arquivo sendo que "a" o atualiza
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo sendo que "a" o atualiza
	fprintf(file, ","); //salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	printf("digite o sobrenome a ser registrado: "); //coleta a informação do usuário
	scanf("%s",sobrenome); //escaneia a string de acordo com os requisitos
	
	file = fopen(arquivo, "a"); //Abre o arquivo sendo que "a" o atualiza
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo sendo que "a" o atualiza
	fprintf(file, ","); //salva o valor da variavel
	fclose(file); //Fecha o arquivo

	printf("digite o cargo a ser cadastrado: "); //coleta a informação do usuário
	scanf("%s",cargo); //escaneia a string de acordo com os requisitos
	
	file = fopen(arquivo, "a"); //Abre o arquivo sendo que "a" o atualiza
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	system("pause"); //pausa o sistema em determinada tela
}

int consulta() //Função responçavel por consultar os usuários no sistema
{
	setlocale(LC_ALL, "portuguese");  //Definindo a linguagem
	
	char cpf[40]; //determinando uma variável/string
	char conteudo[200];//determinando uma variável/string
	
	printf("digite o cpf a ser consultado: "); //coleta a informação do usuário
	scanf("%s",cpf); //escaneia a string de acordo com os requisitos
	
	FILE *file; //Função que determina o uso de um arquivo
	file = fopen(cpf,"r"); //Abre determinado aquivo sendo q "r" o lê 
	
	if(file == NULL) //condição que compara o arquivo a nulo
	{
		printf("Cpf invalido, tente novamente! \n"); //Valida a escolha do usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) //condição que compara o arquivo a nulo
	{
		printf("\nEssas são as informações do usuário: \n"); //Valida a escolha do usuário
		printf("%s", conteudo); //escaneia a string de acordo com os requisitos
		printf("\n\n"); //pula linhas apenas por estética
	}
	
	system("pause"); //pausa o sistema em determinada tela
}

int deletar() //Função responçavel por deletar os usuários no sistema
{
	char cpf[40]; //determinando uma variável/string
	
	printf("digite o cpf a ser deletado: "); //coleta a informação do usuário
	scanf("%s",cpf); //escaneia a string de acordo com os requisitos
	
	remove(cpf); //exclui determinado arquivo
	
	FILE *file; //Função que determina o uso de um arquivo
	file = fopen(cpf, "r"); //Abre determinado aquivo sendo q "r" o lê
	
	if(file == NULL) //condição que compara o arquivo a nulo
	{
		printf("O usuário deletado/não existe!\n"); //Valida a escolha do usuário
		system("pause"); //pausa o sistema em determinada tela
	}
		
}

int main() //função principal
{
	
	int opcao=0;  //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //Limpa a tela do usuário
	
		setlocale(LC_ALL, "portuguese");  //Definindo a linguagem
	
		printf(" ===> CARTÓRIO EBAC <===\n\n");  //Início do menu/exibe uma mensagem para o usuário
		printf(" v Selecione uma das opções abaixo v\n\n"); //exibi uma mensagem para o usuário
		printf("\t > Registrar nomes <\n"); //exibe uma mensagem para o usuário
		printf("\t > Consultar nomes <\n"); //exibe uma mensagem para o usuário
		printf("\t >  deletar nomes  <\n\n\n"); //exibe uma mensagem para o usuário
		printf("Opção: "); //Fim do menu
	
		scanf("%d" , &opcao);  //Armazenado a escolha do usuário
	
		system("cls"); //Limpa a tela do usuário
		
		switch(opcao)  //início da seleção
		{
			case 1: //chamada de funções
			registro();
			break;
			
			case 2: //chamada de funções
			consulta();
			break;
			
			case 3: //chamada de funções
			deletar();
			break;
			
			default: //chamada de funções
			printf("Opção indisponível!\n");
			system("pause");
			break;  //Fim da seleção
				
		}  
	
	}
}
