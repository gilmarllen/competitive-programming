#include <vector>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
std::vector<int> h;

bool verifica_diagonal(int col, int alt)
{
	int steps = alt;

	if( (alt > col+1) || (alt > n-col) )
		return false;

	for (int i = 0; i < steps; ++i, alt--)
	{
		if( (alt > h[col+i]) || (alt > h[col-i]) )
			return false;
	}

	return true;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		h.push_back(tmp);
	}

	int h_max = 0;

	for (int i = 0; i < n; ++i)
	{
		if( verifica_diagonal(i, h_max+1) ){
			h_max++;
			//cout << i << " // " << h_max << endl;
		}
	}

	cout << h_max << endl;

	return 0;
}
