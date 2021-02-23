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
    bool ki[222222];
    ll dp[222222];
    ll n, m;
    cin >> n >> m;
    REP(m) {
        ll a;
        cin >> a;
        ki[a] = true;
    }

    dp[0] = 1;
    REP(n) {
        if(!ki[i+1]) {
            dp[i+1] += dp[i];
            dp[i+1] %= MOD;
        }
        if(!ki[i+2]) {
            dp[i+2] += dp[i];
            dp[i+2] %= MOD;
        }
    }

    cout << dp[n] << endl;
}