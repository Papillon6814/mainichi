#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
vector<pii> v;

int now = -1;
int ans = 0;

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v.push_back(pii(b, a));
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++) {
        int b = v[i].first;
        int a = v[i].second;
        if (a > now || now >= b) {
            now = b-1;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}