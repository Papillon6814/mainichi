#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll sum = 0;

    for(ll i=0; i<n; i++) {
        ll mi, ma;
        cin >> mi >> ma;
        // 等差数列の和の公式
        sum += (mi+ma)*(ma-mi+1)/2;
    }

    cout << sum << endl;

    return 0;
}