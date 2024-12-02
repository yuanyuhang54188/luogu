#include <bits/stdc++.h>
using namespace std;
const int P = 131;
int n, pd[300005];
struct tname {
    char* name;
    unsigned long long hash1;
    tname ( char* xxxx = NULL, unsigned long long yyyy = 0 ) {
        if ( xxxx == NULL ) name = new char[55];
        else name = xxxx;
        hash1 = yyyy;
    }
} coach;
struct classmates {
    char* name;
    unsigned long long hash1;
    classmates ( char* xxxx = NULL, unsigned long long yyyy = 0 ) {
        if ( xxxx == NULL ) name = new char[55];
        else name = xxxx;
        hash1 = yyyy;
    }
} cm[300005];
bool cmp1 ( classmates x, classmates y ) {
    return x.hash1 < y.hash1;
}
unsigned long long dealhash ( char *x ) {
    int len = strlen ( x );
    unsigned long long thash = 0;
    for ( int i = 0; i < len; i++ ) thash = thash*P + x[i] - 'a' + 1;
    return thash;
}
bool cmp2 ( tname const &val_searching, classmates const &element ) {
    return val_searching.hash1 <= element.hash1;
}
int main() {
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; i++ ) {
        scanf ( "%s", cm[i].name );
        cm[i].hash1 = dealhash ( cm[i].name );
    }
    sort ( cm + 1, cm + 1 + n, cmp1 );
    int m;
    scanf ( "%d", &m );
    for ( int i = 1; i <= m; i++ ) {
        scanf ( "%s", coach.name );
        coach.hash1 = dealhash ( coach.name );
        int pot = upper_bound ( cm + 1, cm + 1 + n, coach, cmp2 ) - cm;   // ---- pot是在cm中的索引 ----
        if ( pot == n + 1 || cm[pot].hash1 != coach.hash1 )              // --------- 没找到 ----------
            printf ( "WRONG\n" );
        else
            if ( pd[pot] == 0 ) {
                pd[pot] = 1;
                printf ( "OK\n" );
            } else
                printf ( "REPEAT\n" );
        
        coach = tname();           // 初始化构造函数
    }
}

