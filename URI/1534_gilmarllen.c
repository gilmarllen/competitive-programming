#include <stdio.h>
int con = 1;
int main()
{
	int n, i=0, j=0;

	
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if((i+j) == (n-1))
				{
					printf("2");
				}				
				else
				{
					if(i == j)
					{
						printf("1");
					}
					else{
						printf("3");
					}
				}
			}
			printf("\n");
		}
	}
	return 0;
}
