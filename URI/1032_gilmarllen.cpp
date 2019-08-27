#include <bits/stdc++.h>
using namespace std;

const int MAXP = 112345;
const int MAXN = 3501;

int isPrime[MAXP+5];
vector<int> primes;

// int players[MAXN+5];

int main()
{

    for(int i=2; i<=MAXP; i++) {
        isPrime[i]=i;
    }

    int qtd = 0;
    for(int i=2; i*i<=MAXP; i++) {
        if(isPrime[i]==i) {
            for(int j=i+i; j<=MAXP; j+=i) {
                isPrime[j]=0;
            }
        }
    }

    for(int i=2; i<=MAXP; i++) {
    	if(isPrime[i])
    		primes.push_back(i);
    }

    for(int n=1; n<=MAXN; n++) {
    	vector<int> players;
    	for(int i=1; i<n; i++)
    		players.push_back(i);

    	int current = 0;
    	for(int i=0; i<(n-1); i++)
    	{
    		current += primes[i];
    		if(i>0) current--;
    		current = (current%n)
    		players[current] = 0;
    	}
	}

    // while(true)
    // {
    // 	int n;
    // 	cin >> n;
    // 	if(!n) break;


    // }

	return 0;
}