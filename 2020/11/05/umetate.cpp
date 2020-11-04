#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string fld[11];
string tmp[11];

void dfs(int i, int j) {
    tmp[i][j] = 'x';

    if(0<=i+1 && i+1<10 && 0<=j && j<10 && tmp[i+1][j] == 'o') dfs(i+1, j);
    if(0<=i-1 && i-1<10 && 0<=j && j<10 && tmp[i-1][j] == 'o') dfs(i-1, j);
    if(0<=i && i<10 && 0<=j+1 && j+1<10 && tmp[i][j+1] == 'o') dfs(i, j+1);
    if(0<=i && i<10 && 0<=j-1 && j-1<10 && tmp[i][j-1] == 'o') dfs(i, j-1);

    return;
}

int main() {
    for(int i=0; i<10; i++) cin >> fld[i];

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(fld[i][j] == 'o') continue;

            for(int q=0; q<10; q++) tmp[q] = fld[q];
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

            if (fl) {
                cout << "YES" << endl;
                exit(0);
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}