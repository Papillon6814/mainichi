#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

int main() {
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll sum = 0;

    for(int i=0; i<n; i++) {
        ll x = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        x = max(x, (ll)0);
        ll y = c.end() - upper_bound(c.begin(), c.end(), b[i]);

        sum += x*y;
    }

    cout << sum << endl;

    return 0;
}