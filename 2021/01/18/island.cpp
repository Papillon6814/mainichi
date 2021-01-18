#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
vector<pll> v;

ll now = -1;
ll ans = 0;

int main() {
    ll n, m;
    cin >> n >> m;
    v.resize(m);

    for(int i=0; i<m; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        v[i] = pll(b, a);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++) {
        int b = v[i].first;
        int a = v[i].second;

        if(a > now || now >= b) {
            now = b-1;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}