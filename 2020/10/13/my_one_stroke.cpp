#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// node間を繋ぐedgeを入れるための箱
vector<int> node[10];
// 訪問済みかどうかを確かめるための箱
bool is_visited[10];
int n, m;
int ans = 0;

void dfs(int node_idx, int cnt) {
    // ノード1番目からスタートなのでカウントも1
    if (n == cnt) {
        // ノード一番うしろまで到達したときに全部訪問していれば答えになれる。
        ans++;
        return;
    }

    is_visited[node_idx] = true;
    // つながっているノードの数だけループして探索をする。
    for(int i=0; i<node[node_idx].size(); i++) {
        if (!is_visited[node[node_idx][i]]) dfs(node[node_idx][i], cnt+1);
    }
    is_visited[node_idx] = false;
}

int main() {
    cin >> n >> m;

    for(int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;

        node[u].push_back(v);
        node[v].push_back(u);
    }

    dfs(1, 1);

    cout << ans << endl;

    return 0;
}