#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int ans = 0;
vector<int> g[10];
// ノードが訪問済みかどうかを記録するためのvector
bool vis[10];

void dfs(int cnode_idx, int cnt);

int main() {
    cin >> n >> m;
    g->assign(10, -1);

    for(int i=1; i<=m; i++) {
        // 無向グラフなので双方向で移動ができる
        int v, u;
        cin >> v >> u;

        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);

    cout << ans << endl;

    return 0;
}

void dfs(int cnode_idx, int cnt) {
    // 最後まで到達できたとき
    if (cnt == n) {
        ans++;
        return;
    }

    vis[cnode_idx] = true;
    for(int i=0; i<g[cnode_idx].size(); i++) {
        if(!vis[g[cnode_idx][i]]) dfs(g[cnode_idx][i], cnt+1);
    }
    vis[cnode_idx] = false;
}
