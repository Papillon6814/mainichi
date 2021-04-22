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

struct UnionFind {
    vi data;

    UnionFind(int n) : data(n) {
        REP(n) data[i] = i;
    }

    int root(int x) {
        if (data[x] == x) return x;
        return data[x] = root(data[x]);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        data[rx] = ry;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind tree(N);

    REP(Q) {
        int P, A, B;
        cin >> P >> A >> B;

        if (P == 0) {
            tree.unite(A, B);
        } else {
            if (tree.same(A, B)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}