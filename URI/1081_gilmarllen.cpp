#include <cstdio>
#include <cstring>
#include <set>
#define MAXV 25

using namespace std;

set<int> adj[MAXV];
int visitado[MAXV];

void printa_espacos(int n_espacos)
{
	while(n_espacos--)
		printf(" ");
}

void dfs(int v, int n_espacos)
{	
	visitado[v] = 1;
	
	for (set<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++)
	{
		int w = *(it);
		if (!visitado[w])
		{
			printa_espacos(n_espacos);
			printf("%d-%d pathR(G,%d)\n", v, w, w);

			dfs(w, n_espacos+2);
		}
		else
		{
			printa_espacos(n_espacos);
			printf("%d-%d\n", v, w);
		}
	}
}

bool tem_mais_de1_n_visitado(int N)
{
	int qtd=0;
	for(int i=0; i<N; i++)
	{
		if(visitado[i]==0)
			qtd++;
	}

	return qtd>1;
}

int main()
{
	int ncasos=0, casoAtual=1;
	scanf("%d", &ncasos);

	while(ncasos--)
	{
		memset(visitado, 0, sizeof(visitado));

		for(int i=0; i<MAXV; i++)
			adj[i].clear();

		int N, C;
		scanf ("%d %d", &N, &C);
	
		int X, Y;
		for (int i = 0; i < C; i++)
		{
			scanf ("%d %d", &X, &Y);
			adj[X].insert(Y);
		}
	
		/*for (i = 1; i <= N; i++)
		{
			printf ("%d -> ", i);
			for (vector<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++)
				printf ("%d ", *it);
			printf ("\n");
		}*/

		printf("Caso %d:\n", casoAtual);
		
		for(int i=0; i<N; i++)
		{
			if(visitado[i]==0)
			{
				dfs(i, 2);
				if(adj[i].size()>0)
					//if(tem_mais_de1_n_visitado(N) && ncasos==0)
						printf("\n");
			}
		}

		casoAtual++;
	}

	return 0;
}
