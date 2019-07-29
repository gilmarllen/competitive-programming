#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 112345;

int n, k;
int h[MAXN];
int pd[MAXN];


int rec(int cur)
{
	if(cur==(n-1))
		return 0;

	if(cur>=n)
		return INF;

	if(pd[cur]!=-1)
		return pd[cur];

	int rtnMin = INF;
	for(int i=1; (i<=k) && ((cur+i)<n); i++)
		rtnMin = min(rtnMin, abs(h[cur+i]-h[cur])+rec(cur+i));

	return pd[cur] = rtnMin;
}

int main(){
	memset(pd, -1 , sizeof(pd));

	cin >> n >> k;

	for(int i=0; i<n; i++)
		cin >> h[i];

	cout << rec(0) << endl;

	return 0;
}