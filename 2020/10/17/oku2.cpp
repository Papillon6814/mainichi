#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;

ll n, k;
vector<ll> a, b;

int main() {
    cin >> n >> k;
    a.resize(n);
    b.resize(n);

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    sort(b.begin(), b.end());

    ll ma = LL_INF;
    ll mi = 0;
    ll mid;
    while (ma - mi > 1) {
        mid = (ma+mi)/2;
        ll cnt = 0;
        for(int i=0; i<n; i++) {
            cnt += upper_bound(b.begin(), b.end(), mid/a[i]) - b.begin();
        }

        bool check = k <= cnt;
        if(check) ma = mid;
        else mi = mid;
    }

    cout << ma << endl;

    return 0;
}