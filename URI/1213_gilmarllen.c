#include <stdio.h>

int main()
{
    int l=1, i=1, num;

    while(scanf("%d",&num)!=EOF)
    {
        l=1;
        i=1;
        while (l%num){
		    l = (l*10 + 1)%num;
		    i++;
	    }
        printf("%d\n",i);
    }

	return 0;
}
