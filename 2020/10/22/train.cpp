#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;

    ll n = s.length() - 1;

    string ans = "";

    for(int bit=0; bit < (1<<n); bit++) {
        ans = s[0];
        ll tmp = s[0] - '0';
        for(int i=0; i<3; i++) {
            if(bit&(1<<i)) {
                ans += '+';
                ans += s[i+1];
                tmp += s[i+1] - '0';
            } else {
                ans += '-';
                ans += s[i+1];
                tmp -= s[i+1] - '0';
            }
        }
        if (tmp == 7) {
            ans += "=7";
            cout << ans << endl;
            break;
        }
    }

    return 0;
}