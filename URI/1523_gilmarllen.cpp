#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

const int MAXN = 112345;

int n, k;
int chegada[MAXN];
int saida[MAXN];
bool ans=true;

int main()
{
	while(true)
	{
		scanf("%d %d", &n, &k);
		if((!n) && (!k))
			break;

		stack <int> est;

		memset(chegada, 0, sizeof(chegada));
		memset(saida, 0, sizeof(saida));

		for(int i=1; i<=n; i++)
		{
			int lche, lsai;
			scanf("%d %d", &lche, &lsai);
			chegada[lche] = i;
			saida[lsai] = i;
		}

		ans = true;

		for(int i=1; i<MAXN; i++)
		{
			if(saida[i])
			{
				if(est.empty())
				{
					ans = false;
					break;
				}

				if(est.top() != saida[i])
				{
					ans = false;
					break;
				}
				est.pop();
			}

			if(chegada[i])
			{
				if(est.size()==k)
				{
					ans = false;
					break;
				}
				est.push(chegada[i]);
			}
		}

		if(ans)
			printf("Sim\n");
		else
			printf("Nao\n");

	}

	return 0;
}
