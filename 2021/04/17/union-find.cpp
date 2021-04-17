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

    // 初期化
    void init(int n) {
        data.assign(n, -1);
    }

    // xとyを併合
    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if(x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
    }

    // xとyが同じ集合にあるか判定
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }

    // xを含む集合の要素数を求める
    int size(int x) {
        return -data[root(x)];
    }

    // 親を探す
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind uf;
    uf.init(N);
    REP(Q) {
        int P, A, B;
        cin >> P >> A >> B;

        if (P==0) {
            uf.unionSet(A, B);
        } else {
            if (uf.findSet(A, B)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}