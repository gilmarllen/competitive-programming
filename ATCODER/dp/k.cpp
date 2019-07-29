#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 112;
const int MAXK = 112345;

int n, k;
int stones[MAXN];
int pd[MAXK][5];

int other_p(int p){
	if(p==1) return 2;
	else return 1;
}

int rec(int rest, int p)
{
	if(rest<=0)
		return other_p(p);

	if(pd[rest][p])
		return pd[rest][p];

	bool can_win = false;
	for(int i=0;i<n;i++)
	{
		if( (rest-stones[i] >= 0) && (rec(rest-stones[i], other_p(p)) == p) )
			can_win = true;
	}

	if(can_win) return pd[rest][p] = p;
	else return pd[rest][p] = other_p(p);
}

int main()
{
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> stones[i];

	int resp = rec(k, 1);
	if(resp == 1)
		cout << "First" << endl;
	else
		cout << "Second" << endl;

	return 0;
}