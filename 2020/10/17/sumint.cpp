#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll k, s;

int main() {
    cin >> k >> s;
    ll cnt = 0;

    for(int i=0; i<=k; i++) {
        for(int j=0; j<=k; j++) {
            if(i+j+k >= s && i+j <= s) cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}