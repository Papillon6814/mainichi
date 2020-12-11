#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int h, w;
    cin >> h >> w;

    // 答え格納用
    vector<string> g(h);
    // 最初からある黒いマスの数
    int black = 0;
    for(int i=0; i<h; i++) {
        cin >> g[i];
        for(int j=0; j<w; j++) {
            if(g[i][j] == '#') black++;
        }
    }

    queue<pii> q;
    // キューのペアに(0, 0)を追加
    q.emplace(0, 0);

    // 歩数を記録するためのベクター
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[0][0] = 0;

    const int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for(int i=0; i<4; i++) {
            int ty = y + d[i][0];
            int tx = x + d[i][1];

            if(ty<0 || tx<0 || ty>=h || tx>=w) continue;
            if(g[ty][tx] == '#') continue;
            if(dist[ty][tx] != -1) continue;

            // 現在の歩数プラス1
            dist[ty][tx] = dist[y][x] + 1;
            q.emplace(ty, tx);
        }
    }

    // 到達できてないとき
    if(dist[h-1][w-1] == -1) cout << -1 << endl;
    // 到達できたとき
    // 全体から、自分の歩いた歩数と、もとから黒だったマスの分をマイナスし、最後に初期位置の分もマイナス1する。
    else cout << (h*w) - dist[h-1][w-1] - black - 1 << endl;

    return 0;
}