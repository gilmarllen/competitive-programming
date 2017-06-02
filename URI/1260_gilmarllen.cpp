#include <cstdio>
#include <map>
#include <cstring>
#include <iostream>

using namespace std;

int n;

int main()
{
	scanf("%d\n\n", &n);

	char nome_C[35];

	while(n--)
	{
		map<string, int> mapa;
		int total=0;

		while(true)
		{
			string nome;
			getline(cin, nome);
			if(nome == "") break;

			if(mapa.find(nome)!=mapa.end()) mapa[nome]++;
			else mapa[nome] = 1;

			total++;

			//cout << "-->" << nome << endl;
		}

		for(map<string, int>::iterator it = mapa.begin(); it!=mapa.end(); it++)
		{
			cout << it->first;
			printf(" %.4lf\n", 100*((double)it->second)/((double)total));
		}

		if(n>0) printf("\n");
	}

	return 0;
}
