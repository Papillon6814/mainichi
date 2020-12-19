#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    stringstream ss;
    int count = 0;
    
    for(int i=1; i<=n; i++) {
        ss << dec << i;
        string decn = ss.str();
        ss.str("");
        ss.clear(stringstream::goodbit);
        ss << oct << i;
        string octn = ss.str();
        ss.str("");
        ss.clear(stringstream::goodbit);

        if(decn.find('7') != string::npos || octn.find('7') != string::npos) {
            continue;
        }
        count++;
    }

    cout << count << endl;

    return 0;
}