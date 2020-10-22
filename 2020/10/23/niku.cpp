#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++) cin >> vec[i];
    int ans = INT_MAX;

    for(int bit=0; bit<(1<<n); bit++) {
        int a = 0, b = 0;
        //1なら肉焼き器1で、0なら肉焼き器2で焼く
        for(int i=0; i<n; i++) {
            if(bit&(1<<i)) a += vec[i];
            else b += vec[i];
        }

        ans = min(ans, max(a, b));
    }

    cout << ans << endl;

    return 0;
}