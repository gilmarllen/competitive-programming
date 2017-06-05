#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define MAXN 110

using namespace std;

int teste=1, e, l;
int visitado[MAXN];
vector<int> grafo[MAXN];

void bfs()
{
	queue<int> fila;
	fila.push(1);

	while(!fila.empty())
	{
		int v = fila.front();
		visitado[v] = 1;

		for(vector<int>::iterator it = grafo[v].begin(); it!=grafo[v].end(); it++)
		{
			if(visitado[(*it)]==0)
			{
				//printf("%d %d\n", v, (*it));
				fila.push((*it));
			}
		}

		fila.pop();
	}
}

int main()
{
	scanf("%d %d", &e, &l);
	
	while((e!=0) && (l!=0))
	{
		memset(visitado, 0, sizeof(visitado));
		
		for(int i=0; i<=e; i++)
			grafo[i].clear();

		

		for(int i=0; i<l; i++)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}

		/*for(int i=0; i<=e; i++)
			for(vector<int>::iterator it=grafo[i].begin(); it!=grafo[i].end(); it++)
				printf("%d %d\n", i, (*it));*/
		
		bfs();

		/*for(int i=0; i<=e; i++)
			printf("%d ", visitado[i]);*/

		printf("Teste %d\n", teste);

		int normal=1;

		for(int i=1; i<=e; i++)
			if(visitado[i]==0)
				normal=0;

		scanf("%d %d", &e, &l);

		if(normal==1)
			printf("normal\n");
		else
			printf("falha\n");

		if((e!=0) && (l!=0))
			printf("\n");

		teste++;
		
	}

	return 0;
}
