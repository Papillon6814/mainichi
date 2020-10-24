#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll n, ansA, ansB;
ll a = 3, b = 5;

bool calc() {
    for(ll i=1; a<n; ++i) {
        a = pow(3, i);
        b = 5;
        for(ll j=1; b<n; ++j) {
            b = pow(5, j);

            //cout << "(a, b): " << a << " " << b <<endl;
            if(a+b == n) {
                ansA = i;
                ansB = j;
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> n;

    if (calc()) printf("%llu %llu\n", ansA, ansB);
    else cout << "-1" << endl;

    return 0;
}