#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1123;

int h, w;
char mapa[MAXN][MAXN];
int pd[MAXN][MAXN];
int mod = 1000000000+7;

int rec(int x, int y)
{
	if( pd[x][y] != -1)
		return pd[x][y];

	if((x==h) && (y==w))
		return 1;

	if(x>h || y>w)
		return 0;

	if(mapa[x][y] == '#')
		return 0;

	return pd[x][y] = (rec(x+1, y) + rec(x, y+1))%mod;
}

int main(){
	memset(pd, -1, sizeof(pd));
	scanf("%d %d\n", &h, &w);

	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=w; j++)
			cin >> mapa[i][j];
		scanf("%*c");
	}

	cout << rec(1, 1) << endl;

	return 0;
}