#include <bits/stdc++.h>

using namespace std;

int payment;
int ans = 0;

int main() {
    int coins[6] = {500, 100, 50, 10, 5, 1};
    cin >> payment;
    int change = 1000 - payment;

    for(int i=0; i<6; i++) {
        while(change >= coins[i]) {
            change -= coins[i];
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}