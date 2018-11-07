#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long int h0;

int main()
{
	while(true)
	{
		cin >> h0;
		if(h0==0) break;
		
		long long int h = h0, resp = h0;
		while(h!=1)
		{
			resp = max(resp,h);
			h = (h%2)? 3*h + 1 : h/2;
		}
		cout << resp << endl;
	}

	return 0;
}
