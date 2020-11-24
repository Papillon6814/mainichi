#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int r, c;
int sy, sx;
int gy, gx;
char m[51][51];
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int bfs(int sy, int sx) {
    // INT_MAXはそこまで関係ない値だと思うが大きければいい
    // distは歩数
    vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
    queue<pii> que;

    // ゴールのペアだけとりあえず設定しておく
    pii g(gy, gx);
    que.push(pii(sy, sx));
    dist[sy][sx] = 0;

    // キューがカラになるまでループします
    while(!que.empty()) {
        // キューから値を取り出す
        pii t = que.front();
        que.pop();
        if(t == g) return dist[t.first][t.second];
        for(int i=0; i<4; i++) {
            int tx = t.second + d[i][0];
            int ty = t.first + d[i][1];

            // 移動先が条件内で、歩数が少ない座標へ移動しようとしていなければ
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

    // マスのインデックス番号を調節
    sy--; sx--; gy--; gx--;
    for(int i=0; i<r; i++) cin >> m[i];

    cout << bfs(sy, sx) << endl;

    return 0;
}