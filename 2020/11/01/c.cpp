#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

bool isInSameLine(int px1, int py1, int px2, int py2, int px3, int py3) {
    int dx1, dx2;
    int dy1, dy2;
    
    dx1 = px1-px2;
    dx2 = px1-px3;
    dy1 = py1-py2;
    dy2 = py1-py3;

    if(dx1*dy2 == dx2*dy1) return true;

    return false;
}

int main() {
    cin >> n;
    vector<int> x(n), y(n);
    for(int i=0; i<n; i++) cin >> x[i] >> y[i];

    // sort(x.begin(), x.end());
    // sort(y.begin(), y.end());
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                if(isInSameLine(x[i], y[i], x[j], y[j], x[k], y[k])) {
                    cout << "Yes" << endl;
                    exit(0);
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}