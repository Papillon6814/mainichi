#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

int main() {
    cin >> s;
    ll num = s.length()-1;

    ll ans = 0;
    for(int bit=0; bit<(1<<num); bit++) {
        ll tmp = 0;
        for(ll i=0; i<s.length(); i++) {
            tmp = 10*tmp + s[i] - '0';
            if((1<<i)&bit) {
                //cout << tmp << " " << bit << endl;
                ans += tmp;
                tmp = 0;
            }
        }
        ans += tmp;
    }

    cout << ans << endl;

    return 0;
}