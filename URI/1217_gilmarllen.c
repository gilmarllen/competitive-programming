#include <stdio.h>
#include <string.h>


int main()
{
	int n,i,j=0,o,c;
	double mediaf=0,mediav=0;
	char fruta[5000];
	scanf("%d",&n);
	double v[n];	
	int arm[n];

	for(i=0;i<n;i++)
	{
		scanf("%lf", &v[i]);
		getchar();
		scanf("%[^\n]s", fruta);
		
		if(strlen(fruta)>0)
		{
			j=1;
			for (o=0;o<strlen(fruta);o++)
			{
				if(fruta[o]==' ')
				{
				j++;
				}
			}
		}
		
		printf("day %d: %d kg\n",i+1,j);
		arm[i]=j;
		j=0;	
	}
	



	for(i=0;i<n;i++)
	{
		mediaf+=arm[i];
		mediav+=v[i];
		
	}
	printf("%.2lf kg by day\n", mediaf/n);
	printf("R$ %.2lf by day\n", mediav/n);
	

	return 0;
}
