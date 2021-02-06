#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    long double x, y, r;
    cin >> x >> y >> r;
    ll ans = 0;

    ll mi = (ll)ceil(x-r);
    ll ma = (ll)floor(x+r);

    for(ll i=mi; i<=ma; i++) {
        long double p = (long double)sqrt(pow(r,2)-pow(x-(long double)i, 2));
        ll bottom = (ll)ceil(y-p);
        ll top = (ll)floor(y+p);
        for(ll j=bottom; j<=top; j++) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}