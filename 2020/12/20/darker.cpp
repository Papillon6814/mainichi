#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h); 
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pii> q;
    
    for(int i=0; i<h; i++) {
        cin >> s[i];
        for(int j=0; j<w; j++) {
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

            if(ty<0 || tx<0 || ty>=h || tx>=w) continue;
            if(dist[ty][tx] != -1) continue;
            if(s[ty][tx] == '#') continue;

            q.push(pii(ty, tx));
            dist[ty][tx] = dist[t.first][t.second] + 1;
            max_dist = max(max_dist, dist[ty][tx]);
        }
    }

    cout << max_dist << endl;

    return 0;
}