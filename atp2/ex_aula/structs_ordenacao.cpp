#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio2.h>

#define TF 20

struct TpData
{
	int Dia, Mes, Ano;
};

struct TpProduto
{
	int Codigo, Estoque;
	char Descr[30];
	float Preco;
	TpData DtValidade;
};

void OrdenarDescr(TpProduto Tab[TF], int TL)
{
	int i,j;
	TpProduto RegAux;
	
	if (TL==0)
		printf("\nNão ha Produtos Cadastrados!\n");
	else
		{
			for(i=0; i<TL-1; i++)
				for(j=i+1; i<TL; j++)
					if(stricmp(Tab[i].Descr,Tab[j].Descr)>0)
					{
						RegAux = Tab[i];
						Tab[i] = Tab[j];
						Tab[j] = RegAux;
					}
			
			printf("\nTabela de Produtos Ordenada pela Descricao!\n");
		}
	getch();
}

int BuscaCodProd(TpProduto Tab[TF], int TL, int Codigo)
{
	int i=0;
	while (i<TL && Codigo!=Tab[i].Codigo)
			i++;
	
	if (i<TL)
		return i;
	else
		return -1;
}

void CADProd(TpProduto Tab[TF], int &TL)
{
	int AuxCod, pos;
	clrscr();
	printf("\n# # #  Cadastro de Produtos  # # #\n");
	printf("Codigo: ");
	scanf("%d",&AuxCod);
	while (TL<TF && AuxCod>0)
	{
		pos = BuscaCodProd(Tab,TL,AuxCod);
		if (pos == -1)
		{
			Tab[TL].Codigo = AuxCod;
			printf("Descricao: ");
			fflush(stdin);
			gets(Tab[TL].Descr);
			printf("Estoque: ");
			scanf("%d",&Tab[TL].Estoque);
			printf("Preco: R$ ");
			scanf("%f",&Tab[TL].Preco);
			printf("Data de Validade [dd mm aaaa]: ");
			scanf("%d %d %d",&Tab[TL].DtValidade.Dia, &Tab[TL].DtValidade.Mes, &Tab[TL].DtValidade.Ano);
			TL++;
		}
		else
			{
				printf("\nCodigo do Produto ja Cadastrado!\n");
				getch();
			}
					
		printf("\nCodigo: ");
		scanf("%d",&AuxCod);
	}
}

void RELProd(TpProduto Tab[TF], int TL)
{
	int i;
	clrscr();
	printf("\n# # #  Relatorio de Produtos  # # #\n");
	if (TL==0)
		printf("\nNao ha Produtos Cadastrados!\n");
	else
			for(i=0; i<TL; i++)
			{
				printf("\nCodigo: %d\n",Tab[i].Codigo);
				printf("Descricao: %s\n",Tab[i].Descr);
				printf("Estoque: %d\n",Tab[i].Estoque);
				printf("Preco: R$ %.2f\n",Tab[i].Preco);
				printf("Data de Validade: %d/%d/%d\n",Tab[i].DtValidade.Dia, Tab[i].DtValidade.Mes, Tab[i].DtValidade.Ano);
			}
		
	getch();
}

char Menu(void)
{
	clrscr();
	printf("\n# # #  M E N U  # # #\n");
	printf("\n[A] Cadastrar Produtos");
	printf("\n[B] Relatorio de Produtos");
	printf("\n[C] Ordenar Produtos pela Descricao");
	printf("\n[D] Excluir Produtos");
	printf("\n[E] Vender Produtos");
	printf("\n[F] Comprar Produtos");
	printf("\n[G] Exibir Produtos que comecam com uma determinada letra");
	printf("\n[H] Ordenar Produtos pelo preco - Maior par Menor");
	printf("\n[I] Inserir Dados\n");
	printf("\n[ESC] Sair\n");
	printf("\n\nOpcao desejada: ");
	return toupper(getche());
}


void InserirDados(TpProduto TabProd[TF], int &TLP)
{
	TabProd[TLP].Codigo = 5000;
	strcpy(TabProd[TLP].Descr,"Arroz");
	TabProd[TLP].Estoque = 20;
	TabProd[TLP].Preco = 25;
	TabProd[TLP].DtValidade.Dia = 15;
	TabProd[TLP].DtValidade.Mes = 8;
	TabProd[TLP].DtValidade.Ano = 2025;
	TLP++;
	
	TabProd[TLP].Codigo = 9000;
	strcpy(TabProd[TLP].Descr,"Feijao");
	TabProd[TLP].Estoque = 15;
	TabProd[TLP].Preco = 10.56;
	TabProd[TLP].DtValidade.Dia = 18;
	TabProd[TLP].DtValidade.Mes = 11;
	TabProd[TLP].DtValidade.Ano = 2024;
	TLP++;
	
	TabProd[TLP].Codigo = 7000;
	strcpy(TabProd[TLP].Descr,"Leite");
	TabProd[TLP].Estoque = 150;
	TabProd[TLP].Preco = 3.99;
	TabProd[TLP].DtValidade.Dia = 23;
	TabProd[TLP].DtValidade.Mes = 10;
	TabProd[TLP].DtValidade.Ano = 2023;
	TLP++;
	
	printf("\n*** Dados inseridos! ***\n");
	getch();
}


int main(void)
{
	char opcao;
	TpProduto Produtos[TF];
	int TLP=0;
	
	do
	{
		opcao = Menu();
		switch(opcao)
		{
			case 'A': CADProd(Produtos,TLP);
					  break;
					  
			case 'B': RELProd(Produtos,TLP);
					  break;
					  
			case 'C': OrdenarDescr(Produtos,TLP);
					  break;
			
			case 'D': 
					  break;
					  
			case 'I': InserirDados(Produtos,TLP);
					  break;
		}
	}while(opcao!=27);
	
	return 0;
}
