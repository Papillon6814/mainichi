#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vc = vector<char>;
using vii = vector<vector<int> >;
using vll = vector<vector<ll> >;
using vcc = vector<vector<char> >;
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
    int N, Q;
    cin >> N >> Q;

    vii G(100000);
    for(int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int c[Q], d[Q];
    for(int i=0; i<Q; i++) {
        cin >> c[i] >> d[i];
    }

    for (int i=0; i<Q; i++) {
        vi dist(N, -1);
        queue<int> que;
        dist[c[i]] = 0;
        que.push(c[i]);

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (int nv : G[v]) {
                if(dist[nv] != -1) continue;

                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }

        int len = dist[d[i]];
        if (len%2 == 0) {
            cout << "Town" << endl;
        } else {
            cout << "Road" << endl;
        }
    }
}

