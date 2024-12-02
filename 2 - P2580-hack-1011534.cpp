#include <bits/stdc++.h>
using namespace std;

const int P = 131;
int n, pd[300005];

struct tname {
    char* name;
    unsigned long long hash1;
    tname ( char* xxxx = NULL, unsigned long long yyyy = 0 ) {
        if ( xxxx == NULL ) {
            name = new char[55];
        } else {
            name = xxxx;
        }
        hash1 = yyyy;
    }
} coach;
struct classmates {
    char* name;
    unsigned long long hash1;
    classmates ( char* xxxx = NULL, unsigned long long yyyy = 0 ) {
        if ( xxxx == NULL ) {
            name = new char[55];
        } else {
            name = xxxx;
        }
        hash1 = yyyy;
    }
} cm[300005];

namespace functions {
    bool cmp1 ( classmates x, classmates y ) {
        return x.hash1 < y.hash1;
    }
    unsigned long long dealhash ( char *x ) {
        int len = strlen ( x );
        unsigned long long thash = 0;
        for ( int i = 0; i < len; i++ ) {
            thash = thash*P + x[i] - 'a' + 1;
        }
        return thash;
    }
//    int binary ( unsigned long long h ) {
//        int l = 1, r = n, mid = ( l + r ) / 2;
//        while ( l <= r ) {
//            if ( h > cm[mid].hash1 ) {
//                l = mid + 1;
//                mid = ( l + r ) / 2;
//            } else if ( h <= cm[mid].hash1 && l != r ) {
//                r = mid;
//                mid = ( l + r ) / 2;
//            } else if ( l == r ) {
//                if ( h == cm[mid].hash1 ) {
//                    return l;
//                } else {
//                    return -1;
//                }
//            }
//        }
//    }
    bool cmp2 ( tname const &val_searching, classmates const &element ) {
        return val_searching.hash1 <= element.hash1;
        /*
        * true即此时二分的元素的哈希值不小于目标值
        * false即此时二分位置哈希值小于目标值
        * 最终二分到的是不小于目标值的最小值
        * 即若此值大于目标值, 数组中不存在目标值
        * 若此值等于目标值, 数组中存在该值
        * 似乎不太可能会返回end啊
        * 加个特判吧
        */
    }
} using namespace functions;

int main() {
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; i++ ) {
        scanf ( "%s", cm[i].name );
        cm[i].hash1 = dealhash ( cm[i].name );
//        cout << cm[i].hash1 << endl;
    }
    sort ( cm + 1, cm + 1 + n, cmp1 );
    int m;
    scanf ( "%d", &m );
    for ( int i = 1; i <= m; i++ ) {
        scanf ( "%s", coach.name );
        coach.hash1 = dealhash ( coach.name );
//        cout << coach.hash1 << endl;
        int pot = upper_bound ( cm + 1, cm + 1 + n, coach, cmp2 ) - cm;   // ---- pot是在cm中的索引 ----
//        cout << pot << endl;                                           // ---------------------------
        if ( pot == n + 1 || cm[pot].hash1 != coach.hash1 ) {           // --------- 没找到 ----------
            printf ( "WRONG\n" );
        } else {
            if ( pd[pot] == 0 ) {
                pd[pot] = 1;
                printf ( "OK\n" );
            } else {
                printf ( "REPEAT\n" );
            }
        }
//        coach.hash1 = 0;
//        memset ( coach.name, 0, sizeof ( coach.name ) );
        coach = tname();           // 初始化构造函数
    }
}

