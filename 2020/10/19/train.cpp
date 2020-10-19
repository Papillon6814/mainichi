#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// 例
// 文字列操作があんまわからんかったかもしれんこれは
int main() {
    string s;
    cin >> s;

    // 固定長のやつは固定で書いたほうがいいわ絶対
    for(int bit=0; bit < (1<<3); bit++) {
        // これintにキャストしてんのか初めて知った
        int tmp = s.at(0) - '0';
        string ans = "";
        ans += s.at(0);
        for(int i=0; i<3; i++) {
            if(bit & (1<<i)) {
                tmp += s.at(i+1) - '0';
                ans += '+';
                ans += s.at(i+1);
            } else {
                tmp -= s.at(i+1) - '0';
                ans += '-';
                ans += s.at(i+1);
            }
        }

        if(tmp == 7) {
            cout << ans << "=7";
            break;
        }
    }

    return 0;
}