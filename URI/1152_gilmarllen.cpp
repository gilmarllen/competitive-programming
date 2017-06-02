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
int _parent[MAXN];
int _rank[MAXN];

int _find(int x) {
    if (_parent[x] == x) return x;
    return _parent[x] = _find(_parent[x]);
}

void _union(int a, int b) {
    int x = _find(a), y = _find(b);
    if (x==y) return; 

    if (_rank[x] < _rank[y]) {
        _parent[x] = y;
    }
    else {
        _parent[y] = x;
        if (_rank[x] == _rank[y]) _rank[x]++;
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

		if(_find(x)!=_find(y))
		{
			custo += ligacoes[i].p;
			_union(ligacoes[i].o, ligacoes[i].d);
			n--;
		}
	}

	return custo;
}

int main()
{
	while(true)
    {
	    scanf("%d %d", &n, &m);
        if((!n) && (!m))
            break;

        int total=0;

	    for(int i=0; i<n; i++)
        {
		    _parent[i] = i;
            _rank[i] = 1;
        }

	    for(int i=0; i<m; i++)
	    {
		    edge e;
		    scanf("%d %d %d", &e.o, &e.d, &e.p);
		    ligacoes.push_back(e);
            total += e.p;
	    }

	    printf("%d\n", total - kruskal());

        ligacoes.clear();
    }

	return 0;
}
