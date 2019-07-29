#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 112345;

int n, k;
int a[MAXN], b[MAXN], c[MAXN];
int pd[MAXN][3];

int rec(int cur, int last)
{
	if(cur>=n)
		return 0;

	if(pd[cur][last])
		return pd[cur][last];

	if(last==0)
		return pd[cur][last] = max(b[cur]+rec(cur+1,1), c[cur]+rec(cur+1,2));

	if(last==1)
		return pd[cur][last] = max(c[cur]+rec(cur+1,2), a[cur]+rec(cur+1,0));

	if(last==2)
		return pd[cur][last] = max(b[cur]+rec(cur+1,1), a[cur]+rec(cur+1,0));

	return max(b[cur]+rec(cur+1,1), max(c[cur]+rec(cur+1,2), a[cur]+rec(cur+1,0)));
}

int main() {
	// memset(pd, -1 , sizeof(pd));

	cin >> n;

	for(int i=0; i<n; i++)
		cin >> a[i] >> b[i] >> c[i];

	cout << rec(0, -1) << endl;

	return 0;
}