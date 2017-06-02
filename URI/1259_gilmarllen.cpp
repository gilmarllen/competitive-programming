#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> vet;
int n;

bool cmp(int a, int b)
{
	if(!(a%2) && (b%2))
	{
		return true;
	}

	if((a%2) && !(b%2))
	{
		return false;
	}

	if(!(a%2) && !(b%2))
	{
		return a < b;
	}

	if((a%2) && (b%2))
	{
		return a > b;
	}	
}

int main()
{
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		int temp;
		scanf("%d", &temp);
		vet.push_back(temp);
	}

	sort(vet.begin(), vet.end(), cmp);

	for(int i=0; i<n; i++)
	{
		printf("%d\n", vet[i]);
	}

	return 0;
}
