#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n, k, x, y;
    int sum = 0;

    cin >> n;
    cin >> k;
    cin >> x;
    cin >> y;

    for(int i=1; i<=n; i++) {
        if(i <= k) {
            sum += x;
        } else {
            sum += y;
        }
    }

    cout << sum << "\n";

    return 0;
}