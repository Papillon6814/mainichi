#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// よく理解できてないので色々な人の実装を観察してみる

char fld[11][11];
char tmp[11][11];

void dfs(int i, int j) {
    tmp[i][j] = 'x';

    if(0<=i+1 && i+1<10 && 0<=j && j<10 && tmp[i+1][j] == 'o') dfs(i+1, j);
    if(0<=i-1 && i-1<10 && 0<=j && j<10 && tmp[i-1][j] == 'o') dfs(i-1, j);
    if(0<=i && i<10 && 0<=j+1 && j+1<10 && tmp[i][j+1] == 'o') dfs(i, j+1);
    if(0<=i && i<10 && 0<=j-1 && j-1<10 && tmp[i][j-1] == 'o') dfs(i, j-1);

    return;
}

int main() {
    for(int i=0; i<10; i++) scanf("%s", fld[i]);

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(fld[i][j] == 'o') continue;

            memcpy(tmp, fld, sizeof(fld));
            tmp[i][j] = 'o';
            dfs(i, j);

            bool fl = true;
            for(int q=0; q<10; q++) {
                for(int w=0; w<10; w++) {
                    if(tmp[q][w] == 'o') {
                        fl = false;
                        break;
                    }
                }
            }

            if(fl) {
                cout << "YES" << endl;
                exit(0);
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}