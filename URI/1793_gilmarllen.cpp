#include <cstdio>
#include <vector>
using namespace std;

int n;

int main()
{
	while(true)
	{
		scanf("%d", &n);
		if(!n)
			break;

		vector <int> pessoas;
		for(int i=0; i<n; i++)
		{
			int a;
			scanf("%d", &a);
			pessoas.push_back(a);
		}
		
		int ans=10;
		for(int i=0; i<n-1; i++)
		{
			if(pessoas[i+1] <= pessoas[i]+10)
				ans += pessoas[i+1] - pessoas[i];
			else
				ans += 10;
		}

		printf("%d\n", ans);

	}

	return 0;
}
