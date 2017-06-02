#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);

    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
int main()
{
	while(true)
	{
		int m, n;
		int pontos[112345];
		scanf("%d %d", &n, &m);
		if((!n) && (!m))
			break;
		
		for(int i=1; i<=n; i++)
			scanf("%d", &pontos[i]);

		UnionFind UF(n+1);

		int ans=0;
		while(m--)
		{
			int q, a, b;
			scanf("%d %d %d", &q, &a, &b);

			if(q==1)
			{
				int x = UF.findSet(a);
				int y = UF.findSet(b);
				UF.unionSet(a, b);
				int px = pontos[x];
				int py = pontos[y];
				pontos[x] += py;
				pontos[y] += px;
			}

			if(q==2)
			{
				int pr = UF.findSet(1);
				int pa = UF.findSet(a);
				int pb = UF.findSet(b);

				if(pa==pb)
					continue;

				if(pr==pa)
				{
					if(pontos[pr] > pontos[pb])
						ans++;
				}

				if(pr==pb)
				{
					if(pontos[pr] > pontos[pa])
						ans++;
				}
	
	
			}
		}		

		printf("%d\n", ans);
		
	}


	return 0;
}
