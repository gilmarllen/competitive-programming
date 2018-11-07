#include <vector>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int t;

int main()
{
	cin >> t;

	while(t--)
	{
		int s,c,r;
		std::vector<int> vels;
		cin >> s >> c >> r;

		for(int i=0; i<s; i++)
		{
			int tmp;
			cin >> tmp;
			vels.push_back(tmp);
		}

		sort(vels.begin(), vels.end());

		for(int i=0; i<s && c; i++, c--)
			vels[i] += r;

		double resp = 0.0;
		for(int i=0; i<s; i++)
			resp += 1.0/vels[i];

		printf("%.2lf\n", resp);
	}


	return 0;
}
