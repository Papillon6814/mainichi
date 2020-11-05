#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string in[11];
string target[11];

void dfs(int i, int j) {
    target[i][j] = 'x';

    if(0<=i+1 && i+1<10 && 0<=j && j<10 && target[i+1][j] == 'o') dfs(i+1, j);
    if(0<=i-1 && i-1<10 && 0<=j && j<10 && target[i-1][j] == 'o') dfs(i-1, j);
    if(0<=i && i<10 && 0<=j+1 && j+1<10 && target[i][j+1] == 'o') dfs(i, j+1);
    if(0<=i && i<10 && 0<=j-1 && j-1<10 && target[i][j-1] == 'o') dfs(i, j-1);

    return;
}

int main() {
    for(int i=0; i<10; i++) cin >> in[i];

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(in[i][j] == 'o') continue;

            for(int q=0; q<10; q++) target[q] = in[q];
            // 土地を１つ陸で埋めてみて、陸地の中を深さ優先探索する
            target[i][j] = 'o';
            dfs(i, j);

            bool fl = true;
            for(int q=0; q<10; q++) {
                for(int w=0; w<10; w++) {
                    if(target[q][w] == 'o') {
                        fl = false;
                        break;
                    }
                }
            }

            if (fl) {
                cout << "YES" << endl;
                exit(0);
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}