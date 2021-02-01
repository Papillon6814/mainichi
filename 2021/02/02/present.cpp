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

    // ここまではOK

    vector<int> b(n);
    for(int i=0; i<n; i++) {
        // 新しいベクトルに箱の高さ*-1を格納していく
        b[i] = -a[i].second;
    }

    int ans = -1;
    // 理解不能なベクトル
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