#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> s;
vector<vector<bool>> vis;

int dfs(int h, int w, int ans) {
    int cnt = 0;
    vis[h][w] = true;
    //printf("%d\n", ans);

    if(s[h+1][w] == '.') cnt++;
    if(s[h-1][w] == '.') cnt++;
    if(s[h][w+1] == '.') cnt++;
    if(s[h][w-1] == '.') cnt++;

    int kado = ans;
    if(cnt >= 2) kado++;

    if(s[h+1][w] == '#' && !vis[h+1][w]) kado = dfs(h+1, w, kado);
    if(s[h-1][w] == '#' && !vis[h-1][w]) kado = dfs(h-1, w, kado);
    if(s[h][w+1] == '#' && !vis[h][w+1]) kado = dfs(h, w+1, kado);
    if(s[h][w-1] == '#' && !vis[h][w-1]) kado = dfs(h, w-1, kado);

    return kado;
}

int main() {
    int h, w;
    int sh = -1, sw = -1;
    cin >> h >> w;
    s.resize(h);
    vis.resize(h);
    for(int i=0; i<h; i++) {
        s[i].resize(w);
        vis[i].resize(w);
    }

    int ans = 0;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> s[i][j];
            if(sh == -1 && s[i][j] == '#') {
                sh = i; 
                sw = j;
                //cout << i << " " << j << endl;
            }
        }
    }

    cout << dfs(sh, sw, ans) << endl;
}