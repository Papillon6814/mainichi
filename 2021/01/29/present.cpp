#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    vector<pii> v(n);

    for(int i=0; i<n; i++) {
        int w, h;
        cin >> w >> h;
        v[i] = pii(w, -h);
    }

    sort(v.begin(), v.end());

    // 何用のベクトルだろう
    vector<int> v2(n);
    for(int i=0; i<n; i++) {
        v2[i] = -v[i].second;
    }

    // これも何用のベクトルかわからん
    vector<int> dp(n+1, 1e9);
    dp[0] = -1e9;
    for(int i=0; i<n; i++) {
        int p = lower_bound(dp.begin(), dp.end(), v2[i]) - dp.begin();
        dp[p] = v2[i];
    }

    int ans = -1;
    for(int i=n; i>0; --i) {
        if(dp[i] < 1e9) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}