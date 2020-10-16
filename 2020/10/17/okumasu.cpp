#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;

ll n, k;
vector<ll> a, b;

bool check(ll x) {
    ll cnt = 0;
    for(int i=0; i<n; i++) {
        cnt += upper_bound(b.begin(), b.end(), x/a[i]) - b.begin();
    }

    return cnt >= k;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<n; i++) cin >> b[i];

    //sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll mi = 0;
    ll ma = LL_INF;
    while(ma - mi > 1) {
        ll mid = (ma+mi)/2;

        if(check(mid)) ma = mid;
        else mi = mid;
    }

    cout << ma << endl;
}