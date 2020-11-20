#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
int r, c, sx, sy, gx, gy;

char m[51][51];
int d[4][2]={{0, 1},{1, 0},{-1 ,0},{0, -1}};

int bfs(int sy, int sx) {
    vector< vector<int> > dist(r, vector<int>(c, 10000000));
    queue<pii> que;

    pii g(gy, gx);
    que.push(pii(sy, sx));
    dist[sy][sx] = 0;

    while(!que.empty()) {
        pii t = que.front();
        que.pop();
        if(t == g) return dist[t.first][t.second];
        for(int i=0; i<4; i++) {
            int tx = t.second + d[i][0];
            int ty = t.first + d[i][1];
            if(tx<0 || ty<0 || ty>=r || m[ty][tx] == '#' || dist[ty][tx] <= dist[t.first][t.second] + 1) continue;
            que.push(pii(ty, tx));
            dist[ty][tx] = dist[t.first][t.second] + 1;
        }
    }

    return -1;
}

int main() {
    cin >> r >> c;
    cin >> sy >> sx;
    cin >> gy >> gx;
    sy--;sx--;gy--;gx--;

    for(int i=0; i<r; i++) cin >> m[i];
    cout << bfs(sy, sx) << endl;

    return 0;
}