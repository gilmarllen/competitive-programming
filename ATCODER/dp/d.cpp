#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXW = 112345;
const int MAXN = 112;

int n, w_max;
long long int w[MAXN], v[MAXN];
long long int pd[MAXN][MAXW];

long long int rec(int cur, int available)
{
	if(available<0)
		return -INF;

	if(cur>=n)
		return 0;

	if(available==0)
		return 0;

	if(pd[cur][available]!=-1)
		return pd[cur][available];

	return pd[cur][available] = max(v[cur]+rec(cur+1,available-w[cur]), rec(cur+1,available));
}

int main() {
	memset(pd, -1 , sizeof(pd));

	cin >> n >> w_max;

	for(int i=0; i<n; i++)
		cin >> w[i] >> v[i];

	cout << rec(0, w_max) << endl;

	return 0;
}