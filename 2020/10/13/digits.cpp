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

    ll a, b;

    for(ll i=1; i*i<=n; i++) {
        if (n%i == 0) {
            a = i;
            b = n/i;
        }
    }
    ans = max(get_digit(a), get_digit(b));

    cout << ans << endl;

    return 0;
}
