#include <cstdio>
#include<vector>
#include<cstring>
using namespace std;

vector <int> adj[50];
int visitado[50];
int ans;
int pd[50][50];

int dfs(int atual, int n)
{
	if(pd[atual][n])
		return pd[atual][n];

	if(atual>n)
		return 0;

	if(atual==n)
	{
		return 1;
	}

	int rtn=0;

	visitado[atual] = 1;

	int nVizinhos = adj[atual].size();
	for(int i=0; i<nVizinhos; i++)
	{
		if(!visitado[ adj[atual][i] ]) 
		{
			int d = dfs(adj[atual][i], n);
			rtn+=d;
			pd[adj[atual][i]][n] = d;
		}
	}
	//printf("%d\n", atual);
	visitado[atual] = 0;
	return rtn;
}

int main()
{
	for(int i=0; i<40;i++)
	{
		adj[i].push_back(i+1);
		adj[i].push_back(i+2);
	}

	while(true)
	{
		int n;
		scanf("%d", &n);
		if(!n)
			break;

		ans=0;
		memset(visitado, 0, sizeof(visitado));
		
		printf("%d\n", dfs(0, n));
	}

	return 0;
}
