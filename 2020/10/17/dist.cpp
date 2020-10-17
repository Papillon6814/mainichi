#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
vector<pair<ll, ll> > p;

int main() {
    cin >> n;

    p.resize(n);
    for(int i=0; i<n; i++) {
        ll a, b;
        cin >> a >> b;

        p[i] = make_pair(a, b);
    }

    double longest = 0.0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            ll x = p[i].first - p[j].first;
            ll y = p[i].second - p[j].second;
            double l = sqrt(x*x+y*y);
            if(longest < l) longest = l;
        }
    }

    cout << longest << endl;

    return 0;
}