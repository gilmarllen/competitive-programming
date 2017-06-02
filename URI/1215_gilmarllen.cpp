#include <iostream>
#include <string>
#include <set>
#include <cstdio>
#include <cctype>

using namespace std;

set <string> conj;

int main()
{
	char c_palavra[255];

	while(scanf("%[a-zA-Z]", c_palavra)!=EOF)
	{
		scanf("%*c");

		for(int i=0; c_palavra[i]; i++)
			c_palavra[i] = tolower(c_palavra[i]);

		string palavra = c_palavra;
		conj.insert(palavra);
		//cout << palavra;
	}

	for(set <string>::iterator it = conj.begin(); it!=conj.end(); it++)
		cout << (*it) << endl;

	return 0;
}
