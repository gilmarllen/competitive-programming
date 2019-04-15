#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int a1, a2, a3;

int main()
{
    cin >> a1 >> a2 >> a3;

    int c1 = a2*2 + a3*4;
    int c2 = a1*2 + a3*2;
    int c3 = a1*4 + a2*2;

    cout << min(min(c1,c2), c3) << endl;

    return 0;
}