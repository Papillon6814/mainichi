#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    vector<int> x(n), l(n);
    for(int i=0; i<n; i++) {
        cin >> x[i] >> l[i];
    }

    vector<pii> p(n);
    for(int i=0; i<n; i++) {
        p[i].first = x[i] + l[i];
        p[i].second = x[i] - l[i];
    }

    sort(p.begin(), p.end());

    int ans = 1;
    int t = p[0].first;
    for(int i=1; i<n; i++) {
        if(t <= p[i].second) {
            ans++;
            t = p[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}