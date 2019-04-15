#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 112345;

int n, d;

int main()
{
    while(true)
    {
        cin >> n >> d;
        if(!n && !d) break;
        // cout << n << "  " << d << endl;
        int num[MAX_N];
        int count[MAX_N];
        memset(count, 0, sizeof(count));

        for(int i=0; i<n; i++)
        {
            char c_tmp;
            cin >> c_tmp;
            int tmp = c_tmp - '0';
            num[i] = tmp;
            count[tmp]++;
            // cout << tmp;
        }
        // cout << "end" << endl;

        int qtd = 0;
        for(int i=0; i<=9; i++)
        {
            if(qtd>=d)
                count[i] = 0;
            else if(count[i]){
                qtd += count[i];
                if(qtd>d)
                    count[i] -= (qtd-d);
            }
                
        }

        for(int i=0; i<9; i++)
            cout << i << ": " << count[i] << endl;

        for(int i=0; i<n; i++)
        {
            if( count[ num[i] ] ){
                count[ num[i] ]--;
                num[i]=-1;
            }
        }

        for(int i=0; i<n; i++)
        {
            if(num[i]!=-1) cout << num[i];
        }
        cout << endl;
    }

    return 0;
}