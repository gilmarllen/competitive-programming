/* A Naive recursive implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3123;

char X[MAXN];
char Y[MAXN];
string resp;

int pd[MAXN][MAXN];

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(int m, int n)
{
	if(pd[m][n] != -1)
		return pd[m][n];

	if (m == 0 || n == 0)
		return pd[m][n] = 0;
	if (X[m-1] == Y[n-1])
		return pd[m][n] = ( 1 + lcs(m-1, n-1) );
	else
		return pd[m][n] = max(lcs(m, n-1), lcs(m-1, n));
}

/* Driver code */
int main()
{
	scanf("%s\n%s", X, Y);

	int m = strlen(X);
	int n = strlen(Y);

	memset(pd, -1, sizeof(pd));
	lcs(m, n);

	int i=m;
	int j=n;
	while((i>0) && (j>0)){
		// cout << pd[i][j] << ' ';

		if(X[i-1] == Y[j-1]){
			resp += Y[j-1];
			i-=1;
			j-=1;
		}
		else if(pd[i-1][j] > pd[i][j-1])
			i-=1;
		else
			j-=1;
	}

	reverse(resp.begin(), resp.end());
	cout << resp << endl;

	return 0;
}

// This code is contributed by rathbhupendra 
