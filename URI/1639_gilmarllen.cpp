#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
int a1[10];
// 1 2 ||3 4 5 6|| 7 8
void indexa(int n)
{
	int i=8;
	while(n)
	{
		a1[i] = n%10;
		i--;
		n/=10;
	}
}

int meio()
{
	int rtn = 0;
	rtn+=a1[6];
	rtn+=a1[5]*10;
	rtn+=a1[4]*100;
	rtn+=a1[3]*1000;
	return rtn;
}

int main()
{
	while(true)
	{
		int a0, ans=1;
		scanf("%d", &a0);
		if(!a0)
			break;

		set <int> feitos;
		feitos.insert(a0);

		int m=a0;
		while(true)
		{
			memset(a1, 0, sizeof(a1));
			indexa(m*m);
			//for(int i=1; i<=8; i++)	printf("%d ", a1[i]);
			m = meio();
			//printf("meio::%d\n", m);
			if(feitos.find(m)!=feitos.end())
				break;
			feitos.insert(m);
			ans++;
		}

		printf("%d\n", ans);
	}

	return 0;
}
