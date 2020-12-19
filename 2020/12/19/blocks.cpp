#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w;
    int mi = INT_MAX;
    int ans = 0;
    cin >> h >> w;

    int a[h][w];
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> a[i][j];
            mi = min(mi, a[i][j]);
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            ans += (a[i][j] - mi);
        }
    }

    cout << ans << endl;

    return 0;
}