#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

#define MAXN 100

int tem[MAXN];
int n, b;

bool certo()
{
	for(int i=0; i<=n; i++)
		if(tem[i]==0)
			return false;

	return true;
}

int main()
{
	while(true)
	{
		scanf("%d %d", &n, &b);
		if((n==0) && (b==0))
			break;

		memset(tem, 0, sizeof(tem));

		vector <int> restaram;
		for(int i=0; i<b; i++)
		{
			int le;
			scanf("%d", &le);
			restaram.push_back(le);
		}

		for(int i=0; i<b; i++)
			for(int j=0; j<b; j++)
			{
				tem[(int)abs(restaram[i] - restaram[j])] = 1;
			}

		if(certo())
			printf("Y\n");
		else
			printf("N\n");
	}

	return 0;
}
