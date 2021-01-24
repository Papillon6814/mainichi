#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    vector<pii> v(n);
    for(int i=0; i<n; i++) {
        int x, l;
        cin >> x >> l;
        v[i].first = x + l;
        v[i].second = x - l;
    }

    sort(v.begin(), v.end());

    int ans = 1;
    int tail = v[0].first;
    for(int i=1; i<n; i++) {
        if(tail <= v[i].second) {
            ans++;
            tail = v[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}