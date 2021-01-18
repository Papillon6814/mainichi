#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    int N = 4e5 + 123;
    int cnt[N];

    for(int i=1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    ll ans = 0;

    for(int i=0; i <= n; i++) {
        ans += min(cnt[i], m);
        m = min(cnt[i], m);
    }

    cout << ans << endl;

    return 0;
}