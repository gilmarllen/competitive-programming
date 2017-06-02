#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100010

int n, k;
int casas[MAXN];
int ans = 999999999;

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	scanf("%d %d", &n, &k);

	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &casas[i]);
	}

	sort(casas, &casas[n], cmp);

	for(int i=0; i<=k; i++)
	{
		ans = min(ans, (casas[(n-1) - i] - casas[k - i]));
	}

	printf("%d", ans);

	return 0;
}
