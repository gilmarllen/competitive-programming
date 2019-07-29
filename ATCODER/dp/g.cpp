#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 112345;

int n, m;
vector<int> adj[MAXN];
int pd[MAXN];

int rec(int cur)
{
	if(pd[cur]!=-1)
		return pd[cur];

	int rtn = 0;
	for(int i=0; i<adj[cur].size(); i++)
	{
		rtn = max(1 + rec(adj[cur][i]), rtn);
	}

	return pd[cur] = rtn;
}

int main() {
	memset(pd, -1 , sizeof(pd));

	cin >> n >> m;

	for(int i=0; i<m; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	int resp = 0;
	for(int i=1; i<=n; i++)
		resp = max(resp, rec(i));
	cout << resp << endl;

	return 0;
}