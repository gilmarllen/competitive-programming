#include <cstdio>
#include <cstring>

int v, m;
int moedas[1123];
int tab[112345][1123];

bool pd(int valor, int atual)
{
	if(valor == 0)
		return true;

	if(atual == m)
		return false;

	if(valor < 0)
		return false;

	if(tab[valor][atual] != -1)
		return tab[valor][atual];

	return tab[valor][atual] = (pd(valor, atual+1) || pd(valor-moedas[atual], atual+1));
}

int main()
{
	scanf("%d %d", &v, &m);

	for(int i=0; i<m; i++)
		scanf("%d", &moedas[i]);

	memset(tab, -1, sizeof(tab));

	if(pd(v, 0))
		printf("S\n");
	else
		printf("N\n");

	return 0;
}
