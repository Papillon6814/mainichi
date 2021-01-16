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
        // 終点ごとにソートするのでbを先に入れる
        v.push_back(pii(b, a));
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++) {
        int b = v[i].first;
        int a = v[i].second;
        // 始点が今よりも後ろにあるか
        // 終点が今よりも前にある場合?
        if (a > now || now >= b) {
            now = b-1;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}