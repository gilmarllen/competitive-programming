#include <bits/stdc++.h>
using namespace std;

const int INF = 9999999;
const int MAXN = 112345;

int n;
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

	return pd[cur] = min(abs(h[cur+1]-h[cur])+rec(cur+1),abs(h[cur+2]-h[cur])+rec(cur+2));
}

int main(){
	memset(pd, -1 , sizeof(pd));

	cin >> n;

	for(int i=0; i<n; i++)
		cin >> h[i];

	cout << rec(0) << endl;

	return 0;
}