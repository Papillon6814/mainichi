#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int h, w;
bool c[501][501];
int sx, sy;
int tx, ty;

bool dfs(int px, int py) {
    if(px == tx && py == ty) return true;

    c[px][py] = true;

    if(0 <= px+1 && px+1 < w && 0 <= py && py < h && !c[px+1][py])
        if(dfs(px+1, py)) return true;
    if(0 <= px-1 && px-1 < w && 0 <= py && py < h && !c[px-1][py])
        if(dfs(px-1, py)) return true;
    if(0 <= px && px < w && 0 <= py+1 && py+1 < h && !c[px][py+1])
        if(dfs(px, py+1)) return true;
    if(0 <= px && px < w && 0 <= py-1 && py-1 < h && !c[px][py-1])
        if(dfs(px, py-1)) return true;
    
    return false;
}

int main() {
    cin >> h >> w;

    for(int y=0; y<h; y++) {
        string s;
        cin >> s;
        for(int x=0; x<w; x++) {
            if(s[x] == '#') {
                c[x][y] = true;
            }

            if(s[x] == 's') {
                sx = x;
                sy = y;
            }
            
            if(s[x] == 'g') {
                tx = x;
                ty = y;
            }
        }
    }

    if(dfs(sx, sy)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}