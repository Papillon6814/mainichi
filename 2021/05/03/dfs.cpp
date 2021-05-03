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

int H, W;
int gx, gy;
vcc c;

bool dfs(int x, int y) {
    if(x == gx && y == gy) return true;

    if(c[x+1][y] != '#' && x+1 < W && x+1 >= 0) dfs(x+1, y);
    if(c[x-1][y] != '#' && x-1 < W && x-1 >= 0) dfs(x-1, y);
    if(c[x][y+1] != '#' && y+1 < H && y+1 >= 0) dfs(x, y+1);
    if(c[x][y-1] != '#' && y-1 < H && y-1 >= 0) dfs(x, y-1);

    return false;
}

int main() {
    int sx, sy;

    c.resize(H);
    REP(H) c[i].resize(W);

    REP(H) {
        rep(j, W) {
            cin >> c[i][j];
            if (c[i][j] == 's') {
                sx = j;
                sy = i;
            } else if (c[i][j] == 'g') {
                gx = j;
                gy = i;
            }
        }
    }

    bool ans = dfs(sx, sy);

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}