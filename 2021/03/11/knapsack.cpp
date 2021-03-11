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
    ll N, W;
    cin >> N >> W;
    ll w[110], v[110];
    REP(N) cin >> w[i] >> v[i];

    // 価値を管理するためのdpテーブル
    ll dp[110][100010];
    dp[0][0] = 0;

    REP(N) {
        rep(j, W+1) {
            if(j >= w[i]) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-w[i]]+v[i]);
            }

            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }

    cout << dp[N][W] << endl;
}