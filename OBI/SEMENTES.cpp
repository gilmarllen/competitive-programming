#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100000+5

int f, r, maxim=-1;
int posgotas[MAXN];

int main()
{
	scanf("%d %d", &f, &r);

	for(int i=0; i<r; i++)
		scanf("%d", &posgotas[i]);

	maxim = max(posgotas[0]-1, f-posgotas[r-1]);

	for(int i=0; i<r-1; i++)
	{
		int delta = (posgotas[i+1] - posgotas[i])/2;
		/*if(delta%2)
		{
			delta/=2;
			delta++;
		}else{
			delta/=2;
		}*/
		
		maxim = max(maxim, delta);
	}

	printf("%d\n", maxim);

	return 0;
}
