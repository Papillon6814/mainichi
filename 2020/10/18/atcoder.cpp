#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t;

ll bubbleSort(string str) {
    ll cnt = 0;
    if(str > "atcoder") return cnt;

    for(ll i=(ll)str.length(); i>0; i--) {
        for(ll j=0; j<i; j++) {
            if(str[j+1] > str[j]) {
                auto tmp = str[j+1];
                str[j+1] = str[j];
                str[j] = tmp;
                cnt++;
                if(str > "atcoder") {
                    //cout << str << endl;
                    return cnt;
                }
                break;
            }
        }
        //cout << str << endl;
    }

    return -1;
}

int main() {
    cin >> t;
    string s[t];
    ll a[t];

    for(ll i=0; i<t; i++) {
        cin >> s[i];
    }
    
    for(ll i=0; i<t; i++) {
        a[i] = bubbleSort(s[i]);
        cout << a[i] << endl;
    }

    return 0;
}