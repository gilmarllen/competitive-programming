#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const long long int INF = 999999999;

long long int pont[105];
long long int duracao[105];
long long int pd[105][605];

long long int n, t;

long long int rec(long long int atual, long long int t_restante)
{
    if(pd[atual][t_restante] >= 0) return pd[atual][t_restante];
    if(t_restante < 0) return -INF;
    if((atual == n) || (t_restante==0)) return pd[atual][t_restante] = 0;
    long long int novo_t = t_restante - duracao[atual];
    // cout << atual << " , " << t_restante << " , " << novo_t << endl;

    return pd[atual][t_restante] = max( max( pont[atual]+rec(atual, novo_t), pont[atual]+rec(atual+1, novo_t) ), rec(atual+1, t_restante));
}

int main()
{
    int inst = 1;
    while(true)
    {
        cin >> n >> t;
        if(!n) break;

        memset(pont, 0, sizeof(pont));
        memset(duracao, 0, sizeof(duracao));
        memset(pd, -1, sizeof(pd));

        for(int i=0; i<n; i++)
            cin >> duracao[i] >> pont[i];
        
        cout << "Instancia " << inst << endl << rec(0, t) << endl << endl;
        inst++;
    }

    return 0;
}