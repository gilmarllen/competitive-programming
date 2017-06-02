#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAXN 100010
#define TAMN 20
using namespace std;

typedef struct{
	char nome[TAMN];
	int pnts[12];
	int tot;
} jogador;

void LePnts(int* pnts)
{
	for(int i=0; i<12; i++)
	{
		scanf("%d", &pnts[i]);
	}
}

void OrdenaPnts(int* pnts)
{
	sort(&pnts[0], &pnts[12]);
}

int ContaPnts(int* pnts)
{
	int total = 0;
	for(int i=1; i<11;i++)
	{
		total += pnts[i];
	}
	
	return total;
}

int compJog(const void* a, const void* b)
{
	jogador* x = (jogador*) a;
	jogador* y = (jogador*) b;

	if(x->tot > y->tot)
		return -1;

	if(x->tot < y->tot)
		return 11;

	return strcmp(x->nome, y->nome);
}

int j;

int main()
{
	int t=1, aux=1;

	scanf("%d", &j);

	while(j)
	{
		jogador vetj[j];

		for(int i=0; i<j; i++)
		{
			scanf("\n%s\n", vetj[i].nome);
			LePnts(vetj[i].pnts);
			OrdenaPnts(vetj[i].pnts);
			vetj[i].tot = ContaPnts(vetj[i].pnts);
		}

		qsort(vetj, j, sizeof(jogador), compJog);

		printf("Teste %d\n", t);
		for(int i=0; i<j; i++)
		{
			if(vetj[i].tot == vetj[i-1].tot && i)
				printf("%d %d %s\n", aux, vetj[i].tot, vetj[i].nome);
			else{
				aux = i+1;
				printf("%d %d %s\n", aux, vetj[i].tot, vetj[i].nome);
			}
		}

		printf("\n");
		scanf("%d", &j);
		t++;
	}

	

	return 0;
}
