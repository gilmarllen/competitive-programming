#include<vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int INFINITO = 999999999;

int t, n, m;
vector<int> blocos;
int pd[30][1000000+5];

int rec(int idx, int rest)
{
	if(rest==0)
		return 0;

	if(rest<0)
		return INFINITO;

	if(idx == -1)
		return INFINITO;

	if(idx==0)
		return pd[idx][rest] = rest;

	// Penultimo tamanho de bloco, soh tem o bloco de tamanho 1 dps, pode usar guloso aqui
	if(idx==1)
		return pd[idx][rest] = (rest/blocos[idx]) + (rest%blocos[idx]);

	if( pd[idx][rest]!=-1 )
		return pd[idx][rest];

	int pegar_ficar = 1 + rec(idx,rest-blocos[idx]);
	int pegar_passar = 1 + rec(idx-1,rest-blocos[idx]);
	int n_pegar = rec(idx-1,rest);

	return pd[idx][rest] = min(min(pegar_ficar, pegar_passar), n_pegar);
}

int main()
{
	cin >> t;

	while(t--)
	{
		memset(pd, -1, sizeof(pd));
		blocos.clear();

		cin >> n >> m;

		for(int i=0; i<n; i++){
			int tmp;
			cin >> tmp;
			blocos.push_back(tmp);
		}

		sort(blocos.begin(), blocos.end());

		//cout << blocos[0] << endl;

		cout << rec(n-1, m) << endl;
	}

	return 0;
}
