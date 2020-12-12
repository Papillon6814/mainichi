#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int h, w;
int black = 0;
vector<string> g;
vector<vector<int>> dist;
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void bfs() {
    dist.resize(h, vector<int>(w, -1));
    queue<pii> q;

    dist[0][0] = 0;
    q.push(pii(0, 0));
    while(!q.empty()) {
        pii t = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int ty = t.first + d[i][0];
            int tx = t.second + d[i][1];

            if(ty<0 || tx<0 || ty>=h || tx>=w) continue;
            if(g[ty][tx] == '#') continue;
            if(dist[ty][tx] != -1) continue;

            q.push(pii(ty, tx));
            dist[ty][tx] = dist[t.first][t.second] + 1;
        }
    }
}

int main() {
    cin >> h >> w;
    g.resize(h);
    for(int i=0; i<h; i++) {
        cin >> g[i];
        for(int j=0; j<w; j++) {
            if(g[i][j] == '#') black++;
        }
    }

    bfs();

    if(dist[h-1][w-1] == -1) cout << -1 << endl;
    else cout << (h*w) - black - dist[h-1][w-1] - 1 << endl;

    return 0;
}