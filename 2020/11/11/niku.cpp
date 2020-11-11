#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    int t[n];
    for(int i=0; i<n; i++) cin >> t[i];

    int ans = INT_MAX;

    for(int bit=0; bit < 1<<n; bit++) {
        int yakia = 0;
        int yakib = 0;
        for(int i=0; i<n; i++) {
            if(bit&(1<<i)) yakia += t[i];
            else yakib += t[i];
        }
        ans = min(ans, max(yakia, yakib));
    }

    cout << ans << endl;

    return 0;
}