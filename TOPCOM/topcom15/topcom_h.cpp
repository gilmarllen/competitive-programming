#include <cstdio>
#include <iostream>

using namespace std;

const int INFINITO = 999999999;

int u;
int mapa[1000][1000]; // 0: Nada, 1: Zumbi, 2: Pessoa

int main()
{
    cin >> u;
    while(u--)
    {
        int n, m, h, v;
        int melhor_z=-INFINITO, melhor_p, melhor_i, melhor_j;
        cin >> h >> v >> m >> n; // Horizontal: m / h, Vertical: n x v
        for(int i=0; i<n; i++){
            char line[1000];
            scanf(" %s", line);
            for(int j=0; j<m; j++)
                mapa[i][j] = line[j] - '0';
        }

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                int z = 0, p = 0;
                // cout << h << j << " || ";
                for(int y=i-v; y<=i+v; y++){
                    for(int x=j-h; x<=j+h; x++)
                    {
                        if(y>=0 && y<n && x>=0 && x<m)
                        {
                            // cout << "(" << x << "," << y << ")=" << mapa[y][x];
                            if(mapa[y][x]==1)
                                z++;

                            if(mapa[y][x]==2)
                                p++;
                        }
                    }
                    // cout << "   ";
                }
                // cout << endl;
                // cout << "X:" << j << " Y:" << i << " ==> z:" << z << " p:" << p << endl;

                bool swap = false;
                if(z > melhor_z)
                    swap = true;
                else if(z==melhor_z){
                    if(p<melhor_p)
                        swap = true;
                    else if(p==melhor_p){
                        if(i<melhor_i)
                            swap = true;
                        else if(i==melhor_i){
                            if(j<melhor_j)
                                swap = true;
                        }
                    }
                }

                if(swap){
                    melhor_z = z;
                    melhor_p = p;
                    melhor_i = i;
                    melhor_j = j;
                }
            }

        cout << "X:" << melhor_j << " Y:" << melhor_i << endl;
    }

    return 0;
}