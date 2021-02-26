#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a = "a", b = "b";
    cout << a << '\n' << b << '\n';
    for (int i = 2; i <= 10; ++i) {
        a = b + a;
        cout << a;
        swap(a, b);
    }
    return 0;
}
