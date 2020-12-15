#include <bits/stdc++.h>

using namespace std;

int dist[1010][1010];

int main() {
    int H, W;
    queue<pair<int, int>> que;
    const int dh[4] = {1, 0, -1, 0};
    const int dw[4] = {0, 1, 0, -1};
    string A[1010];

    cin >> H >> W;
    for(int h=0; h<H; h++) cin >> A[h];
    for(int h=0; h<H; h++) {
        for(int w=0; w<W; w++) {
            dist[h][w] = -1;
            if(A[h][w] == '#') {
                que.push(pair<int, int>(h, w));
                dist[h][w] = 0;
            }
        }
    }

    int max_dist = 0;
    while(!que.empty()) {
        pair<int, int> hw = que.front();
        que.pop();
        for(int i=0; i<4; i++) {
            int next_h = hw.first + dh[i];
            int next_w = hw.second + dw[i];
            if(0 <= next_h && next_h < H && 0 <= next_w && next_w < W && dist[next_h][next_w] == -1 && A[next_h][next_w] == '.') {
                dist[next_h][next_w] = dist[hw.first][hw.second] + 1;
                max_dist = max(max_dist, dist[next_h][next_w]);
                que.push(pair<int, int>(next_h, next_w));
            }
        }
    }

    cout << max_dist << endl;
    return 0;
}