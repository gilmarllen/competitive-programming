#include <stdio.h>

int FoiResgatado(int i, int* resgatados, int r)
{
	int con=0;
	for(con=0; con<r; con++)
	{
		if(resgatados[con] == i)
		{
			return 1;
		}
	}
	return 0;
}

int main(){
	int r=0, n=0, i=0, aux=0;

	while(scanf("%d %d",&n,&r)!=EOF)
	{
		int resgatados[r];
		for(i=0; i<r; i++)
		{
			scanf("%d",&resgatados[i]);
		}
		
		aux=0;
		for(i=1; i!=n+1; i++)
		{
			//printf("i:%d\n",i);
			if(!FoiResgatado(i, resgatados, r))
			{
				printf("%d ",i);				
				aux=1;
			}
		}
		if(aux)
		{
			printf("\n");
		}else
		{
			printf("*\n");
		}
	}
	return 0;
}
