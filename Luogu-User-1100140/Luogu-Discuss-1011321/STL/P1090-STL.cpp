#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int,vector<int>, greater<int>> q;

signed main(signed argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x, y = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> x;
        q.push(x);
    }
    while (q.size() > 1) {
        x = q.top(); q.pop();
        x +=q.top(); q.pop();
        q.push(x);
        y += x;
    }
    cout << y << endl;
    return 0;
}
