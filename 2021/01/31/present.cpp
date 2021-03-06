#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    vector<pii> a(n);

    for(int i=0; i<n; i++) {
        int w, h;
        cin >> w >> h;
        a[i] = pii(w, -h);
    }

    sort(a.begin(), a.end());

    vector<int> b(n);
    for(int i=0; i<n; i++) {
        b[i] = -a[i].second;
    }

    int ans = -1;
    vector<int> dp(n+1, 1e9);
    for(int i=n; i>0; --i) {
        if(dp[i] < 1e9) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}