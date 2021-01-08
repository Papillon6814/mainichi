#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ll N;
    cin >> N;
    vector<pll> v(N);

    for(int i=0; i<N; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].first += INT_MAX;
        v[i].first += v[i].second;
        (v[i].second *= -2) += v[i].first;
    }

    sort(v.begin(), v.end());

    long utan{0}, ans{0};
    for(int i=0; i<N; i++) {
        if(v[i].second >= utan) {
            ++ans;
            utan = v[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}