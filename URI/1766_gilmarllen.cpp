#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int t, teste=1;

typedef struct {
	char nome[100];
	int peso;
	int idade;
	double altura;
} rena;

bool cmp(rena a, rena b)
{
	if(a.peso==b.peso)
	{
		if(a.idade==b.idade)
		{
			if(a.altura==b.altura)
			{
				return strcmp(a.nome, b.nome) > 0;
			}		
			return a.altura < b.altura;
		}
		return a.idade < b.idade;
	}

	return a.peso > b.peso;
}

int main()
{
	scanf("%d", &t);

	while(t--)
	{
		int n, m;
		scanf("%d %d\n", &n, &m);

		vector<rena> vecRenas;

		for(int i=0; i<n; i++)
		{
			rena r;
			scanf("%s %d %d %lf\n", r.nome, &r.peso, &r.idade, &r.altura);
			vecRenas.push_back(r);
		}

		printf("CENARIO {%d}\n", teste);

		sort(vecRenas.begin(), vecRenas.end(), cmp);

		for(int i=0; i<m; i++)
			printf("%d - %s\n", i+1, vecRenas[i].nome);

		teste++;
	}

	return 0;
}
