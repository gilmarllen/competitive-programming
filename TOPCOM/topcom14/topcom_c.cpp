#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n;

int main()
{
    cin >> n;
    while(n--)
    {
        string resp;
        char line[1005];
        scanf(" %s", line);

        int tam = strlen(line);
        for(int i=0; i<tam;)
        {
            char c_num = line[i];
            int j=i;
            while( (line[j]==c_num) && (j<tam) )
                j++;

            resp += to_string(j-i) + c_num;

            i=j;
        }

        cout << resp << endl;
    }

    return 0;
}