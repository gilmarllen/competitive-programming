#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int h, p, f;

int main()
{
	while(true)
	{
		scanf("%d %d %d", &h, &p, &f);
		if(!h && !p && !f)
			break;

		stack <int> pilhas[1000];
		queue <int> fila;

		int leitura[1000][1000];
		memset(leitura, 0, sizeof(leitura));
		for(int i=0; i<h; i++)
			for(int j=0; j<p; j++)
				scanf("%d", &leitura[j][i]);

		for(int i=0; i<p; i++)
			for(int j=h-1; j>=0; j--)
				if(leitura[i][j])
					pilhas[i].push(leitura[i][j]);

		int lefila[1000];
		for(int i=0; i<f; i++)
		{
			scanf("%d", &lefila[i]);
			fila.push(lefila[i]);
		}			

		for(int i=p-1; i>=0; i--)
		{
			//printf("i:%d %ld\n", i, pilhas[i].size());
			while(pilhas[i].size()<h)
			{
				pilhas[i].push(fila.front());
				fila.pop();
			}
		}

		for(int i=0; i<p; i++)
		{
			while(pilhas[i].size() < h)
			{
				pilhas[i].push(0);
			}
		}

		//printf("p:%d h:%d\n", p, h);
		for(int j=h-1; j>=0; j--)
		{
			for(int i=0; i<p; i++)
			{
				printf("%d", pilhas[i].top());
				pilhas[i].pop();
				if(i!=p-1)
					printf(" ");
			}
			printf("\n");
		}
	}

	return 0;
}
