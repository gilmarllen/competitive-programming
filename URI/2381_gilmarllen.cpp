#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAXN 110
#define TAMMAX 30

using namespace std;

int k, n;

vector<string> tab;

bool compara(string a, string b)
{
	if(a > b)
		return false;

	return true;
}

int main()
{
	string temp;
	char t[TAMMAX];

	scanf("%d %d", &k, &n);

	for(int i=0; i<k; i++)
	{
		scanf("\n%s", t);
		temp = t;
		tab.push_back(temp);
	}

	/*for(int i=0; i<k; i++)
	{
		cout << tab[i] << endl;
	}*/

	sort(tab.begin(), tab.end(), compara);

	
	cout << tab[n-1] << endl;

	return 0;
}  
