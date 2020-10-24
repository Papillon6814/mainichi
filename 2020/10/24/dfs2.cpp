#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int h, w;
// 塀があるかどうかを判定するための二次元配列
int c[500][500];
int sx, sy;
int tx, ty;

bool dfs(int px, int py) {
    if(tx == px && ty == py) return true;
    c[py][px] = true;
    
    if(0 <= px+1 && px+1 < w && 0 <= py && py < h && !c[py][px+1])
        if (dfs(px+1, py)) return true;
    if(0 <= px && px < w && 0 <= py+1 && py+1 < h && !c[py+1][px])
        if (dfs(px, py+1)) return true;
    if(0 <= px-1 && px-1 < w && 0 <= py && py < h && !c[py][px-1])
        if (dfs(px-1, py)) return true;
    if(0 <= px && px < w && 0 <= py-1 && py-1 < h && !c[py-1][px])
        if (dfs(px, py-1)) return true;

    return false;
}

int main() {
    cin >> h >> w;
    for(int y=0; y<h; y++) {
        string s;
        cin >> s;
        for(int x=0; x<w; x++) {
            if(s[x] == '#') c[y][x] = true;
            if(s[x] == 's') {
                sx = x;
                sy = y;
            } else if(s[x] == 'g') {
                tx = x;
                ty = y;
            }
        }
    }

    if (dfs(sx, sy)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}