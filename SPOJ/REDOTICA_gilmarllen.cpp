#include <cstdio>
#include <vector>
#include <algorithm>

#define MAXN 200000

using namespace std;

typedef struct edge {
	int o, d, p;
} Edge;

int parent[MAXN], rank[MAXN];
int n, m, t=1;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void UNION(int a, int b) {
    int x = find(a), y = find(b);
    if (x==y) return; 

    if (rank[x] < rank[y]) {
        parent[x] = y;
    }
    else {
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

bool compara(Edge a, Edge b)
{
	return a.p < b.p;
}

void kruskal(vector <Edge> ligacoes)
{
	int N = n, M = ligacoes.size();
	for(int i=1; i<=n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}

	sort(ligacoes.begin(), ligacoes.end(), compara);

	/*for(int i=0; i<m; i++)
	{
		printf("%d\n", ligacoes[i].p);
	}*/

	for(int i=0; i<M && N>1; i++)
	{
		int x = ligacoes[i].o;
		int y = ligacoes[i].d;

		if(find(x)!=find(y))
		{
			UNION(ligacoes[i].o, ligacoes[i].d);
			printf("%d %d\n", min(x, y), max(x, y));
			N--;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	while(n!=0 || m!=0)
	{
		vector <Edge> ligacoes;
		for(int i=0; i<m; i++)
		{
			Edge e;
			scanf("%d %d %d", &e.o, &e.d, &e.p);
			ligacoes.push_back(e);
		}
		
		printf("Teste %d\n", t);
		kruskal(ligacoes);

		scanf("%d %d", &n, &m);
		
		t++;
		printf("\n");
	}

	return 0;
}
