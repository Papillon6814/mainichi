#include<stdio.h>
#include<stdbool.h>

const int nDays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool is_LeapYear(const int y)
{
   bool ans;

    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0){
        ans = true;
    }else{
        ans = false;
    }

  return ans;
}

bool is_in_range(const int y, const int m, const int d)
{
    if (m<1|| m>12) {printf("月が範囲外\n");return false;}
    int LastDay = nDays[m];
    if (m==2 && is_LeapYear(y)) {LastDay = 29;}
    if (d<0 || d>LastDay){printf("日が範囲外\n");return false;}
    return true;
}

void increment_date(int *py, int *pm, int *pd)
{
    int LastDay = nDays[*pm];
    // うるう年
    if (is_LeapYear(*py) && *pm == 2) LastDay = 29;

    *pd+=1;

    if(*pd > LastDay) {
        *pm+=1;
        *pd = 1;
    }

    if(*pm > 12) {
        *py+=1;
        *pm = 1;
    }
}

void decrement_date(int *py, int *pm, int *pd)
{
    int i;

    for(int i=0; i<2; i++) {
        int LastDay = nDays[*pm-1];

        if (is_LeapYear(*py) && *pm-1 == 2) LastDay = 29;
        
        *pd-=1;

        if(*pd < 1) {
            *pm-=1;
            *pd = *pm == 0 ? nDays[12] : LastDay;

            // if(*pm == 0) {
            //     *pd = nDays;
            // } else {
            //     *pd = LastDay;
            // }
        }

        if(*pm < 1) {
            *py-=1;
            *pm = 12;
        }
    }
}

int main (void){
    int y, m, d;
    int y_wk, m_wk, d_wk;
    bool ans;

    printf("年月日を入力してください。=>");
    scanf("%d%d%d",&y,&m,&d);

    if(!is_in_range(y, m, d)) return 1;

    y_wk = y; m_wk = m; d_wk = d;

    increment_date(&y_wk, &m_wk, &d_wk);
    printf("その翌日は、%d年%d月%d日です\n",y_wk, m_wk, d_wk);
    decrement_date(&y_wk, &m_wk, &d_wk);
    printf("その前日は、%d年%d月%d日です\n",y_wk, m_wk, d_wk);
    return 0;
}