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

ll R, B, x, y;

bool check(int mid) {
    int r = R - mid;
    int b = B - mid;
    if (r < 0 || b < 0) return false;

    int num = (r/x) + (b/y);
    return num >= mid;
}

int main() {
    cin >> R >> B;
    cin >> x >> y;

    ll ok = 0;
    ll ng = (R+B)/2 + 1;

    while(ng - ok > 1) {
        ll mid = (ok+ng)/2;
        if(check(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;
}