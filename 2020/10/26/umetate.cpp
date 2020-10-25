#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n = 0;
int sum = 1;
// 前後に２つずつのマージン？
int pas[14][14] = {};

void dfs(int i, int j, char a[14][14]) {
    pas[i][j] = 1;
    n++;

    // -1したり+1したりして深さ優先探索を進める
    if(a[i-1][j] == 1 && pas[i-1][j] == 0) dfs(i-1, j, a);
    if(a[i+1][j] == 1 && pas[i+1][j] == 0) dfs(i+1, j, a);
    if(a[i][j+1] == 1 && pas[i][j+1] == 0) dfs(i, j+1, a);
    if(a[i][j-1] == 1 && pas[i][j-1] == 0) dfs(i, j-1, a);

    if(n == sum) {
        printf("YES\n");
        exit(0);
    }
}

int main() {
    char a[14][14] = {};

    //XXX: なんで12なのかはわからん
    // まずは陸地と海の部分を埋める
    for(int i=2; i<12; i++) {
        for(int j=2; j<12; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'o') {
                a[i][j] = 1;
                sum++;
            } else {
                a[i][j] = 0;
            }
        }
    }

    // スタート地点の探索
    for(int i=2; i<12; i++) {
        for(int j=2; j<12; j++) {
            if(a[i][j] == 0) {
                a[i][j] = 1;
                for(int q=0; q<14; q++)
                    for(int w=0; w<14; w++)
                        pas[q][w] = 0;

                n = 0;
                dfs(i, j, a);
                a[i][j] = 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}