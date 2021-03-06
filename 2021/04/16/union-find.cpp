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
    vector<int> data;

    void init(int N) {
        data.assign(N, -1);
    }

    // その要素の根を取得する
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    // 木の大きさ
    int size(int x) {
        return -data[root(x)];
    }

    // 木の融合
    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        // 同じ木だったらダメ
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }

        return x != y;
    }

    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind uf;
    // まずは木を初期化する
    uf.init(N);

    // クエリがQ回くる
    REP(Q) {
        int P, A, B;
        cin >> P >> A >> B;
        if (P == 0) {
            // 連結クエリ
            uf.unionSet(A, B);
        } else {
            // 判定クエリ
            bool ans = uf.findSet(A, B);
            if (ans) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}