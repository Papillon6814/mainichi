#include <bits/stdc++.h>

using namespace std;

int main() {
    // かぶったら他の箱に移してみる？
    int n, k;
    int ans = 0;
    cin >> n >> k;
    vector<int> a(n);
    //vector<vector<int>> box(k, vector<int>(n, -1));
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int cnt[n];
    for(int i=0; i<n; i++) {
        if(a[0] != 0) break;

        if(i == 0) ans++;
        if(i != 0) {
            if(a[i] == a[i-1]) {
                cnt[i]++;
                if(cnt[i] == k) continue;
                if(cnt[i] <= cnt[i-1]) {
                    ans++;
                }
            }
            if(a[i] == a[i-1]+1) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}