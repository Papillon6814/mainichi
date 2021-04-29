#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vc = vector<char>;
using vii = vector<vector<int>>;
using vll = vector<vector<ll>>;
using vcc = vector<vector<char>>;
using vs = vector<string>;
using Pi = pair<int , int>;
using Pl = pair<ll, ll>;
using vpi = vector<Pi>;
using vpl = vector<Pl>;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(n) for (ll i = 0; i < n; i++)
#define repint(i, n) for (int i = 0; i < n; i++)
#define rep2(i, s, n) for (int i = (s); i < n; i++)
#define REP2(s, n) for (int i = (s); i < n; i++)
#define rep3(i ,j, n, m) rep(i, n)rep(j, m)
#define REP3(n, m) rep(i, n)rep(j, m)
#define sort(A) sort(A.begin(),A.end());
#define reverse(A) reverse(A.begin(),A.end());
#define k(s) cout << fixed << setprecision(s);
const long double pi=3.14159265358979323846;
const long long MOD=1000000007;

int main() {
    int N;
    cin >> N;

    int t[N];
    REP(N) {
        cin >> t[i];
    }

    int ans = INT_MAX;

    REP(1<<N) {
        int a = 0, b = 0;
        rep(j, N) {
            if(i&(1<<j)) {
                a += t[j];
            } else {
                b += t[j];
            }
        }

        ans = min(ans, max(a, b));
    }

    cout << ans << endl;
}

/*
bit: 0
1<<j:   1
false
bit: 0
1<<j:   2
false
bit: 0
1<<j:   4
false
bit: 0
1<<j:   8
false
bit: 1
1<<j:   1
true
bit: 1
1<<j:   2
false
bit: 1
1<<j:   4
false
bit: 1
1<<j:   8
false
bit: 2
1<<j:   1
false
bit: 2
1<<j:   2
true
bit: 2
1<<j:   4
false
bit: 2
1<<j:   8
false
bit: 3
1<<j:   1
true
bit: 3
1<<j:   2
true
bit: 3
1<<j:   4
false
bit: 3
1<<j:   8
false
bit: 4
1<<j:   1
false
bit: 4
1<<j:   2
false
bit: 4
1<<j:   4
true
bit: 4
1<<j:   8
false
bit: 5
1<<j:   1
true
bit: 5
1<<j:   2
false
bit: 5
1<<j:   4
true
bit: 5
1<<j:   8
false
bit: 6
1<<j:   1
false
bit: 6
1<<j:   2
true
bit: 6
1<<j:   4
true
bit: 6
1<<j:   8
false
bit: 7
1<<j:   1
true
bit: 7
1<<j:   2
true
bit: 7
1<<j:   4
true
bit: 7
1<<j:   8
false
bit: 8
1<<j:   1
false
bit: 8
1<<j:   2
false
bit: 8
1<<j:   4
false
bit: 8
1<<j:   8
true
bit: 9
1<<j:   1
true
bit: 9
1<<j:   2
false
bit: 9
1<<j:   4
false
bit: 9
1<<j:   8
true
bit: 10
1<<j:   1
false
bit: 10
1<<j:   2
true
bit: 10
1<<j:   4
false
bit: 10
1<<j:   8
true
bit: 11
1<<j:   1
true
bit: 11
1<<j:   2
true
bit: 11
1<<j:   4
false
bit: 11
1<<j:   8
true
bit: 12
1<<j:   1
false
bit: 12
1<<j:   2
false
bit: 12
1<<j:   4
true
bit: 12
1<<j:   8
true
bit: 13
1<<j:   1
true
bit: 13
1<<j:   2
false
bit: 13
1<<j:   4
true
bit: 13
1<<j:   8
true
bit: 14
1<<j:   1
false
bit: 14
1<<j:   2
true
bit: 14
1<<j:   4
true
bit: 14
1<<j:   8
true
bit: 15
1<<j:   1
true
bit: 15
1<<j:   2
true
bit: 15
1<<j:   4
true
bit: 15
1<<j:   8
true
*/