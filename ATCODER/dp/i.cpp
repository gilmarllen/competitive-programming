#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 3123;

int n;
double p[MAXN];
bool stat[MAXN][MAXN];
double pd[MAXN][MAXN];

double rec(int cur, int n_head)
{
	if(cur>=n)
	{
		if(n_head > (n/2))
			return 1.00;
		else
			return 0.00;
	}

	if(stat[cur][n_head])
		return pd[cur][n_head];

	stat[cur][n_head] = true;
	return pd[cur][n_head] = p[cur]*rec(cur+1,n_head+1) + (1-p[cur])*rec(cur+1,n_head);
}

int main(){

	cin >> n;
	for(int i=0; i<n; i++){
		char in[8];
		scanf("%s", in);
		p[i] = stod(in);
		// cout << p[i] << endl;
	}

	printf("%.9lf\n", rec(0, 0));

	return 0;
}