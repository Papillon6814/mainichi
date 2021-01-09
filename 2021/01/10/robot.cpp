#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int N;
    cin >> N;
    vector<int> x(N), l(N);
    
    for(int i=0; i<N; i++) {
        cin >> x[i] >> l[i];
    }

    vector<pii> p(N);
    for(int i=0; i<N; i++) {
        p[i].first = x[i] + l[i];
        p[i].second = x[i] - l[i];
    }

    // 終端がfirstに入っているので、終端を優先にソート
    sort(p.begin(), p.end());

    int ans = 1;
    int t = p[0].first;
    for(int i=1; i<N; i++) {
        if(t <= p[i].second) {
            ans++;
            t = p[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}