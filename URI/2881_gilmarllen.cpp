#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef struct {
	int ini;
	int fim;
	int n_musicas;
	int palco;
} show;

const int INFINITO = 999999999;

int n_palcos=0;
std::vector<show> shows;
int n_shows;

int last_added = -1;

// bool pd[1005];
map< set<int>, int > visitados_pd[1005];

//set<int> visitados;

int rec(int idx, set<int> visitados)
{
	//cout << "running " << idx << endl;
	// if( (pd[idx]!=-1) && (visitados_pd[idx] == visitados) )
	// 	return pd[idx];

	map< set<int>,int >::iterator it = visitados_pd[idx].find(visitados);
	if (it != visitados_pd[idx].end())
		return it->second;

	//cout << "ALO" << endl;

	if(idx==n_shows)
	{
		if(visitados.size() == n_palcos)
			return visitados_pd[idx][visitados] = 0;
		else
			return visitados_pd[idx][visitados] = -INFINITO;
	}

	if(last_added != -1)
	{
		if(shows[last_added].fim > shows[idx].ini)
		{
			return visitados_pd[idx][visitados] = rec(idx+1, visitados);
		}
	}

	int tmp = last_added;
	//bool set_palco = false;

	last_added = idx;
	bool palco_novo = visitados.find(shows[idx].palco) == visitados.end();
	visitados.insert(shows[idx].palco);

	int ir = shows[idx].n_musicas + rec(idx+1, visitados);

	if(palco_novo)
		visitados.erase(shows[idx].palco);
	last_added = tmp;

	int nao_ir = rec(idx+1, visitados);

	return visitados_pd[idx][visitados] = max(ir, nao_ir);

	// if(ir > nao_ir)
	// {
	// 	visitados.insert(shows[idx].palco);
	// 	return visitados_pd[idx][visitados] = ir;
	// } else
	// 	return visitados_pd[idx][visitados] = nao_ir;
}

bool cmp(show a, show b)
{
	return a.ini < b.ini;
}

int main()
{
	//memset(pd, -1, sizeof(pd));
	cin >> n_palcos;

	for(int i=0; i<n_palcos; i++)
	{
		int qtd_shows;
		cin >> qtd_shows;

		while(qtd_shows--)
		{
			show tmp;
			tmp.palco = i;
			scanf("%d %d %d", &tmp.ini, &tmp.fim, &tmp.n_musicas);

			shows.push_back(tmp);
		}
	}

	n_shows = shows.size();
	sort(shows.begin(), shows.end(), cmp);

	set<int> v;
	int resp = rec(0, v);

	if(resp >= 0)
		cout << resp << endl;
	else
		cout << "-1" << endl;

	return 0;
}
