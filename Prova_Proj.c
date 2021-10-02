// Pedro Vinícius Moraes Alves

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<locale.h>
#define MAX 100



enum X{
	
	VI=0
}REF2;

typedef struct { 
 	
struct{ 
	
	char Nome[MAX];
	int Saldo;
	union{
		int saque;
		int deposito;
		int pagamento;
	}valor;
	
}conta;

}cadastros;
	
	int cont=VI;
	int cont2=0;
	cadastros CAD[MAX];
	unsigned int Cadastro(); 
	void Listar(); 
	void Saque();
	void Deposito();
	void Extrato();
	void Pagamento();
	



int main(){
	
	setlocale(LC_ALL,"portuguese");
	
	int op;
	int sair=1;
do{	

	printf("==========MENU==========\n\n1-Cadastro de Clientes\n2-Listar Clientes\n3-Saque\n4-Deposito\n5-Pagamento\n6-Extrato\n7-Sair\n\n");
	scanf("%i",&op);

	
	switch(op){
		
		case 1: Cadastro();
		break;
		
		case 2: if(cont==0){
			printf("\nNenhum Usuario Foi Cadastrado!!!\n");
			system("pause");
			system("cls");
			}
			else{
				Listar();
			}
		break;
		
		case 3:
			if(cont==0){
			printf("\nNenhum Usuario Foi Cadastrado!!!\n");
			system("pause");
			system("cls");
			}
			else{
				 Saque();
	}
		break;
		
		case 4: 
			if(cont==0){
			printf("\nNenhum Usuario Foi Cadastrado!!!\n");
			system("pause");
			system("cls");
			}
			else{
				Deposito();
			}
		break;
		
		case 5:
			if(cont<2){
			printf("\nUsuarios Insuficientes Para Operação!!!\n");
			system("pause");
			system("cls");
			}
			else{

				Pagamento();
				
			}
		break;
		
		case 6: 
			if(cont==0){
			printf("\nNenhum Usuario Foi Cadastrado!!!\n");
			system("pause");
			system("cls");
			}
			else{
				Extrato();
			}
		break;
		case 7: sair=0;
				system("cls");
		break;
		
		default: printf("\nERROR!!\n");
				 system("pause");
				 system("cls");
		break;	
	}
	
}while(sair!=0);
	return 0;
}





unsigned int Cadastro(){
	system("cls");
	int sair2=1;
	char saida;
	do{
		
		printf("\nCADASTRO DA CONTA %i:",cont+1);
		printf("\nDigite o nome do usuario:");
		fflush(stdin);
		gets(CAD[cont].conta.Nome);
		CAD[cont].conta.Saldo=0;
		printf("\nDeseja Cadastrar Outro Usuario?(S ou N)\n");
		scanf("%c",&saida);
		if(saida=='N'||saida=='n'){
			sair2=0;
			system("cls");
		}
		else if(saida=='S'||saida=='s'){
			system("cls");
		}
		else{
			
			printf("\nDigito Invalido!!!\nSAINDO DO CADASTRO...\n");
			sair2=0;
			system("pause");
			system("cls");
		}
		cont++;
		
	}while(sair2!=0);
	
	return(cont);///PASSAGEM DE PARAMETRO DO N.CONTA.
	
	
}



void Listar(){
	
	system("cls");
	printf("\nLISTAGEM:\n");
	for(cont2=0;cont2<cont;cont2++){
		
		printf("\nCONTA%i:\n",cont2+1);
		printf("Nome:%s\n",CAD[cont2].conta.Nome);
		printf("Saldo:%i\n",CAD[cont2].conta.Saldo);
		}
	
	system("pause");
	system("cls");
	
}


void Saque(){
	system("cls");
	int cont3,sair3=1;
	int comp;
	char saida2;
	do{
		printf("Digite o Numero da conta que deseja Sacar:");
		scanf("%i",&cont3);
		cont3=cont3-1;
		comp=cont-1;
		if(cont3>comp){
			
			printf("\nESSA CONTA NÃO EXISTE!!!");
			sair3=0;
			system("pause");
			system("cls");
		}
		else{
			
			printf("\nDigite o Valor do Saque do Usuario %s:",CAD[cont3].conta.Nome);
			scanf("%i",&CAD[cont3].conta.valor.saque);
			if(CAD[cont3].conta.valor.saque>CAD[cont3].conta.Saldo){
				
				printf("\nSALDO INSUFICIENTE!!");
				sair3=0;
				system("pause");
				system("cls");
				
			}
			else {
			
			CAD[cont3].conta.Saldo=CAD[cont3].conta.Saldo-CAD[cont3].conta.valor.saque;
			printf("\nDeseja Fazer o saque de outra conta?(S ou N)");
			fflush(stdin);
			scanf("%c",&saida2);
		if(saida2=='N'||saida2=='n'){
			sair3=0;
			system("cls");
		}
		else if(saida2=='S'||saida2=='s'){
			system("cls");
		}
		}
		}
	
		
	}while(sair3!=0);
	
	
}




