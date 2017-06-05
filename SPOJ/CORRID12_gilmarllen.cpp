#include <iostream>

using namespace std;

int main()
{
	int c, n, aux;

	cin >> c >> n;

	while(c >= n)
	{
		c -= n;
	}

	cout << c << endl;

	return 0;
}
