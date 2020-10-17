#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, y;

int main() {
    cin >> n >> y;
    ll fuku = -1;
    ll higu = -1;
    ll nogu = -1;

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            ll fu = 10000*i;
            ll hi = 5000*j;
            ll no = 1000*(n-i-j);
            if(fu+hi+no == y && n-i-j >= 0) {
                fuku = i;
                higu = j;
                nogu = (n-i-j);
                break;
            }
        }
    }

   cout << fuku << " " << higu << " " << nogu << endl;

    return 0;
}