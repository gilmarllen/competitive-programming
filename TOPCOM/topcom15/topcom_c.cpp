// reset
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int n, m;
bool vars[10005];
vector<int> clauses[10005];
set<string> resps;

bool isResp()
{
    bool resp = true;
    for(int i=0; i<m; i++)
    {
        bool cla = false;
        int tam = clauses[i].size();
        for(int j=0; j<tam; j++)
        {
            bool var_cla;
            if(clauses[i][j]>0)
                var_cla = vars[ clauses[i][j] ];
            else
                var_cla = !vars[ -clauses[i][j] ];

            cla = cla || var_cla;
        }
        resp = resp && cla;
    }

    return resp;
}

void saveResp()
{
    string resp;
    for(int i=1; i<=n; i++)
    {
        if(vars[i])
            resp += to_string(i);
        else{
            // resp += '-';
            resp += to_string(-i);
        }
        if(i<n) resp += ' ';
    }
    // cout << resp << endl;
    resps.insert(resp);
}

void rec(int idx)
{
    // cout << idx << endl;
    if(idx==(n+1)){

        // string resp;
        // for(int i=1; i<=n; i++)
        // {
        //     if(vars[i])
        //         resp += (i+'0');
        //     else{
        //         resp += '-';
        //         resp += (i+'0');
        //     }
        //     if(i<n) resp += ' ';
        // }
        // cout << resp << endl;

        if(isResp()){
            saveResp();
        }
    } else{
        vars[idx] = true;
        rec(idx+1);
        vars[idx] = false;
        rec(idx+1);
    }
}

int main()
{
    scanf("p %d %d", &n, &m);

    for(int i=0; i<m; i++)
    {
        int num;
        char c;
        while(true)
        {
            if(scanf("%d%c",&num, &c)<1)
                break;
            // cout << num << " // " << (int)c << endl;
            clauses[i].push_back(num);

            if(c=='\n') break;
        }
    }

    rec(1);

    for (set<string>::iterator it=resps.begin(); it!=resps.end(); ++it)
        cout << *it << endl;

    return 0;
}