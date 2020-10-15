#include <stdio.h>
using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long ll;

int n;

int get_block(int rating)
{
    if (rating < 400) return 1;
    else if (rating < 800) return 2;
    else if (rating < 1200) return 3;
    else if (rating < 1600) return 4;
    else if (rating < 2000) return 5;
    else if (rating < 2400) return 6;
    else if (rating < 2800) return 7;
    else if (rating < 3200) return 8;
    else return 0;
}

int main() {
    scanf("%d", &n);
    int block[9] = {0};
    int t;

    for(int i=0; i<n; i++) {
        scanf("%d", &t);
        block[get_block(t)]++;
    }

    int cnt = 0;
    for(int i=1; i<=8; i++) {
        if(block[i] != 0) cnt++;
    }

    int maans = cnt + block[0];
    int mians = max(cnt, block[0]);

    printf("%d %d\n", mians, maans);

    return 0;
}
