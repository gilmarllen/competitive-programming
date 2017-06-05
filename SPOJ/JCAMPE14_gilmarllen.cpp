#include <iostream>

using namespace std;

int main()
{
	int cv, ce, cs, fv, fe, fs, cp, fp;

	cin >> cv >> ce >> cs >> fv >> fe >> fs;

	cp = (cv*3) + ce;
	fp = (fv*3) + fe;

	if(cp > fp)
	{
		cout << "C" << endl;
		return 0;
	}

	if(cp < fp)
	{
		cout << "F" << endl;
		return 0;
	}

	if(cp==fp)
	{
		if(cs > fs)
		{
			cout << "C" << endl;
			return 0;
		}

		if(cs < fs)
		{
			cout << "F" << endl;
			return 0;
		}

		if(cs == fs)
		{
			cout << "=" << endl;
			return 0;
		}

	}

	return 0;
}
