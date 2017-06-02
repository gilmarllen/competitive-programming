#include <stdio.h>

int valor(char* str, int elemento)
{
	int valor=0, i=0;
	
	while(str[i]!='\0')
	{
		valor = valor + i + elemento + (str[i] - 'A');		

		i++;
	}
	
	
	return valor;
}

int main()
{
	int n,i=0,q,j=0,hash=0;
	char str[51];

	scanf("%d",&n);

	while(i<n)
	{
		scanf("%d",&q);
		hash = 0;
		j=0;
		while(j<q)
		{
			scanf("%s",str);
			hash = hash + valor(str,j);

			j++;
		}
		
		printf("%d\n",hash);

		i++;
	}	


	return 0;
}
