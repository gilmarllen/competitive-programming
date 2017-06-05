#include <cstdio>

using namespace std;

int parent[100020];
int rank[100020];
int numFam;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void UNION(int a, int b) {
    int x = find(a), y = find(b);
    if (x==y) return; 
	numFam--;
    if (rank[x] < rank[y]) {
        parent[x] = y;
    }
    else {
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

int n, m;

int main()
{
	scanf("%d %d", &n, &m);

	numFam = n;
	for(int i=1; i<=n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}

	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		UNION(a, b);
	}

	printf("%d\n", numFam);

	return 0;
}
