#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 15;

int k, ans=0;
int port[MAXN];
int mat[MAXN];
int fis[MAXN];
int qui[MAXN];
int bio[MAXN];

vector <int> conj;

int main()
{
	int p, m, f, q, b;

	scanf("%d", &p);
	for(int i=0; i<p; i++) scanf("%d", &port[i]);

	scanf("%d", &m);
	for(int i=0; i<m; i++) scanf("%d", &mat[i]);

	scanf("%d", &f);
	for(int i=0; i<f; i++) scanf("%d", &fis[i]);

	scanf("%d", &q);
	for(int i=0; i<q; i++) scanf("%d", &qui[i]);

	scanf("%d", &b);
	for(int i=0; i<b; i++) scanf("%d", &bio[i]);

	scanf("%d", &k);

	for(int i=0; i<p; i++)
		for(int j=0; j<m; j++)
			for(int k=0; k<f; k++)
				for(int l=0; l<q; l++)
					for(int g=0; g<b; g++)
						conj.push_back(port[i]+mat[j]+fis[k]+qui[l]+bio[g]);

	sort(conj.rbegin(), conj.rend());

	for(int i=0; i<k; i++)
		ans+=conj[i];

	printf("%d\n", ans);

	return 0;
}
