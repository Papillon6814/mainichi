#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll get_digit(ll num) {
    ll digit = 0;
    while (num > 0) {
        num /= 10;
        digit++;
    }

    return digit;
}

const ll LL_INF = 9223372036854775807;

int main() {
    ll n, ans = LL_INF;
    cin >> n;

    for(ll i=1; i*i<n; i++) {
        if (n%i == 0) {
            ll a = (ll)n/i;
            ll m = max(get_digit(i), get_digit(a));
            if (m < ans) ans = m;
        }
    }

    cout << ans << endl;

    return 0;
}
