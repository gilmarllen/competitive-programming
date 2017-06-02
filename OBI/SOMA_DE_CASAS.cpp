#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100010

using namespace std;

int n;
long int soma;

long int casas[MAXN];

int bbin(int index)
{
	int ini = index+1;
	int fim = n-1;	

	while(ini<=fim)
	{
		int mid = (ini+fim)/2;
		int s = casas[mid] + casas[index];
		if(s == soma)
			return mid;

		if(s < soma)
			ini = mid+1;

		if(s > soma)
			fim = mid -1;
	}

	return -1;
}

int main()
{
	int i=0, x=-1;

	scanf("%d", &n);

	for(i=0; i<n; i++)
		scanf("%ld", &casas[i]);

	scanf("%ld", &soma);
	
	for(i=0; i<n; i++)
	{
		x = bbin(i);
		if(x>=0)
			break;
	}

	printf("%ld %ld\n", casas[i], casas[x]);

	return 0;
}
