#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int N;
    cin >> N;
    // それぞれ座標と腕の長さを表す
    vector<int> x(N), l(N);

    for(int i=0; i<N; i++) {
        cin >> x[i] >> l[i];
    }

    // robotの始点と終点
    vector<pii> p(N);
    for(int i=0; i<N; i++) {
        p[i].first = x[i] + l[i];
        p[i].second = x[i] - l[i];
    }

    sort(p.begin(), p.end());

    int ans = 1;
    int tail = p[0].first;
    for(int i=1; i<N; i++) {
        if(tail <= p[i].second) {
            ans++;
            tail = p[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}