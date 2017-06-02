#include <iostream>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
map<int,int> notas;

int main()
{
	cin >> n;

	while(n--)
	{
		int num;
		cin >> num;

		if(notas.find(num)!=notas.end()) notas[num]++;
		else notas[num] = 1;
	}

	map<int,int>::iterator it=notas.begin();

	int maior=0;
	for(;it!=notas.end();it++)
		maior = max(it->second, maior);

	int resp=-1;
	for(it=notas.begin();it!=notas.end();it++)
		if(it->second == maior)
			resp = it->first;

	cout << resp << endl;

	return 0;
}
