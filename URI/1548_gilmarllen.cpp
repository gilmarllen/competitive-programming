#include <cstdio>
#include <algorithm>

using namespace std;

int n;

int main()
{
	scanf("%d", &n);

	while(n--)
	{
		int tam, ans=0;
		scanf("%d", &tam);

		int vetA[tam];
		int vetB[tam];

		for(int i=0; i<tam; i++)
		{
			scanf("%d", &vetA[i]);
			vetB[i]=vetA[i];
		}

		sort(vetB, vetB+tam);
		reverse(vetB, vetB+tam);
		for(int i=0; i<tam; i++)
		{
			if(vetA[i]==vetB[i])
				ans++;
		}

		printf("%d\n", ans);
	}

	return 0;
}
