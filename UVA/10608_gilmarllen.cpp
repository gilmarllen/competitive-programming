#include <cstdio>
#include <algorithm>

using namespace std;
 
#define MAXN 30010

int t, n, m, pai[MAXN], peso[MAXN], qtd[MAXN];

void initFind(int tam)
{
	for(int i=0; i<=tam; i++)
	{
		pai[i] = i;
		peso[i] = 0;
		qtd[i] = 1;
	}
}

//http://noic.com.br/informatica/curso-noic-de-informatica/aula-15-union-find/

int find(int x)
{
	if(pai[x]==x) return x;
	return pai[x]=find(pai[x]);
}

void join(int x, int y)
{

	x=find(x);
	y=find(y);

	if(x==y) return;
	
	if(peso[x]<peso[y]){		
		 pai[x]=y;
		 qtd[y]+=qtd[x];
	}

	if(peso[x]>peso[y]){
		
		 pai[y]=x;
		 qtd[x]+=qtd[y];
	}

	if(peso[x]==peso[y]){
		pai[x]=y;
		peso[y]++;
		qtd[y]+=qtd[x];
	}
}

int main()
{
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d", &n, &m);

		initFind(n);

		for(int i=0; i<m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			join(a,b);
		}

		sort(qtd, qtd+n+1);
		printf("%d\n",qtd[n]);
	}	

	return 0;
}
