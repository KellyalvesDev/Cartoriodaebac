#include <stdio.h> //biblioteca de comunica��o com o �suario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h>// biblioteca responsavel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os us�arios no sistema
{
	//inicio cria��o de vari�veis/string
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de variaveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do us�ario
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string 
    
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
    file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa atualizar
    fprintf(file,","); //salva e a "," serve para n�o deixar as informa��es coladas
    fclose(file); // fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //coletando informa��es do us�ario
    scanf("%s", nome); //%s refere-se a string
    
    file = fopen(arquivo, "a"); // cria o arq. e o "a" significa atualizar
    fprintf(file,nome); //salva o valor da vari�vel
    fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arq. e o "a" significa atualizar
	fprintf(file, ","); //salva e a "," serve para n�o deixar as infos coladas
	fclose(file); // fecha o arq.
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do us�ario
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arq. e o "a" significa atualizar
	fprintf(file, sobrenome); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arq. e o "a" significa atualizar
	fprintf(file, ","); //salva e a "," serve para n�o deixar as infos coladas
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��es do us�ario
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arq. e o "a" significa atualizar
	fprintf(file, cargo); //salva o valor da vari�vel
	fclose(file); //fechar o arquivo.
	
	system("pause"); // pausa para leitura do us�ario
	
}

int consulta() //Fin��o respons�vel por consultar os dados de um us�ario
{
	setlocale(LC_ALL, "Portuguese"); //defini��o do idioma

    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: "); //coleta o cpf a ser consultado
    scanf("%s", cpf); // leitura da string cpf
    
    FILE *file; //ponteiro para o arquivo
    file = fopen(cpf, "r"); // abre o arquivo para leitura
    
    if(file == NULL) //verifica a exist�ncia do arquivo
    {
        printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
    }

    while(fgets(conteudo, 200, file) != NULL) //leitura do arquivo
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo); //exibe o conte�do lido
    	printf("\n\n");
	}

        system("pause"); //pausa para leitura do us�ario
}

int deletar() //fun��o respons�vel por deletar um us�ario
{
    char cpf[40]; //vari�vel para armazenar o CPF
    
    printf("Digite o CPF do us�ario a ser deletado: "); //coletar o CPF
    scanf("%s",cpf); // leitura da string CPF
    
    remove(cpf); //remove o arquivo correspondente ao cpf
    
    FILE *file; //ponteiro para o arquivo
    file = fopen(cpf,"r"); //tenta reabrir o arquivo para confirmar a exclus�o
    
    if(file == NULL) //verifica se o arquivo realmente foi deletado
    {
    	printf("O us�ario n�o se encontra no sistema!.\n");
    	system("pause"); //pausa o sistem apara leitura do us�ario
	}
    
    
}



int main() //fun��o principal
{
		int opcao=0; //definindo vari�veis
	    int laco=1; // controle de repeti��o
	
	for(laco=1;laco=10;) //loop de execu��o do menu
	{
	
	system("cls"); //respons�vel por limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); //defini��o do idioma
	
	printf("### Cart�rio da EBAC ###\n\n"); // inicio do menu
	printf("Escolha a op��o desejada do menu:\n\n"); // titulo inicial
	printf("\t1 - Registar nomes\n"); //difini��o de op��o 01
	printf("\t2 - Consultar nomes\n"); //defini��o de op��o 02
	printf("\t3 - Deletar nomes\n\n"); //defini��o de op��o 03 
	printf("Op��o: "); //fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do �suario
	
	system("cls"); // respons�vel por limpar a tela 


	switch(opcao) //inicio da sele��o do menu
	{
		case 1:
        registro(); //chamada da fun��o de registro
		break;
		
		case 2:
		consulta(); //chamada da fun��o de consulta
		break;
		
		case 3:
		deletar (); //chamada da fun��o de deletar
		break;
		
		default:
		printf("Essa op��o n�o est� disponivel!\n"); //aviso de erro 
		system("pause"); //pausa para leitura do us�ario
		break;
	} //fim da sele��o
		
    }
}

