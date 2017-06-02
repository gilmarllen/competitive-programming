#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 30;

int n;
int entrada[MAXN];
int chegada[MAXN];

int localiza(int num)
{
	int i=0;
	for(i=1; i<=n; i++)
	{
		if(entrada[i]==num)
			break;
	}

	return i;
}

int main()
{
	while(scanf("%d", &n)!=EOF)
	{
		for(int i=1; i<=n; i++)
			scanf("%d", &entrada[i]);

		for(int i=1; i<=n; i++)
			scanf("%d", &chegada[i]);


		int ans=0;
		for(int i=1; i<=n; i++)
		{
			int pos = localiza(chegada[i]);
			while(entrada[i]!=chegada[i])
			{
				swap(entrada[pos], entrada[pos-1]);
				pos--;
				ans++;
			}
		}

		printf("%d\n", ans);
		
	}

	return 0;
}
