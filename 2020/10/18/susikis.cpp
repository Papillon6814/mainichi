#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
ll sum = 0;

int main() {
    cin >> s;
    for(ll bit=0; bit < (1<<(s.length()-1)); bit++) {
        ll m = 0;
        for(ll i=0; i<s.length(); i++) {
            m = m*10+s[i] - '0';
            if((1<<i) & bit) {
                sum += m;
                m = 0;
            }
        }
        // プラスが入らないとき
        sum += m;
    }

    cout << sum << endl;

    return  0;
}