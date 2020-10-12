#include <cstdio>
#include <iostream>

using namespace std;

string sort(string *sarray, size_t size);

int main() {
    int n, l;

    cin >> n >> l;

    string s[n];
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }

    cout << sort(s, n) << "\n";

    return 0;
}

// bubble sort
string sort(string *sarray, size_t size) {
    string s = "";

    for (int i=0; i<size; i++) {
        for (int j=size-1; j>i; j--) {
            if (sarray[j-1] > sarray[j]) {
                string tmp = sarray[j];
                sarray[j] = sarray[j-1];
                sarray[j-1] = tmp;
            }
        }
    }

    for (int i=0; i<size; i++) {
        s += sarray[i];
    }

    return s;
}
