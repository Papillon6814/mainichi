#include <bits/stdc++.h>

using namespace std;

int ans, n, m;
vector<int> e[10];
bool check[10];

void dfs(int p, int tot) {
    // 訪問済みに切り替える
    check[p] = true;

    // すべてのノードを通ったらansに１加算
    if(tot == n) {
        ans++;
    } else {
        for(int i=0; i<e[p].size(); i++) {
            // ノードが訪問済みだったらcontinue
            if(check[e[p][i]]) continue;
            dfs(e[p][i], tot+1);
        }
    }
    // 次の処理のために未訪問に戻す
    check[p] = false;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        // ノードを登録する
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 1);

    cout << ans << endl;

    return 0;
}