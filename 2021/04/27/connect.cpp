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
    vi rank;

    UnionFind(int n) {
        data.resize(n);
        rank.resize(n);

        REP(n) {
            data[i] = i;
            rank[i] = 0;
        }
    }

    int root(int x) {
        if (data[x] == x) return x;
        return data[x] = root(data[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);

        if (rank[rx] < rank[ry]) data[rx] = ry;
        else {
            data[ry] = rx;
            if(rank[rx] == rank[ry]) rank[rx]++;
        }
    }
};

int main() {
    int N, K, L;
    cin >> N >> K >> L;

    UnionFind road(N), rail(N);
    
    REP(K) {
        int P, Q;
        cin >> P >> Q;
        road.unite(P-1, Q-1);
    }

    REP(L) {
        int R, S;
        cin >> R >> S;
        rail.unite(R-1, S-1);
    }

    map<Pi, int> m;
    REP(N) m[Pi(road.root(i), rail.root(i))]++;
    REP(N) {
        cout << m[Pi(road.root(i), rail.root(i))] << endl;
    }
}