#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    int x[n], y[n];
    for(int i=0; i<n; i++) cin >> x[i] >> y[i];

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                int dx1 = x[i] - x[j];
                int dx2 = x[i] - x[k];
                int dy1 = y[i] - y[j];
                int dy2 = y[i] - y[k];

                if(dx1*dy2 == dx2*dy1) {
                    cout << "Yes" << endl;
                    exit(0);
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}