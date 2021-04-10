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

int root(int a, vector<int>& v) {
    if(v[a] == a) return a;
    return (v[a] = root(v[a], v));
}

void unite(int a, int b, vector<int>& v) {
    v[root(a, v)] = root(b, v);
}

int main() {
    int N;
    cin >> N;
    int K, L;
    cin >> K >> L;

    vector<int> road, train;
    road.resize(N);
    REP(N) {
        road[i] = i;
    }

    train.resize(N);
    REP(N) {
        train[i] = i;
    }

    REP(K) {
        int p, q;
        cin >> p >> q;
        unite(p-1, q-1, road);
    }

    REP(L) {
        int r, s;
        cin >> r >> s;
        unite(r-1, s-1, train);
    }
}