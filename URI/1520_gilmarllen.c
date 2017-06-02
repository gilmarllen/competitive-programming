#include <stdio.h>
#include <string.h>

#define MAXP 110

int ncx, consulta;
int prat[MAXP];

int main()
{
	while(scanf("%d", &ncx)!=EOF)
	{
		memset(prat, 0, sizeof(prat));

		int i=0, cont=0;
		for(i=0; i<ncx; i++)
		{		
			int x, y;
			scanf("%d %d", &x, &y);

			int j=0;
			for(j=x; j<=y; j++)
				prat[j]++;
		}

		scanf("%d", &consulta);
		int acum=0;
		for(i=1; i<consulta; i++)
		{
			
			acum+=prat[i];
			//printf("%d//%d ", prat[i], acum);
		}
		
		if(prat[consulta])
		{
			printf("%d found from %d to %d\n", consulta, acum, acum+prat[consulta]-1);
		}else{
			printf("%d not found\n", consulta);
		}
		
	}

	return 0;
}
