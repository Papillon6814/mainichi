#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// 例
int main() {
    int n;
    cin >> n;

    vector<int> l(n);
    for(int i=0; i<n; i++) cin >> l[i];

    sort(l.begin(), l.end());

    int ans = 0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                if(l[i]==l[j]||l[j]==l[k]) continue;
                // 三角形の成立条件
                if(l[i]+l[j] > l[k]) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}