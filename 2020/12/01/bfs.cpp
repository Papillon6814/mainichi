/*


なんか今回は無理



*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int r, c;
int sy, sx;
int gy, gx;
char m[51][51];
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int bfs(int y, int x) {
    vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
    queue<pii> q;

    pii g(gy, gx);
    dist[sy][sx] = 0;
    q.push(pii(y, x));
    
    while(!q.empty()) {
        pii t = q.front();
        q.pop();

        if (t == g) return dist[t.first][t.second] + 1;
        for(int i=0; i<4; i++) {
            int tx = t.first + d[i][0];
            int ty = t.second + d[i][1];

            // 範囲外に出たり条件外になったらキューにpushしない
            if(0<=ty && ty<=c && 0<=tx && tx<=r && m[ty][tx] != '#') {
                q.push(pii(ty, tx));
                // 歩数もベクトルに記録する
                dist[ty][tx] = dist[t.first][t.second] + 1;
            }
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