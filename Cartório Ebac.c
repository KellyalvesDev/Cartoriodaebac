#include <stdio.h> //biblioteca de comunicação com o úsuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h>// biblioteca responsavel por cuidar das string

int registro() //Função responsável por cadastrar os usúarios no sistema
{
	//inicio criação de variáveis/string
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variaveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usúario
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsável por copiar os valores das string 
    
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); // fecha o arquivo
	
    file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa atualizar
    fprintf(file,","); //salva e a "," serve para não deixar as informações coladas
    fclose(file); // fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //coletando informações do usúario
    scanf("%s", nome); //%s refere-se a string
    
    file = fopen(arquivo, "a"); // cria o arq. e o "a" significa atualizar
    fprintf(file,nome); //salva o valor da variável
    fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arq. e o "a" significa atualizar
	fprintf(file, ","); //salva e a "," serve para não deixar as infos coladas
	fclose(file); // fecha o arq.
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usúario
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arq. e o "a" significa atualizar
	fprintf(file, sobrenome); //salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arq. e o "a" significa atualizar
	fprintf(file, ","); //salva e a "," serve para não deixar as infos coladas
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informações do usúario
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arq. e o "a" significa atualizar
	fprintf(file, cargo); //salva o valor da variável
	fclose(file); //fechar o arquivo.
	
	system("pause"); // pausa para leitura do usúario
	
}

int consulta() //Finção responsável por consultar os dados de um usúario
{
	setlocale(LC_ALL, "Portuguese"); //definição do idioma

    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: "); //coleta o cpf a ser consultado
    scanf("%s", cpf); // leitura da string cpf
    
    FILE *file; //ponteiro para o arquivo
    file = fopen(cpf, "r"); // abre o arquivo para leitura
    
    if(file == NULL) //verifica a existência do arquivo
    {
        printf("Não foi possivel abrir o arquivo, não localizado!. \n");
    }

    while(fgets(conteudo, 200, file) != NULL) //leitura do arquivo
    {
    	printf("\nEssas são as informações do usuário: ");
    	printf("%s", conteudo); //exibe o conteúdo lido
    	printf("\n\n");
	}

        system("pause"); //pausa para leitura do usúario
}

int deletar() //função responsável por deletar um usúario
{
    char cpf[40]; //variável para armazenar o CPF
    
    printf("Digite o CPF do usúario a ser deletado: "); //coletar o CPF
    scanf("%s",cpf); // leitura da string CPF
    
    remove(cpf); //remove o arquivo correspondente ao cpf
    
    FILE *file; //ponteiro para o arquivo
    file = fopen(cpf,"r"); //tenta reabrir o arquivo para confirmar a exclusão
    
    if(file == NULL) //verifica se o arquivo realmente foi deletado
    {
    	printf("O usúario não se encontra no sistema!.\n");
    	system("pause"); //pausa o sistem apara leitura do usúario
	}
    
    
}



int main() //função principal
{
		int opcao=0; //definindo variáveis
	    int laco=1; // controle de repetição
	
	for(laco=1;laco=10;) //loop de execução do menu
	{
	
	system("cls"); //responsável por limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); //definição do idioma
	
	printf("### Cartório da EBAC ###\n\n"); // inicio do menu
	printf("Escolha a opção desejada do menu:\n\n"); // titulo inicial
	printf("\t1 - Registar nomes\n"); //difinição de opção 01
	printf("\t2 - Consultar nomes\n"); //definição de opção 02
	printf("\t3 - Deletar nomes\n\n"); //definição de opção 03 
	printf("Opção: "); //fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do úsuario
	
	system("cls"); // responsável por limpar a tela 


	switch(opcao) //inicio da seleção do menu
	{
		case 1:
        registro(); //chamada da função de registro
		break;
		
		case 2:
		consulta(); //chamada da função de consulta
		break;
		
		case 3:
		deletar (); //chamada da função de deletar
		break;
		
		default:
		printf("Essa opção não está disponivel!\n"); //aviso de erro 
		system("pause"); //pausa para leitura do usúario
		break;
	} //fim da seleção
		
    }
}

