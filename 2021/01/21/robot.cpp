#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    vector<pii> x(n);

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;

        int x1 = a - b;
        int x2 = a + b;
        x[i] = pii(x2, x1);
    }

    // 当然だけど昇順
    sort(x.begin(), x.end());

    int ans = 1;
    int tail = x[0].first;
    for(int i=1; i<n; i++) {
        // 前のロボットの腕の終点よりも始点があとにくる場合はTrue
        if(tail <= x[i].second) {
            ans++;
            tail = x[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}