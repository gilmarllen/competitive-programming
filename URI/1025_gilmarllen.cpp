#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include <algorithm>

using namespace std;

int ordena(const void* a, const void* b)
{
	int* x = (int*)a;
	int* y = (int*)b;

	int p = (int)*x;
	int q = (int)*y;

	if(p==q)
		return 0;

	if(p>q)
		return 1;

	return -1;
}

int main()
{
	int nPecas, nConsultas, teste=1, i=0, temp, j=0, aux=0;

	scanf("%d %d", &nPecas, &nConsultas);
	while(nPecas || nConsultas)
	{
		vector<int> pecas;

		for(i=0; i<nPecas; i++)
		{
			scanf("%d", &temp);
			pecas.push_back(temp);
		}

		/*printf("\nAntes:\n");
		for(i=0; i<pecas.size(); i++)
		{
			printf("%d ", pecas[i]);
		}*/

		//qsort(&pecas[0], pecas.size(), sizeof(vector<int>), ordena);
		sort(pecas.begin(), pecas.end());

		/*printf("\nDepois:\n");
		for(i=0; i<pecas.size(); i++)
		{
			printf("%d ", pecas[i]);
		}*/		

		printf("CASE# %d:\n", teste);

		for(i=0; i<nConsultas; i++)
		{
			scanf("%d", &temp);
			aux=0;
			for(j=0; j<pecas.size(); j++)
			{
				if(temp==pecas[j])
				{
					aux=1;
					printf("%d found at %d\n", temp, j+1);
					break;
				}
			}
			if(!aux)
				printf("%d not found\n", temp);
		}

		scanf("%d %d", &nPecas, &nConsultas);
		teste++;
	}

	return 0;
}
