#include <bits/stdc++.h>

using namespace std;

bool c[99], l[199], r[199];
char b[99][99];

void print(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << b[i][j];
        cout << '\n';
    }
    cout << '\n';
}

void solve(int i, int n) {
    if (i == n) {
        print(n);
        return;
    }
    for (int j = 0; j < n; ++j) {
        if (c[j] || l[i - j + n - 1] || r[i + j - n + 1]) continue;
        c[j] = true;
        l[i - j + n - 1] = true;
        r[i + j - n + 1] = true;
        b[i][j] = '*';
        solve(i + 1);
        b[i][j] = '-';
        r[i + j - n + 1] = false;
        l[i - j + n - 1] = false;
        c[j] = false;
    }
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[i][j] = '-';
    solve(0, n);
    return 0;
}
