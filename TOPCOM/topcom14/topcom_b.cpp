#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n;

int main()
{
    while(true)
    {
        cin >> n;
        if(!n) break;

        map<int,int> mapa;

        for(int i=0; i<n; i++)
        {
            int a;
            cin >> a;
            if(mapa.find(a)==mapa.end())
                mapa[a] = 1;
            else
                mapa[a]++;
        }

        int qtd = n;
        int resp = 0;
        while(qtd)
        {
            bool not_first = false;
            for(map<int,int>::iterator it=mapa.begin(); it!=mapa.end(); it++)
            {
                if(it->second > 0)
                {
                    it->second--;
                    qtd--;
                    if(not_first)
                        resp++;
                    else
                        not_first = true;
                    // cout << ":: " << it->first << endl;
                }
            }
        }

        cout << resp << endl;
        
    }

    return 0;
}