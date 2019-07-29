#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 312;

int n;
bool stat[MAXN][MAXN][MAXN];
double pd[MAXN][MAXN][MAXN];

double rec(int q_1, int q_2, int q_3)
{
	// cout << q_1 << ' ' << q_2 << ' ' << q_3 << endl;

	if(stat[q_1][q_2][q_3])
		return pd[q_1][q_2][q_3];

	double p = (n*1.00)/(q_1+q_2+q_3);

	if(q_1==1 && q_2==0 && q_3==0)
		return p;

	double sum = 0.0;

	int nn = (q_1-1)+q_2+q_3;
	if(nn>0 && q_1>0)
		sum += rec(q_1-1, q_2, q_3)*q_1;

	nn = (q_1+1)+(q_2-1)+q_3;
	if(nn>0 && q_2>0)
		sum += rec(q_1+1, q_2-1, q_3)*q_2;

	nn = q_1+(q_2+1)+(q_3-1);
	if(nn>0 && q_3>0)
		sum += rec(q_1, q_2+1, q_3-1)*q_3;

	stat[q_1][q_2][q_3] = true;
	return pd[q_1][q_2][q_3] = p+(sum/(q_1+q_2+q_3));
}

int main(){
	int q_1 = 0, q_2 = 0, q_3 = 0;

	cin >> n;
	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		if(tmp==1) q_1++;
		if(tmp==2) q_2++;
		if(tmp==3) q_3++;
	}

	printf("%.9lf\n", rec(q_1, q_2, q_3));

	return 0;
}