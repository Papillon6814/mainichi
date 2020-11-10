#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // 頂点どうしの結びつきを確保するための二次元配列
    int m[100][100] = {0};
    for(int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        m[u][v] = m[v][u] = 1;
    }

    // 木の数格納用
    int ans = 0;
    bool used[100] = {0};
    for(int s=0; s<N; s++) {
        if(!used[s]) {
            queue<pair<int, int> > Q;
            Q.push(pair<int, int>(s, -1));
            bool f = true;

            // XXX: このwhileの部分はよくわからん
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
                        Q.push(pair<int, int>(i, now));
                    }
                }
            }
            if(f) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}