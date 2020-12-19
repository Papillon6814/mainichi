#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;

    for(ll i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(ll i=0; i<n; i++) {
        ll pl = a[i] * (n-1);
        ll mi = a[i] * i * (-2);
        sum += pl+mi;
    }

    cout << abs(sum) << endl;

    return 0;
}