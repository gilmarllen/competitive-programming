#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int MAX_N = 100+5;

//
// Função mmc
//
int mmc(int num1, int num2) {

    int mmc, aux, i;

    for (i = 2; i <= num2; i++) {
        aux = num1 * i;
        if ((aux % num2) == 0) {
            mmc = aux;
            i = num2 + 1;
        }
    }
    return mmc;
}

char initial_state[MAX_N];
bool changed[MAX_N];

int main(){
    int n, q;
    int n_test = 0;
    while(true)
    {
        scanf("%d %d", &n, &q);
        if(!n && !q)
            break;
        // cout << n << " " << q;
        for(int i=0; i<n; i++){
            scanf(" %c", &initial_state[i]);
            // cout << initial_state[i];
        }

        for(int i=0; i<q; i++){
            int k, m;
            cin >> k >> m;
            
            int repeat = (mmc(n, k)/k);
            int count = m%repeat;

            memset(changed, 0, sizeof(changed));
            if((m/repeat)%2){
                int first_it = repeat;
                int idx = 0;
                while(first_it--){
                    changed[idx] = !changed[idx];
                    idx = (idx+k)%n;
                }
            }
            
            int idx = 0;
            while(count--)
            {
                changed[idx] = !changed[idx];
                idx = (idx+k)%n;
            }

            for(int j=0; j<n; j++){
                char c_out = initial_state[j];
                if(changed[j])
                    c_out = (c_out=='x') ? 'o' : 'x';
                cout << c_out;
            }
            cout << endl;

            n_test++;
        }

    }
    
    return 0;
}

// 1 4 7 2 5 8 3 6 1