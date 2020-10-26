#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// bit全探索をして0と1で判別し、0なら１つ目の肉焼き器みたいな感じ
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    int ans = INT_MAX;

    for(int bit=0; bit<(1<<n); bit++) {
        int yakia = 0;
        int yakib = 0;
        for(int i=0; i<n; i++) {
            if(bit&(1<<i)) yakia += a[i];
            else yakib += a[i];
        }
        ans = min(ans, max(yakia, yakib));
    }

    cout << ans << endl;

    return 0;
}