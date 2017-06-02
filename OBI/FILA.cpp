#include <cstdio>
#include <set>

#define MAXN 50010

using namespace std;

int n, m;
int fila[MAXN];

set<int> ret;

int main()
{
	scanf("%d", &n);

	for(int i=0; i<n; i++)
		scanf("%d", &fila[i]);

	scanf("%d", &m);
	for(int i=0; i<m; i++)
	{
		int temp;
		scanf("%d", &temp);
		ret.insert(temp);
	}

	for(int i=0; i<n; i++)
	{
		if(!ret.count(fila[i]))
		{
			printf("%d ", fila[i]);
		}
	}
	printf("\n");

	return 0;
}
