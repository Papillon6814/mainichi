#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool land[11][11];
bool tmp[11][11];

void dfs(int px, int py) {
    tmp[px][py] = false;

    if(0 <= px-1 && px-1 < 10 && 0 <= py && py < 10 && tmp[px-1][py]) dfs(px-1, py);
    if(0 <= px+1 && px+1 < 10 && 0 <= py && py < 10 && tmp[px+1][py]) dfs(px+1, py);
    if(0 <= px && px < 10 && 0 <= py-1 && py-1 < 10 && tmp[px][py-1]) dfs(px, py-1);
    if(0 <= px && px < 10 && 0 <= py+1 && py+1 < 10 && tmp[px][py+1]) dfs(px, py+1);

    return;
}

int main() {
    for(int i=0; i<10; i++) {
        string s;
        cin >> s;
        for(int j=0; j<10; j++) {
            if(s[j] == 'o') land[i][j] = true;
        }
    }

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(land[i][j]) continue;
            for(int q=0; q<10; q++) {
                for(int w=0; w<10; w++) {
                    tmp[q][w] = land[q][w];
                }
            }

            tmp[i][j] = true;
            dfs(i, j);

            bool fl = true;
            for(int q=0; q<10; q++) {
                for(int w=0; w<10; w++) {
                    if(tmp[q][w]) fl = false;
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