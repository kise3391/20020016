#include <bits/stdc++.h>

using namespace std;

bool c[8], l[15], r[15];
char b[8][8];

void print() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
            cout << b[i][j];
        cout << '\n';
    }
    cout << '\n';
}

void solve(int i) {
    if (i == 8) {
        print();
        return;
    }
    for (int j = 0; j < 8; ++j) {
        if (c[j] || l[i - j + 7] || r[i + j - 7]) continue;
        c[j] = true;
        l[i - j + 7] = true;
        r[i + j - 7] = true;
        b[i][j] = '*';
        solve(i + 1);
        b[i][j] = '-';
        r[i + j - 7] = false;
        l[i - j + 7] = false;
        c[j] = false;
    }
}

int main()
{
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            b[i][j] = '-';
    solve(0);
    return 0;
}
