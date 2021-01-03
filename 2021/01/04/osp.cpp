#include <bits/stdc++.h>

using namespace std;

bool check[10];
vector<int> e[10];
int n, m, ans;

void dfs(int p, int tot) {
    check[p] = true;

    if(tot == n) {
        ans++;
    } else {
        for(int i=0; i<e[p].size(); i++) {
            if(check[e[p][i]]) continue;
            dfs(e[p][i], tot+1);
        }
    }

    check[p] = false;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    dfs(1, 1);

    cout << ans << endl;

    return 0;
}