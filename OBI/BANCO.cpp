#include <cstdio>
#include <deque>

using namespace std;

#define MAXC 15

typedef struct{
	int tEnt;
	int tDemora;
	int fila;
} client;

int c, n, tempo, ncout;
int caixas[MAXC];

deque<client> clientes;

int caixaVazio()
{
	int i=0;
	for(; i<c; i++)
	{
		if(!caixas[i])
			break;
	}
	return i;
}

void passaTempoCx()
{
	for(int i=0; i<c; i++)
	{
		if(caixas[i])
			caixas[i]--;
	}
}

void passaTempoClient()
{
	if(clientes.empty())
		return;

	deque<client>::iterator it = clientes.begin();
	for(;it!=clientes.end();it++)
	{
		(*it).fila++;
	}
}

void ImprimeTempoClient()
{
	if(clientes.empty())
	{
		return;
	}

	deque<client>::iterator it = clientes.begin();
	for(;it!=clientes.end();it++)
	{
		printf("%d ", (*it).fila);
	}
}

int main()
{
	tempo = 0;
	ncout = 0;

	scanf("%d %d", &c, &n);
	
	for(int i=0; i<n; i++)
	{
		client temp;
		scanf("%d %d", &temp.tEnt, &temp.tDemora);
		temp.fila = 0;
		clientes.push_back(temp);
	}

	while(!clientes.empty())
	{
		while(!clientes.empty() && (clientes.front()).tEnt <= tempo)
		{
			int cx = caixaVazio();

			if(cx!=c)
			{
				caixas[cx]=(clientes.front()).tDemora;

				if(((clientes.front()).fila - (clientes.front()).tEnt)> 20)
				{
					ncout++;
				}
				
				clientes.pop_front();
			}else{
				break;
			}
		}

		passaTempoClient();
		passaTempoCx();
		tempo++;

		/*printf("t:%d//", tempo);
		for(int i=0; i<c; i++)
			printf("%d ", caixas[i]);
		printf("size:%d", clientes.size());
		printf("   ll  ");
		//ImprimeTempoClient();
		printf("\n");*/
	}
	
	printf("%d\n", ncout);

	return 0;
}
