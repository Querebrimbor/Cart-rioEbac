#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()	
{
	setlocale(LC_ALL, "Portuguese");
	
	 char cpf[50];
	 char nome[50];
	 char sobrenome[50];
	 char cargo[50];
	 char arquivo[50];
	
	printf("Digite o CPF a ser cadrastado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " \n");
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
	int opcao=0;
	int	laco=1;
	
	for(laco=1;laco=1;)
    { 
    
	   system("cls");
	 
	   setlocale(LC_ALL, "Portuguese");
	 
	   printf("### Cartório da Ebac ###\n\n");
	   printf("Escolha a opção desejada do menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n");
	   printf("\t Esse software é para Luana\n");
	   printf("Opção: ");
	 
	    scanf("%d", &opcao);
	
	   system("cls");
	   
	   switch(opcao)
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
	        	
	        default:
	        printf("Essa opção não está Disponível!!\n");
	        system("pause");
	        break;
	   } 
	
	
   }	
}
