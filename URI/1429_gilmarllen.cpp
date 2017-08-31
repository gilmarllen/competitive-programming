#include <cstdio>

int ent;
int fat[10];

long long int converte(int num, int pos)
{
	if(pos==6) return 0;

	return ((fat[pos] * (num%10)) + converte(num/10, pos+1));
}

int main()
{
	fat[1] = 1;
	for(int i=2; i<=5; i++)
		fat[i] = fat[i-1] * i;

	while(true)
	{
		scanf("%d", &ent);
		if(ent==0) break;

		printf("%lld\n", converte(ent, 1));

	}

	return 0;
}
