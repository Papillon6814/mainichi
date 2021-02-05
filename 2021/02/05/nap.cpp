#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int weight[n], value[n];
    for(int i=0; i<n; i++) {
        cin >> weight[i] >> value[i];
    }
    int w;
    cin >> w;

    // dpテーブル
    int dp[n][10110];
    for(int i=0; i<=w; i++) dp[0][i] = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j <= w; j++) {
            if(j >= weight[i]) dp[i+1][j] = max(dp[i][j-weight[i]] + value[i], dp[i][j]);
            else dp[i+1][j] = dp[i][j];
        }
    }

    cout << dp[n][w] << endl;
}