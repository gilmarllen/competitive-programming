#include <cstdio>
#include <deque>

using namespace std;

#define MAXC 1123
#define MAXL 1000010

int i, p, tempo;
int vendedor[MAXC];
int nLig[MAXC];

deque<int> ligacoes;

int vendedorDisp()
{
	int j=0;

	for(j=0; j<i; j++)
	{
		if(vendedor[j]==0)
		{
			return j;
		}
	}

	return j;
}

int passaTempoVend()
{
	for(int j=0; j<i; j++)
	{
		vendedor[j] -= 1;
	}
}

int main()
{
	tempo = 0;

	scanf("%d %d", &i, &p);
	
	for(int j=0; j<p; j++)
	{
		int temp;
		scanf("%d", &temp);
		ligacoes.push_back(temp);
	}

	while(!ligacoes.empty())
	{
		while(!ligacoes.empty())
		{
			int vDisp = vendedorDisp();

			if(vDisp!=i)
			{
				vendedor[vDisp]=ligacoes.front();

				nLig[vDisp]++;

				ligacoes.pop_front();
			}else{
				break;
			}
		}

		passaTempoVend();
	}

	for(int j=0; j<i; j++)
	{
		printf("%d %d\n", j+1, nLig[j]);
	}

	return 0;
}
