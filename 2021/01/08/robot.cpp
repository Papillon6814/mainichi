#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ll N;
    cin >> N;
    vector<pll> v(N);
    for(auto& i: v) {
        cin >> i.first >> i.second;
        i.first += INT_MAX;
        i.first += i.second;
        (i.second *= -2) += i.first;
    }

    sort(v.begin(), v.end());
    long utan{0}, ans{0};
    for(auto& i: v) {
        if(i.second >= utan) {
            ++ans;
            utan = i.first;
        }
    }

    cout << ans << endl;

    return 0;
}