#include <cstdio>
#include <map>
using namespace std;

map<char, char> cifra;

int main()
{
	char le;
	for(int i=0; i<26; i++)
	{
		scanf("%c", &le);
		cifra['a' + i] = le;
	}
	scanf("%*c");

	while(scanf("%c", &le) && (le!='\n'))
		printf("%c", cifra[le]);
	printf("\n");

	return 0;
}
