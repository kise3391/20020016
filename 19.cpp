#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, z;
    bool b = false;
    cin >> x >> y >> z;
    if (x > y && y > z) b = true;
    if (x < y && y < z) b = true;
    cout << b;
    return 0;
}
