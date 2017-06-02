#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

#define MAXN 45050

map<long long int, int> casas;

int n, m, ans=0, atual;

int main()
{
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++)
	{
		long long int temp;
		scanf("%lli", &temp);
		casas[temp] = i;
	}

	atual=0;
	for(int i=0; i<m; i++)
	{
		long long int temp;
		scanf("%lli", &temp);
		ans += abs(casas[temp] - atual);
		atual = casas[temp];
	}

	printf("%d\n", ans);

	return 0;
}
