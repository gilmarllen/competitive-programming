#include <cstdio>
#include <algorithm>
using namespace std;

//-------------------------
#define MAXN 105
#define INFINITO 999999999

int n, m;
int mapa[MAXN][MAXN];
int distancia[MAXN][MAXN];
//-------------------------

int main(){
    
    scanf("%d %d", &n, &m);

    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
		{
			if(i!=j)
            	mapa[i][j] = INFINITO;
		}
    
    for(int i = 1;i <= m;i++){
        
        int x, y, dist;
        scanf("%d %d %d", &x, &y, &dist);

        mapa[x][y] = min(mapa[x][y], dist);
        mapa[y][x] = min(mapa[y][x], dist);
    }
    
	/*for(int i = 0;i < n;i++)
	{
    	for(int j = 0;j < n;j++)
			printf("%d ", 	mapa[i][j]);
		printf("\n");
	}*/

    for(int i = 0;i < n;i++)
    for(int j = 0;j < n;j++)
		distancia[i][j] = mapa[i][j];
    
    // Algoritmo de Floyd-Warshall
    for(int k = 0;k < n;k++)
    for(int i = 0;i < n;i++)
    for(int j = 0;j < n;j++)
        distancia[i][j] = min(distancia[i][j], distancia[i][k] + distancia[k][j]);

	/*for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
			printf("%d ", distancia[i][j]);
		printf("\n");
	}*/

	int resp = INFINITO;
	for(int i = 0;i < n;i++)
	{
		int maior_dist = 0;
		for(int j = 0;j < n;j++)
		{
			maior_dist = max(maior_dist, distancia[i][j]);
		}
		resp = min(resp, maior_dist);
		//printf("%d\n", maior_dist);
	}

	printf("%d\n", resp);
    
    return 0;
}
