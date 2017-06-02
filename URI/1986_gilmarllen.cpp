#include <cstdio>

int main()
{
	int n;

	scanf("%d\n", &n);

	char e1, e2;

	while(n--)
	{
		scanf("%c%c ", &e1, &e2);

		if(e1=='6')
		{
			if(e2>='0' && e2<='9')
			{
				printf("%c", 97+(e2-'1'));
			}else{
				printf("%c", 106+(e2-'A'));
			}
		}

		if(e1=='7')
		{
			if(e2>='0' && e2<='9')
			{
				printf("%c", 112+(e2-'0'));
			}else{
				printf("%c", 122+(e2-'A'));
			}
		}		
		
	}

	printf("\n");

	return 0;
}
