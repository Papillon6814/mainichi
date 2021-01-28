#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int main() {
    int n;
    cin >> n;
    vector<pipii> v(n);

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        int mul = a*b;
        v[i] = pipii(mul, pii(a, b));
    }

    sort(v.begin(), v.end());

    int ans = 1;
    pii tail = v[0].second;
    for(int i=1; i<v.size(); i++) {
        pii se = v[i].second;
        if(se.first > tail.first && se.second > tail.second) {
            ans++;
            tail = se;
        }
    }

    cout << ans << endl;

    return 0;
}