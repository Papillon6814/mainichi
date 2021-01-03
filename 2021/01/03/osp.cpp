#include <bits/stdc++.h>

using namespace std;

bool check[10];
int n, m, ans;
vector<int> e[10];

void dfs(int g, int tot) {
    check[g] = true;

    if(tot == n) {
        ans++;
    } else {
        for(int i=0; i<e[g].size(); i++) {
            if(check[e[g][i]]) continue;
            dfs(e[g][i], tot+1);
        }
    }

    check[g] = false;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        
        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs(1, 1);

    cout << ans << endl;

    return 0;
}