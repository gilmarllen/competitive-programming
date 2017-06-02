#include <cstdio>
#include <cstring>

int d;
char n[112];

int main()
{
	while(true)
	{
		scanf("%d %s\n", &d, n);
		if(!d)
			break;
		//printf("ddd\n");
		int tam = strlen(n);
		for(int i=0; i<tam; i++)
		{
			if(n[i] - '0' == d)
				n[i] = 'a';
		}

		int w=0;
		while(n[w] == '0' || n[w] == 'a')
		{
			n[w] = 'a';
			w++;
		}

		bool zero = true;
		for(int i=0; i<tam; i++)
			if(n[i]!='a')
			{
				zero = false;
				printf("%c", n[i]);
			}

		if(zero)
			printf("0");
		printf("\n");
	}

	return 0;
}
