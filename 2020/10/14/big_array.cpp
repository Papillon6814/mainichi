#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k;

int main() {
    cin >> n >> k;
    vector<pair<ll, ll>> v(n);

    for(int i=0; i<n; i++) {
        ll a, b;
        cin >> a >> b;

        v[i] = make_pair(a, b);
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++) {
        k -= v[i].second;
        if(k <= 0) {
            cout << v[i].first;
            break;
        }
    }

    return 0;
}