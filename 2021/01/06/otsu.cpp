#include <bits/stdc++.h>

using namespace std;

int main() {
    int money;
    int coin[6] = {500, 100, 50, 10, 5, 1};
    int ans = 0;

    cin >> money;
    money = 1000 - money;
    for(int i=0; i<6; i++) {
        while(money >= coin[i]) {
            money -= coin[i];
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}