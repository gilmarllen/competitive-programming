#include <cstdio>
#include <cctype>
#include <cstring>

char ch;
int j=0;

int main()
{
	while(scanf("%c", &ch)!=EOF)
	{
		if(ch=='\n')
		{
			printf("\n");
			j=0;
			continue;
		}

		if(ch==' ')
		{
			printf(" ");
			continue;
		}

		if(j%2)
			ch = tolower(ch);
		else
			ch = toupper(ch);

		printf("%c", ch);
		j++;
	}

	return 0;
}
