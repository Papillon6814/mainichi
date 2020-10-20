#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
vector<double> x;

int main() {
    cin >> n;
    x.resize(n);
    for(ll i=0; i<n; i++) cin >> x[i];

    double manh = 0.0;
    double yuku = 0.0;
    double cheb = 0.0;
    for(ll i=0; i<n; i++) {
        manh += abs(x[i]);
        yuku += abs(x[i])*abs(x[i]);
        cheb = max(abs(cheb), abs(x[i]));
    }

    yuku = sqrt(yuku);
    
    // 精度がたりなさそうなときはsetprecisionをして桁数を増やしてあげるといいかもしれない
    cout << fixed << setprecision(12) << manh << endl;
    cout << yuku << endl;
    cout << cheb << endl;
}