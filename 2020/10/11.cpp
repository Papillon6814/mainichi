#include <cstdio>
#include <iostream>
using namespace std;

// Iroha and Haiku
int main() {
    int a, b, c;

    cin >> a;
    cin >> b;
    cin >> c;

    if (a+b+c == 17) {
        if ((a == 5 || a == 7) &&
            (b == 5 || b == 7) &&
            (c == 5 || c == 7)) {
                printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        printf("NO\n");
    }

    return 0;
}