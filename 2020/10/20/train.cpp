#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;

    string ans = "";

    for(int bit=0; bit < (1<<3); bit++) {
        int tmp = s.at(0) - '0';
        ans = s.at(0);

        for(int i=1; i<4; i++) {
            // bit全探索とこのif分岐の条件式は相性良さそう
            if(bit & (1<<i-1)) {
                // 2進で1のとき
                ans += '+';
                tmp += s.at(i) - '0';
            } else {
                // 2進で0のとき
                ans += '-';
                tmp -= s.at(i) - '0';
            }
            ans += s.at(i);
        }

        if(tmp == 7) {
            ans += "=7";
            break;
        }
    }

    cout << ans << endl;

    return 0;
}