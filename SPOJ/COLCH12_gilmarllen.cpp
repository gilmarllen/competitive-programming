#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> porta;

int main()
{
	vector<int> colchao;

	int t, i=0;

	for(i=0; i<3; i++)
	{
		cin >> t;
		colchao.push_back(t);
	}

	for(i=0; i<2; i++)
	{
		cin >> t;
		porta.push_back(t);
	}

	sort(porta.begin(), porta.end());
	sort(colchao.begin(), colchao.end());

	if((colchao[0] < porta[0]) && (colchao[1] < porta[1]))
	{
		cout << "S" << endl;
	}else
	{
		cout << "N" << endl;
	}
	
	return 0;
}
