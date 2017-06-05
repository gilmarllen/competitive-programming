#include <cstdio>

#define MAXN 150

using namespace std;

int e, l, t=1;
int parent[MAXN];
int rank[MAXN];
int numJoins;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void UNION(int a, int b) {
    int x = find(a), y = find(b);
    if (x==y) return; 
	numJoins--;
    if (rank[x] < rank[y]) {
        parent[x] = y;
    }
    else {
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

int main()
{
	scanf("%d %d", &e, &l);

	while(e!=0 || l!=0)
	{
		numJoins = e;
		for(int i=1; i<=e; i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}

		for(int i=0; i<l; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			UNION(a, b);
		}

		printf("Teste %d\n", t);

		if(numJoins==1)
			printf("normal\n");
		else
			printf("falha\n");

		printf("\n");

		scanf("%d %d", &e, &l);
		t++;
	}

	return 0;
}
