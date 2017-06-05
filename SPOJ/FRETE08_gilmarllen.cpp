#include <cstdio>
#include <vector>
#include <algorithm>

#define MAXN 100020

using namespace std;

typedef struct {
	int o, d, p;
} edge;

int n, m;
vector<edge> ligacoes;
int parent[MAXN];
int rank[MAXN];

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

bool compara(edge a, edge b)
{
	return a.p < b.p;
}

int kruskal()
{
	int custo = 0;
	
	sort(ligacoes.begin(), ligacoes.end(), compara);

	for(int i=0; i<m && n>1; i++)
	{
		int x = ligacoes[i].o;
		int y = ligacoes[i].d;

		if(find(x)!=find(y))
		{
			custo += ligacoes[i].p;
			UNION(ligacoes[i].o, ligacoes[i].d);
			n--;
		}
	}

	return custo;
}

int main()
{
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++)
		parent[i] = i;

	for(int i=0; i<m; i++)
	{
		edge e;
		scanf("%d %d %d", &e.o, &e.d, &e.p);
		ligacoes.push_back(e);
	}

	printf("%d\n", kruskal());

	return 0;
}
