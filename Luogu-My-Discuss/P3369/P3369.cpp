```cpp
#include <bits/stdc++.h>
#define I using
#define AK namespace
#define IOI std;
#define int long long
#undef INT_MIN
#define INT_MIN (LONG_LONG_MIN + 1145)
#undef INT_MAX
#define INT_MAX (LONG_LONG_MAX - 1145)
#define rint register int
#define loop(bg, ed, k) for (rint i = bg; i <= ed; i += k)
#define P1 "标记点1"
#define P2 "标记点2"
#define P3 "标记点3"
#define P4 "标记点4"
#define P5 "标记点5"
#define P6 "标记点6"
#define P7 "标记点7"
#define P8 "标记点8"
#define P9 "标记点9"
#define P0 "标记点0"
#define M                       ( L + R >> 1 )
#define len                     (R - L + 1)
#define tv                      t[u].value
#define ts                      t[u].rngsm
#define ls                      (u << 1)
#define rs                      (u << 1 | 1)
#define llen                    (M - L + 1)
#define rlen                    (R - M)
#define sls                     t[ls].rngsm
#define srs                     t[rs].rngsm
#define vls                     t[ls].value
#define vrs                     t[rs].value
#define vl                      actions[i].val
#define op                      actions[i].opt
#define pre                     kth ( rnk ( vl ) - 1 )
#define nxt_not_in              kth ( rnk ( vl ) )
#define nxt_is_in               kth ( rnk ( vl ) + 1 )
#define MAXN 100007
I AK IOI;

AK CSP {
    inline void read ( int &x ) {
        x = 0;
        char c = getchar();
        int pn = 1;
        while ( !isdigit ( c ) ) {
            if ( c == '-' ) {
                pn = -1;
            }
            c = getchar();
        }
        while ( isdigit ( c ) ) {
            x = x * 10 + c - 48;
            c = getchar();
        }
        x *= pn;
        return;
    }
    inline void write ( int x ) {
        if ( x < 0 ) {
            putchar ( '-' ), x = -x;
        }
        if ( x >= 10 ) {
            write ( x / 10 );
        }
        putchar ( x % 10 + 48 );
        return;
    }
    struct inputstream {
        inputstream operator>> ( int &x ) {
            read ( x );
            return *this;
        }
    } in;
    struct outputstream {
        outputstream operator<< ( int x ) {
            write ( x );
            putchar ( 10 );
            return *this;
        }
    } out;
}
I AK CSP;

int Q, N;
struct segment_tree_node {
    int value;                 // 存极大值
    int rngsm;                 // 存区间数量
    segment_tree_node ( int v = 0, int s = 0 ) {
        value :
        v;
        rngsm :
        s;
    }
};
segment_tree_node t[MAXN << 2];
struct action {
    int opt;
    int val;
    action ( int opr = 0, int vlr = 0 ) {
        opt :
        opr;
        val :
        vlr;
    }
};
action actions[MAXN];
priority_queue<int, vector<int>, greater<int> > dat;
map<int, int> m;
map<int, int> mp;
vector<int> numbers;

AK NOI {
    /* functions list :
    * +--------------------------+-------------------+
    * |     NAME OF FUNCTION     |    DONE OR NOT    |
    * |--------------------------|-------------------|
    * |        set_val           |        YES        |
    * |--------------------------|-------------------|
    * |          ins             |        YES        |
    * |--------------------------|-------------------|
    * |          del             |        YES        |
    * |--------------------------|-------------------|
    * |          rnk             |        YES        |
    * |--------------------------|-------------------|
    * |          kth             |        YES        |
    * |--------------------------|-------------------|
    * |          pre             |        YES        |
    * |--------------------------|-------------------|
    * |          nxt             |        YES        |
    * +--------------------------+-------------------+
    */
    inline void set_val ( int u = 1, int L = 1, int R = N ) {
        if ( L == R ) {
            tv = numbers[L - 1];
            ts = 0;
            return;
        } else if ( L > R ) {
            return;
        }
        set_val ( ls, L, M );
        set_val ( rs, M + 1, R );
        ts = 0;
        tv = max ( vls, vrs );
        return;
    }
    inline void ins ( int val, int u = 1, int L = 1, int R = N ) {
        ++ts;
        if ( L == R ) {
            return;
        } else if ( L > R ) {
            --ts;
            return;
        }
        if ( val <= vls ) {
            ins ( val, ls, L, M );
        } else {
            ins ( val, rs, M + 1, R );
        }
        return;
    }
    inline void del ( int val, int u = 1, int L = 1, int R = N ) {
        --ts;
        if ( L == R ) {
            return;
        } else if ( L > R ) {
            ++ts;
            return;
        }
        if ( val <= vls ) {
            del ( val, ls, L, M );
        } else {
            del ( val, rs, M + 1, R );
        }
        return;
    }
    inline int rnk ( int k, int u = 1, int L = 1, int R = N ) {
        if ( L == R ) {
            if ( k <= tv ) {
                return 1;
            } else {
                return ts + 1;        // 大于tv的话, tv的数量也要算上
            }
        } else if ( L > R ) {
            return INT_MIN;
        }
        if ( k <= vls ) {
            return rnk ( k, ls, L, M );
        } else {
            return sls + rnk ( k, rs, M + 1, R );
        }
        return INT_MIN;
    }
    inline int kth ( int k, int u = 1, int L = 1, int R = N ) {
        if ( L == R ) {
            return tv;
        } else if ( L > R ) {
            return INT_MIN;
        }
        if ( k <= sls ) {
            return kth ( k, ls, L, M );
        } else {
            return kth ( k - sls, rs, M + 1, R );
        }
        return INT_MIN;
    }
} I AK NOI;

signed main ( signed argc, char const *argv[] ) {
    in >> Q;
    loop ( 1, Q, 1 ) {
        in >> op >> vl;
        if ( op == 1 ) {
            dat.push ( vl );
        }
    }
    for ( rint i = 1; !dat.empty(); i++ ) {
        if ( !m.count ( dat.top() ) ) {
            m[dat.top()] = i;
            ++N;
            numbers.push_back ( dat.top() );
        }
        dat.pop();
    }
    set_val();
    loop ( 1, Q, 1 ) {
        if ( op == 1 ) {
            ins ( vl );
            mp[vl]++;
        }  else if ( op == 2 ) {
            del ( vl );
            mp[vl]--;
        }  else if ( op == 3 ) {
            out << rnk ( vl );
        }  else if ( op == 4 ) {
            out << kth ( vl );
        }  else if ( op == 5 ) {
            out << pre;
        }  else if ( op == 6 ) {
            if ( mp.count ( vl ) && mp[vl] != 0 ) {
                out << nxt_is_in;
            } else {
                out << nxt_not_in;
            }
        }
    }
    return 0;
}
```
