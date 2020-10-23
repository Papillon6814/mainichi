#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 障害物の管理をするための配列
bool c[501][501];
int sx, sy;
int tx, ty;
int h, w;

bool dfs(int px, int py) {
    if(px == tx && py == ty) {
        return true;
    }
    c[py][px] = true;
    // 4方向を探索するための配列を作成している
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    for(int i=0; i<4; i++) {
        int nx = px+dx[i];
        int ny = py+dy[i];
        if(0<=nx && nx<w && 0<=ny && ny<h && !c[ny][nx]) {
            if(dfs(nx, ny)) return true;
        }
    }

    return false;
}

int main() {
    // この辺は全部座標入力
    cin >> h >> w;
    for(int y=0; y<h; y++) {
        string in;
        cin >> in;
        for(int x=0; x<w; x++) {
            c[y][x] = (in[x] == '#');
            if (in[x] == 's') {
                sx = x;
                sy = y;
            } else if(in[x] == 'g') {
                tx = x;
                ty = y;
            }
        }
    }
    
    cout << (dfs(sx, sy) ? "Yes" : "No") << endl;
    return 0;
}