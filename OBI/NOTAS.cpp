#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

#define MAXN 45050

map<int, int> notas;

int n, maior=-1, ans;

int main()
{
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		int temp;
		scanf("%d", &temp);

		if(notas.count(temp))
		{
			notas[temp]++;
		}else
		{
			notas[temp] = 1;
		}		
	}

	map<int, int>::iterator it;

	for(it=notas.begin(); it!=notas.end();it++)
	{
		if((*it).second == maior)
		{
			ans = (*it).first;
			continue; 
		}

		if((*it).second > maior)
		{
			ans = (*it).first;
			maior = (*it).second;
		}
	}

	printf("%d\n", ans);

	return 0;
}
