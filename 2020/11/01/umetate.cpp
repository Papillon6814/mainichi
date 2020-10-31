#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// 実際に探索をするための地図の二次元配列
char mp[15][15];
// 入力を取るための二次元配列
char tmp[15][15];

void dfs(int x, int y) {
    // 海に落ちちゃったらreturn
    if(mp[x][y] == 'x') return;
    mp[x][y] = 'x';

    if(0 <= x+1 && x+1 < 10 && 0 <= y && y < 10)
        dfs(x+1, y);
    if(0 <= x-1 && x-1 < 10 && 0 <= y && y < 10)
        dfs(x-1, y);
    if(0 <= x && x < 10 && 0 <= y+1 && y+1 < 10)
        dfs(x, y+1);
    if(0 <= x && x < 10 && 0 <= y-1 && y-1 < 10)
        dfs(x, y-1);
}

bool solve() {
    // スタート地点を探索するためのループ
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(mp[i][j] == 'o') {
                dfs(i, j);
                i=10;
                j=10;
                break;
            }
        }
    }

    // dfsで変化したmpを観察して上手く埋め立てが出来たかを確認する
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(mp[i][j] == 'o') return false;
        }
    }

    return true;
}

// このコードけっこうわかりやすいかもしれない
int main() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cin >> tmp[i][j];
        }
    }

    bool flag = false;

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            memcpy(mp, tmp, sizeof(mp));
            mp[i][j] = 'o';
            if(solve()) {
                i = 10;
                j = 10;
                flag = true;
                break;
            }
        }
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}