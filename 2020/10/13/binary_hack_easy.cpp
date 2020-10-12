#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s = "";
    string sin;
    cin >> sin;

    for(int i=0; i<sin.length(); i++) {
        if (sin[i] == 'B' && s.length() != 0) {
            s.erase(s.length()-1);
        }

        if (sin[i] != 'B') {
            s += sin[i];
        }
    }

    cout << s << endl;

    return 0;
}