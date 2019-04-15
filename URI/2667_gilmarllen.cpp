#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char line[105];

int main()
{
    scanf("%s", line);

    int sum = 0;
    int tam = strlen(line);
    for(int i=0; i<tam; i++)
        sum += line[i]-'0';
    cout << (sum%3) << endl;
    // if(sum%3 == 0)
    //     cout << "0" << endl;
    // else if( (line[tam-1] - '0') % 2  == 0 )
    //     cout << "2" << endl;
    // else
    //     cout << "1" << endl;

    return 0;
}