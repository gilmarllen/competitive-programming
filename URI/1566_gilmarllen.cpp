#include <cstdio>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main()
{
	scanf("%d", &n);

	while(n--)
	{
		vector <int> alturas;

		int qtd;
		scanf("%d", &qtd);

		for(int i=0; i<qtd; i++)
		{
			int a;
			scanf("%d", &a);
			alturas.push_back(a);
		}

		sort(alturas.begin(), alturas.end());
		
		printf("%d", alturas[0]);
		for(int i=1; i<qtd; i++)
		{
			printf(" %d", alturas[i]);
		}
		printf("\n");
	}

	return 0;
}
