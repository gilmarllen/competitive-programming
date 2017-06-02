#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 9

int matriz[MAXN][MAXN];

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	if(a==b)
	{
		printf("%d\n", a);
	}else{
		printf("%d\n",max(a,b));
	}

	
	

	return 0;
}
