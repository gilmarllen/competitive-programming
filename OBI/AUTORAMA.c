#include <stdlib.h>
#include <stdio.h>

#define MAXM 10010

typedef struct{
	int checkpnt;
	int ordem;
	int numero;
} car;

car cpt[MAXM];

int compara(const void* a, const void* b)
{
	car* x = (car*)a;
	car* y = (car*)b;

	if(x->checkpnt > y->checkpnt)
	{
		return 1;
	}

	if(x->checkpnt < y->checkpnt)
	{
		return -1;
	}

	if(x->ordem < y->ordem)
	{
		return 1;
	}

	if(x->ordem > y->ordem)
	{
		return -1;
	}

	if(x->numero < y->numero)
	{
		return -1;
	}

	return 1;
}

int main()
{
	int i=0, k=0, n=0, m=0, index, temp, calc;
	
	scanf("%d %d %d", &k, &n, &m);	

	for(i=0; i<=n; i++)
	{
		cpt[i].checkpnt = 0;
		cpt[i].ordem = 0;
		cpt[i].numero = i;
	}	

	for(i=0; i<m; i++)
	{
		scanf("%d %d", &index, &temp);

		calc = cpt[index].checkpnt % k;
	
		if((calc+1) == temp)
		{
			cpt[index].checkpnt++;
			cpt[index].ordem = i;
		}
	}

	qsort(cpt, n+1, sizeof(car), compara);

	for(i=n; i>0; i--)
	{
		printf("%d ", cpt[i].numero);
	}	
	printf("\n");

	return 0;
}