void Deposito(){
	system("cls");	
	int cont4,sair4=1;
	int comp2;
	char saida3;
	
		do{
		printf("Digite o Numero da conta que deseja Depositar:");
		scanf("%i",&cont4);
		cont4=cont4-1;
		comp2=cont-1;
		if(cont4>comp2){
			
			printf("\nESSA CONTA NÃO EXISTE!!!");
			sair4=0;
			system("pause");
			system("cls");
		}
		else{
			
			printf("\nDigite o Valor do Deposito para o Usuario %s:",CAD[cont4].conta.Nome);
			scanf("%i",&CAD[cont4].conta.valor.deposito);
			CAD[cont4].conta.Saldo=CAD[cont4].conta.Saldo+CAD[cont4].conta.valor.deposito;
			printf("\nDeseja Fazer um Deposito em outra conta?(S ou N)");
			fflush(stdin);
			scanf("%c",&saida3);
		if(saida3=='N'||saida3=='n'){
			sair4=0;
			system("cls");
		}
		else if(saida3=='S'||saida3=='s'){
			system("cls");
		}
		}
		
	
		
	}while(sair4!=0);
	
}

void Pagamento(){
	system("cls");	
	int cont3,sair3=1;
	int comp;
	int contP;
	char saida2;
	do{
		printf("Digite o Numero da conta que deseja Pagar:");
		scanf("%i",&cont3);
		cont3=cont3-1;
		comp=cont-1;
		if(cont3>comp){
			
			printf("\nESSA CONTA NÃO EXISTE!!!");
			sair3=0;
			system("pause");
			system("cls");
		}
		else{
		
		printf("Digite o Numero da conta que recebera o Pagamento:");
		scanf("%i",&contP);
		contP=contP-1;
		if(contP>comp){

			printf("\nESSA CONTA NÃO EXISTE!!!");
			sair3=0;
			system("pause");
			system("cls");			
		}
		else {

			printf("\nDigite o Valor do Pagamento do Usuario %s:",CAD[cont3].conta.Nome);
			scanf("%i",&CAD[cont3].conta.valor.pagamento);
			if(CAD[cont3].conta.valor.pagamento>CAD[cont3].conta.Saldo){
				
				printf("\nSALDO INSUFICIENTE!!");
				sair3=0;
				system("pause");
				system("cls");
			}
			else{
				
				printf("\nO usuario %s",CAD[contP].conta.Nome);
				printf(" Recebera %i",CAD[cont3].conta.valor.pagamento);
				CAD[cont3].conta.Saldo=CAD[cont3].conta.Saldo-CAD[cont3].conta.valor.pagamento;
			    CAD[contP].conta.Saldo=CAD[contP].conta.Saldo+CAD[cont3].conta.valor.pagamento;
			    printf("\nDeseja Fazer um outro pagamento?(S ou N)");
			    fflush(stdin);
			    scanf("%c",&saida2);
		if(saida2=='N'||saida2=='n'){
			sair3=0;
			system("cls");
		}
		else if(saida2=='S'||saida2=='s'){
			system("cls");
		}
				
			}
		}	

			}
		}while(sair3!=0);
	}
	
	
	void Extrato(){
	system("cls");		
		int comp;
		int cont3;
		int sairEX=1;
		char saida2;

		do{

		printf("Digite o Numero da conta que deseja Emitir o Extrato:");
		scanf("%i",&cont3);
		cont3=cont3-1;
		comp=cont-1;
		if(cont3>comp){
			
			printf("\nESSA CONTA NÃO EXISTE!!!");
			system("pause");
			system("cls");
		}
		else{
			printf("\nEMITINDO EXTRATO...");
			system("pause");			
			printf("\nConta:%i",cont3+1);
			printf("\nUsuario:%s",CAD[cont3].conta.Nome);
			printf("\nSaldo:%i",CAD[cont3].conta.Saldo);
			printf("\nValor da Ultima Transação:%i\n\n",CAD[cont3].conta.valor);
			system("pause");
			system("cls");
		}
			    printf("\nDeseja Fazer um outro Extrato?(S ou N)");
				fflush(stdin);
				scanf("%c",&saida2);
		if(saida2=='N'||saida2=='n'){
			sairEX=0;
			system("cls");
		}
		else if(saida2=='S'||saida2=='s'){
			system("cls");
		}			
			
		}while(sairEX!=0);
		
		
	}
