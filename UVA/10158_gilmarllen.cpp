#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
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
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int n, op=1, a=1, b=1;

int main()
{
	scanf("%d", &n);

	UnionFind war(2*n);

	while(scanf("%d %d %d", &op, &a, &b)!=0 && (a!=0 || b!=0 || op!=0))
	{
		if(op==1)
		{
			if(war.isSameSet(2*a,(2*b)+1) || war.isSameSet((2*a)+1,(2*b)))
				printf("-1\n");
			else
			{
				war.unionSet((2*a), (2*b));
				war.unionSet((2*a)+1, (2*b)+1);
			}
		}

		if(op==2)
		{
			if(war.isSameSet(2*a, 2*b) || war.isSameSet((2*a)+1, (2*b)+1))
				printf("-1\n");
			else
			{
				war.unionSet((2*a)+1, (2*b));
				war.unionSet((2*a), (2*b)+1);
			}
		}

		if(op==3)
		{
			if(war.isSameSet(2*a, 2*b) || war.isSameSet((2*a)+1, (2*b)+1))
				printf("1\n");
			else
				printf("0\n");
		}

		if(op==4)
		{
			if(war.isSameSet(2*a,(2*b)+1) || war.isSameSet((2*a)+1,(2*b)))
				printf("1\n");
			else
				printf("0\n");
		}
	}


	return 0;
}
