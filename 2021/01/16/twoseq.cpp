#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll a[n];
    ll b[n];
    vector<ll> c(n, -1);

    for(ll i=0; i<n; i++) {
        cin >> a[i];
    }

    for(ll i=0; i<n; i++) {
        cin >> b[i];
    }

    ll amax = -1;
    for(ll i=0; i<n; i++) {
        amax = max(amax, a[i]);

        if(i==0) {
            c[0] = amax*b[0];
        } else {
            c[i] = max(c[i-1], amax*b[i]);
        }
    }

    for(ll i=0; i<n; i++) {
        cout << c[i] << endl;
    }

    return 0;
}