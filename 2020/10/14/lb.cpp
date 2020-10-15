#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
bool flag[8];

void init_flag() {
    for(int i=0; i<8; i++) flag[i] = false;
}

ll get_larger_variety(ll *arr) {
    init_flag();
    for(int i=0; i<n; i++) {
        for(int c=0; c<8; c++) 
            if(400*c <= arr[i] && arr[i] < 400*(c+1)) flag[c] = true;
    }

    int cnt = 0;

    // 3200はfalseに割り振る
    for(int i=0; i<n; i++) 
        if(arr[i] >= 3200) cnt++;
    
    for(int i=0; i<cnt; i++) 
        for(int c=0; c<8; c++)
            if(!flag[c]) {
                flag[c] = true;
                break;
            }

    ll color_num = 0;
    for(int i=0; i<8; i++)
        if(flag[i]) color_num++;

    return color_num;
}

ll get_smaller_variety(ll *arr) {
    init_flag();
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) continue;

        for(int c=0; c<8; c++) {
            if(400*c <= arr[i] && arr[i] < 400*(c+1)) flag[c] = true;
        }

        // 3200以上のやつには何もしない
    }

    ll color_num = 0;
    for(int i=0; i<8; i++)
        if(flag[i]) color_num++;

    return color_num;
}

int main() {
    cin >> n;
    ll a[n];
    for(ll i=0; i<n; i++) cin >> a[i];

    cout << get_smaller_variety(a) << " " << get_larger_variety(a) << endl;

    return 0;
}