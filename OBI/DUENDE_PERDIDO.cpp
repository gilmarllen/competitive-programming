#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int mapa[10][10];
int dp[10][10];
int visitado[10][10];
int n,m, menor=INT_MAX;

int caminhos(int x, int y)
{
	
	if(mapa[x][y] == 0)
		return 0;
	
	if(mapa[x][y]==2)
		return 999999;

	if(visitado[x][y]==1)
		return 999999;
		
	if(dp[x][y] != -1)
		return dp[x][y];
	
	int minimo = INT_MAX;
	
	//printf("oi1 %d %d\n",x, n);
	
	if(x+1 < n)
	{
		visitado[x][y]=1;
		minimo = min(minimo, caminhos(x+1, y));
		visitado[x][y]=0;
	}
	
	//printf("oi2\n");
	
	
	if(x-1 >= 0)
	{
		visitado[x][y]=1;
		minimo = min(minimo, caminhos(x-1, y));
		visitado[x][y]=0;
	}
	
	//printf("oi3\n");
	
	if(y+1 < m)
	{
		visitado[x][y]=1;
		minimo = min(minimo, caminhos(x, y+1));
		visitado[x][y]=0;
	}
	
	//printf("oi4\n");
	
	if(y-1 >= 0)
	{
		visitado[x][y]=1;
		minimo = min(minimo, caminhos(x, y-1));
		visitado[x][y]=0;
	}
	
	//printf("x= %d y= %d %d\n", x, y, minimo);
	return dp[x][y] = 1 + minimo;
	

	

	/*for(int l=0; l<n; l++)
	{
	    for(int j=0; j<m; j++)
	    {
			printf("%d ", visitado[l][j]);
		}
		printf("\n");
	}*/

    //printf("%d %d %d\n",x,y, mapa[x][y]);
    /*if(mapa[x][y]==0)
	{
		//custo[x][y] = min(cus, custo[x][y]);
		visitado[x][y]=0;
		//cus++;
		menor = min(menor, cus);
		//printf("\t\tsaida %d %d %d m:%d c:%d\n", x, y, mapa[x][y], menor, cus);
		return;
	}*/

	//if(i==1 /*&& (x+1!=xo || y!=yo)*/)
	//{
		/*printf("down\n");*///caminhos(x+1, y, cus+1, x, y);
	//}

	//else if(i==2 /*&& (x-1!=xo || y!=yo)*/)
	//{
		/*printf("up\n");*///caminhos(x-1, y, cus+1, x, y);
	//}

	//else if(i==3 /*&& (x!=xo || y+1!=yo)*/)
	//{
		/*printf("dir\n");*///caminhos(x, y+1, cus+1, x, y);
	//}

	//else if(i==4 /*&& (x!=xo || y-1!=yo)*/)
	//{
		/*printf("esq\n");*///caminhos(x, y-1, cus+1, x, y);
	//}

	//visitado[x][y]=0;

    /*if(x+1<n && (mapa[x+1][y]==1 || mapa[x+1][y]==0) && (x+1!=xo || y!=yo))
	{		
		printf("dir\n");caminhos(x+1, y, cus+1, x, y);
	}

    if(x-1>=0 && (mapa[x-1][y]==1 || mapa[x-1][y]==0) && (x-1!=xo || y!=yo))
	{
        printf("esq\n");caminhos(x-1, y, cus+1, x, y);
	}

    if(y+1<m && (mapa[x][y+1]==1 || mapa[x][y+1]==0)  && (x!=xo || y+1!=yo))
	{
        printf("down\n");caminhos(x, y+1, cus+1, x, y);
	}

    if(y-1>=0 && (mapa[x][y-1]==1 || mapa[x][y-1]==0) && (x!=xo || y-1!=yo))
	{
        printf("up\n");caminhos(x, y-1, cus+1, x, y);
	}*/

}

int main()
{
    scanf("%d %d", &n, &m);

    int Xini, Yini;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
			//custo[i][j] = INT_MAX;
            scanf("%d", &mapa[i][j]);
            if(mapa[i][j] == 3)
			{
                Xini = i;
                Yini = j;
			}
        }
    }
    
    memset(dp, -1, sizeof(dp));

	/*for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
			printf("%d ", mapa[i][j]);
		}
		printf("\n");
	}*/

	//caminhos(Xini, Yini, 0, -1, -1);

    printf("%d\n", caminhos(Xini, Yini));
	
	return 0;
}  
/*
6 6
3 1 1 1 1 1
1 1 1 1 1 1 
1 1 1 1 1 1
1 1 1 2 1 1
1 1 1 1 0 1
1 1 1 1 1 1
*/ 
