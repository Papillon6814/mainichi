#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll t[n];
    for(ll i=0; i<n; i++) cin >> t[i];

    ll ans = LONG_LONG_MAX;

    for(ll bit=0; bit < (1<<n); bit++) {
        ll a = 0;
        ll b = 0;
        for(ll j=0; j<n; j++) {
            if(bit&(1<<j)) {
                a += t[j];
            } else {
                b += t[j];
            }
        }
        ans = min(ans, max(a, b));
    }

    cout << ans << endl;

    return 0;
}