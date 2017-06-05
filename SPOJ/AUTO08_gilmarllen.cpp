#include <cstdio>

#define MAXE 1000000+10

using namespace std;

char ent;
int c, ans;

int main()
{
	scanf("%d\n", &c);

	for(int i=0; i<c; i++)
	{
		scanf("%c", &ent);
		if(ent=='A')
			ans++;

		if(ent=='P')
			ans+=2;

		if(ent=='C')
			ans+=2;
	}

	printf("%d\n", ans);

	return 0;
}
