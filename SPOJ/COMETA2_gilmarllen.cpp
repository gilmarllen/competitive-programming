#include <cstdio>

using namespace std;

int main()
{
	int atual;

	scanf("%d", &atual);

	atual++;
	while((atual-1986)%76)
	{
		atual++;
	}

	printf("%d\n", atual);

	return 0;
}
