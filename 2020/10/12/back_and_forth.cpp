// GIVE UP

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;

int sx, sy, tx, ty;
string ans = "";

int main() {
    cin >> sx >> sy >> tx >> ty;

    // やっぱdx, dyはつくるんだ
    int dx = tx-sx, dy = ty-sy;

    for (int i=0; i < dy; i++) ans += 'U';
    for (int i=0; i < dx; i++) ans += 'R';
    for (int i=0; i < dy; i++) ans += 'D';
    for (int i=0; i < dx; i++) ans += 'L';

    ans += 'L';
    for (int i=0; i < dy+1; i++) ans += 'U';
    for (int i=0; i < dx+1; i++) ans += 'R';
    ans += 'D';
    ans += 'R';
    for (int i=0; i < dy+1; i++) ans += 'D';
    for (int i=0; i < dx+1; i++) ans += 'L';
    ans += 'U';

    cout << ans << endl;

    return 0;
}

/*
おれのは処理の書き方が汚かったから混ざっちゃったけど
処理の方法的にはそこまで間違ってなかったと思う。
細分化しすぎてコードが冗長になることが多い。
あとおれ問題文読まなさすぎで考慮する部分が増えてたのは致命的。
*/
