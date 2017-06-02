#include <cstdio>
using namespace std;

int quad[5][5];
int valor = -1;
int nzeros = 0;

int main()
{

	for(int i=0;i<3; i++)
		for(int j=0;j<3; j++)
		{
			scanf("%d", &quad[i][j]);
			if(quad[i][j]==0) nzeros++;
		}

	bool n_achou = true;

	//Linhas
	for(int i=0;i<3 && n_achou; i++)
	{
		bool temzero = false;
		int soma = 0;
		for(int j=0;j<3; j++)
		{
			if(quad[i][j]==0)
				temzero = true;

			soma += quad[i][j];
		}

		if(!temzero)
		{
			valor = soma;
			n_achou = false;
			break;
		}
	}

	//Colunas
	for(int i=0;i<3 && n_achou; i++)
	{
		bool temzero = false;
		int soma = 0;
		for(int j=0;j<3; j++)
		{
			if(quad[j][i]==0)
				temzero = true;

			soma += quad[j][i];
		}

		if(!temzero)
		{
			valor = soma;
			n_achou = false;
			break;
		}
	}

	//Diagonais
	int soma = quad[0][0] + quad[1][1] + quad[2][2];
	if((quad[0][0] && quad[1][1] && quad[2][2]) && n_achou)
	{
		valor = soma;
		n_achou = false;
	}


	soma = quad[0][2] + quad[1][1] + quad[2][0];
	if((quad[0][2] && quad[1][1] && quad[2][0]) && n_achou)
	{
		valor = soma;
		n_achou = false;
	}

	if(n_achou)
	{
		valor=0;
		for(int i=0;i<3; i++)
			for(int j=0;j<3; j++)
				valor+=quad[i][j];

		valor /= 2;
	}

	/*-----------------Preenchimento-----------*/

	while(nzeros)
	{
		int a,b;

		//Linhas
		for(int i=0;i<3; i++)
		{
			int zeros = 0;
			int soma = 0;
			for(int j=0;j<3; j++)
			{
				if(quad[i][j]==0)
				{
					zeros++;
					a = i;
					b = j;
				}

				soma += quad[i][j];
			}

			if(zeros==1)
			{
				quad[a][b] = valor - soma;
				nzeros--;
			}
		}

		//Colunas
		for(int i=0;i<3; i++)
		{
			int zeros = 0;
			int soma = 0;
			for(int j=0;j<3; j++)
			{
				if(quad[j][i]==0)
				{
					zeros++;
					a = j;
					b = i;
				}

				soma += quad[j][i];
			}

			if(zeros==1)
			{
				quad[a][b] = valor - soma;
				nzeros--;
			}
		}

		int zero_aux=0;
		//Diagonais
		int soma = quad[0][0] + quad[1][1] + quad[2][2];
		if(quad[0][0]==0)
		{
			zero_aux++; a=0; b=0;
		}

		if(quad[1][1]==0)
		{
			zero_aux++; a=1; b=1;
		}

		if(quad[2][2]==0)
		{
			zero_aux++; a=2; b=2;
		}

		if(zero_aux==1)
		{
			quad[a][b] = valor - soma;
			nzeros--;
		}


		zero_aux=0;
		soma = quad[0][2] + quad[1][1] + quad[2][0];
		if(quad[0][2]==0)
		{
			zero_aux++; a=0; b=2;
		}

		if(quad[1][1]==0)
		{
			zero_aux++; a=1; b=1;
		}

		if(quad[2][0]==0)
		{
			zero_aux++; a=2; b=0;
		}

		if(zero_aux==1)
		{
			quad[a][b] = valor - soma;
			nzeros--;
		}
	}

	for(int i=0;i<3; i++)
	{
		for(int j=0;j<2; j++)
			printf("%d ", quad[i][j]);
		printf("%d\n", quad[i][2]);
	}

	return 0;
}
