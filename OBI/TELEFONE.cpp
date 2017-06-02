#include <cstdio>
#include <map>

using namespace std;

#define MAXN 20

char entrada[MAXN];

int main()
{
	scanf("%s", entrada);

    for(int i=0; entrada[i]!='\0'; i++)
    {
        if(entrada[i] >= '0'&& entrada[i] <='9')
        {
            printf("%c", entrada[i]);
            continue;
        }
        
        if(entrada[i] == '-')
        {
            printf("%c", entrada[i]);
            continue;
        }

        if(entrada[i] == 'A' || entrada[i] == 'B' || entrada[i] == 'C')
        {
            printf("2");
        }

        if(entrada[i] == 'D' || entrada[i] == 'E' || entrada[i] == 'F')
        {
            printf("3");
        }

        if(entrada[i] == 'G' || entrada[i] == 'H' || entrada[i] == 'I')
        {
            printf("4");
        }

        if(entrada[i] == 'J' || entrada[i] == 'K' || entrada[i] == 'L')
        {
            printf("5");
        }

        if(entrada[i] == 'M' || entrada[i] == 'N' || entrada[i] == 'O')
        {
            printf("6");
        }

        if(entrada[i] == 'P' || entrada[i] == 'Q' || entrada[i] == 'R' || entrada[i] == 'S')
        {
            printf("7");
        }

        if(entrada[i] == 'T' || entrada[i] == 'U' || entrada[i] == 'V')
        {
            printf("8");
        }

        if(entrada[i] == 'W' || entrada[i] == 'X' || entrada[i] == 'Y' || entrada[i] == 'Z')
        {
            printf("9");
        }

    }

	printf("\n");

	return 0;
}
