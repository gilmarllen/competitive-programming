// reset
#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

char tmp[100];

int n_casos;

int main(){
    cin >> n_casos;

    while(n_casos--)
    {
        map<char, string> regras;
        string str;

        int n;
        cin >> n;
        cin >> str;

        int n_regras;
        cin >> n_regras;
        while(n_regras--)
        {
            scanf(" %s", tmp);
            string exp(&tmp[2]);
            regras[ tmp[0] ] = exp;
            // cout << var << "=" << exp << endl;
        }
        
        while(n--)
        {
            string new_str;
            int tam = str.length();
            for(int i=0; i<tam; i++)
            {
                string reg = regras[ str[i] ];
                if(reg != "")
                    new_str += reg;
                else
                    new_str += str[i];
            }

            str = new_str;
        }

        cout << str << endl;
    }
    return 0;
}