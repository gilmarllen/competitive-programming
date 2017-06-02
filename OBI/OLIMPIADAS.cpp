#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 110

using namespace std;

typedef struct{
	int num;
	int qtdM;
} pais;

int n, m;

pais vet[MAXN];

int comp(const void* a, const void* b)
{
	pais* x = (pais*)a;
	pais* y = (pais*)b;

	pais c = *x;
	pais d = *y;

	if(c.qtdM < d.qtdM)
	{
		return 1;
	}

	if(c.qtdM > d.qtdM)
	{
		return -1;
	}

	if(c.qtdM == d.qtdM)
	{
		if(c.num > d.num)
			return 1;

		if(c.num < d.num)
			return -1;
	}

	return 0;
}

int main()
{
	int o, p, b;

	scanf("%d %d", &n, &m);

	//memset(vet, 0, sizeof(vet));

	for(int i=0; i<=n; i++)
	{
		vet[i].num = i;
		vet[i].qtdM = 0;
	}
	vet[0].qtdM = -1;

	for(int i=0; i<m; i++)
	{
		scanf("%d %d %d", &o, &p, &b);
		vet[o].qtdM++;
		vet[p].qtdM++;
		vet[b].qtdM++;
	}

	//for(int i=1; i<=n; i++)
	//{
	//	printf("%d %d\n", vet[i].num, vet[i].qtdM);
	//}

	qsort(vet, n+1, sizeof(pais), comp);

	for(int i=0; i<n; i++)
	{
		printf("%d ", vet[i].num);
		
	}
	printf("\n");

	return 0;
}
