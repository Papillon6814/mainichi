#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    vector<pii> x;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        x[i].first = b;
        x[i].second = a;
    }

    sort(x.begin(), x.end());

    int ans = 1;
    int tail = x[0].first;
    for(int i=1; i<n; i++) {
        if(x[i].second >= tail) {
            ans++;
            tail = x[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}