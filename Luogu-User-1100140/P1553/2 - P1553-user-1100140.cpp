#include <bits/stdc++.h>
using namespace std;
char a[50],b[50];
bool c[50];
bool flag;
int main() {
    scanf("%s", a);
    for(int i = 0; i < strlen(a); i++) {
        if(a[i] > '9' || a[i] < '0') {
            if(a[i] == '%') {
                int cnt = 0;
                flag = true;
                for(int j = i-1; j >= 0; j--) {
                    b[cnt++] = a[j];
                }
                b[cnt++] = '%';
            } else if(a[i] == '.') {
                int cnt = 0;
                flag = true;
                for(int j = i-1; j >= 0; j--) {
                    b[cnt++] = a[j];
                }
                b[cnt++] = '.';
                for(int j = strlen(a)-1; j >= i+1; j--) {
                    b[cnt++] = a[j];
                }
                break;
            } else if(a[i] == '/') {
                int cnt = 0;
                flag = true;
                for(int j = i-1; j >= 0; j--) {
                    b[cnt++] = a[j];
                }
                b[cnt++] = '/';
                for(int j = strlen(a)-1; j >= i+1; j--) {
                    b[cnt++] = a[j];
                }
                break;
            }
        }
    }
    if(!flag) {
        bool flag2 = true;
        for(int i = strlen(a)-1; i >= 0; i--) {
            if(i != 0 && flag2 && a[i] == '0') continue;
            else if(a[i]!='0' && flag2) flag2 = false;
            printf("%c", a[i]);
        }
    } else {
        bool flag2 = true;
        int len = 0,tmp = strlen(b);
        for(int i = tmp-1; i >= 0; i--) {
            len = i;
            if(b[i] < '0' || b[i] > '9') break;
        }
        for(int i = 0; i <= len-1; i++) {
            if(i != len-1 && flag2 && b[i] == '0') continue;
            else if(b[i] != '0' && flag2) flag2 = false;
            printf("%c", b[i]);
        }
        printf("%c", b[len]);
        if (b[len] == '.') {                         // 特殊处理, 删掉的是后缀0, 不是前缀0
            c[strlen(b)] = false;
            for (int i = strlen(b) - 1; i > len; i--) {
                if (b[i] == '0') c[i] = c[i + 1];
                else c[i] = true;
            }
            c[len + 1] = true;
            for (int i = len+1; i < strlen(b); i++) {
                if (c[i]) printf("%c", b[i]);
            }
        } else {
            flag2 = true;
            for(int i = len+1; i < strlen(b); i++) {
                if(i != strlen(b) - 1 && flag2 && b[i] == '0') continue;
                else if(b[i] != '0' && flag2) flag2 = false;
                printf("%c", b[i]);
            }
        }
    }
}
