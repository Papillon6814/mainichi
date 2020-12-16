#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    int h, w;
    queue<pii> q;

    string s[1010];

    cin >> h >> w;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    for(int i=0; i<h; i++) cin >> s[i];
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            dist[i][j] = -1;
            if(s[i][j] == '#') {
                q.push(pii(i, j));
                dist[i][j] = 0;
            }
        }
    }

    int max_dist = 0;
    while(!q.empty()) {
        pii t = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int ty = t.first + d[i][0];
            int tx = t.second + d[i][1];

            if(0>ty || 0>tx || h<=ty || w<=tx) continue;
            if(dist[ty][tx] != -1) continue;
            if(s[ty][tx] == '#') continue;

            dist[ty][tx] = dist[t.first][t.second] + 1;
            max_dist = max(max_dist, dist[ty][tx]);
            q.push(pii(ty, tx));
        }
    }

    cout << max_dist << endl;
    return 0;
}