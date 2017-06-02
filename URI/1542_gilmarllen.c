#include <stdio.h>

int main()
{
	
	int q,d,p;
	
	while(1)
	{	
	scanf("%d",&q);
	if(q==0)
	{
		break;
	}
	else
	{
		scanf("%d %d",&d,&p);
		int npag = -p*q*d/(q-p);
		if(npag==1)
			printf("1 pagina\n");
		else
			printf("%d paginas\n", npag);
	}
	}
	return 0;
}
