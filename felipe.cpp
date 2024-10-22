#include <stdio.h> //Biblioteca de Comunicação
#include <stdlib.h> //Reserva de memoria para alguma coisa
#include <locale.h> //biblioteca de linguagem
#include <string.h> //biblioteca de strings

int registro()	
{
	setlocale(LC_ALL, "Portuguese");
	
	 char cpf[50];
	 char nome[50];
	 char sobrenome[50];
	 char cargo[50];
	 char arquivo[50];
	
	printf("Digite o CPF a ser cadrastado: ");
	scanf("%s", cpf); //Armazena a variavel do tipo string - Lê a string 'cpf'
	
	strcpy(arquivo, cpf);//Copia o 'cpf' para o arquivo
	
	FILE *file;//Cria o arquivo (file) no banco de dados do Pc(FILE)
	file = fopen(arquivo, "w");//Abre o arquuivo (file)
	fprintf(file,cpf);// Salva no arquivo (file)
	fclose(file);//Fecha o arquivo (file)
	
	file = fopen(arquivo, "a");//Abre o arquivo e atualiza
	fprintf(file, ", ");//Separa os cpfs com virgula
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " \n");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}
	
int consulta()
{   
	 setlocale(LC_ALL, "Portuguese");
	 
	 char cpf[50];
	 char conteudo[200];
	 
	 printf("Digite o CPF a ser consultado: ");
	 scanf("%s",cpf);
	 
	 FILE *file;
	 file = fopen(cpf,"r");
	 
	 if(file == NULL)
	 {
	 	printf("Não foi possível encontrar o arquivo!.\n");
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL)
	 {
	 	printf("\nEssas são as informações do Usuário: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 }	 
	 
	 system("pause");
	 	
}

int deletar()
{

	char cpf[50];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	{
		printf("CPF deletado.!");
	}
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado. \n");
		system("pause");
	}
	
}	

    int main()
{
	int opcao=0;// Primeira variavel sempre será 0
	int laco=1;
	
	for(laco=1;laco=1;)//laço infinito
    { 
    
	   system("cls");
	 
	   setlocale(LC_ALL, "Portuguese");//modo de escrita
	 
	   printf("### Cartório da Ebac ###\n\n");
	   printf("Escolha a opção desejada do menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n");
	   printf("\t4 - Sair do Sistema\n");
	   printf("Opção: ");
	 
	    scanf("%d", &opcao);//Armazena variaveis do tipo inteiro, le a variavel (opção)
	
	   system("cls");
	   
	   switch(opcao)//switch e if (memória e processamento)
	   {
            case 1:
            	registro();
		break;
	        
	        case 2: 
		consulta();
	    	break;
	        
	        case 3:
	       	deletar();
	        break;
		
		case 4:
		printf("Obrigado por ultilizar o sistema!");
		break;
		return 0;//retorna variavel 0, o sistema encerra   
		   
	        	
	        default:
	        printf("Essa opção não está Disponível!!\n");
	        system("pause");
	        break;
	   } 
	
	
   }	
}
