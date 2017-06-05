#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n=1, m=1;
int frente[112];
int traz[112];

vector<double> ratio;

int main()
{
    scanf("%d", &n);
    while(n!=0)
    {
        double maiorDif=-1;
        double d1=0, d2=0;

        scanf("%d", &m);
        
        for(int i=0; i<n; i++)
            scanf("%d", &frente[i]);

        for(int i=0; i<m; i++)
            scanf("%d", &traz[i]);

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                ratio.push_back((double)traz[j]/(double)frente[i]);

        sort(ratio.begin(), ratio.end());

        vector<double>::iterator it;

        for(it=ratio.begin()+1; it!=ratio.end(); it++)
        {
            double dif = (*it)/(*(it-1));
            if(dif > maiorDif)
            {
                maiorDif = dif;
                d2 = (*it);
                d1 = (*(it-1));
            }
        }

        printf("%.2lf\n", d2/d1);

        scanf("%d", &n);
        ratio.clear();
    }

	return 0;
}
