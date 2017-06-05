#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;

char str[55];
char str0[55] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
	cin >> N;

	while(N--)
	{
		int tam;
		cin >> tam;

		scanf("%s", str);

		bool errado=false;
		for(int i=0; i<tam-1; i++)
		{
			if(str[i] > str[i+1])
			{
				int aux=0;
				for(int j=i; j<tam; j++)
				{
					if(str[j] > str[i])
					{
						aux = str[j-1];
						str[j-1] = str[i];
						str[i] =  aux;
						//cout << "if1" << endl;
						break;
					}
				}
				if(!aux)
				{
					aux = str[tam-1];
					str[tam-1] = str[i];
					str[i] =  aux;
					//cout << "if2" << endl;
				}
			}
		}

		for(int i=0; i<tam-1; i++)
		{
			//cout << str[i] << endl;
			if(str[i] > str[i+1])
			{
				errado = true;
			}
		}

		//cout << resp << endl;

		if(errado)
			cout << "There aren't the chance." << endl;
		else
			cout << "There are the chance." << endl;
	}

	return 0;
}
