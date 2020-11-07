#include <bits/stdc++.h>

using namespace std;

string in[11];
string land[11];

void dfs(int i, int j) {
    land[i][j] = 'x';

    if(0 <= i+1 && i+1 < 10 && 0 <= j && j < 10 && land[i+1][j] == 'o') dfs(i+1, j);
    if(0 <= i-1 && i-1 < 10 && 0 <= j && j < 10 && land[i-1][j] == 'o') dfs(i-1, j);
    if(0 <= i && i < 10 && 0 <= j+1 && j+1 < 10 && land[i][j+1] == 'o') dfs(i, j+1);
    if(0 <= i && i < 10 && 0 <= j-1 && j-1 < 10 && land[i][j-1] == 'o') dfs(i, j-1);

    return;
}

int main() {
    for(int i=0; i<10; i++) cin >> in[i];

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(in[i][j] == 'o') continue;

            for(int q=0; q<10; q++) land[q] = in[q];

            land[i][j] = 'o';
            dfs(i, j);

            bool fl = true;
            for(int q=0; q<10; q++) {
                for(int w=0; w<10; w++) {
                    if(land[q][w] == 'o') {
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