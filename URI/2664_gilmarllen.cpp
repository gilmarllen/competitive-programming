#include <bits/stdc++.h>
using namespace std;

#define trav(a, x) for(auto& a : x)
#define print(a) trav(x, a) cout << x << " "; cout << "\n";
// vector<int> arrDebug;

const long long int div_1 = pow(10, 9) + 7;

long long int t, m, n, upBound;
long long int pd[55][112345];

long long int rec(long long int timeLeft, long long int current){
  if((current > upBound) || (current < 0))
    return 0;

  // arrDebug.push_back(current);

  if(timeLeft==0){
    // print(arrDebug);
    // arrDebug.pop_back();
    return 1;
  }
  if(pd[timeLeft][current]!=-1)
    return pd[timeLeft][current];

  long long int d = rec(timeLeft-1, current-1);
  long long int u = rec(timeLeft-1, current+1);
  // arrDebug.pop_back();

  return pd[timeLeft][current] = (d + u)%div_1;
}

int main()
{
  memset(pd, -1, sizeof(pd));

  scanf("%lld %lld %lld", &t, &m, &n);
  upBound = n-m;

  long long int resp = 0;
  for(int i=0; i<=upBound; i++){
    resp += rec(t-1,i);
    resp = resp%div_1;
  }
  printf("%lld\n", resp);

  return 0;
}