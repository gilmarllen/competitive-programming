#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int INFINITO = 999999999;
const int N_MAX = 100+5;

int t, n, d;
char pedra_tipo[N_MAX];
int pedra_dist[N_MAX];

int main()
{
	cin >> t;

	while(t--)
	{
		cin >> n >> d;

		for(int i=0; i<n; i++)
		{
			char tipo;
			scanf("%*c");
			scanf("%c-%d", &pedra_tipo[i], &pedra_dist[i]);
		}

		cout << rec(0) << endl;
	}

	// cout << INT_MAX << endl;
	return 0;
}
