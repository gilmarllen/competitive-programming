#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int N_MAX = 2000+5;

string str_cpp, cod_cpp, cod_rev_cpp;
//bool isValid[N_MAX];

int main()
{
	cin >> str_cpp >> cod_cpp;

	int resp = 0;

	const char* str = str_cpp.c_str();
	const char* cod = cod_cpp.c_str();

	cod_rev_cpp = cod_cpp;
	reverse( cod_rev_cpp.begin(), cod_rev_cpp.end() );
	const char* cod_rev = cod_rev_cpp.c_str();

	int str_len = str_cpp.size();
	int cod_len = cod_cpp.size();
	int cod_rev_len = cod_rev_cpp.size();

	for(int i=0; i+cod_len<=str_len; i++)
	{
		char zero = '\0';
		char one = '\0';

		bool isValid = true;
		for(int j=0; j<cod_len; j++)
		{
			if(cod[j] == '0')
			{
				if(zero == '\0')
					zero = str[i+j];
				else if(zero != str[i+j])
					isValid = false;
			}

			if(cod[j] == '1')
			{
				if(one == '\0')
					one = str[i+j];
				else if(one != str[i+j])
					isValid = false;
			}
		}

		zero = '\0';
		one = '\0';

		if(!isValid){
			isValid = true;

			for(int j=0; j<cod_rev_len; j++)
			{
				if(cod_rev[j] == '0')
				{
					if(zero == '\0')
						zero = str[i+j];
					else if(zero != str[i+j])
						isValid = false;
				}

				if(cod_rev[j] == '1')
				{
					if(one == '\0')
						one = str[i+j];
					else if(one != str[i+j])
						isValid = false;
				}
			}
		}		

		//printf("%d: %d\n", i, isValid);

		if(isValid) resp++;
	}

	printf("%d\n", resp);

	return 0;
}