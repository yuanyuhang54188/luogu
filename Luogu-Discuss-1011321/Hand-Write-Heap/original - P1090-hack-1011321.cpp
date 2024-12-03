//取堆中次小值时没考虑len==2的情况,已修正
#include <bits/stdc++.h>
using namespace std;
int a[10005], len, n;
void extract() {
    int p = 1;
    a[1] = a[n];
    len--;
    int s = p * 2;
    while ( s <= n ) {
        if ( a[s] > a[s + 1] && s < n ) {
            s++;
        }
        if ( a[s] < a[p] ) {
            swap ( a[s], a[p] );
            p = s;
            s *= 2;
        } else {
            break;
        }
    }
}
void insert ( int val ) {
    a[++len] = val;
    int s = len / 2, p = len;
    while ( s >= 1 ) {
        if ( a[s] > a[p] ) {
            swap ( a[s], a[p] );
            p = s;
            s = p / 2;
        } else {
            break;
        }
    }
}
int main() {
    scanf ( "%d", &n );
    len = n;
    for ( int i = 1; i <= n; i++ ) {
        scanf ( "%d", &a[i] );
    }
    sort ( a + 1, a + 1 + n );
    int ans = 0;
    for ( int i = 1; i <= n - 1; i++ ) {
        int tmp2 = len >= 3 ? min ( a[2], a[3] ) : a[2];
        ans += ( a[1] + tmp2 );   // 答案计数操作体重值
        int tmp = ( a[1] + tmp2 );
        extract();
        extract();
        insert ( tmp );
    }
    printf ( "%d", ans );
    return 0;
}
