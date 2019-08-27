#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 21+5;
const int MAXK = 3123456;
const int mod = 1000000000+7;

int n;
int match_values[MAXN][MAXN];
int pd[MAXN][MAXK];

int rec(int cur, int bmask)
{
	if(cur==n)
		return 1;

	if(pd[cur][bmask]!=-1)
		return pd[cur][bmask];

	int sum = 0;
	for(int j=0; j<n; j++)
	{
		if(match_values[cur][j] && !(bmask & (1<<j))){
			sum += rec(cur+1, bmask | (1<<j));
			sum = sum%mod;
		}
	}

	return pd[cur][bmask] = sum;
}

int main()
{
	memset(pd, -1, sizeof(pd));
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			cin >> match_values[i][j];
		}

	cout << rec(0, 0) << endl;

	return 0;
}