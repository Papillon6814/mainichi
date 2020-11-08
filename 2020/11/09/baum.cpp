#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int main() {
    int N, M;
    cin >> N >> M;

    int m[100][100] = {0};
    for(int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        m[u][v] = m[v][u] = 1;
    }

    int ans = 0;
    bool used[100] = {0};
    for(int s=0; s<N; s++) {
        if(!used[s]) {
            queue<P> Q;
            Q.push(P(s, -1));
            bool f = true;

            while(!Q.empty()) {
                int now = Q.front().first;
                int prev = Q.front().second;
                Q.pop();

                if(used[now]) {
                    f = false;
                    continue;
                }
                used[now] = true;
                for(int i=0; i<N; i++) {
                    if(m[now][i] && i != prev) {
                        Q.push(P(i, now));
                    }
                }
            }
            if(f) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}