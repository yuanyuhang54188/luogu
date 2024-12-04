//取堆中次小值时没考虑len==2的情况,已修正
#include <bits/stdc++.h>
using namespace std;
int h[10005], len, n;

void del() {
    int p = 1;
    h[1] = h[len];
    len--;
    int s = p * 2;
    while ( s <= n ) {
        if ( h[s] > h[s + 1] && s < n ) {
            s++;
        }
        if ( h[s] < h[p] ) {
            swap ( h[s], h[p] );
            p = s;
            s *= 2;
        } else {
            break;
        }
    }
    return;
}
void insert ( int val ) {
    h[++len] = val;
    int s = len / 2, p = len;
    while ( s >= 1 ) {
        if ( h[s] > h[p] ) {
            swap ( h[s], h[p] );
            p = s;
            s = p / 2;
        } else {
            break;
        }
    }
    return;
}
int main() {
    scanf ( "%d", &n );
    len = n;
    int x;
    for ( int i = 1; i <= n; i++ ) {
        scanf ( "%d", &x );
        insert ( x );
    }
    int ans = 0;
    for ( int i = 1; i <= n - 1; i++ ) {
        int tmp2 = h[1] + h[2];
        ans += tmp2 ;
        del();
        del();
        insert ( tmp2 );
    }
    printf ( "%d", ans );
    return 0;
}
