#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
ll a, b;

ll get_digit(ll num) {
    ll digit = 0;
    while(num > 0) {
        num /= 10;
        digit++;
    }

    return digit;
}

int main() {
    cin >> n;
    for(ll i=1; i*i<=n; i++) {
        if(n%i == 0) {
            a = (ll)(n/i);
            b = i;
        }
    }
    cout << max(get_digit(a), get_digit(b)) << endl;

    return 0;
}