#include <stdio.h>//Biblioteca de Comunica�ao com o usuario
#include <stdlib.h>//Biblioteca de Aloca�ao de espa�o em memoria
#include <locale.h>//Biblioteca de Aloca�ao de texto por regiao
#include <string.h>//biblioteca responsavel por cuidar das string

int registro()//funcao responsavel por cadastrar os usuarios no sistema
{
	//inicio da criacao de variaveis/string
	 char arquivo[40];
	 char cpf[40];
	 char nome [40];
	 char sobrenome[40];
	 char cargo[40];
	 //final da criacao de variaveis/string
	 
	 printf("Digite o CPF a ser cadastrado: ");//coletando informacao do usuario
	 scanf("%s",cpf);//%s refere-se a string
	 
	 strcpy(arquivo, cpf); //Responsavel porcopiar os valores das string
	 
	 FILE *file; //cria o arquivo
	 file = fopen(arquivo,"w"); //cria o arquivo e o "w" significa escrever
	 fprintf(file,cpf); //salvo o valor do arquivo
	 fclose(file); //fecha o arquivo
	 
	 file = fopen(arquivo,"a");
	 fprintf(file,",");
	 fclose(file);
	 
	 printf("Digite o nome a ser cadastrado: ");
	 scanf("%s",nome);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,nome);
	 fclose(file);
	 
	 file = fopen(arquivo,"a");
	 fprintf(file,",");
	 fclose(file);
	 
	 printf("Digite o sobrenome a ser cadastrado: ");
	 scanf("%s",sobrenome);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,sobrenome);
	 fclose(file);
	 
	 file = fopen (arquivo,"a");
	 fprintf(file,",");
	 fclose(file);
	 
	 printf("Digite o cargo a ser cadastrado: ");
	 scanf("%s",cargo);
	 
	 file = fopen(arquivo,"a");
	 fprintf(file,cargo);
	 fclose(file);
	 
	 system("pause");
	 
}

int consulta()

{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	
	if(file == NULL)
	{
		printf("Nao foi possivel abrir o arquivo, nao localizado! .\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas sao as informacoes do usuario: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletad: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usuario nao se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
{

 int opcao=0; //Definindo variaveis
 int laco=1;
 
 for(laco=1;laco=1;)
 {
 
 system("cls");
 
setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem

printf("###Cart�rio da EBAC ### \n\n"); //Inicio do menu
printf("Escolha a op�ao desejada do menu: \n\n");
printf("\t1 - Registrar nomes\n");
printf("\t2 - Consultar nomes\n");
printf("\t3 - Deletar nomes\n\n"); 
printf("Opcao:"); //fim do menu

scanf("%d",&opcao); //armazenando a escolha do usuario

system("cls");//responsavel por limpar a tela

switch(opcao)//inicio da selecao do menu
{
	case 1:
    registro();//chamada de funcoes
	break;
	
	case 2:
	consulta();
	break;
	
	case 3:
	deletar();
	break;
	
	default:
	printf("Essa opcao nao esta disponivel!\n"); 
	system("pause");
	break;
}


}
}
