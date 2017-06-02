#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <set>

#define MAXN 100100

using namespace std;

int teste=1, e, l;
int visitado[MAXN];
set<int> normal;
vector<int> grafo[MAXN];

void bfs(int gilmito)
{
	queue<int> fila;
	fila.push(gilmito);

	while(!fila.empty())
	{
		int v = fila.front();
		visitado[v] = 1;
		normal.insert(v);

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

	for(int i=0; i<l; i++)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}


	for(int k=1; k<=e; k++){
		if(visitado[k]) continue;

		/*for(int i=0; i<=e; i++)
			for(vector<int>::iterator it=grafo[i].begin(); it!=grafo[i].end(); it++)
				printf("%d %d\n", i, (*it));*/
		
		bfs(k);

/*		for(int i=0; i<=e; i++)
			printf("%d ", visitado[i]);
		printf("\n");*/

		if(normal.size() == e) break;
		teste++;
	}
		printf("%d\n", teste);
		

	return 0;
}
