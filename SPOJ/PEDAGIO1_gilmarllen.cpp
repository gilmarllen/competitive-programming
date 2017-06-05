#include <iostream>

using namespace std;

int main()
{
	int l, d, k, p, total=0;

	cin >> l >> d >> k >> p;

	total += l*k;

	total += (l/d)*p;

	cout << total << endl;

	return 0;
}
