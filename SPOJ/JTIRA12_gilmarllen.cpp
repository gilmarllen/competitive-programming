#include <iostream>
#include <vector>
#include <algorithm>

#define x 432
#define y 468

using namespace std;

int main()
{
	int a, b;

	cin >> a >> b;

	if(a>=0 && a<=x)
	{
		if(b>=0 && b<=y)
		{
			cout << "dentro" << endl;
			return 0;
		}
	}

	cout << "fora" << endl;
	return 0;
}
