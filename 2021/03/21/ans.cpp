#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int t[2] = {0, 0};
    while (n--) {
        string s;
        cin >> s;
        int cc = 0;
        for (char&c : s) {
            cc ^= (c - '0');
        }
        t[cc]++;
    }
    cout << 1LL * t[0] * t[1];
    return 0;
}