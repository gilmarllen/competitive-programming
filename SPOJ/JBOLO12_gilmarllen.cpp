#include <iostream>
#include <vector>
#include <algorithm>

#define trigo 2
#define ovo 3
#define leite 5

using namespace std;

int main()
{
	int a, b, c, i=0;

	cin >> a >> b >> c;	
	
	vector<int> val;

	val.push_back(a/trigo);
	val.push_back(b/ovo);
	val.push_back(c/leite);

	sort(val.begin(), val.end());

	cout << val[0] << endl;

	return 0;
}
