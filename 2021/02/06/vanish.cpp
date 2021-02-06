#include <bits/stdc++.h>

using namespace std;

int main() {
    int v, t, s, d;
    cin >> v >> t >> s >> d;

    int start, finish;
    start = v*t;
    finish = v*s;

    if(start <= d && d <= finish) cout << "No" << endl;
    else cout << "Yes" << endl;
}